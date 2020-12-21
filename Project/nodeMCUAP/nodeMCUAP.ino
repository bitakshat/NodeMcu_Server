// Creating Soft Access Point
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

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

  server.on("/", handle_OnConnect);
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

void handle_OnConnect() {
    server.send(200, "text/html", SendHTML());
    server.handleClient();
}

String SendHTML() {
    String ptr = "<!DOCTYPE html>\n";
    ptr += "<html>\n";
    ptr += "<head>\n";
    ptr += "<title>Welcome Page\n";
    ptr += "</title>\n";
    ptr += "</head>\n";
    ptr += "<body>\n";
    ptr += "<h3>Hello Fuck you!!\n";
    ptr += "</h3>\n";
    ptr += "</body>\n";
    ptr += "</html>\n";

    return ptr;
}

void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}
