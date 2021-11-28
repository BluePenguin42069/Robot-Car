#include<Servo.h>
#include <IRremote.h> 
Servo Myservo;
int IRpin=7;
IRrecv IR(IRpin);
decode_results cmd;

int pos1=150;
int pos2=105;
int pos3=195;
int speedPin=5;
int dir1=4;
int dir2=3;
int mSpeed=255;

void setup(){
Serial.begin(9600);
IR.enableIRIn();
pinMode(speedPin, OUTPUT);
pinMode(dir1, OUTPUT);
pinMode(dir2, OUTPUT);
Myservo.attach(6);  
  }

void loop(){
while(IR.decode(&cmd)==0){}
Serial.println(cmd.value,HEX);
delay(1500);
IR.resume();
  
if (cmd.value==0xFF629D){//up
    digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  digitalWrite(dir1,HIGH);
  analogWrite(speedPin, mSpeed);
 Myservo.write(pos1); 
}
if (cmd.value==0xFFC23D){//right
    digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  digitalWrite(dir1,HIGH);
  analogWrite(speedPin, mSpeed);
 Myservo.write(pos3); 
}

if (cmd.value==0xFF22DD){//left
    digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  digitalWrite(dir1,HIGH);
  analogWrite(speedPin, mSpeed);
 Myservo.write(pos2); 
}

if (cmd.value==0XFF6897){//stop
digitalWrite(dir1,LOW);
analogWrite(speedPin, mSpeed=0);
}

}


  
