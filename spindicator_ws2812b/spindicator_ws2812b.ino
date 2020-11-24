#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 12
#define PIN 8

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    pixels.begin();
    // pixels.clear();
    // pixels.show();
}


void loop() {
    uint32_t colour = pixels.Color(255, 0, 0);
    int initial_bright = 0;
    int last_bright = 255;
    int step = 1;
    int delay_ = 1;
    
    for (int i=initial_bright; i<=last_bright; i=i+step){
        pixels.fill(colour);
        pixels.setBrightness(i);
        pixels.show();
        delay(delay_);
    }
    for (int i=last_bright; i>=initial_bright; i=i-step){
        pixels.fill(colour);
        pixels.setBrightness(i);
        pixels.show();
        delay(delay_);
    }

}