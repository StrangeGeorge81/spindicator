#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 12
#define PIN 8

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

/*      
*       pixels.setPixelColor(n, red, green, blue);
*       NUMPIXELS <=> nas 
*       rd/gr/bl/brght are stated from 0 to 255
*
*/
int nas = 11;
int brght = pinax;
int funk = brght/4;
int rd = pinax;
int gr = pinax;
int bl = pinax;
void circlex3left (){

    for (nas=11; nas>=0; nas--){

        if (nas==11){

            pixels.setBrightness(brght);
            pixels.setPixelColor (nas, rd, gr, bl);
            pixels.show();
            pixels.setBrightness(funk);
            pixels.setPixelColor (0, rd, gr, bl);
            pixels.show();
            pixels.setBrightness();
            pixels.setPixelColor (1, rd, gr, bl);
            pixels.show();
            pixels.clear();
            delay (281);

        }

        if (nas==10){
            
            pixels.setBrightness(brght);
            pixels.setPixelColor (nas, rd, gr, bl);
            pixels.show();
            pixels.setBrightness(funk);
            pixels.setPixelColor (11, rd, gr, bl);
            pixels.show();
            pixels.setBrightness(1);
            pixels.setPixelColor (0, rd, gr, bl);
            pixels.show();
            pixels.clear();
            delay (281);

        }

        if (nas!=11 and nas!=10){

            pixels.setBrightness(brght);
            pixels.setPixelColor (nas, rd, gr, bl);
            pixels.show();
            pixels.setBrightness(funk);
            pixels.setPixelColor (nas+1, rd, gr, bl);
            pixels.show();
            pixels.setBrightness(1);
            pixels.setPixelColor (nas+2, rd, gr, bl);
            pixels.show();
            pixels.clear();
            delay (281);

        }

    }
    
}


void setup() {
    
    pixels.begin();

}


void loop() {


}
