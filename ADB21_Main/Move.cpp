#include "Move.h"
int speed = 0;
//CAN ids: 0x01- Motors; 0x02 - lights; 0x03 - sensor

unsigned char mvForward(){
  Serial.println("Move forward");
  int sendSpeed = speed - 48;
  if(sendSpeed>0&&sendSpeed<=9){
     return sendSpeed;
  }
  else if(sendSpeed == 65){
    unsigned char m = 'M';
    return m;
  }
  return 0;
}
unsigned char mvBackward(){
  Serial.println("Move back");
  int sendSpeed = speed - 48;
  if(sendSpeed>0&&sendSpeed<=9){
     return sendSpeed;
  }
  else if(sendSpeed == 65){
    unsigned char m = 'M';
    return m;
  }
  return 0;
}
void mvLeft(){
  Serial.println("Left");
}
void mvRight(){
  Serial.println("Right");
}
void frontRight(){
  Serial.println("Front right");
}
void frontLeft(){
  Serial.println("Front left");
}
void backRight(){
  Serial.println("Back right");
}
void backLeft(){
  Serial.println("Back left");
}
void setSpeed(int spd){
  speed = spd;
  Serial.print("Speed = ");
  Serial.println (spd);
}
