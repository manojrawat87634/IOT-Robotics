void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, LOW);   // many relay modules activate on LOW
  delay(5000);

  digitalWrite(13, HIGH);
  delay(5000);
}