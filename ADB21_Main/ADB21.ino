#include <SoftwareSerial.h> 
#include <SPI.h> 
#include "mcp2515_can.h"
#include "Move.h"
#include "Lights.h"
SoftwareSerial bt(0, 1); 
const int SPI_CS_PIN = 10;
mcp2515_can CAN(SPI_CS_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  
  bt.begin(9600);
  
  while (CAN_OK != CAN.begin(CAN_500KBPS)) {             // init can bus : baudrate = 500k
        Serial.println("CAN init fail, retry...");
        delay(100);
    }
  Serial.println("CAN init ok!");
  delay(100); 
}
int cmd;
void loop() {
  // put your main code here, to run repeatedly:
  
  if (bt.available()){
  cmd = bt.read();
  if( cmd != 83) Serial.println(cmd);
  switch (cmd){
    case 70:{
      unsigned char msg[2] ={'F', mvForward()}; // front
      CAN.sendMsgBuf(0x01, 0, 2, msg);
      break;
    }
    case 66: {
      unsigned char msg[2] ={'B', mvBackward()}; // back
      CAN.sendMsgBuf(0x01, 0, 2, msg);
      break;
    }
    case 76:{
      unsigned char msg[2] ={'L', 0};  //left
      CAN.sendMsgBuf(0x01, 0, 2, msg);
      break;
    }
    case 82:{
      unsigned char msg[2] ={'R', 0};  //right
      CAN.sendMsgBuf(0x01, 0, 2, msg);
      break;
    }
    case 87: fLightOn(); break;
    case 119: fLightOff(); break;
    case 85: bLightOn(); break;
    case 117: blightOff(); break;
    case 88: blinkOn(); break;
    case 120: blinkOff(); break;
    case 86: hornOn(); break;
    case 118: hornOff(); break;
    case 73:{
      unsigned char msg[2] ={'F', mvForward()}; // front
      CAN.sendMsgBuf(0x01, 0, 2, msg);
      unsigned char msg1[2] ={'R', 0};  //right
      CAN.sendMsgBuf(0x01, 0, 2, msg1);
      break;
    }
    case 74:{
      unsigned char msg[2] ={'B', mvBackward()}; // back
      CAN.sendMsgBuf(0x01, 0, 2, msg);
      unsigned char msg1[2] ={'R', 0};  //right
      CAN.sendMsgBuf(0x01, 0, 2, msg1);
      break;
    }
    case 72:{
      unsigned char msg[2] ={'B', mvBackward()}; // back
      CAN.sendMsgBuf(0x01, 0, 2, msg);
      unsigned char msg1[2] ={'L', 0};  //left
      CAN.sendMsgBuf(0x01, 0, 2, msg1);
      break;
    }
    case 71:{
      unsigned char msg[2] ={'F', mvForward()}; // front
      CAN.sendMsgBuf(0x01, 0, 2, msg);
      unsigned char msg1[2] ={'L', 0};  //left
      CAN.sendMsgBuf(0x01, 0, 2, msg1);
      break;
    }
    
    case 83: break;
    default: setSpeed(cmd); break;
    }
    
  }
}
