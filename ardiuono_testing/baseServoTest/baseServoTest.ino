#include <Servo.h>

Servo servo1; //Servo 1: Pin 13

void s1_angle(int start, int end) {
  
  int angle = start;

  if(start == end) servo1.write(angle);

  else if(start < end) {
    while(angle < end) {
      angle = angle + 1;
      servo1.write(angle);
      delay(20);
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

//MAIN SETUP AND LOOP:
void setup() {

  servo1.write(0);
  servo1.attach(13);
  servo1.write(0);
  Serial.begin(9600);

}

void loop() {

  delay(2000);
  
  s1_angle(0,90);
  delay(5000);
  s1_angle(90,0);
  
  

  delay(200000000000);
}
