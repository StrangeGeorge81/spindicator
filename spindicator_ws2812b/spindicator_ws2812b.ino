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



// uint32_t rgbcolor = pixels.ColorHSV(hue, strn, brght);
btn spinBtn(START_SPINNING_BTN_PIN);
btn cyrcleHue(CIRCLE_HUE_BTN_PIN);
Switch switchDir(SWITCH_SPIN_DIRECTION_SWITCH_PIN);
pot hue_pot(POTENTIOMETER_PIN);
spindicator spinD(NUMPIXELS, PIXELS_PIN);



void setup() {
    
    spinD.begin();
    spinD.clear();
    spinD.show();

    // TODO: Finish the boot sequence
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
    
    // strn = hue_pot.value() / 4.0117647058823529;
    // funkyColors();

    switchDir.update();
    
    if (switchDir.status()){
        if (spinBtn.status()) {
            spinD.brght=48;
            spinD.circlex3left();
        }
        else{
            spinD.brght=spinD.brght-3;            
            if (spinD.brght<0){
                spinD.brght=0;
            }
        }
    }
    if (switchDir.status()){
        if (spinBtn.status()){
            spinD.brght=48;
            spinD.circlex3right();
        }
        else{
            spinD.brght=spinD.brght-3;            
            if (spinD.brght<0){
                spinD.brght=0;
            }
        }
    }

}