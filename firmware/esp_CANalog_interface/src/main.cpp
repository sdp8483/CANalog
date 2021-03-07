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
#include "root.html.h"
#include "style.css.h"
#include "libs.js.h"

#define DEVICE_NAME				"CANalog WiFi"
#define SERVER_ADDRESS    "www.canalog.io"
/* Version should be interpreted as: (MAIN).(TOPIC).(FUNCTION).(BUGFIX)
 * 		MAIN marks major milestones of the project such as release
 * 		TOPIC marks the introduction of a new functionality or major changes
 * 		FUNCTION marks introduction of new functionality and aim to advance the current TOPIC
 * 		BUGFIX marks very minor updates such as bug fix, optimization, or text edit
 */
#define FW_VERSION				"V0.0.3.0"

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

AsyncWebServer server(80);

/* funcition prototypes ------------------------------------------------------*/
void handleRoot(AsyncWebServerRequest *request);
void handleSave(AsyncWebServerRequest *request);
void handleJavascript(AsyncWebServerRequest *request);
void handleStyle(AsyncWebServerRequest *request);
void handleData(AsyncWebServerRequest *request);
void handleNotFound(AsyncWebServerRequest *request);
void handleInvalidRequest(AsyncWebServerRequest *request);

void setup(void){
  /* start serial for debugging ----------------------------------------------*/
  Serial.begin(115200);

  /* start SPI master --------------------------------------------------------*/
  spiMaster.begin();

  pinMode(STM32_RESET_PIN, OUTPUT);   /* reset STM32 to avoid error states */
  digitalWrite(STM32_RESET_PIN, LOW);
  delay(1000);
  digitalWrite(STM32_RESET_PIN, HIGH);
  delay(10000);                       /* wait for STM32 to startup */

  /* get data from STM32 so we can use sn to set the SSID --------------------*/
  spiMaster.read((uint8_t *) &can, sizeof(Signal_Handle_t));
  printData(&can);                    /* print received data for debugging */

  /* assemble SSID with SN from STM32 for unique SSID per device -------------*/
  ssid += String(can.sn, HEX);

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

  /* server page request handles ---------------------------------------------*/
  server.on("/", HTTP_GET, handleRoot);         /* Call the 'handleRoot' function when a client requests URI "/" */
  server.on("/save", HTTP_POST, handleSave);    /* Call the 'handleSave' function when a POST request is made to URI "/save" */
  server.on("/libs.js", handleJavascript);      /* javascript */
  server.on("/style.css", handleStyle);         /* styles */
  server.on("/data.txt", handleData);
  server.onNotFound(handleNotFound);            /* When a client requests an unknown URI call function "handleNotFound" */

  server.begin();                               /* Actually start the server */
  Serial.println("HTTP server started");
}

void loop(void){
  dnsServer.processNextRequest();
}

void handleRoot(AsyncWebServerRequest *request) {
  request->send_P(200, "text/html", PAGE_Root_HTML);
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

  /* save data to EEPROM */
  EEPROM.put(0, can);
  boolean ok = EEPROM.commit();
  Serial.println((ok) ? "Commit OK" : "Commit failed");

  /* send data to STM32 */
  spiMaster.write((uint8_t *) &can, sizeof(Signal_Handle_t));
  printData(&can);

  String saved = "<!DOCTYPE html>";
  saved += "<html>";
  saved += "<head><title>CANalog</title>";
  saved += "<style>";
  saved += "h1 {font-size: 500%;}";
  saved += "h2 {font-size: 300%;}";
  saved += "</style>";
  saved += "</head>";
  saved += "<body>";
  saved += "<h1>CANalog Settings Updated!</h1>";
  saved += "<h2><a href=\"/\"> Return To Previous Page</h2></a>";
  saved += "</body></html>";

  request->send(200, "text/html", saved);
}

void handleJavascript(AsyncWebServerRequest *request) {
  request->send_P(200, "application/javascript", PAGE_libs_js);
}

void handleStyle(AsyncWebServerRequest *request) {
  request->send_P(200, "text/css", PAGE_style_css);
}

void handleData(AsyncWebServerRequest *request) {
  StaticJsonDocument<192> data;

  data["baud"] = can.can_baud;
  data["type"] = can.can_type;
  data["id"] = String(can.can_id, HEX);
  data["start_bit"] = can.start_bit;
  data["bit_len"] = can.bit_len;
  data["endianness"] = can.endianness;
  data["max"] = can.max;
  data["min"] = can.min;

  String json;
  serializeJson(data, json);

  request->send(200, "application/json", json);
}

void handleNotFound(AsyncWebServerRequest *request){
  request->send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}

void handleInvalidRequest(AsyncWebServerRequest *request) {
  request->send(400, "text/plain", "400: Invalid Request");         // The request is invalid, so send HTTP status 400
}