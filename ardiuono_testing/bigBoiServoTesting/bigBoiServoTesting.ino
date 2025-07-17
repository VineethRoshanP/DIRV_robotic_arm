#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
int relay = 2;

void s1_angle(int start, int end) {
  
  int angle = start;

  if(start < end) {
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

void s2_angle(int start, int end) {
  
  int angle = start;

  if(start < end) {
    while(angle < end) {
      angle = angle + 1;
      servo2.write(angle);
      delay(10);
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

  if(start < end) {
    while(angle < end) {
      angle = angle + 1;
      servo3.write(angle);
      delay(10);
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

void setup() {
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  
  servo1.attach(13);
  servo2.attach(12);
  servo3.attach(11);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  Serial.begin(9600);

}

void loop() {

  delay(2000);

  s3_angle(0, 69);
  delay(100);
  s2_angle(0, 70);
  delay(100);
  s1_angle(0, 80);
  delay(100);
  
  delay(100);
  digitalWrite(relay, HIGH);
  delay(500);
  s1_angle(80, 105);
  delay(2000);
  s1_angle(105, 50);
  delay(2000);
  s1_angle(50, 105);
  delay(2000);

  s1_angle(95, 0);
  delay(500);
  s2_angle(70, 0);
  delay(500);
  s3_angle(69, 0);
  delay(500);

  digitalWrite(relay, LOW);
  delay(200000000000);

}
