/**
 * Handle the spindicator by extending the Adafruit_NeoPixel library
 * 
 * This way all the functions of the Adafruit_NeoPixel are availabe
 * in addition to more specialised functions.
 * 
*/

#ifndef SPINDICATOR_H
#define SPINDICATOR_H

#include <Adafruit_NeoPixel.h>
#include "Arduino.h"

class spindicator : public Adafruit_NeoPixel{
    private:

        Adafruit_NeoPixel pixels;
        uint32_t rgbcolor;

        byte first_pixel = 0;
        byte max_brght = 42;//initial goes up to 42 (not higher, too bright!!)

        int hue = 0;// HUE from 0 to 65535
        const byte frame_delay = 42;

        // bool start_spin = 0;// input to start
        // bool circle_hue = 0;// input to cycle the HUE

        // int swh = 0 ; // switch for circle left or right 
        // bool swh_btn = 0 ;// temp value to convert switch 2 button. TODO: fix this

        float dmr = 0;
        int strn = 0;
        /**
         *  dmr  : dimmer, controls the dimming. Conected to analog pin (goes from 0 to 1023)
         *  strn : saturation, goes from 0 to 255
         * 
         * The following equation connects the two variables
         * with dmr/255 <=> strn = dmr/4.0117647058823529 (fuck me, right?)
        */

       /**
        * Update the colors of the second and third pixel in the tail
        * 
        */
       void HSV_around(int second_pixel, int third_pixel){    
            rgbcolor = pixels.ColorHSV(hue, strn, brght);
            pixels.setPixelColor (first_pixel, rgbcolor);
            rgbcolor = pixels.ColorHSV(hue, strn, brght/2);
            pixels.setPixelColor (second_pixel, rgbcolor);
            rgbcolor = pixels.ColorHSV(hue, strn, brght/16);
            pixels.setPixelColor (third_pixel, rgbcolor);
            pixels.show();
        }

    public:
        byte brght = 0;

        /**
         * The constructor. Initialize the LED strip.
        */
        spindicator(byte NUMPIXELS, int PIXELS_PIN) {
            pixels.updateType(NEO_GRB + NEO_KHZ800);
            pixels.updateLength(NUMPIXELS);
            pixels.setPin(PIXELS_PIN);

            uint32_t rgbcolor = pixels.ColorHSV(0, 0, 0);

            pixels.clear();
            pixels.show();
        }

        /**
         * Move the tail of the spindicator one position to the left
        */
        void circlex3left (){
            if (first_pixel == -1 || first_pixel==12){                
                first_pixel = 11;
            }
            if (first_pixel==11){
                HSV_around(0, 1);
            }
            if (first_pixel==10){
                HSV_around(11, 0);
            }
            if (first_pixel!=11 && first_pixel!=10){
            HSV_around(first_pixel+1, first_pixel+2);
            }
            first_pixel--;
            delay (frame_delay);
            pixels.clear();    
        }

        /**
         * Move the tail of the spindicator one position to the right
        */
        void circlex3right (){
            if (first_pixel==12 || first_pixel== -1){                
                first_pixel = 0;
            }
            if (first_pixel==0){
                HSV_around(11, 10);
            }
            if (first_pixel==1){   
                HSV_around(0, 11);
            }
            if (first_pixel!=0 && first_pixel!=1){     
            HSV_around(first_pixel-1, first_pixel-2);
            }
            first_pixel++;
            delay (frame_delay);
            pixels.clear();
        }
        /**
         * TODO: make funkyColors() work
         * 
        */
        // void funkyColors (){
        //     if (cyrcleHue.status()){  
        //         hue=hue+255;
        //         // 65535/255=257 different colors!!!!
        //         //if you want more, do the math (HUE div)
        //     }
        //     if (hue==65535){   
        //         hue=0;
        //     }
        // }

};



#endif