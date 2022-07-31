#include <Arduino.h>
#include <SoftwareSerial.h>

#define pinTest PB7     //pin 1
#define pinHALL PA13    //pin 7
#define _Serial SerialLP1

//SoftwareSerial _Serial(PA0, PA8);  //RX = pin 5  TX = pin 6  PA8 PA12
volatile int _counted = 0;
bool _led_state = false;
long _elapsed = 0;

void ISR_Hall(){
    _counted++;
}

void setup() {
    pinMode(pinHALL, INPUT_PULLUP);
    pinMode(pinTest , OUTPUT);
    digitalWrite(pinTest, HIGH);
    _Serial.begin(115200);  
   // attachInterrupt(digitalPinToInterrupt(pinHALL), ISR_Hall, FALLING);
}

void loop() {
    
    if (_Serial.available()){
        /*
        while (_Serial.available()){
            _Serial.read();
            delayMicroseconds(50);
        }
        */
        //_Serial.println("Received !");
    }
    
    if (millis() - _elapsed > 1000){
       // _Serial.println(_counted, DEC);
       // _Serial.println("Ok");
        _elapsed = millis();
        _counted = 0;
        if (_led_state){
            digitalWrite(pinTest, LOW);
            _led_state = false;
        }
        else{    
            digitalWrite(pinTest, HIGH);
            _led_state = true;
        }
    }
    delay(1);
}