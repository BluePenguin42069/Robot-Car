//#define ENABLE 7
//#define DIRA 3
//#define DIRB 4

//1 second for 60 cm 
#include <Servo.h>
int enA = 7;
int DIRA=3;
int DIRB=4;
Servo myservo;
int trigpin = 9;
int echopin = 8;
int Input, duration, distance;
long previousMillis=0;
unsigned long currentMillis=0;
int i;
//adjust timing based on legnth of path
long forward = 2100;//10000 seconds to go forward 120 cm 60 cm
long turn = 1000;//7 second to rotate 90 degrees CW
long forward2=800; //600010 second go forward
long turn2 = 1000;
long forward3 =2100;//60 cm 

void setup() {
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  myservo.attach(6);
  myservo.write(100);
  analogWrite(enA,255); //enable on
  digitalWrite(DIRA,LOW); //one way
  digitalWrite(DIRB,HIGH);
  }

void loop() {
  i=1;
  Input=sensor();
  myservo.write(98);
  if(i==1)
  {
    while(Input>15){
    myservo.write(98);
  analogWrite(enA,255); //enable on
  digitalWrite(DIRA,LOW); //one way
  digitalWrite(DIRB,HIGH);
  analogWrite(enA,0); //enable on
  digitalWrite(DIRA,LOW); //one way
  digitalWrite(DIRB,HIGH);
    Input=sensor();
    if(Input < 15)
     {
      break;
     
      }
    }
    previousMillis=millis();
    while(Input>15)
    {
  analogWrite(enA,255); //enable on
  digitalWrite(DIRA,LOW); //one way
  digitalWrite(DIRB,HIGH);
  myservo.write(98);
  Input=sensor();
     
     if(Input < 15)
     {
      break;
     
      } 
      }
if(Input < 15)
{
  analogWrite(enA,0); //enable on
  digitalWrite(DIRA,LOW); //one way
  digitalWrite(DIRB,HIGH);
  currentMillis=0;
  currentMillis = millis();
  while(millis()-currentMillis<600) //1000
  {
    analogWrite(enA,0); //enable on
  digitalWrite(DIRA,LOW); //one way
  digitalWrite(DIRB,HIGH);
  delay(50);
  
    myservo.write(65);
    
    analogWrite(enA,255); //enable on
  digitalWrite(DIRA,LOW); //one way
  digitalWrite(DIRB,HIGH);
    } 
    currentMillis=millis();

   while (millis()-currentMillis<700)//6000
   {
    analogWrite(enA,255); //enable on
  digitalWrite(DIRA,LOW); //one way
  digitalWrite(DIRB,HIGH);
    }
currentMillis=millis();
  while (millis()-currentMillis<800)//8000
{
  myservo.write(131);
    analogWrite(enA,255); //enable on
  digitalWrite(DIRA,LOW); //one way
  digitalWrite(DIRB,HIGH);
  }
  currentMillis=millis();
  
    while (millis()-currentMillis<1000)//10000
{
  myservo.write(98);
    analogWrite(enA,255); //enable on
  digitalWrite(DIRA,LOW); //one way
  digitalWrite(DIRB,HIGH);
  }
  currentMillis=millis();
  while (millis()-currentMillis<1100)//65000
{
  myservo.write(131);
    analogWrite(enA,255); //enable on
  digitalWrite(DIRA,LOW); //one way
  digitalWrite(DIRB,HIGH);
  }
   while (millis()-currentMillis<1200)//60000
{
  myservo.write(65);
    analogWrite(enA,255); //enable on
  digitalWrite(DIRA,LOW); //one way
  digitalWrite(DIRB,HIGH);
  }
     while (millis()-currentMillis<1300)//60000
{
  myservo.write(98);
    analogWrite(enA,255); //enable on
  digitalWrite(DIRA,LOW); //one way
  digitalWrite(DIRB,HIGH);
  }
  while (millis()-currentMillis<1601)//60000
{
  
    analogWrite(enA,0); //enable on
  digitalWrite(DIRA,LOW); //one way
  digitalWrite(DIRB,HIGH);
  }
  }

  
}
  Serial.print(currentMillis);
    Serial.println(" ");

}

double sensor()
{
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration = pulseIn(echopin,HIGH);
  distance = 100.0*(343.0*(duration/2.0))/1000000.0;
  distance = constrain(distance,0,15);
  return(distance);
  
  }
