#include <Arduino.h>
#include <DNSServer.h>
#include <ESP_EEPROM.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

/* Local Libraries */
#include "spi_master.h"
#include "can_signal.h"

/* Raw String Literals for webpages */
#include "about.html.h"
#include "about.js.h"
#include "Chart.min.js.h"
#include "index.html.h"
#include "index.js.h"
#include "pgnid.html.h"
#include "pgnid.js.h"
#include "saved_nok.html.h"
#include "saved_ok.html.h"
#include "style.css.h"
#include "view.html.h"
#include "view.js.h"

/* Version Info --------------------------------------------------------------*/
#define DEVICE_NAME				"CANalog WiFi"
#define SERVER_ADDRESS    "www.canalog.io"
/* Version should be interpreted as: (MAIN).(TOPIC).(FUNCTION).(BUGFIX)
 * 		MAIN marks major milestones of the project such as release
 * 		TOPIC marks the introduction of a new functionality or major changes
 * 		FUNCTION marks introduction of new functionality and aim to advance the current TOPIC
 * 		BUGFIX marks very minor updates such as bug fix, optimization, or text edit
 */
#define FW_VERSION				"V1.0.0.1"
char stm32_fw_version[9];                 /* string that stores fw version from stm32 */
char stm32_hw_version[5];                 /* string that stores hw version from stm32 */

/* ESP to STM32 Comunication -------------------------------------------------*/
Signal_Handle_t can;                      /* data used on webpages and passed between esp and STM32 */
#define STM32_RESET_PIN 5                 /* esp pin used to reset STM32 on startup */
#define STM32_RDY_PIN   4                 /* STM32 will pull this pin low when it is ready to receive SPI data */
ESPMaster spiMaster(SS, STM32_RDY_PIN);   /* ESP master SPI mode */

/* WiFi Settings -------------------------------------------------------------*/
String ssid = "CANalog ";                 /* first part of ssid, will append device sn to end */
IPAddress apIP(192, 168, 1, 1);
IPAddress subnet(255,255,255,0);
const byte DNS_PORT = 53;
DNSServer dnsServer;

#define WIFI_LED_PIN 0                    /* Clinets connected indicator */

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");
bool ws_stream_data = false;              /* when true stream data using websocket */
unsigned long last_ws_sent;

/* funcition prototypes ------------------------------------------------------*/
void handleRoot(AsyncWebServerRequest *request);
void handleSave(AsyncWebServerRequest *request);
void handleView(AsyncWebServerRequest *request);
void handlePGNtoID(AsyncWebServerRequest *request);
void handleAbout(AsyncWebServerRequest *request);
void handleIndexJavascript(AsyncWebServerRequest *request);
void handleViewJavascript(AsyncWebServerRequest *request);
void handlePGNtoIDJavascript(AsyncWebServerRequest *request);
void handleAboutJavascript(AsyncWebServerRequest *request);
void handleChartJavascript(AsyncWebServerRequest *request);
void handleStyle(AsyncWebServerRequest *request);
void handleData(AsyncWebServerRequest *request);
void handleInfo(AsyncWebServerRequest *request);
void handleNotFound(AsyncWebServerRequest *request);
void handleInvalidRequest(AsyncWebServerRequest *request);
void onWsEvent(AsyncWebSocket * server, 
               AsyncWebSocketClient * client, 
               AwsEventType type, 
               void * arg, 
               uint8_t *data, 
               size_t len);

void setup(void){
  /* start serial for debugging ----------------------------------------------*/
  Serial.begin(115200);
  Serial.println("\n\r");

  pinMode(WIFI_LED_PIN, OUTPUT);
  digitalWrite(WIFI_LED_PIN, HIGH);

  /* start SPI master --------------------------------------------------------*/
  spiMaster.begin();

  pinMode(STM32_RESET_PIN, OUTPUT);   /* reset STM32 to avoid error states */
  digitalWrite(STM32_RESET_PIN, LOW);
  delay(1000);
  digitalWrite(STM32_RESET_PIN, HIGH);
  delay(10000);                       /* wait for STM32 to startup */

  /* get data from STM32 so we can use sn to set the SSID --------------------*/
  // spiMaster.read((uint8_t *) &can, sizeof(Signal_Handle_t));
  // printData(&can);                    /* print received data for debugging */

  spiMaster.read(SPI_GET_FW_VERSION, (uint8_t*) stm32_fw_version, sizeof(stm32_fw_version));
  Serial.print("STM32 FW: ");
  Serial.println(String(stm32_fw_version));

  spiMaster.read(SPI_GET_HW_VERSION, (uint8_t*) stm32_hw_version, sizeof(stm32_hw_version));
  Serial.print("STM32 HW: ");
  Serial.println(String(stm32_hw_version));


  /* assemble SSID with SN from STM32 for unique SSID per device -------------*/
  uint32_t sn;
  spiMaster.read(SPI_GET_SN, (uint8_t*) &sn, sizeof(sn));
  ssid += String(sn, HEX);

  /* setup EEPROM ------------------------------------------------------------*/
  EEPROM.begin(sizeof(Signal_Handle_t));

  /* Check if the EEPROM contains valid data from another run */
  if(EEPROM.percentUsed()>=0) {         /* valid data from previous run */
    EEPROM.get(0, can);                 /* get data to update Signal_Handle_t */
    Serial.println("EEPROM has data from a previous run.");
    Serial.print(EEPROM.percentUsed());
    Serial.println("% of ESP flash space currently used");

    spiMaster.write((uint8_t *) &can, sizeof(Signal_Handle_t)); /* send data from EEPROM to STM32 */
  } else {
    Serial.println("EEPROM size changed - EEPROM data zeroed - commit() to make permanent");  
  }

  /* start up WiFi Server ----------------------------------------------------*/
  Serial.print("Setting AP configuration ... ");
  Serial.println(WiFi.softAPConfig(apIP, apIP, subnet) ? "Ready" : "Failed!");

  Serial.print("Setting AP ... ");
  Serial.println(WiFi.softAP(ssid) ? "Ready" : "Failed!");

  Serial.print("AP IP address = ");
  Serial.println(WiFi.softAPIP());

  /* DNS Server --------------------------------------------------------------*/
  /* modify TTL associated  with the domain name (in seconds)
   *  default is 60 seconds */
  dnsServer.setTTL(300);
  /* set which return code will be used for all other domains (e.g. sending
   *  ServerFailure instead of NonExistentDomain will reduce number of queries sent by clients)
   *  default is DNSReplyCode::NonExistentDomain */
  dnsServer.setErrorReplyCode(DNSReplyCode::ServerFailure);

  // start DNS server for a specific domain name
  dnsServer.start(DNS_PORT, SERVER_ADDRESS, apIP);

  /* Websocket ---------------------------------------------------------------*/
  ws.onEvent(onWsEvent);
  server.addHandler(&ws);

  /* server page request handles ---------------------------------------------*/
  server.on("/", HTTP_GET, handleRoot);           /* Call the 'handleRoot' function when a client requests URI "/" */
  server.on("/index.html", HTTP_GET, handleRoot); /* Call the 'handleRoot' function when a client requests URI "/index" */
  server.on("/save", HTTP_POST, handleSave);      /* Call the 'handleSave' function when a POST request is made to URI "/save" */
  server.on("/pgnid.html", HTTP_GET, handlePGNtoID);
  server.on("/view.html", HTTP_GET, handleView);
  server.on("/about.html", HTTP_GET, handleAbout);
  server.on("/index.js", handleIndexJavascript);  /* javascript */
  server.on("/view.js", handleViewJavascript);
  server.on("/pgnid.js", handlePGNtoIDJavascript);
  server.on("/about.js", handleAboutJavascript);
  server.on("/Chart.min.js", handleChartJavascript);
  server.on("/style.css", handleStyle);           /* styles */
  server.on("/data.txt", handleData);
  server.on("/info.txt", handleInfo);
  server.onNotFound(handleNotFound);              /* When a client requests an unknown URI call function "handleNotFound" */

  server.begin();                                 /* Actually start the server */
  Serial.println("HTTP server started");
}

void loop(void){
  dnsServer.processNextRequest();
  ws.cleanupClients();

  // if (ws.count() > 0) {
  //   digitalWrite(WIFI_LED_PIN, LOW);
  // } else {
  //   digitalWrite(WIFI_LED_PIN, HIGH);
  // }

  if (WiFi.softAPgetStationNum() > 0){
    digitalWrite(WIFI_LED_PIN, LOW);
  } else {
    digitalWrite(WIFI_LED_PIN, HIGH);
  }

  if (ws_stream_data == true) {
    if ((millis() - last_ws_sent) >= 1000) {
      last_ws_sent = millis();

      spiMaster.read(SPI_GET_CAN_SIGNAL, (uint8_t *) &can.value, sizeof(can.value));
      delayMicroseconds(50);
      spiMaster.read(SPI_GET_DAC_VALUE, (uint8_t *) &can.dac_out, sizeof(can.dac_out));
      delayMicroseconds(50);
      spiMaster.read(SPI_GET_CAN_FRAME, can.frame, sizeof(can.frame));

      StaticJsonDocument<96> data;
      
      data["value"] = can.value;
      data["dac"] = can.dac_out;
      
      String frame;
      for (uint8_t i=0; i<sizeof(can.frame); i++) {
        frame += (can.frame[i] < 16 ? "0": "") + String(can.frame[i], HEX); // add leading zero
      }

      data["frame"] = frame;

      String json;
      serializeJson(data, json);

      ws.textAll(json.c_str(), json.length());
    }
  }
}

void handleRoot(AsyncWebServerRequest *request) {
  request->send_P(200, "text/html", PAGE_index_HTML);
}

void handleSave(AsyncWebServerRequest *request) {
  can.can_baud    = request->arg("can_baud").toInt();
  can.can_type    = request->arg("can_id_bit_len").toInt();
  can.can_id      = strtoul(request->arg("can_id").c_str(), NULL, 16);
  can.start_bit   = request->arg("can_signal_start_bit").toInt();
  can.bit_len     = request->arg("can_signal_bit_len").toInt();
  can.endianness  = request->arg("can_endianness").toInt();
  can.max         = request->arg("can_signal_max").toInt();
  can.min         = request->arg("can_signal_min").toInt();
  can.term        = request->arg("term").toInt();

  /* save data to EEPROM */
  EEPROM.put(0, can);
  boolean ok = EEPROM.commit();
  Serial.println((ok) ? "Commit OK" : "Commit failed");

  /* send data to STM32 */
  spiMaster.write((uint8_t *) &can, sizeof(Signal_Handle_t));
  printData(&can);

  /* check to make sure data was received */
  Signal_Handle_t can_on_stm32;
  spiMaster.read((uint8_t *) &can_on_stm32, sizeof(Signal_Handle_t));
  printData(&can_on_stm32);

  if (signal_struct_cmp(&can, &can_on_stm32) == SIGNAL_STRUCTS_ARE_EQUAL) {
    request->send_P(200, "text/html", PAGE_saved_ok_HTML); // data transfer is good
  } else {
    request->send_P(200, "text/html", PAGE_saved_nok_HTML); // data transfer is good
  }
}

void handleView(AsyncWebServerRequest *request) { 
  request->send_P(200, "text/html", PAGE_view_HTML);
}

void handlePGNtoID(AsyncWebServerRequest *request) { 
  request->send_P(200, "text/html", PAGE_pgnid_HTML);
}

void handleAbout(AsyncWebServerRequest *request) {
  request->send_P(200, "text/html", PAGE_about_HTML);
}

void handleIndexJavascript(AsyncWebServerRequest *request) {
  request->send_P(200, "application/javascript", PAGE_index_JS);
}

void handleViewJavascript(AsyncWebServerRequest *request) {
  request->send_P(200, "application/javascript", PAGE_view_JS);
}

void handlePGNtoIDJavascript(AsyncWebServerRequest *request) {
  request->send_P(200, "application/javascript", PAGE_pgnid_JS);
}

void handleAboutJavascript(AsyncWebServerRequest *request) {
  request->send_P(200, "application/javascript", PAGE_about_JS);
}

void handleChartJavascript(AsyncWebServerRequest *request) {
  request->send_P(200, "application/javascript", PAGE_chart_JS);
}

void handleStyle(AsyncWebServerRequest *request) {
  request->send_P(200, "text/css", PAGE_style_CSS);
}

void handleData(AsyncWebServerRequest *request) {
  /* read data */
  spiMaster.read((uint8_t *) &can, sizeof(Signal_Handle_t));

  StaticJsonDocument<192> data;

  data["baud"] = can.can_baud;
  data["type"] = can.can_type;
  data["id"] = String(can.can_id, HEX);
  data["start_bit"] = can.start_bit;
  data["bit_len"] = can.bit_len;
  data["endianness"] = can.endianness;
  data["max"] = can.max;
  data["min"] = can.min;
  data["term"] = can.term;
  data["value"] = can.value;
  data["dac_out"] = can.dac_out;

  String json;
  serializeJson(data, json);

  request->send(200, "application/json", json);
}

void handleInfo(AsyncWebServerRequest *request) {
  StaticJsonDocument<192> info;

  info["esp_fw"] = FW_VERSION;
  info["stm_fw"] = stm32_fw_version;
  info["stm_hw"] = stm32_hw_version;

  String json;
  serializeJson(info, json);

  request->send(200, "application/json", json);
}

void handleNotFound(AsyncWebServerRequest *request){
  request->send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}

void handleInvalidRequest(AsyncWebServerRequest *request) {
  request->send(400, "text/plain", "400: Invalid Request");         // The request is invalid, so send HTTP status 400
}

void onWsEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, 
               AwsEventType type, void * arg, uint8_t *data, size_t len) {
  switch (type) {
  case WS_EVT_CONNECT:
    Serial.println("Websocket data stream started");
    client->text("Websocket data stream started");
    ws_stream_data = true;
    break;
  case WS_EVT_DISCONNECT:
    Serial.println("Websocket data stream ended");
    ws_stream_data = false;
    break;
  case WS_EVT_ERROR:

    break;
  case WS_EVT_PONG:

    break;
  case WS_EVT_DATA:

    break;
  

  default:
    break;
  }
}