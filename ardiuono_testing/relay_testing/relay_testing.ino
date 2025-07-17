int relay = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relay, LOW);
  delay(1000);
  digitalWrite(relay, HIGH);
  delay(1000);
}
