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
    ptr += "<style>\n";
    ptr += ".fields {font: 20px Arial, sans-serif;}";
    ptr += "</style>\n";
    ptr += "</head>\n";
    ptr += "<body>\n";
    ptr += "<h3 align=\"center\">Welcome To ESP Home";
    ptr += "</h3>\n";
    ptr += "<div id=\"fields\">\n";
    // Input Variables: access through JavaScript
    ptr += "<p>Enter SSID: </p>\n";
    ptr += "<input type=\"text\" id=\"ssid\">\n";
    ptr += "<p>Enter Password: </p>\n";
    ptr += "<input type=\"text\" id=\"pass\">\n";
    ptr += "</div>\n";
    ptr += "<script type=\"text/javascript\">\n";
    ptr += "function getVaules() {var WIFI_SSID = document.getElementById(\"ssid\"); document.write(\"SSID Entered: \"WIFI_SSID.value);}";
    ptr += "</script>\n";
    ptr += "<button onclick=\"getValues()\">OK</button>";
    ptr += "</body>\n";
    ptr += "</html>\n";
    
    return ptr;
}


void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}
