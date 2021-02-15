#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <ESP_EEPROM.h>
#include <ArduinoJson.h>

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
#define FW_VERSION				"V0.0.2.0"

/* EEPROM parameters ---------------------------------------------------------*/
// struct MyEEPROMStruct {
//   uint16_t baud;			  /* CAN baud rate in kbps */
//   uint8_t  type;			  /* ID type */
// 	uint32_t id;			    /* CAN frame ID */
// 	uint8_t  start_bit;		/* signal start bit */
// 	uint8_t  bit_len;			/* signal bit length */
//   uint8_t  endianness;  /* signal endianness */
// 	uint16_t max;				  /* signal max value */
// 	uint16_t min;				  /* signal min value */
// } can;

Signal_Handle_t can;      /* data used on webpages and passed between esp and STM32 */
ESPMaster spiMaster(SS);        /* ESP master SPI mode */

uint16_t possible_can_baud[]    = {10, 20, 50, 83, 100, 125, 250, 500, 800, 1000};
#define NUMBER_CAN_BAUD_RATES   (sizeof(possible_can_baud)/sizeof(uint16_t))

/* WiFi Settings -------------------------------------------------------------*/
String ssid = "CANalog ";           /* first part of ssid, will append device sn to end */
IPAddress apIP(192, 168, 1, 1);
IPAddress subnet(255,255,255,0);
const byte DNS_PORT = 53;
DNSServer dnsServer;

ESP8266WebServer server(80);

/* funcition prototypes ------------------------------------------------------*/
void handleRoot(void);
void handleSave(void);
void handleJavascript(void);
void handleStyle(void);
void handleData(void);
void handleNotFound(void);
void handleInvalidRequest(void);

void setup(void){
  /* start serial for debugging ----------------------------------------------*/
  Serial.begin(115200);

  /* start SPI master --------------------------------------------------------*/
  spiMaster.begin();
  delay(10000);         /* wait for STM32 to startup */

  /* get data from STM32 so we can use sn to set the SSID --------------------*/
  spiMaster.read((uint8_t *) &can, sizeof(Signal_Handle_t));
  printData(&can);      /* print received data for debugging */

  /* assemble SSID with SN from STM32 for unique SSID per device -------------*/
  ssid += String(can.sn, HEX);

  /* setup EEPROM ------------------------------------------------------------*/
  EEPROM.begin(sizeof(Signal_Handle_t));

  /* Check if the EEPROM contains valid data from another run */
  if(EEPROM.percentUsed()>=0) {/* valid data from previous run */
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
  server.on("/", HTTP_GET, handleRoot);        /* Call the 'handleRoot' function when a client requests URI "/" */
  server.on("/save", HTTP_POST, handleSave);   /* Call the 'handleSave' function when a POST request is made to URI "/save" */
  server.on("/libs.js", handleJavascript);
  server.on("/style.css", handleStyle);
  server.on("/data.txt", handleData);
  server.onNotFound(handleNotFound);           /* When a client requests an unknown URI (i.e. something other than "/"), call function "handleNotFound" */

  server.begin();                              /* Actually start the server */
  Serial.println("HTTP server started");
}

void loop(void){
  dnsServer.processNextRequest();
  server.handleClient();                      /* Listen for HTTP requests from clients */
}

void handleRoot() {
  server.send(200, "text/html", PAGE_Root_HTML);
}

void handleSave() {
  can.can_baud    = server.arg("can_baud").toInt();
  can.can_type    = server.arg("can_id_bit_len").toInt();
  can.can_id      = strtoul(server.arg("can_id").c_str(), NULL, 16);
  can.start_bit   = server.arg("can_signal_start_bit").toInt();
  can.bit_len     = server.arg("can_signal_bit_len").toInt();
  can.endianness  = server.arg("can_endianness").toInt();
  can.max         = server.arg("can_signal_max").toInt();
  can.min         = server.arg("can_signal_min").toInt();

  /* TODO: handle parameter verification using javascript client side */
  /* parameter verification */
  // if((can.can_id > 0x7FF) && (can.can_type == ID_TYPE_11BIT)){
  //   String over = "<!DOCTYPE html>";
  //   over += "<html>";
  //   over += "<head><title>CANalog</title>";
  //   over += "<style>";
  //   over += "h1 {font-size: 500%;}";
  //   over += "h2 {font-size: 300%;}";
  //   over += "</style>";
  //   over += "</head>";
  //   over += "<body>";
  //   over += "<h1>CAN ID Type Error!</h1>";
  //   over += "<h2> CAN ID: ";
  //   String cid = String(can.can_id, HEX);
  //   cid.toUpperCase();
  //   over += cid;
  //   over += "</h2>";
  //   over += "<h2>ID Type: 11bit</h2>";
  //   over += "<h2>11bit ID Type has a max of 0x7FF</h2>";
  //   over += "<h2>Lower CAN ID or change to 29bit ID Type</h2>";
  //   over += "<h2><a href=\"/\"> Return To Previous Page</h2></a>";
  //   over += "</body></html>";

  //   server.send(200, "text/html", over);

  //   return;
  // }

  // if (can.min >= can.max) {
  //   String minmax = "<!DOCTYPE html>";
  //   minmax += "<html>";
  //   minmax += "<head><title>CANalog</title>";
  //   minmax += "<style>";
  //   minmax += "h1 {font-size: 500%;}";
  //   minmax += "h2 {font-size: 300%;}";
  //   minmax += "</style>";
  //   minmax += "</head>";
  //   minmax += "<body>";
  //   minmax += "<h1>Signal Min >= Signal Max!</h1>";
  //   minmax += "<h2>";
  //   minmax += can.min;
  //   minmax += " >= ";
  //   minmax += can.max;
  //   minmax += "</h2>";
  //   minmax += "<h2>signal min must be less than signal max</h2>";
  //   minmax += "<h2><a href=\"/\"> Return To Previous Page</h2></a>";
  //   minmax += "</body></html>";

  //   server.send(200, "text/html", minmax);

  //   return;
  // }

  // if(can.endianness == SIGNAL_LITTLE_ENDIAN) {
  //   int8_t end_bit = (int8_t)can.start_bit + (int8_t)can.bit_len;
  //   if(end_bit >= 64) {
  //   String sigover = "<!DOCTYPE html>";
  //   sigover += "<html>";
  //   sigover += "<head><title>CANalog</title>";
  //   sigover += "<style>";
  //   sigover += "h1 {font-size: 500%;}";
  //   sigover += "h2 {font-size: 300%;}";
  //   sigover += "</style>";
  //   sigover += "</head>";
  //   sigover += "<body>";
  //   sigover += "<h1>Signal Exceeds Frame!</h1>";
  //   sigover += "<h2><a href=\"/\"> Return To Previous Page</h2></a>";
  //   sigover += "</body></html>";

  //   server.send(200, "text/html", sigover);
  //   }
  // } else {
  //   /* TODO: start, end bit checks for big endian */
  // }

  /* save data to EEPROM */
  EEPROM.put(0, can);
  boolean ok = EEPROM.commit();
  Serial.println((ok) ? "Commit OK" : "Commit failed");

  /* send data to STM32 */
  spiMaster.write((uint8_t *) &can, sizeof(Signal_Handle_t));

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

  server.send(200, "text/html", saved);
}

void handleJavascript(void) {
  server.send(200, "application/javascript", PAGE_libs_js);
}

void handleStyle(void) {
  server.send(200, "text/css", PAGE_style_css);
}

void handleData(void) {
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

  server.send(200, "application/json", json);
}

void handleNotFound(){
  server.send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}

void handleInvalidRequest(void) {
  server.send(400, "text/plain", "400: Invalid Request");         // The request is invalid, so send HTTP status 400
}