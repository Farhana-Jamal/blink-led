#include <Arduino.h>

int LED = 2;
void setup() {
  pinMode(LED,OUTPUT);
  Serial.begin(115200);
 
  // put your setup code here, to run once:
}

void loop() {
  digitalWrite(LED,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
  delay(1000);
   Serial.println("hello world");
  // put your main code here, to run repeatedly:
}