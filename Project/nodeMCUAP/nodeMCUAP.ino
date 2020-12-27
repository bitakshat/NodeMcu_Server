// Creating Soft Access Point
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "index.h"

const char* ssid = "ESPAP";
const char* password = "thereisnospoon";
ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.println("*****************************************************");
  Serial.print("[+]Setting up Access Point...");
  Serial.println();
  Serial.println(WiFi.softAP(ssid, password) ? "[+]Access Point Ready" : "[!]Failed");

//  Original handle
//  server.on("/", handle_OnConnect); 
  server.on("/", handleRoot);
  server.onNotFound(handle_NotFound);
  
  server.begin();
  Serial.println("[+]HTTP Server started");
  Serial.print("[+]Use this IP to Connect: ");
  Serial.print("https://");
  Serial.println(WiFi.softAPIP());
  Serial.printf("[+]Stations connected = %d\n", WiFi.softAPgetStationNum());
  Serial.println("*****************************************************");
}

void loop() {
    server.handleClient();
}

void handleRoot() {
    String s = WEB_PAGE;
    server.send(200, "text/html", s);
    server.handleClient();
}

void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}
