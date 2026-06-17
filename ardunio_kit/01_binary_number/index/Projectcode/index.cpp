void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  for (int num = 0; num < 16; num++) {

    digitalWrite(13, (num >> 3) & 1); // MSB
    digitalWrite(12, (num >> 2) & 1);
    digitalWrite(11, (num >> 1) & 1);
    digitalWrite(10, (num >> 0) & 1); // LSB

    delay(1000); // 1 second delay
  }
}