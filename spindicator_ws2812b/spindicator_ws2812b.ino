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
int brght = 50;
int funk = brght/4;
int rd = 0;
int gr = 0;
int bl = 0;
int delay_ = 100;

uint32_t rgbcolor = pixels.ColorHSV(0, 255, brght);

void circlex3left (){

    for (nas=11; nas>=0; nas--){

        if (nas==11){

            rgbcolor = pixels.ColorHSV(0, 255, brght);
            pixels.setPixelColor (nas, rgbcolor);

            rgbcolor = pixels.ColorHSV(0, 255, brght/2);
            pixels.setPixelColor (0, rgbcolor);

            rgbcolor = pixels.ColorHSV(0, 255, brght/brght);
            pixels.setPixelColor (1, rgbcolor);

            pixels.show();

        }

        if (nas==10){
            
            rgbcolor = pixels.ColorHSV(0, 255, brght);
            pixels.setPixelColor (nas, rgbcolor);
            
            rgbcolor = pixels.ColorHSV(0, 255, brght/2);
            pixels.setPixelColor (11, rgbcolor);
            
            rgbcolor = pixels.ColorHSV(0, 255, brght/brght);
            pixels.setPixelColor (0, rgbcolor);

            pixels.show();

        }

        if (nas!=11 and nas!=10){

            rgbcolor = pixels.ColorHSV(0, 255, brght);
            pixels.setPixelColor (nas, rgbcolor);
            
            rgbcolor = pixels.ColorHSV(0, 255, brght/2);
            pixels.setPixelColor (nas+1, rgbcolor);
            
            rgbcolor = pixels.ColorHSV(0, 255, brght/brght);
            pixels.setPixelColor (nas+2, rgbcolor);

            pixels.show();

        }


        delay (delay_);
        pixels.clear();

    }
    
}

// byte bright = 0;
// uint32_t rgbcolor = pixels.ColorHSV(0, 255, bright);

// while(1){
//     pixels.fill(rgbcolor);
//     pixels.show();
//     bright += 1;
//     rgbcolor = pixels.ColorHSV(0, 255, bright);
//     delay(200);
// }

void setup() {
    
    pixels.begin();

}


void loop() {
    circlex3left();

}
