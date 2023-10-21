#include <SPI.h>
#include <WiFiNINA.h>

3

char ssid[] = "Abhi";
char pass[] = "";

int keyIndex = 0;
int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
Serial.begin(9600);
pinMode(LED_BUILTIN, OUTPUT);
while (status != WL_CONNECTED) {
Serial.print("Attempting to connect to Network named: ");
Serial.println(ssid);
status = WiFi.begin(ssid, pass);
delay(10000);
}
server.begin();
Serial.print("SSID: ");
Serial.println(WiFi.SSID());
IPAddress ip = WiFi.localIP();
Serial.print("IP Address: ");
Serial.println(ip);
}
void blinker() {
Serial.println("Blinking");
digitalWrite(LED_BUILTIN, HIGH);
delay(1000); 
digitalWrite(LED_BUILTIN, LOW); 
delay(1000); 
}

void loop() {
WiFiClient client = server.available();
if (client) {
Serial.println("new client");
String currentLine = "";
while (client.connected()) {
if (client.available()) {
char c = client.read();
Serial.write(c);
if (c == '\n') {
if (currentLine.length() == 0) {
client.println("Hello World");
for(int i=0;i<10;i++)
{
blinker();
}
break;
} else {
currentLine = "";
}
} else if (c != '\r') {
currentLine += c;
}
}
}
client.stop();
Serial.println("client disonnected");
}

}
