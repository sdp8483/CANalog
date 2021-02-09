#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <ESP_EEPROM.h>

#define DEVICE_NAME				"CANalog WiFi"
#define SERVER_ADDRESS    "www.canalog.io"
/* Version should be interpreted as: (MAIN).(TOPIC).(FUNCTION).(BUGFIX)
 * 		MAIN marks major milestones of the project such as release
 * 		TOPIC marks the introduction of a new functionality or major changes
 * 		FUNCTION marks introduction of new functionality and aim to advance the current TOPIC
 * 		BUGFIX marks very minor updates such as bug fix, optimization, or text edit
 */
#define FW_VERSION				"V0.0.1.0"

/* Command parsing settings --------------------------------------------------*/
#define CMD_BUFFER_LEN				    16			/* how long the rx command buffer is */

#define SIGNAL_LITTLE_ENDIAN   	  12
#define SIGNAL_BIG_ENDIAN      	  21

#define ID_TYPE_11BIT			        11
#define ID_TYPE_29BIT			        29

/* common characters and strings for command parser */
#define CMD_START_CHAR			      '$'			  /* all commands start with this character */
#define CMD_GET_CHAR				      '?'			  /* used by rx line to get value */
#define CMD_SET_CHAR				      '='			  /* used by rx line to set value */
#define CMD_RESPOND_CHAR		      ':'			  /* use to respond with value */
#define CMD_END_CHAR				      '\n'		  /* all valid commands end with this character */
#define CMD_EOL						        "\r\n"		/* used to terminate command */
#define CMD_IS_GOOD					      "OK\r\n"	/* response when command is accepted */
#define CMD_IS_BAD					      "NOK\r\n"	/* response when command is not accepted */
#define CMD_IS_LONG					      "OVF\r\n"	/* response when command is too long */

/* parameters to set or get with command parser, case is important */
#define CMD_SN						        's'			/* 32bit unique device serial number */
#define CMD_CAN_BAUD				      'B'			/* CAN baud rate */
#define CMD_CAN_ID_TYPE				    'T'			/* CAN ID is 11bit or 29bit */
#define CMD_CAN_ID					      'I'			/* CAN ID in hex */
#define CMD_CAN_SIGNAL_START_BIT  'S'			/* CAN Signal Start Bit */
#define CMD_CAN_SIGNAL_BIT_LEN		'L'			/* CAN Signal Bit Length */
#define CMD_CAN_ENDIANNESS			  'E'			/* CAN Signal endianness */
#define CMD_CAN_SIGNAL_MAX			  'M'			/* CAN signal max value */
#define CMD_CAN_SIGNAL_MIN			  'm'			/* CAN signal min value */

#define CMD_MAX_RETRY             10      /* max retransmissions for cmd responding with NOK */
#define CMD_TIMEOUT               10      /* if no response after ms move on */
#define CMD_OK                    0       /* response if command is accepted */
#define CMD_NOK                   1       /* response on command timeout */

String inputString      = "";
String outputString     = "";
String expectedResponse = "";
bool stringComplete     = false;  // whether the string is complete

/* EEPROM parameters ---------------------------------------------------------*/
struct MyEEPROMStruct {
  uint16_t baud;			  /* CAN baud rate in kbps */
  uint8_t  type;			  /* ID type */
	uint32_t id;			    /* CAN frame ID */
	uint8_t  start_bit;		/* signal start bit */
	uint8_t  bit_len;			/* signal bit length */
  uint8_t  endianness;  /* signal endianness */
	uint16_t max;				  /* signal max value */
	uint16_t min;				  /* signal min value */
} can;

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
void handleNotFound(void);
void handleInvalidRequest(void);
void serialEvent(void);
void get_sn(char cmd_character);
uint8_t send_value(char cmd_char, uint32_t value);
void send_get_parameter(char cmd_character);
void send_set_parameter(char cmd_character);

void setup(void){
  /* setup Strings, reserve memory */
  inputString.reserve(CMD_BUFFER_LEN);
  outputString.reserve(CMD_BUFFER_LEN);
  expectedResponse.reserve(CMD_BUFFER_LEN);

  /* start serial and send EOL to reset STM32 */
  Serial.begin(115200);
  delay(10);
  Serial.println(CMD_EOL);
  Serial.flush();

  /* setup default values */
  can.baud        = 500;
  can.type        = ID_TYPE_29BIT;
  can.id          = 0x18efb300;
  can.start_bit   = 0;
  can.bit_len     = 16;
  can.endianness  = SIGNAL_LITTLE_ENDIAN;
  can.max         = 65535;
  can.min         = 0;

  /* setup EEPROM */
  EEPROM.begin(sizeof(MyEEPROMStruct));

  /* Check if the EEPROM contains valid data from another run
   * If so, overwrite the 'default' values set up in our struct */
  if(EEPROM.percentUsed()>=0) {
    EEPROM.get(0, can);
    Serial.println("EEPROM has data from a previous run.");
    Serial.print(EEPROM.percentUsed());
    Serial.println("% of ESP flash space currently used");
  } else {
    Serial.println("EEPROM size changed - EEPROM data zeroed - commit() to make permanent");  
  }

  /* get SN to use in ssid */
  Serial.print(CMD_EOL);
  Serial.flush();
  get_sn(CMD_SN);

    /* Send out parsable commands for stm32 */
  send_value(CMD_CAN_BAUD, can.baud);
  send_value(CMD_CAN_ID_TYPE, can.type);
  send_value(CMD_CAN_ID, can.id);
  send_value(CMD_CAN_SIGNAL_START_BIT, can.start_bit);
  send_value(CMD_CAN_SIGNAL_BIT_LEN, can.bit_len);
  send_value(CMD_CAN_ENDIANNESS, can.endianness);
  send_value(CMD_CAN_SIGNAL_MAX, can.max);
  send_value(CMD_CAN_SIGNAL_MIN, can.min);

  /* start up WiFi Server */
  Serial.print("Setting AP configuration ... ");
  Serial.println(WiFi.softAPConfig(apIP, apIP, subnet) ? "Ready" : "Failed!");

  Serial.print("Setting AP ... ");
  Serial.println(WiFi.softAP(ssid) ? "Ready" : "Failed!");

  Serial.print("AP IP address = ");
  Serial.println(WiFi.softAPIP());

  /* DNS Server */
  // modify TTL associated  with the domain name (in seconds)
  // default is 60 seconds
  dnsServer.setTTL(300);
  // set which return code will be used for all other domains (e.g. sending
  // ServerFailure instead of NonExistentDomain will reduce number of queries
  // sent by clients)
  // default is DNSReplyCode::NonExistentDomain
  dnsServer.setErrorReplyCode(DNSReplyCode::ServerFailure);

  // start DNS server for a specific domain name
  dnsServer.start(DNS_PORT, SERVER_ADDRESS, apIP);

  server.on("/", HTTP_GET, handleRoot);        // Call the 'handleRoot' function when a client requests URI "/"
  server.on("/save", HTTP_POST, handleSave);   // Call the 'handleSave' function when a POST request is made to URI "/save"
  server.onNotFound(handleNotFound);           // When a client requests an unknown URI (i.e. something other than "/"), call function "handleNotFound"

  server.begin();                            // Actually start the server
  Serial.println("HTTP server started");
}

void loop(void){
  serialEvent();                              /* check for serial data */
  dnsServer.processNextRequest();
  server.handleClient();                      /* Listen for HTTP requests from clients */
}

void handleRoot() {
  String root = "<!DOCTYPE html>";
  root += "<html>";
  root += "<head><title>CANalog</title>";
  root += "<style>";
  root += "h1 {font-size: 500%;}";
  root += "select {font-size: 300%;}";
  root += "input {font-size: 300%;}";
  root += "label {font-size: 300%;}";
  root += "input[type=submit] {height: 150px; width: 800px;}";
  root += "</style>";
  root += "</head>";
  root += "<body>";

  root += "<h1>CANalog Configuration</h1>";

  root += "<form action=\"/save\" method=\"POST\">";
  
  root += "<table>";
  /* CAN Baud Rate */
  root += "<tr>";
  root += "<td style=\"text-align: right;\"><label for=\"can_baud\">CAN Baud Rate: </label></td>";
  root += "<td><select id=\"can_baud\" name=\"can_baud\">";
  for (uint8_t i=0; i<NUMBER_CAN_BAUD_RATES; i++) {
    if (can.baud == possible_can_baud[i]) {
        root += "<option value=\"";
        root += possible_can_baud[i];
        root += "\" selected>";
        root += possible_can_baud[i];
        root += "kbps</option>";
      } else {
        root += "<option value=\"";
        root += possible_can_baud[i];
        root += "\">";
        root += possible_can_baud[i];
        root += "kbps</option>";
      }
  }
  root += "</select></td>";
  root += "</tr>";

  /* CAN ID type */
  root += "<tr>";
  root += "<td style=\"text-align: right;\"><label for=\"can_id_bit_len\">ID Type: </label></td>";
  root += "<td><select id=\"can_id_bit_len\" name=\"can_id_bit_len\">";
  if (can.type == ID_TYPE_11BIT) {
    root += "<option value=\"11\" selected>11bit</option>";
    root += "<option value=\"29\">29bit</option>";
  } else {
    root += "<option value=\"11\">11bit</option>";
    root += "<option value=\"29\" selected>29bit</option>";
  }
  root += "</select></td>";
  root += "</tr>";

  /* CAN ID */
  root += "<tr>";
  root += "<td style=\"text-align: right;\"><label for=\"can_id\">CAN ID: </label></td>";
  root += "<td><input type=\"text\" id=\"can_id\" name=\"can_id\" value=\"";
  root += String(can.id, HEX);
  root += "\"  size=\"9\"></td>";
  root += "</tr>";

  /* signal start bit */
  root += "<tr>";
  root += "<td style=\"text-align: right;\"><label for=\"can_signal_start_bit\">Bit Position: </label></td>";
  root += "<td><input type=\"number\" id=\"can_signal_start_bit\" name=\"can_signal_start_bit\" value=\"";
  root += can.start_bit;
  root += "\" min=\"0\" max=\"64\" size=\"3\"></td>";
  root += "</tr>";

  /* signal bit len */
  root += "<tr>";
  root += "<td style=\"text-align: right;\"><label for=\"can_signal_bit_len\">Number of Bits: </label></td>";
  root += "<td><input type=\"number\" id=\"can_signal_bit_len\" name=\"can_signal_bit_len\" value=\"";
  root += can.bit_len;
  root += "\" min=\"1\" max=\"64\" size=\"3\"></td>";
  root += "</tr>";

  /* signal endianness */
  root += "<tr>";
  root += "<td style=\"text-align: right;\"><label for=\"can_endianness\">Signal Endianness: </label></td>";
  root += "<td><select id=\"can_endianness\" name=\"can_endianness\">";
  if (can.endianness == SIGNAL_LITTLE_ENDIAN) {
    root += "<option value=\"12\" selected>little</option>";
    root += "<option value=\"21\">big</option>";
  } else {
    root += "<option value=\"12\">little</option>";
    root += "<option value=\"21\" selected>big</option>";
  }
  root += "</select></td>";
  root += "</tr>";

  /* signal max */
  root += "<tr>";
  root += "<td style=\"text-align: right;\"><label for=\"can_signal_max\">Signal Max: </label></td>";
  root += "<td><input type=\"text\" id=\"can_signal_max\" name=\"can_signal_max\" value=\"";
  root += can.max;
  root += "\" min=0 max=65535 size=\"6\"></td>";
  root += "</tr>";

  /* signal min */
  root += "<tr>";
  root += "<td style=\"text-align: right;\"><label for=\"can_signal_min\">Signal Min: </label></td>";
  root += "<td><input type=\"text\" id=\"can_signal_min\" name=\"can_signal_min\" value=\"";
  root += can.min;
  root += "\" min=0 max=65535 size=\"6\"></td>";
  root += "</tr>";

  root += "</table>";

  /* save button */
  root += "<input type=\"submit\" value=\"Save\">";

  root += "</form>";
  root += "</body>";
  root += "</html>";

  server.send(200, "text/html", root);
}

void handleSave() {
  can.baud        = server.arg("can_baud").toInt();
  can.type        = server.arg("can_id_bit_len").toInt();
  can.id          = strtoul(server.arg("can_id").c_str(), NULL, 16);
  can.start_bit   = server.arg("can_signal_start_bit").toInt();
  can.bit_len     = server.arg("can_signal_bit_len").toInt();
  can.endianness  = server.arg("can_endianness").toInt();
  can.max         = server.arg("can_signal_max").toInt();
  can.min         = server.arg("can_signal_min").toInt();

  uint8_t error_count = 0;

  /* Send out parsable commands for stm32 */
  error_count += send_value(CMD_CAN_BAUD, can.baud);
  error_count += send_value(CMD_CAN_ID_TYPE, can.type);
  error_count += send_value(CMD_CAN_ID, can.id);
  error_count += send_value(CMD_CAN_SIGNAL_START_BIT, can.start_bit);
  error_count += send_value(CMD_CAN_SIGNAL_BIT_LEN, can.bit_len);
  error_count += send_value(CMD_CAN_ENDIANNESS, can.endianness);
  error_count += send_value(CMD_CAN_SIGNAL_MAX, can.max);
  error_count += send_value(CMD_CAN_SIGNAL_MIN, can.min);

  if(error_count == 0) {
    /* save data to EEPROM */
    EEPROM.put(0, can);
    boolean ok = EEPROM.commit();
    Serial.println((ok) ? "Commit OK" : "Commit failed");

    String saved = "<!DOCTYPE html>";
    saved += "<html>";
    saved += "<head><title>CANalog</title>";
    saved += "<style>";
    saved += "h1 {font-size: 500%;}";
    saved += "h2 {font-size: 300%;}";
    saved += "select {font-size: 300%;}";
    saved += "input {font-size: 300%;}";
    saved += "label {font-size: 300%;}";
    saved += "</style>";
    saved += "</head>";
    saved += "<body>";
    saved += "<h1>CANalog Settings Updated!</h1>";
    saved += "<h2><a href=\"/\"> Return To Previous Page</h2></a>";
    saved += "</body></html>";

    server.send(200, "text/html", saved);
  } else {
    String error = "<!DOCTYPE html>";
    error += "<html>";
    error += "<head><title>CANalog</title>";
    error += "<style>";
    error += "h1 {font-size: 500%;}";
    error += "h2 {font-size: 300%;}";
    error += "select {font-size: 300%;}";
    error += "input {font-size: 300%;}";
    error += "label {font-size: 300%;}";
    error += "</style>";
    error += "</head>";
    error += "<body>";
    error += "<h1>Error Updating Settings!</h1>";
    error += "<h2>";
    error += error_count;
    error += " settings were not updated. </h2>";
    error += "<h2> Renter settings and retry </h2>";
    error += "<h2> Restart if problem persists </h2>";
    error += "<h2><a href=\"/\"> Return To Previous Page</h2></a>";
    error += "</body></html>";

    server.send(200, "text/html", error);
  }
}

void handleNotFound(){
  server.send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}

void handleInvalidRequest(void) {
  server.send(400, "text/plain", "400: Invalid Request");         // The request is invalid, so send HTTP status 400
}

void get_sn(char cmd_character) {
  uint8_t attempts = 0;
  uint32_t start_time = millis();

  uint32_t device_sn;
  bool parameter_was_fetched = false;
  send_get_parameter(cmd_character);
  while(parameter_was_fetched == false) {
    serialEvent();

    if ((millis() - start_time) >= CMD_TIMEOUT) {
      return;
    }

    if(stringComplete) {
      stringComplete = false;

      expectedResponse = "";
      expectedResponse += CMD_START_CHAR;
      expectedResponse += cmd_character;
      expectedResponse += CMD_RESPOND_CHAR;

      if(inputString.startsWith(expectedResponse)) {
        inputString.remove(0, 3);   /* remove $X: */
        device_sn = strtoul(inputString.c_str(), NULL, 10);
        ssid += String(device_sn, HEX);
        parameter_was_fetched = true;
      } else {
        attempts++;
        delay(10);
        send_get_parameter(cmd_character);
      }
      inputString = "";   /* clear the input */
    }

    if(attempts >= CMD_MAX_RETRY) {
      return;
    }
  }
}

uint8_t send_value(char cmd_char, uint32_t value) {
  uint8_t attemps = 0;
  uint32_t cmd_start_time = millis();

  send_set_parameter(cmd_char);
  Serial.print(value);
  Serial.print(CMD_EOL);
  Serial.flush();

  bool cmd_accepted = false;

  while(cmd_accepted == false) {
    serialEvent();
    
    if((millis() - cmd_start_time) >= CMD_TIMEOUT) {  /* timput error, return */
      return CMD_NOK;
    }

    if(stringComplete) {
      stringComplete = false;
      // Serial.print(inputString);
      if(inputString.equals(CMD_IS_GOOD)) {
        cmd_accepted = true;
      } else {
        attemps++;
        send_set_parameter(cmd_char);
        Serial.print(value);
        Serial.print(CMD_EOL);
        Serial.flush();
      }

      inputString = "";
    }

    if(attemps >= CMD_MAX_RETRY) {    /* max tx attempts, return with error */
      return CMD_NOK;
    }
  }

  return CMD_OK;
}

void send_get_parameter(char cmd_character) {
  outputString = "";
  outputString += CMD_START_CHAR;
  outputString += cmd_character;
  outputString += CMD_GET_CHAR;
  outputString += CMD_EOL;

  Serial.print(outputString);
  Serial.flush();
  outputString = "";
}

void send_set_parameter(char cmd_character) {
  delay(1);
  outputString = "";
  outputString += CMD_START_CHAR;
  outputString += cmd_character;
  outputString += CMD_SET_CHAR;

  Serial.print(outputString);
  outputString = "";
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}