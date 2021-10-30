#include <SPI.h> 
#include "mcp2515_can.h"
#include "Move.h"
// Set SPI CS Pin according to your hardware

const int SPI_CS_PIN = 10;
const int CAN_INT_PIN = 2;

mcp2515_can CAN(SPI_CS_PIN); // Set CS pin  

void setup() {
    pinMode(EN_wheel, OUTPUT);
    pinMode(wheelA, OUTPUT);
    pinMode(wheelB, OUTPUT);
    pinMode(EN_steering, OUTPUT);
    pinMode(steeringA, OUTPUT);
    pinMode(steeringB, OUTPUT);

    digitalWrite(wheelA, LOW);
    digitalWrite(wheelB, LOW);
    digitalWrite(steeringA, LOW);
    digitalWrite(steeringB, LOW);

  
    Serial.begin(9600);
    
    while(!Serial){};

    while (CAN_OK != CAN.begin(CAN_500KBPS)) {             // init can bus : baudrate = 500k
        Serial.println("CAN init fail, retry...");
        delay(100);
    }
    Serial.println("CAN init ok!");
    delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
    unsigned char len = 0;
    unsigned char buf[2];
  if (CAN_MSGAVAIL == CAN.checkReceive()) {         // check if data coming
      CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
      if(buf[0]=='F'){
        if(buf[1]=='M')mvForward(10);
        else mvForward(buf[1]);
      }
      else if(buf[0]=='B'){
        if(buf[1]=='M')mvBackward(10);
        else mvBackward(buf[1]);
      }
      else if(buf[0]=='L'){
        mvLeft();
      }
      else if(buf[0]=='R'){
        mvRight();
      }
  }
  else stop();
  

}
