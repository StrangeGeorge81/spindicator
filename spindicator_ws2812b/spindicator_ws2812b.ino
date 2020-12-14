#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 12
#define PIN 8

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int nas = 11;
//NUMPIXELS 12 <=> 0 to 11

int brght = 0;
//initial goes up to 48 (not higher, too bright!!)

int funk = 0;
// funk from 0 to 65535

int delay_ = 42; //static

bool btn = 0;
bool btn2 = 0;
// buttons, btn for circle / btn2 for HUE

uint32_t rgbcolor = pixels.ColorHSV(funk, 255, brght);

void HSV_around(int a, int b){
        
    rgbcolor = pixels.ColorHSV(funk, 255, brght);
    pixels.setPixelColor (nas, rgbcolor);

    rgbcolor = pixels.ColorHSV(funk, 250, brght/2);
    pixels.setPixelColor (a, rgbcolor);

    rgbcolor = pixels.ColorHSV(funk, 240, brght/16);
    pixels.setPixelColor (b, rgbcolor);

    pixels.show();

}

void circlex3left (){

    if (nas==11){

        HSV_around(0, 1);

    }

    if (nas==10){
        
        HSV_around(11, 0);

    }

    if (nas!=11 && nas!=10){

       HSV_around(nas+1, nas+2);

    }

    delay (delay_);
    pixels.clear();
    
}

void funkyColors (){

    if (btn2){
        
        funk=funk+255;
        // 65535/255=257 different colors!!!!
        //if you want more do the math (HUE div)
    }

    if (funk==65535){
        
        funk=0;

    }

}


void setup() {
    
    pixels.begin();
    pinMode (9, INPUT);
    pinMode (10, INPUT);

}

void loop() {

    btn = digitalRead (9);
    btn2 = digitalRead(10);
    funkyColors();
    
    if (btn) {

        brght=48;

        circlex3left();

        nas--;

        if (nas<0){
            
            nas = 11;
        }
    }
    
    brght=brght-3;
    
    if (brght<0){
        
        brght=0;

    }

    circlex3left();

}
