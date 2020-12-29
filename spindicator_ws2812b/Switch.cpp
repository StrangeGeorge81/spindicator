/**
 * General library to handle switches
 * 
*/

#ifndef SWITCH_h
#define SWITCH_h

#include "Arduino.h"

class Switch {
    private:
        int _pin;
        bool _status;

    public:
        Switch(int pin) {
            _pin = pin;
            pinMode(_pin, INPUT);
        }

        bool status() {
            return _status;
        }

        void update() {
            _status = digitalRead(_pin);
        }




};



#endif