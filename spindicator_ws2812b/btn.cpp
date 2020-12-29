/**
 * General library to handle buttons
 * 
*/

#ifndef BTN_h
#define BTN_h

#include "Arduino.h"

class btn {
    private:
        int _pin;

    public:
        btn(int pin) {
            _pin = pin;
            pinMode(_pin, INPUT);
        }

        bool status() {
            return digitalRead(_pin);
        }




};



#endif