#include<ESP8266WiFi.h>

const char* ssid = "YOUR WIFI SSID";
const char* password = "YOUR WIFI PASSWORD";
WiFiServer server(80);

void setup() {
	Serial.begin(115200);
	Serial.print("Connecting to: ");
	Serial.println(ssid);
	WiFi.begin(ssid, password);

	while( WiFi.status() != WL_CONNECTED ) {
		Serial.print("*");
		delay(500);
	}

	Serial.println("WiFi Connected!");
	server.begin();
	Serial.println("Server Started");
	Serial.print("Use this IP to connect: "):
	Serial.println(WiFi.localIP());
}

void loop() {
	WiFiClient client = server.available();
	if( !client ) {
		return;
	}
	while( client.available() ) {
		delay(1);
	}

	String request = client.readStringUntil('\r');
	Serial.print(request);
	client.flush();

	client.println("HTTP/1.1 200 OK");
	client.println("Content-Type: text-html");
	client.println(" ");
	client.println("<!DOCTYPE html>");
	client.println("<head></head>");
	/*write HTML source code here*/
	client.println("<body></body>");
	client.println("</html>");
}
