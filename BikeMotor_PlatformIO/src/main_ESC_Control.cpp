#include <Arduino.h>
#include "ESC/VescUart.h"

long _elapsed= 0;
VescUart _ESC;

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  //_ESC.setSerialPort(&Serial1);
  //_ESC.setDebugPort(&Serial);
}

char _read;
double _duty = 0;
double _duty_ramp;
bool _noDuty = true;
void loop() {
  
  while (Serial1.available()){
    Serial.write(Serial1.read());
    delayMicroseconds(25);
  }

  if (millis() - _elapsed > 1000){
    Serial.println("loop");
    Serial1.print("test");
    _elapsed = millis();
  }  
  /*
  if (Serial.available()){
    _read = Serial.read();
    switch (_read)
    {
    case 'A':
      //_ESC.setDuty(0.250);
      _duty = 0.25;
      _duty_ramp = 0.1;
      break;
    case 'B':
      _duty = 0;
      _duty_ramp = 0;
      //_ESC.setDuty(0);
      break;
    default:
      break;
    }
    _noDuty = false;
  }
 
  if (!_noDuty){
    _ESC.setDuty(_duty_ramp);
    _noDuty = (_duty == 0);
  }

  while (_duty_ramp < _duty){
    _duty_ramp += 0.01;
    Serial.println(_duty_ramp, 2);
  }

  if (millis() - _elapsed > 1000){
    _ESC.getVescValues();
    Serial.print("RPM : ");
    Serial.println(_ESC.data.rpm / 6.95, 0);
    Serial.print("Amp Motor : ");
    Serial.println(_ESC.data.avgMotorCurrent, 1);
    Serial.print("Amp Input : ");
    Serial.println(_ESC.data.avgInputCurrent, 1);
    _elapsed = millis();
  }
  delay(100);
  */
}