const int CS = D3;
const int INC = D2;
const int UD = D1;

void setup() {
  Serial.begin(9600);
  pinMode(CS, OUTPUT);
  pinMode(INC, OUTPUT);
  pinMode(UD, OUTPUT);
  digitalWrite(CS, HIGH);
  digitalWrite(INC, HIGH);
  digitalWrite(UD, HIGH);
}

void loop() {
  //   for (int i=60; i<=63; i+=2) {
  //    setResistance(i);
  //    delay(2000);
  //  }
    int k = random(40, 50);
    Serial.print(k);
    setResistance(k);
    delay(3000);

  //setResistance(100);
}

void setResistance(int percent) {
  digitalWrite(UD, LOW);
  digitalWrite(CS, LOW);
  for (int i = 0; i < 100; i++) {
    digitalWrite(INC, LOW);
    delayMicroseconds(1);
    digitalWrite(INC, HIGH);
    delayMicroseconds(1);
  }

  digitalWrite(UD, HIGH);
  for (int i = 0; i < percent; i++) {
    digitalWrite(INC, LOW);
    delayMicroseconds(1);
    digitalWrite(INC, HIGH);
    delayMicroseconds(1);
  }

  digitalWrite(CS, HIGH);
}
