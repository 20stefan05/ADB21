#include "Move.h"

int  currentSpeed = 0;

void mvForward(int speed){
  Serial.print("Moving forward with speed = ");
  Serial.println(speed);
  int speedToMotor = map(speed, 0, 10, 0, 255);
  if(currentSpeed<speedToMotor){
      currentSpeed+=2;
      analogWrite(EN_wheel, abs(currentSpeed));
      delay(20);
  }
  if(currentSpeed>=0){
  digitalWrite(wheelA, HIGH);
  digitalWrite(wheelB, LOW);
  }
  Serial.println(currentSpeed);  
}
void mvBackward(int speed){
  Serial.print("Moving backward with speed = ");
  Serial.println(speed);
    int speedToMotor = map(speed, 0, 10, 0, 255);
    speedToMotor*=-1;;
  if(currentSpeed>speedToMotor){
      currentSpeed-=2;
      analogWrite(EN_wheel, abs(currentSpeed));
      delay(20);
  }
  if(currentSpeed<0){
  digitalWrite(wheelA, LOW);
  digitalWrite(wheelB, HIGH);
  }
  Serial.println(currentSpeed);  
}
void mvLeft(){
  Serial.println("Moving left");
  analogWrite(EN_steering, 128);
  digitalWrite(steeringA, HIGH);
  digitalWrite(steeringB, LOW);
}
void mvRight(){
  Serial.println("Moving right");
  analogWrite(EN_steering, 128);
  digitalWrite(steeringB, HIGH);
  digitalWrite(steeringA, LOW);
}
void stop(){
  if(currentSpeed>0){
    currentSpeed-=2;
    analogWrite(EN_wheel, currentSpeed);
    delay(20);
  }
  else if(currentSpeed<0){
    currentSpeed+=2;
    analogWrite(EN_wheel, abs(currentSpeed));
    delay(20);
  }
  Serial.println(currentSpeed);  
}
