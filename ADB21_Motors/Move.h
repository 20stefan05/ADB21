#ifndef MOVE_H
#define MOVE_H
#endif

#include "Arduino.h"

#define EN_wheel 9
#define wheelA 8
#define wheelB 7
#define EN_steering 6
#define steeringA 5
#define steeringB 4


void mvForward(int speed);
void mvBackward(int speed);
void mvLeft();
void mvRight();
void stop();
