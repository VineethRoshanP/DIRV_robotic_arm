// TCS230 or TCS3200 pins wiring to Arduino
#define S0 9
#define S1 10
#define S2 11
#define S3 12
#define sensorOut 13

// Stores frequency read by the photodiodes
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int yellowFrequency = 0; // Approximate yellow from red + green

void setup() {
  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);
  
  // Setting frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,HIGH);
  
  // Begins serial communication 
  Serial.begin(9600);
}

void loop() {
  // Detect RED
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  redFrequency = pulseIn(sensorOut, LOW);
  Serial.print("Red = ");
  Serial.print(redFrequency);
  delay(100);
  
  // Detect BLUE
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);
  Serial.print(" | Blue = ");
  Serial.print(blueFrequency);
  delay(100);

  // Detect GREEN (needed for Yellow)
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);
  Serial.print(" | Green = ");
  Serial.print(greenFrequency);
  delay(100);

  // Approximate Yellow (Red + Green)
  yellowFrequency = (redFrequency + greenFrequency) / 2;
  Serial.print(" | Yellow = ");
  Serial.println(yellowFrequency);
  delay(100);


  if((blueFrequency < redFrequency) && (blueFrequency < greenFrequency)) {
    if(greenFrequency - blueFrequency >= 10) Serial.print("--------- BLUE DETECTED ---------");
    else Serial.print("--------- GREEN DETECTED ---------");
  }

  else if((greenFrequency < redFrequency) && (greenFrequency < blueFrequency)) {
    Serial.print("--------- GREEN DETECTED ---------");
  }

  else if((redFrequency < greenFrequency) && (redFrequency < blueFrequency)) {
    //if((yellowFrequency - redFrequency) >= 15) {
    Serial.print("--------- RED DETECTED ---------");
    //}
    /*
    if((yellowFrequency - redFrequency) < 15) {
      Serial.print("--------- YELLOW DETECTED ---------");
    }
    */

  }

  Serial.print(" ");
  delay(1000);

}