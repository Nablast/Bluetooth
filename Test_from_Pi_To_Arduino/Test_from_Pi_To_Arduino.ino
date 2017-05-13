#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

int ledPin = 13;
char character;

void setup() {
  Serial.begin( 9600 );    // 9600 is the default baud rate for the serial Bluetooth module
  Serial.print("waiting ...");
  BTSerial.begin(9600);
}
void loop() {

  String Data = "";
  
  while(BTSerial.available()) {
     character = BTSerial.read();
     Data.concat(character);
     
     delay (10);
    }

    Serial.print(Data);
   
    if (Data == "1") digitalWrite(ledPin, HIGH);
    if (Data == "0") digitalWrite(ledPin, LOW);
}
void blinkLED(int count) {
  for (int i=0; i< count; i++) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}
