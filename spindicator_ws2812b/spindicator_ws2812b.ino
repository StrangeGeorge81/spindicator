#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 12
#define PIN 8

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int nas = 0;
//NUMPIXELS 12 <=> 0 to 11
int brght = 0;
//initial goes up to 42 (not higher, too bright!!)
int funk = 0;
// funk from 0 to 65535
int delay_ = 42; //static
bool btn = 0;
bool btn2 = 0;
// buttons, btn for circle / btn2 for HUE
int swh = 0 ;
bool btn3 = 0 ;
// swh = switch for circle left or right
// btn3 contols swh
float dmr = 0;
int strn = 0;
/* 
*  dmr = dimmer, 255 = saturation
*  strn goes from 0 to 255
*  dmr goes from 0 to 1023
*  with dmr/255 <=> strn = dmr/4.0117647058823529 (fuck me, right?)
*/

uint32_t rgbcolor = pixels.ColorHSV(funk, strn, brght);

void HSV_around(int a, int b){    
    rgbcolor = pixels.ColorHSV(funk, strn, brght);
    pixels.setPixelColor (nas, rgbcolor);
    rgbcolor = pixels.ColorHSV(funk, strn, brght/2);
    pixels.setPixelColor (a, rgbcolor);
    rgbcolor = pixels.ColorHSV(funk, strn, brght/16);
    pixels.setPixelColor (b, rgbcolor);
    pixels.show();
}

void circlex3left (){
    if (nas == -1 or nas==12){                
        nas = 11;
    }
    if (nas==11){
        HSV_around(0, 1);
    }
    if (nas==10){
        HSV_around(11, 0);
    }
    if (nas!=11 && nas!=10){
       HSV_around(nas+1, nas+2);
    }
    nas--;
    delay (delay_);
    pixels.clear();    
}

void circlex3right (){
    if (nas==12 or nas== -1){                
        nas = 0;
    }
    if (nas==0){
        HSV_around(11, 10);
    }
    if (nas==1){   
        HSV_around(0, 11);
    }
    if (nas!=0 && nas!=1){     
       HSV_around(nas-1, nas-2);
    }
    nas++;
    delay (delay_);
    pixels.clear();
}

void switchbtn() {
    if (btn3 && swh==0){    
        swh = 1;
    }
    if (btn && swh==1){
        swh = 0;
    }
}

void funkyColors (){
    if (btn2){  
        funk=funk+255;
        // 65535/255=257 different colors!!!!
        //if you want more, do the math (HUE div)
    }
    if (funk==65535){   
        funk=0;
    }
}


void setup() {
    
    pixels.begin();
    pinMode (9, INPUT);
    pinMode (10, INPUT);
    pinMode (A5, INPUT);
    pinMode (11, INPUT);

    // BOOT Secuence!!!
/*
    int i=0;
    while (i<=12){
        for (i=1; i<=12; i++){            
            uint32_t colour = pixels.Color(i*20, i*20, i*20);

            pixels.setPixelColor (i, colour);
            pixels.setBrightness(42);
            pixels.show();
            delay(200);
        }
    }
    for (i=0; i<=3; i++){
        pixels.setBrightness(42);
        delay(21);
        pixels.setBrightness(5);
    }
    pixels.clear();
    
    // Might work,might not....
    */
}

void loop() {

    btn = digitalRead (9);
    btn2 = digitalRead(10);
    btn3 = digitalRead(11);
    dmr = analogRead (A5);
    strn = dmr / 4.0117647058823529;
    funkyColors();
    switchbtn();
    
    if (swh==0){
        if (btn) {
            brght=48;
            circlex3left();
        }
        brght=brght-3;            
        if (brght<0){
            brght=0;
        }
    }
    if (swh==1){
        if (btn){
            brght=48;
            circlex3right();
        }
        brght=brght-3;            
        if (brght<0){
            brght=0;
        }
    }
    
}