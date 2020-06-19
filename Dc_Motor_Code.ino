
void setup() {
  // put your setup code here, to run once:
pinMode(6  , OUTPUT);
pinMode(7  , OUTPUT);
pinMode(11 , OUTPUT);
pinMode(12 , OUTPUT);
}

void loop() {
  // Forwed moter 1 and 2:
  analogWrite(6, HIGH);
  analogWrite(7, LOW);
  analogWrite(11, HIGH);
  analogWrite(12, LOW);
  delay(500); 
  // bacowerd moter 1 and 2:
  analogWrite(6, LOW);
  analogWrite(7, HIGH);
  analogWrite(11, LOW);
  analogWrite(12, HIGH);
  delay(500);
  // Right moter :
  analogWrite(6, HIGH);
  analogWrite(7, LOW);
  analogWrite(11, LOW);
  analogWrite(12, LOW);
  delay(500);
  // Laft moter :
  analogWrite(6, LOW);
  analogWrite(7, LOW);
  analogWrite(11, HIGH);
  analogWrite(12, LOW);
  delay(500);
}
