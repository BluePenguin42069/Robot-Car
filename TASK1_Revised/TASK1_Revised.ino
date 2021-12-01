#include <IRremote.h>
#include<Servo.h>

Servo Myservo;
int pos1=150;//going straight
int pos2=105;//going left
int pos3=195;//going right
int speedPin=5;
int dir1=4;
int dir2=3;
int mSpeed=255;

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

void setup(){
  Serial.begin(9600);
  pinMode(speedPin, OUTPUT);
pinMode(dir1, OUTPUT);
pinMode(dir2, OUTPUT);
Myservo.attach(6);  
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){

switch(results.value){

case 0xFF629D:
Serial.println("up");
digitalWrite(dir1,HIGH);
analogWrite(speedPin, mSpeed);
Myservo.write(pos1);

break;  

      
case 0xFFC23D:
Serial.println("right");
digitalWrite(dir1,HIGH);
analogWrite(speedPin, mSpeed);
Myservo.write(pos3); 

break;

      
case 0xFF22DD:
Serial.println("left");
digitalWrite(dir1,HIGH);
analogWrite(speedPin, mSpeed);
Myservo.write(pos2); 

break;

default:       
//case 0XFF6897:
Serial.println("stop");
digitalWrite(dir1,LOW);
analogWrite(speedPin, mSpeed);
Myservo.write(pos1); 
break;
}
delay(1000);
irrecv.resume();
  }
}
