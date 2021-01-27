#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid =      "CANalog";
const char* password =  "admin";
IPAddress local_IP(192,168,4,1);
IPAddress gateway(192,168,4,9);
IPAddress subnet(255,255,255,0);

String canID = "18EFB300";
String msgBitPosition = "0";
String msgBitLen = "8";

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
  root += "<head><title>CANalog</title></head>";
  root += "<body>";
  root += "<h2>CANalog Configuration</h2>";
  root += "<form action=\"/save\" method=\"POST\">";
  root += "<label for=\"canid\">CAN ID:</label><br>";
  root += "<input type=\"text\" id=\"canid\" name=\"canid\" value=\"";
  root += canID;
  root += "\"><br>";
  root += "<label for=\"bitpos\">Bit Position:</label><br>";
  root += "<input type=\"number\" id=\"bitpos\" name=\"bitpos\" value=\"";
  root += msgBitPosition;
  root += "\" min=\"0\" max=\"32\"><br>";
  root += "<label for=\"msglen\">Number of Bits:</label><br>";
  root += "<input type=\"number\" id=\"msglen\" name=\"msglen\" value=\"";
  root += msgBitLen;
  root += "\" min=\"1\" max=\"32\"><br><br>";
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

  canID = server.arg("canid");
  msgBitPosition = server.arg("bitpos");
  msgBitLen = server.arg("msglen");

  Serial.print("CAN ID: 0x");
  Serial.println(canID);
  Serial.print("Bit Position: ");
  Serial.println(msgBitPosition);
  Serial.print("Bit Length: ");
  Serial.println(msgBitLen);
  Serial.println();

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