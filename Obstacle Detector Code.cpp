int IRSensor = 2; // Connect IR sensor module to Arduino pin 2
int Buzzer = 3; // Connect buzzer to Arduino pin 3
void setup()
{
Serial.begin(9600); // Initialize Serial at 9600 Baud
Serial.println("Serial Working"); // Test to check if serial is working or not
pinMode(IRSensor, INPUT); // IR Sensor pin INPUT
pinMode(Buzzer, OUTPUT); // Buzzer pin OUTPUT
}
void loop()
{
int sensorStatus = digitalRead(IRSensor); // Read the status of IR sensor pin
if (sensorStatus == HIGH)
{
// Obstacle detected, activate buzzer
digitalWrite(Buzzer, HIGH); // Buzzer ON
Serial.println("Obstacle Detected!");
}
else {
// No obstacle, turn off buzzer
digitalWrite(Buzzer, LOW); // Buzzer OFF
Serial.println("No Obstacle Detected!");
}
delay(500);
}