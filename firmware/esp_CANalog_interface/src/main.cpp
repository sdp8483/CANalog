#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid =      "CANalog";
const char* password =  "admin";
IPAddress local_IP(192,168,4,1);
IPAddress gateway(192,168,4,9);
IPAddress subnet(255,255,255,0);

#define NUMBER_CAN_BAUD_RATES  9
String possible_can_baud[NUMBER_CAN_BAUD_RATES] = {"10", "20", "50", "100", "125", "250", "500", "750", "1000"};

String can_baud = "500";
String can_id = "18EFB300";
String can_is_extended = "true";
String can_signal_start_bit = "0";
String can_signal_bit_len = "8";

ESP8266WebServer server(80);

void handleRoot(void);              // function prototypes for HTTP handlers
void handleSave(void);
void handleNotFound(void);
void handleInvalidRequest(void);

void setup(void){
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');

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

void loop(void){
  server.handleClient();                     // Listen for HTTP requests from clients
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
  root += can_id;
  root += "\"  size=\"9\"><br>";

  root += "<label for=\"can_is_extended\">29bit ID: </label>";
  root += "<select id=\"can_is_extended\" name=\"can_is_extended\">";
  if (can_is_extended == "true") {
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
  //String canID_str = server.arg("canid");
  //String msgBitPosition_str = server.arg("bitpos");
  //String msgBitLen_str = server.arg("msglen");

  can_baud = server.arg("can_baud");
  can_id = server.arg("can_id");
  can_is_extended = server.arg("can_is_extended");
  can_signal_start_bit = server.arg("can_signal_start_bit");
  can_signal_bit_len = server.arg("can_signal_bit_len");

  Serial.print("CAN Baud Rate: ");
  Serial.print(can_baud);
  Serial.println("kbps");
  Serial.print("CAN ID: 0x");
  Serial.println(can_id);
  Serial.print("29bit ID? ");
  Serial.println(can_is_extended);
  Serial.print("Signal Start Bit: ");
  Serial.println(can_signal_start_bit);
  Serial.print("Signal Bit Length: ");
  Serial.println(can_signal_bit_len);
  Serial.println();

  /* Send out parsable commands for stm32 */
  Serial.print("@can_baud=");
  Serial.println(can_baud);

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