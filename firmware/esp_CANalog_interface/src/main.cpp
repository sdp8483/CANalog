#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "state_machine.h"

#define DEVICE_NAME				"CANalog WiFi"
/* Version should be interpreted as: (MAIN).(TOPIC).(FUNCTION).(BUGFIX)
 * 		MAIN marks major milestones of the project such as release
 * 		TOPIC marks the introduction of a new functionality or major changes
 * 		FUNCTION marks introduction of new functionality and aim to advance the current TOPIC
 * 		BUGFIX marks very minor updates such as bug fix, optimization, or text edit
 */
#define FW_VERSION				"V0.0.1.0"

/* Command parsing settings --------------------------------------------------*/
#define CMD_BUFFER_LEN				16			/* how long the rx command buffer is */

/* common characters and strings for command parser */
#define CMD_START_CHAR				'$'			/* all commands start with this character */
#define CMD_GET_CHAR				'?'			/* used by rx line to get value */
#define CMD_SET_CHAR				'='			/* used by rx line to set value */
#define CMD_RESPOND_CHAR			':'			/* use to respond with value */
#define CMD_END_CHAR				'\n'		/* all valid commands end with this character */
#define CMD_EOL						"\r\n"		/* used to terminate command */
#define CMD_IS_GOOD					"OK\r\n"	/* response when command is accepted */
#define CMD_IS_BAD					"NOK\r\n"	/* response when command is not accepted */
#define CMD_IS_LONG					"OVF\r\n"	/* response when command is too long */

/* parameters to set or get with command parser, case is important */
#define CMD_SN						's'			/* 32bit unique device serial number */
#define CMD_CAN_BAUD				'B'			/* CAN baud rate */
#define CMD_CAN_ID					'I'			/* CAN ID in hex */
#define CMD_CAN_SIGNAL_START_BIT 	'S'			/* CAN Signal Start Bit */
#define CMD_CAN_SIGNAL_BIT_LEN		'L'			/* CAN Signal Bit Length */

String inputString = "";
String outputString = "";
String expectedResponse = "";
bool stringComplete = false;  // whether the string is complete

uint32_t device_sn;
uint16_t can_baud;
uint32_t can_id;
uint8_t can_is_extended;
uint8_t can_signal_start_bit;
uint8_t can_signal_bit_len;

/* WiFi Settings -------------------------------------------------------------*/
String ssid = "CANalog ";   /* first part of ssid, will append device sn to end */
IPAddress local_IP(192,168,4,1);
IPAddress gateway(192,168,4,9);
IPAddress subnet(255,255,255,0);

#define NUMBER_CAN_BAUD_RATES  9
uint16_t possible_can_baud[NUMBER_CAN_BAUD_RATES] = {10, 20, 50, 100, 125, 250, 500, 750, 1000};

StateMachine fsm;   /* first state is STARTUP */

ESP8266WebServer server(80);

void handleRoot(void);              // function prototypes for HTTP handlers
void handleSave(void);
void handleNotFound(void);
void handleInvalidRequest(void);
void serialEvent(void);
void send_get_parameter(char cmd_character);
void send_set_parameter(char cmd_character);

void setup(void){
  inputString.reserve(CMD_BUFFER_LEN);
  outputString.reserve(CMD_BUFFER_LEN);
  expectedResponse.reserve(CMD_BUFFER_LEN);

  Serial.begin(115200);
  delay(10);
  Serial.println(CMD_EOL);
  delay(10);
}

void loop(void){
  serialEvent();  /* check for serial data */

  switch (fsm.state) {
  case STARTUP:
    if (fsm.first_run());
    fsm.changeState(GET_SN_STARTUP);
    break;
  case GET_SN_STARTUP:
    if (fsm.first_run()) {
      send_get_parameter(CMD_SN);
    }

    if(stringComplete) {
      stringComplete = false;

      expectedResponse = "";
      expectedResponse += CMD_START_CHAR;
      expectedResponse += CMD_SN;
      expectedResponse += CMD_RESPOND_CHAR;

      if(inputString.startsWith(expectedResponse)) {
        inputString.remove(0, 3);   /* remove $s: */
        device_sn = strtoul(inputString.c_str(), NULL, 10);
        ssid += String(device_sn, HEX);
        ssid.c_str();

        fsm.changeState(GET_BAUD_STARTUP);
      } else {
        delay(10);
        send_get_parameter(CMD_SN);
      }
      inputString = "";   /* clear the input */
    }
    break;
  case GET_BAUD_STARTUP:
    if (fsm.first_run()) {
      send_get_parameter(CMD_CAN_BAUD);
    }

    if(stringComplete) {
      stringComplete = false;

      expectedResponse = "";
      expectedResponse += CMD_START_CHAR;
      expectedResponse += CMD_CAN_BAUD;
      expectedResponse += CMD_RESPOND_CHAR;

      if(inputString.startsWith(expectedResponse)) {
        inputString.remove(0, 3);   /* remove $B: */
        can_baud = inputString.toInt();
        fsm.changeState(GET_ID_STARTUP);
      } else {
        delay(10);
        send_get_parameter(CMD_CAN_BAUD);
      }
      inputString = "";   /* clear the input */
    }
  case GET_ID_STARTUP:
    if (fsm.first_run()) {
      send_get_parameter(CMD_CAN_ID);
    }

    if(stringComplete) {
      stringComplete = false;

      expectedResponse = "";
      expectedResponse += CMD_START_CHAR;
      expectedResponse += CMD_CAN_ID;
      expectedResponse += CMD_RESPOND_CHAR;

      if(inputString.startsWith(expectedResponse)) {
        inputString.remove(0, 3);   /* remove $I: */
        can_id = strtoul(inputString.c_str(), NULL, 10);

        fsm.changeState(GET_START_STARTUP);
      } else {
        delay(10);
        send_get_parameter(CMD_CAN_ID);
      }
      inputString = "";   /* clear the input */
    }
    break;
  case GET_START_STARTUP:
    if (fsm.first_run()) {
      send_get_parameter(CMD_CAN_SIGNAL_START_BIT);
    }

    if(stringComplete) {
      stringComplete = false;

      expectedResponse = "";
      expectedResponse += CMD_START_CHAR;
      expectedResponse += CMD_CAN_SIGNAL_START_BIT;
      expectedResponse += CMD_RESPOND_CHAR;

      if(inputString.startsWith(expectedResponse)) {
        inputString.remove(0, 3);   /* remove $I: */
        can_signal_start_bit = inputString.toInt();

        fsm.changeState(GET_LEN_STARTUP);
      } else {
        delay(10);
        send_get_parameter(CMD_CAN_SIGNAL_START_BIT);
      }
      inputString = "";   /* clear the input */
    }
    break;
  case GET_LEN_STARTUP:
    if (fsm.first_run()) {
      send_get_parameter(CMD_CAN_SIGNAL_BIT_LEN);
    }

    if(stringComplete) {
      stringComplete = false;

      expectedResponse = "";
      expectedResponse += CMD_START_CHAR;
      expectedResponse += CMD_CAN_SIGNAL_BIT_LEN;
      expectedResponse += CMD_RESPOND_CHAR;

      if(inputString.startsWith(expectedResponse)) {
        inputString.remove(0, 3);   /* remove $I: */
        can_signal_bit_len = inputString.toInt();

        fsm.changeState(SETUP_WIFI);
      } else {
        delay(10);
        send_get_parameter(CMD_CAN_SIGNAL_BIT_LEN);
      }
      inputString = "";   /* clear the input */
    }
    break;
  case SETUP_WIFI:
    if (fsm.first_run()) {
      Serial.print("Setting AP configuration ... ");
      Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");

      Serial.print("Setting AP ... ");
      Serial.println(WiFi.softAP(ssid) ? "Ready" : "Failed!");

      Serial.print("AP IP address = ");
      Serial.println(WiFi.softAPIP());

      server.on("/", HTTP_GET, handleRoot);        // Call the 'handleRoot' function when a client requests URI "/"
      server.on("/save", HTTP_POST, handleSave);   // Call the 'handleSave' function when a POST request is made to URI "/save"
      server.onNotFound(handleNotFound);           // When a client requests an unknown URI (i.e. something other than "/"), call function "handleNotFound"

      server.begin();                            // Actually start the server
      Serial.println("HTTP server started");
    }

    fsm.changeState(MAIN_LOOP);
  break;
  case MAIN_LOOP:
    server.handleClient();                     // Listen for HTTP requests from clients
  break;
  
  default:
    break;
  }
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
  outputString = "";
  outputString += CMD_START_CHAR;
  outputString += cmd_character;
  outputString += CMD_SET_CHAR;
  outputString += CMD_EOL;

  Serial.print(outputString);
  Serial.flush();
  outputString = "";
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
  root += "</style>";
  root += "</head>";
  root += "<body>";
  root += "<h1>CANalog Configuration</h1>";

  root += "<form action=\"/save\" method=\"POST\">";
  
  root += "<label for=\"can_baud\">CAN Baud Rate: </label>";
  root += "<select id=\"can_baud\" name=\"can_baud\">";

  for (uint8_t i=0; i<NUMBER_CAN_BAUD_RATES; i++) {
    if (can_baud == possible_can_baud[i]) {
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
  root += "</select><br>";

  root += "<label for=\"can_id\">CAN ID: </label>";
  root += "<input type=\"text\" id=\"can_id\" name=\"can_id\" value=\"";

  // String S_can_id = String(can_id, HEX);

  root += String(can_id, HEX);
  root += "\"  size=\"9\"><br>";

  root += "<label for=\"can_is_extended\">29bit ID: </label>";
  root += "<select id=\"can_is_extended\" name=\"can_is_extended\">";
  if (can_is_extended == 1) {
    root += "<option value=\"true\" selected>true</option>";
    root += "<option value=\"false\">false</option>";
  } else {
    root += "<option value=\"true\">true</option>";
    root += "<option value=\"false\" selected>false</option>";
  }
  root += "</select><br>";

  root += "<label for=\"can_signal_start_bit\">Bit Position: </label>";
  root += "<input type=\"number\" id=\"can_signal_start_bit\" name=\"can_signal_start_bit\" value=\"";
  root += can_signal_start_bit;
  root += "\" min=\"0\" max=\"32\" size=\"3\"><br>";

  root += "<label for=\"can_signal_bit_len\">Number of Bits: </label>";
  root += "<input type=\"number\" id=\"can_signal_bit_len\" name=\"can_signal_bit_len\" value=\"";
  root += can_signal_bit_len;
  root += "\" min=\"1\" max=\"32\" size=\"3\"><br><br>";

  root += "<input type=\"submit\" value=\"Save\">";

  root += "</form>";
  root += "</body>";
  root += "</html>";

  server.send(200, "text/html", root);
}

void handleSave() {
  can_baud = server.arg("can_baud").toInt();
  can_id = strtoul(server.arg("can_id").c_str(), NULL, 16);
  can_is_extended = server.arg("can_is_extended").toInt();
  can_signal_start_bit = server.arg("can_signal_start_bit").toInt();
  can_signal_bit_len = server.arg("can_signal_bit_len").toInt();

  /* Send out parsable commands for stm32 */
  send_set_parameter(CMD_CAN_BAUD);
  Serial.print(can_baud);
  Serial.print(CMD_EOL);

  bool cmd_accepted = false;

  while(cmd_accepted == false) {
    serialEvent();

    if(stringComplete) {
      stringComplete = false;
      // Serial.print(inputString);
      if(inputString.equals(CMD_IS_GOOD)) {
        cmd_accepted = true;
      } else {
        send_set_parameter(CMD_CAN_BAUD);
        Serial.print(can_baud);
        Serial.print(CMD_EOL);
      }

      inputString = "";
    }
  }

  send_set_parameter(CMD_CAN_ID);
  Serial.print(can_id);
  Serial.print(CMD_EOL);

  send_set_parameter(CMD_CAN_SIGNAL_START_BIT);
  Serial.print(can_signal_start_bit);
  Serial.print(CMD_EOL);

  send_set_parameter(CMD_CAN_SIGNAL_BIT_LEN);
  Serial.print(can_signal_bit_len);
  Serial.print(CMD_EOL);

  /*
  if( ! server.hasArg("username") || ! server.hasArg("password")  
      || server.arg("username") == NULL || server.arg("password") == NULL) { // If the POST request doesn't have username and password data
    server.send(400, "text/plain", "400: Invalid Request");         // The request is invalid, so send HTTP status 400
    return;
  }
  if(server.arg("username") == "John Doe" && server.arg("password") == "password123") { // If both the username and the password are correct
    server.send(200, "text/html", "<h1>Welcome, " + server.arg("username") + "!</h1><p>Login successful</p>");
  } else {                                                                              // Username and password don't match
    server.send(401, "text/plain", "401: Unauthorized");
  }
  */

  // return to root  
  server.sendHeader("Location", "/");       // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                         // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleNotFound(){
  server.send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}

void handleInvalidRequest(void) {
  server.send(400, "text/plain", "400: Invalid Request");         // The request is invalid, so send HTTP status 400
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