int LEDPin = 13;
int ButtonPin = A0;
int button;
int dt = 250;


void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(ButtonPin, INPUT);
  // put your setup code here, to run once:
}

void loop() {

  button = digitalRead(ButtonPin);
  delay(dt);
  Serial.println(button);
  if (button == 1){
    digitalWrite(LEDPin, LOW);
  }
  else {
    digitalWrite(LEDPin, HIGH);
  }
  // put your main code here, to run repeatedly:

}
