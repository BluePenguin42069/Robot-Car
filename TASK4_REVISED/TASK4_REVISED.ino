#include<Servo.h>
Servo Myservo;
int pos1=150;//going striaght
int pos2=105;//going left
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
 delay(1400);
 Myservo.write(pos2);
 delay(600);
 Myservo.write(pos1);
 delay(900);
 Myservo.write(pos2);
 delay(600); 
 Myservo.write(pos1);
 delay(900);
 Myservo.write(pos2);
 delay(600);
 Myservo.write(pos1);
 delay(800);
  Myservo.write(pos2);
 delay(400);

 
  digitalWrite(dir1,LOW);
  analogWrite(speedPin, mSpeed=0);
 Myservo.write(pos2=pos1);
  }
