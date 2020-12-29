/**
 * Handle the spindicator by extending the Adafruit_NeoPixel library
 * 
 * This way all the functions of the Adafruit_NeoPixel are availabe
 * in addition to more specialised functions
 * 
*/

#ifndef SPINDICATOR_H
#define SPINDICATOR_H

#include <Adafruit_NeoPixel.h>
#include "Arduino.h"

class spindicator : public Adafruit_NeoPixel{
    private:

        Adafruit_NeoPixel pixels;

    public:
        spindicator(byte NUMPIXELS, int PIXELS_PIN) {
            // NUMPIXELS, PIXELS_PIN, NEO_GRB + NEO_KHZ800
            pixels.updateType(NEO_GRB + NEO_KHZ800);
            pixels.updateLength(NUMPIXELS);
            pixels.setPin(PIXELS_PIN);
        }


};



#endif