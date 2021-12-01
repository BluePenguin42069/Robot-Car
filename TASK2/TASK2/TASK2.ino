#include<Servo.h>
Servo Myservo;
int pos1=150;//going straight
int pos2=105;//going left
int pos3=195;//going right
int speedPin=5;
int dir1=4;
int dir2=3;
int mSpeed=255;

void setup(){
pinMode(speedPin, OUTPUT);
pinMode(dir1, OUTPUT);
pinMode(dir2, OUTPUT);
Myservo.attach(6);  
  }

void loop(){
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  digitalWrite(dir1,HIGH);
  analogWrite(speedPin, mSpeed);
 Myservo.write(pos1);
 delay(1200);
 Myservo.write(pos3);
 delay(1200);
 Myservo.write(pos1);
 delay(400);
 Myservo.write(pos2);
 delay(1200); 
 Myservo.write(pos1);
 delay(800);


 
  digitalWrite(dir1,LOW);
  analogWrite(speedPin, mSpeed=0);
 Myservo.write(pos2=150);
  Myservo.write(pos3=150);
  }
