#include <Servo.h>
int lightPen = A0;
int lightVal;
int dv =250;
int outPin = 13;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPen, INPUT);
  pinMode(outPin, OUTPUT);
    myServo.attach(outPin);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPen);
  Serial.println(lightVal);
  myServo.write(1024 - lightVal);
//   if (lightVal < 120){
//     digitalWrite(outPin, HIGH);
//   }
//   else{
//     digitalWrite(outPin, LOW);
//   }
  delay(dv);
}