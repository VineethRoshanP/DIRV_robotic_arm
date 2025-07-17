#include <Servo.h>

Servo servo1; //Servo 1: Pin 13
Servo servo2; //Servo 2: Pin 12
Servo servo3; //Servo 3: Pin 11
int relay = 3; //Relay: Pin D3
int trigPin = 7; //Ultrasonic Trigger: Pin 7 //green
int echoPin = 6; //Ultrasonic Echo: Pin 6 //blue

long duration, cm;
long current_dist;

//CUSTOM SERVO MOVING FUNCTIONS:

void s1_angle_fast(int start, int end) {
  
  int angle = start;

  if(start == end) servo1.write(angle);

  else if(start < end) {
    while(angle < end) {
      angle = angle + 1;
      servo1.write(angle);
      delay(1);
    }
  }

  else {
    while(angle > end) {
      angle = angle - 1;
      servo1.write(angle);
      delay(1);
    }
  }

}

void s1_angle(int start, int end) {
  
  int angle = start;

  if(start == end) servo1.write(angle);

  else if(start < end) {
    while(angle < end) {
      angle = angle + 1;
      servo1.write(angle);
      delay(30);
    }
  }

  else {
    while(angle > end) {
      angle = angle - 1;
      servo1.write(angle);
      delay(20);
    }
  }

}

void s2_angle(int start, int end) {
  
  int angle = start;

  if(start == end) servo1.write(angle);

  else if(start < end) {
    while(angle < end) {
      angle = angle + 1;
      servo2.write(angle);
      delay(20);
    }
  }

  else {
    while(angle > end) {
      angle = angle - 1;
      servo2.write(angle);
      delay(10);
    }
  }
  
}

void s3_angle(int start, int end) {
  
  int angle = start;

  if(start == end) servo1.write(angle);

  else if(start < end) {
    while(angle < end) {
      angle = angle + 1;
      servo3.write(angle);
      delay(20);
    }
  }

  else {
    while(angle > end) {
      angle = angle - 1;
      servo3.write(angle);
      delay(10);
    }
  }
  
}


//SERVO POSITIONS FUNCTIONS:
void reset_pos(int start1, int start2, int start3) {
  s3_angle(start3, 0);
  delay(100);
  s2_angle(start2, 0);
  delay(100);
  s1_angle(start1, 0);
}

void scan_pos(int start1, int start2, int start3) {
  s3_angle(start3, 40);
  delay(100);
  s2_angle(start2, 34);
  delay(100);
  s1_angle(start1, 60);
}

void bin_full() {
  s3_angle(40, 69);
  delay(100);
  s2_angle(34, 70);
  delay(100);
  s1_angle_fast(60, 80);
  
  delay(100);
  digitalWrite(relay, HIGH);
  
  delay(500);
  s1_angle_fast(80, 105);
  delay(2000);
  s1_angle_fast(105, 50);
  delay(2000);
  s1_angle_fast(50, 105);
  delay(2000);

  s1_angle(105, 0);
  delay(500);
  s2_angle(70, 0);
  delay(500);
  s3_angle(69, 0);
  delay(500);
}

void bin_half() {
  s3_angle(40, 70);
  delay(100);
  s2_angle(34, 60);
  delay(100);
  s1_angle_fast(60, 109);
  
  delay(100);
  digitalWrite(relay, HIGH);
  
  delay(500);
  s1_angle_fast(109, 120);

  delay(2000);

  s1_angle(120, 0);
  delay(500);
  s2_angle(60, 0);
  delay(500);
  s3_angle(70, 0);
  delay(500);
}

void bin_empty() {
  s3_angle(40, 0);
  delay(100);
  s2_angle(34, 0);
  delay(100);
  s1_angle(60, 0);
  delay(100);
}


//OTHER SENSOR FUNCTIONS (ULTRASONIC & COLOR SENSOR):

long distance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  return cm;
}

// -----------------------------------------------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------------------------------------------------


//MAIN SETUP AND LOOP:

void setup() {

  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  
  servo1.attach(13);
  servo2.attach(12);
  servo3.attach(11);

  servo1.write(0);
  servo2.write(0);
  servo3.write(0);

  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

}

void loop() {

  delay(2000);
  scan_pos(0, 0, 0);
  delay(1000);
  
  current_dist = distance();
  Serial.print(current_dist);
  Serial.println(" cm");

  delay(1000);

  current_dist = distance();
  Serial.print(current_dist);
  Serial.println(" cm");

  

  if(current_dist <= 20) {
    bin_full(); //17-18 cm
  }

  else if(current_dist > 20 && current_dist <= 26) {
    bin_half(); //22-23 cm
  }

  else if(current_dist > 26) {
    bin_empty(); //28-29 cm
  }
  
  

  digitalWrite(relay, LOW);
  delay(200000000000);
}
