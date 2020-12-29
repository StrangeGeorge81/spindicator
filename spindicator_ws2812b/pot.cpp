/**
 * General library to handle potentiometers
 * 
*/

#ifndef POT_H
#define POT_H

#include "Arduino.h"

class pot {
    private:
        int _pin;

    public:
        pot(int pin) {
            _pin = pin;
            pinMode(_pin, INPUT);
        }

        bool value() {
            return analogRead(_pin);
        }

};



#endif