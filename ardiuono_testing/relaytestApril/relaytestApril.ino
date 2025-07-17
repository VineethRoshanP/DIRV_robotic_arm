// TCS230 or TCS3200 pins wiring to Arduino
#define S0 7

void setup() {
  // Setting the outputs
  pinMode(S0, OUTPUT);
  digitalWrite(S0,LOW); 
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  digitalWrite(S0,HIGH);
  delay(5000);
  digitalWrite(S0,LOW);
}