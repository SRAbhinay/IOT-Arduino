void setup() { 
 pinMode(2, OUTPUT);
 }

void loop() { 
 digitalWrite(2, HIGH);
 delay(500);
 digitalWrite(2, LOW);
 delay(500);
 } 

void setup() { pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT); // Green LED // Additional setup code for traffic control mechanism if used 
}
void loop() { // Check traffic control mechanism for the desired light sequence
if (trafficControl == RED) { digitalWrite(2, HIGH); // Red LED on
digitalWrite(3, LOW); // Yellow LED off
digitalWrite(4, LOW); // Green LED off
delay(5000); // Delay for red light duration 
}
else if (trafficControl == YELLOW)
{ digitalWrite(2, LOW); // Red LED off
digitalWrite(3, HIGH); // Yellow LED on
digitalWrite(4, LOW); // Green LED off
delay(2000); // Delay for yellow light duration 
}
else if (trafficControl == GREEN) {
digitalWrite(2, LOW); // Red LED off
digitalWrite(3, LOW); // Yellow LED off
digitalWrite(4, HIGH); // Green LED on
delay(5000); // Delay for green light duration 
} }
