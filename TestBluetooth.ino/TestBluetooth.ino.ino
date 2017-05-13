#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

int ledPin = 13;

void setup() {
  Serial.begin( 9600 );    // 9600 is the default baud rate for the serial Bluetooth module
  Serial.print("waiting ...");
  BTSerial.begin(9600);
}
void loop() {
  Serial.print("sending ..");
  BTSerial.print(String(1)+","+String(2));
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}
void blinkLED(int count) {
  for (int i=0; i< count; i++) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}
