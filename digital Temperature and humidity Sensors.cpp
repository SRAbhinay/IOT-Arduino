#include <DHT.h>
#define DHTPIN 2 // Digital pin connected to the DHT sensor
#define RELAYPIN 3 // Digital pin connected to the relay module
#define DHTTYPE DHT22 // DHT22 (AM2302) sensor
DHT dht(DHTPIN, DHTTYPE);
void setup() {
Serial.begin(9600);
dht.begin();
pinMode(RELAYPIN, OUTPUT);
}
void loop() {
delay(2000); // Delay for 2 seconds between readings
float temperature = dht.readTemperature(); // Read temperature in Celsius
float humidity = dht.readHumidity(); // Read humidity
if (isnan(temperature) || isnan(humidity)) {
Serial.println("Failed to read from DHT sensor!");
return;
3
}
Serial.print("Temperature: ");
Serial.print(temperature);
Serial.print(" °C");
Serial.print(" Humidity: ");
Serial.print(humidity);
Serial.println(" %");
// Adjust the conditions as per your requirement
if (temperature > 30.0) {
digitalWrite(RELAYPIN, HIGH); // Turn on the fan or AC
} else {
digitalWrite(RELAYPIN, LOW); // Turn off the fan or AC
}
}