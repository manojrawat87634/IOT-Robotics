int lightPen = A0;
int lightVal;
int dv =250;
int outPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPen, INPUT);
  pinMode(outPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPen);
  Serial.println(lightVal);
  if (lightVal < 120){
    digitalWrite(outPin, HIGH);
  }
  else{
    digitalWrite(outPin, LOW);
  }
  delay(dv);
}
