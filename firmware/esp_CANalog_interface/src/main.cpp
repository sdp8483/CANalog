#include <Arduino.h>
#include <DNSServer.h>
#include <ESP_EEPROM.h>
#include <TaskScheduler.h>

/* ESP8266 WiFi Includes ----------------------------------------------------- */
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>
#include <ArduinoJson.h>

/* Local Libraries ----------------------------------------------------------- */
#include "spi_master.h"
#include "can_signal.h"

/* Raw String Literals for Webpages ------------------------------------------ */
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

/* Version Info -------------------------------------------------------------- */
#define DEVICE_NAME				  "CANalog"
#define SERVER_ADDRESS      "www.canalog.io"
/* Version should be interpreted as: (MAIN).(TOPIC).(FUNCTION).(BUGFIX)
 * 		MAIN marks major milestones of the project such as release
 * 		TOPIC marks the introduction of a new functionality or major changes
 * 		FUNCTION marks introduction of new functionality and aim to advance the current TOPIC
 * 		BUGFIX marks very minor updates such as bug fix, optimization, or text edit
 */
#define FW_VERSION				  "V1.0.2.1"
char stm32_fw_version[9];                 /* string that stores fw version from stm32 */
char stm32_hw_version[5];                 /* string that stores hw version from stm32 */

/* Private define ------------------------------------------------------------ */
#define DEBUG_MESSAGES      1             /* set to 1 to enable serial print messages */

#define WIFI_LED_PIN        0             /* clients connected indicator */
#define STM32_RESET_PIN     5             /* esp pin used to reset STM32 on startup */
#define STM32_RDY_PIN       4             /* STM32 will pull this pin low when it is ready to receive SPI data */

/* WiFi Settings ------------------------------------------------------------- */
#define SSID_LEN            32            /* sources suggest SSID length has a max of 32 characters */
String ssid = DEVICE_NAME + String(" ");  /* first part of ssid, will append device sn to end */
IPAddress apIP(192, 168, 4, 1);
IPAddress subnet(255,255,255,0);

const byte DNS_PORT = 53;
DNSServer dnsServer;

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");
StaticJsonDocument<1028> wsData;

#define WS_TRANSMIT_RATE_ms 1000

/* Private macro ------------------------------------------------------------- */
#if DEBUG_MESSAGES
#define debugLog(x) 	Serial.print(x)
#define debugLogln(x)	Serial.println(x)
#else
#define debugLog(x)
#define debugLogln(x)
#endif

/* Private variables --------------------------------------------------------- */
Signal_Handle_t can;                      /* data used on webpages and passed between esp and STM32 */
ESPMaster spiMaster(SS, STM32_RDY_PIN);   /* ESP master SPI mode */

/* Private function prototypes ----------------------------------------------- */

/* Webserver Handles --------------------------------------------------------- */
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
void wsReceiveParse(uint8_t *data, size_t len);
void wsStream();

/* Task Scheduler ------------------------------------------------------------ */
Scheduler runner;
Task wsTask(WS_TRANSMIT_RATE_ms, TASK_FOREVER, &wsStream);

/* Setup --------------------------------------------------------------------- */
void setup(void){
  /* start serial for debugging ---------------------------------------------- */
  Serial.begin(115200);
  Serial.println("\n\r");

  pinMode(WIFI_LED_PIN, OUTPUT);
  digitalWrite(WIFI_LED_PIN, HIGH);

  /* setup task scheduler ---------------------------------------------------- */
	runner.init();

  /* start SPI master -------------------------------------------------------- */
  spiMaster.begin();

  pinMode(STM32_RESET_PIN, OUTPUT);   /* reset STM32 to avoid error states */
  digitalWrite(STM32_RESET_PIN, LOW);
  delay(1000);
  digitalWrite(STM32_RESET_PIN, HIGH);
  delay(10000);                       /* wait for STM32 to startup */

  /* get data from STM32 so we can use sn to set the SSID -------------------- */
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
  /* modify TTL associated  with the domain name (in seconds), default is 60 seconds */
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

  AsyncElegantOTA.begin(&server);                 /* Start OTA update server */
  server.begin();                                 /* Actually start the server */
  Serial.println("HTTP server started");
}

/* Main Loop ----------------------------------------------------------------- */
void loop(void){
  dnsServer.processNextRequest();
  ws.cleanupClients();
  runner.execute();

  if (WiFi.softAPgetStationNum() > 0){
    digitalWrite(WIFI_LED_PIN, LOW);
  } else {
    digitalWrite(WIFI_LED_PIN, HIGH);
  }
}

/* Web Server Handle Functions ----------------------------------------------- */
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
  request->send(404, "text/plain", "404: Not found");               // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}

void handleInvalidRequest(AsyncWebServerRequest *request) {
  request->send(400, "text/plain", "400: Invalid Request");         // The request is invalid, so send HTTP status 400
}

void onWsEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, 
               AwsEventType type, void *arg, uint8_t *data, size_t len) {
	
	AwsFrameInfo * info = (AwsFrameInfo*)arg;
    switch(type) {
      case WS_EVT_CONNECT:
        /* client connected */
        Serial.printf("ws[%s][%u] connect\n", server->url(), client->id());
        client->printf("Hello Client %u :)", client->id());
        client->ping();
        runner.addTask(wsTask);
        wsTask.enable();
        break;
      case WS_EVT_DISCONNECT:
        /* client disconnected */
        Serial.printf("ws[%s][%u] disconnect\n", server->url(), client->id());
        wsTask.disable();
        runner.deleteTask(wsTask);
        break;
      case WS_EVT_ERROR:
        /* error was received from the other end */
        Serial.printf("ws[%s][%u] error(%u): %s\n", server->url(), client->id(), *((uint16_t*)arg), (char*)data);
        break;
      case WS_EVT_PONG:
        /* pong message was received (in response to a ping request maybe) */
        Serial.printf("ws[%s][%u] pong[%u]: %s\n", server->url(), client->id(), len, (len)?(char*)data:"");
        break;
      case WS_EVT_DATA:
        /* data packet */
        if(info->final && info->index == 0 && info->len == len) {
          //the whole message is in a single frame and we got all of it's data
          Serial.printf("ws[%s][%u] %s-message[%llu]: ", 
                server->url(), client->id(), (info->opcode == WS_TEXT)?"text":"binary", info->len);
          if(info->opcode == WS_TEXT) {
            data[len] = 0;
            Serial.printf("%s\n", (char*)data);
            wsReceiveParse(data, info->len);
          } else {
            for(size_t i=0; i < info->len; i++){
              Serial.printf("%02x ", data[i]);
            }
            Serial.printf("\n");
          }
          if(info->opcode == WS_TEXT)
            client->text("I got your text message");
          else
            client->binary("I got your binary message");
        } else {
          //message is comprised of multiple frames or the frame is split into multiple packets
          if(info->index == 0){
            if(info->num == 0)
            Serial.printf("ws[%s][%u] %s-message start\n", server->url(), client->id(), (info->message_opcode == WS_TEXT)?"text":"binary");
            Serial.printf("ws[%s][%u] frame[%u] start[%llu]\n", server->url(), client->id(), info->num, info->len);
          }

          Serial.printf("ws[%s][%u] frame[%u] %s[%llu - %llu]: ", 
                server->url(), client->id(), info->num, 
                (info->message_opcode == WS_TEXT)?"text":"binary", info->index, info->index + len);
          if(info->message_opcode == WS_TEXT){
            data[len] = 0;
            Serial.printf("%s\n", (char*)data);
          } else {
            for(size_t i=0; i < len; i++){
              Serial.printf("%02x ", data[i]);
            }
            Serial.printf("\n");
          }

          if((info->index + len) == info->len){
            Serial.printf("ws[%s][%u] frame[%u] end[%llu]\n", server->url(), client->id(), info->num, info->len);
            if(info->final) {
              Serial.printf("ws[%s][%u] %s-message end\n", 
                    server->url(), client->id(), (info->message_opcode == WS_TEXT)?"text":"binary");
              if(info->message_opcode == WS_TEXT)
                client->text("I got your text message");
              else
                client->binary("I got your binary message");
            }
          }
        }
        break;
      default:
        break;
	}
}

void wsReceiveParse(uint8_t *data, size_t len) {
	/* get data from JSON */
	DeserializationError error = deserializeJson(wsData, data, len);

	if (error) {
		debugLog("deserializeJason() failed: ");
		debugLogln(error.f_str());
	}

	switch (wsData["action"].as<uint8_t>()) {
    case 0:
      break;
    default:
      break;
	}
}

void wsStream() {
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