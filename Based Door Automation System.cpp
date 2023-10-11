#include <Servo.h>
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int SERVO_PIN = 5;
const int DISTANCE_THRESHOLD = 50;
Servo servo;
void setup() {
Serial.begin(9600);
pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
servo.attach(SERVO_PIN);
}
void loop() {
digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN, LOW);
float duration_us = pulseIn(ECHO_PIN, HIGH);
float distance_cm = 0.017 * duration_us;
if (distance_cm < DISTANCE_THRESHOLD) {
servo.write(90);
delay(2000);
servo.write(0);
}
delay(500);
}
