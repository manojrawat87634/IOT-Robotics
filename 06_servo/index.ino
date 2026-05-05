#include <Servo.h>

int servoPin = 13;
int servoPosition = 0;
Servo myServo;

void setup(){
    Serial.begin(9600);
    myServo.attach(servoPin);
}

void loop (){
    myServo.write(servoPosition);
}