#include <Servo.h>

int lightPen = A0;
int lightVal;
int dv =2500;
int outPin = 13;
Servo s;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPen, INPUT);
  pinMode(outPin, OUTPUT);
  s.attach(outPin);
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPen);
  Serial.println(lightVal);
 s.write((180.0/1023.0) * lightVal);
}
