#include <SoftwareSerial9.h>

#define TX1 4
#define RX1 5
#define TX2 6
#define RX2 7

SoftwareSerial9 wheel1(RX1, TX1);
SoftwareSerial9 wheel2(RX2, TX2);

const byte statuses[] = {0x55, 0xAA}; //[unlocked, immobile]
signed int speed1 = 0, speed2 = 0;
bool immobile = 0;
unsigned long lastUpdate = 0;

void setWheelSpeed(signed int spd1, signed int spd2) {
  speed1 = spd1;
  speed2 = spd2;
}

void updateWheelSpeed() {
  wheel1.write9(0x100);                   //initialization of data packet
  wheel1.write9(speed1 & 0xFF);           //send low byte
  wheel1.write9((speed1 >> 8) & 0xFF);    //send high byte
  wheel1.write9(speed1 & 0xFF);           //repeat low byte
  wheel1.write9((speed1 >> 8) & 0xFF);    //repeat high byte
  wheel1.write9(statuses[immobile]);      //send immobile state
  //same thing for the second wheel
  wheel2.write9(0x100);                   //initialization of data packet
  wheel2.write9((-speed2) & 0xFF);        //send low byte
  wheel2.write9(((-speed2) >> 8) & 0xFF); //send high byte
  wheel2.write9((-speed2) & 0xFF);        //repeat low byte
  wheel2.write9(((-speed2) >> 8) & 0xFF); //repeat high byte
  wheel2.write9(statuses[immobile]);      //send immobile state
  delayMicroseconds(300);
  lastUpdate = millis();
}

void setup() {
  // put your setup code here, to run once:
  wheel1.begin(26315);
  wheel2.begin(26315);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  updateWheelSpeed();
}
