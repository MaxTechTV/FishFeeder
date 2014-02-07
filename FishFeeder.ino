/*
  Quick&Easy FishFeeder
 
  'EinmalFütterAutomat' mit einem Servo
  Servo an Pin 9
  Da der verwendete Servo etwas defekt ist wurde keine komplette 180° Drehung verwendet
 
  created 18. Jan 2014
  by Max Hentsch 'MaxTechTV'
  Version 0.1

*/
 
#include <Servo.h>
 
Servo futterservo;
 
void warteStunden(int i)
{
  for (int k=1;k<i;k++){
    delay(3600000);
  }
}
 
void shake(){
  futterservo.write(130);
  delay(100);
  futterservo.write(140);
  delay(100);
  futterservo.write(130);
  delay(100);
  futterservo.write(140);
  delay(100);
  futterservo.write(130);
  delay(100);
  futterservo.write(140);
  delay(100);
  futterservo.write(130);
  delay(100);
  futterservo.write(140);
}
 
void feed(){
  futterservo.write(140);
  delay(200);
  shake();
  futterservo.write(30);
}
void setup()
{
  futterservo.attach(9);
  futterservo.write(20);
  pinMode(13,OUTPUT);
  feed();
  digitalWrite(13,HIGH);
  delay(30);
}
 
void loop(){
  warteStunden(24);
  feed();
  digitalWrite(13,LOW);
  while(true);
}
