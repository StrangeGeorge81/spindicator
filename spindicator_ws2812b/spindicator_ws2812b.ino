#include "btn.cpp"
#include "Switch.cpp"
#include "pot.cpp"
#include "spindicator.cpp"

#define NUMPIXELS 12//NUMPIXELS 12 <=> 0 to 11
#define PIXELS_PIN 8

#define START_SPINNING_BTN_PIN 9
#define CIRCLE_HUE_BTN_PIN 10
#define SWITCH_SPIN_DIRECTION_SWITCH_PIN 11
#define POTENTIOMETER_PIN A5


int first_pixel = 0;
int brght = 0;
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

// uint32_t rgbcolor = pixels.ColorHSV(hue, strn, brght);
btn spinBtn(START_SPINNING_BTN_PIN);
btn cyrcleHue(CIRCLE_HUE_BTN_PIN);
Switch switchDir(SWITCH_SPIN_DIRECTION_SWITCH_PIN);
pot hue_pot(POTENTIOMETER_PIN);
spindicator spinD(NUMPIXELS, PIXELS_PIN);
uint32_t rgbcolor = spinD.ColorHSV(hue, strn, brght);

void HSV_around(int second_pixel, int third_pixel){    
    rgbcolor = spinD.ColorHSV(hue, strn, brght);
    spinD.setPixelColor (first_pixel, rgbcolor);
    rgbcolor = spinD.ColorHSV(hue, strn, brght/2);
    spinD.setPixelColor (second_pixel, rgbcolor);
    rgbcolor = spinD.ColorHSV(hue, strn, brght/16);
    spinD.setPixelColor (third_pixel, rgbcolor);
    spinD.show();
}

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
    spinD.clear();    
}

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
    spinD.clear();
}

void funkyColors (){
    if (cyrcleHue.status()){  
        hue=hue+255;
        // 65535/255=257 different colors!!!!
        //if you want more, do the math (HUE div)
    }
    if (hue==65535){   
        hue=0;
    }
}


void setup() {
    
    spinD.begin();
    spinD.clear();
    spinD.show();

    // BOOT Secuence!!!
/*
    for (int i=0; i<=11; i++){            
        uint32_t colour = pixels.Color((i+1)*20, (i+1)*20, (i+1)*20);

        pixels.setPixelColor (i, colour);
        pixels.setBrightness(42);
        pixels.show();
        delay(81);
    }
    for (int i=42; i<102; i=i+3){
       pixels.setBrightness(i);
       pixels.show();
       delay(10); 
    }
    for (int i=0; i<=3; i++){
        pixels.setBrightness(102);
        pixels.show();
        delay(21);
        pixels.setBrightness(41);
        pixels.show();
        delay(10);

    }
    pixels.clear();
    */
    // Might work,might not....
    
}

void loop() {
    
    strn = hue_pot.value() / 4.0117647058823529;

    funkyColors();
    switchDir.update();
    
    if (switchDir.status()){
        if (spinBtn.status()) {
            brght=48;
            circlex3left();
        }
        else{
            brght=brght-3;            
            if (brght<0){
                brght=0;
            }
        }
    }
    if (switchDir.status()){
        if (spinBtn.status()){
            brght=48;
            circlex3right();
        }
        else{
            brght=brght-3;            
            if (brght<0){
                brght=0;
            }
        }
    }

}