#include <Servo.h>
const int TRIG_PIN = 9; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = 10; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int SERVO_PIN = 5; // Arduino pin connected to Servo Motor's signal pin
const int DISTANCE_THRESHOLD = 50; // centimeters
Servo servo; // Servo object to control the motor
void setup() {
Serial.begin(9600); // initialize serial port
pinMode(TRIG_PIN, OUTPUT); // set Arduino pin to output mode
pinMode(ECHO_PIN, INPUT); // set Arduino pin to input mode
servo.attach(SERVO_PIN); // attach the servo motor to the corresponding pin
}
void loop() {
// generate 10-microsecond pulse to TRIG pin
digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN, LOW);
// measure duration of pulse from ECHO pin
float duration_us = pulseIn(ECHO_PIN, HIGH);
// calculate the distance
float distance_cm = 0.017 * duration_us;
if (distance_cm < DISTANCE_THRESHOLD) {
// Open the door
servo.write(90); // Rotate the servo motor to 90 degrees (open position)
delay(2000); // Wait for 2 seconds
// Close the door
servo.write(0); // Rotate the servo motor to 0 degrees (closed position)
}
delay(500);
}