
void setup() {
  // put your setup code here, to run once:
  pinMode(6  , OUTPUT);
  pinMode(7  , OUTPUT);
}

void loop() {
  // Forwed motor:
  analogWrite(6, HIGH);
  analogWrite(7, LOW);
  delay(500);
  // bacowerd motor:
  analogWrite(6, LOW);
  analogWrite(7, HIGH);
  delay(500);
}
