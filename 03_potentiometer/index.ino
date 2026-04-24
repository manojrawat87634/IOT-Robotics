int myVoltPin = A2;
int readVal;
float V2;


void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  readVal = analogRead(myVoltPin);
  V2 = (5./1023.) * readVal;
  Serial.print("voltage is ");
  

  if (V2 > 3){
    digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(13, LOW);
  }
  Serial.println(V2);
  delay(700);
}
