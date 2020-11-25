#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 12
#define PIN 8

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

/*      
*       pixels.setPixelColor(n, red, green, blue);
*       n = NUMPIXELS <=> nas (0 to 11)
*       rgb stated from 0 to 100
*/

void setup() {
    
    pixels.begin();

}


void loop() {

    for (int nas=11; nas>=0; nas--){

        if (nas==11){

            pixels.setBrightness(80);
            pixels.setPixelColor (nas, 100, 64, 255);
            pixels.show();
            delay(11);
            pixels.setBrightness(40);
            pixels.setPixelColor (0, 100, 64, 255);
            pixels.show();
            delay(11);
            pixels.setBrightness(1);
            pixels.setPixelColor (1, 100, 255, 64);
            pixels.show();
            delay(11);
            pixels.clear();
            delay (68);

        }

        if (nas==10){
            
            pixels.setBrightness(80);
            pixels.setPixelColor (nas, 100, 64, 255);
            pixels.show();
            delay(11);
            pixels.setBrightness(40);
            pixels.setPixelColor (11, 100, 64, 255);
            pixels.show();
            delay(11);
            pixels.setBrightness(1);
            pixels.setPixelColor (0, 100, 255, 64);
            pixels.show();
            delay(11);
            pixels.clear();
            delay (68);

        }

        if (nas!=11 and nas!=10){

            pixels.setBrightness(80);
            pixels.setPixelColor (nas, 100, 64, 255);
            pixels.show();
            delay(11);
            pixels.setBrightness(40);
            pixels.setPixelColor (nas+1, 100, 64, 255);
            pixels.show();
            delay(11);
            pixels.setBrightness(1);
            pixels.setPixelColor (nas+2, 100, 255, 64);
            pixels.show();
            delay(11);
            pixels.clear();
            delay (68);

        }

    }

}