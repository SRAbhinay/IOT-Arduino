int ledPin = 13;

void setup() {

pinMode(ledPin, OUTPUT);
Serial.begin(9600);

void loop() { 
if (Serial.available())
{ char command = Serial.read();
  if (receivedChar == 'LED ON') {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED ON");
    } 
  else if (receivedChar == 'LED OFF') {
    digitalWrite(ledPin, LOW);
    Serial.println("LED OFF");
              }
            }
          }
        }
