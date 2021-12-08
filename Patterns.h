#ifndef PATTERNS_H
#define PATTERNS_H
#include <FastLED.h>


// --------------------------------------------------------------------------------
// 3 November 2021, Tim Hyde
// Pattern header file for light system. 
// The intention is that this file will be used by all of the NODEMCU modules 
// --------------------------------------------------------------------------------


DEFINE_GRADIENT_PALETTE(Sunset_Real_gp){
  0, 120, 0, 0,
  22, 179, 22, 0,
  51, 255, 104, 0,
  85, 67, 22, 18,
  135, 100, 0, 103,
  198, 16, 0, 130,
  255, 0, 0, 160
};

CRGBPalette16 sunset = Sunset_Real_gp;

DEFINE_GRADIENT_PALETTE(ib06_gp) {
    0,   0, 14,  6,
    0,   8,  8,  3,
    0,  51, 88, 27,
    0,  30, 66, 33,
    5,  28, 63, 31,
   38,   1, 28,  4,
   79,   4, 44, 12,
  101,  39,122, 75,
  130,   0, 30,  9,
  158,  50,127,115,
  178,   1, 50, 21,
  188,  24, 70, 51,
  211,   1,  4,  1,
  219,   0, 44,  8,
  242,  39,122, 75,
  255,   1, 18,  7
};

CRGBPalette16 p2 = ib06_gp;

// --------------------------------------------------------------------------------

int wait (int a){
  EVERY_N_MILLISECONDS(a){
    return 0;
  }
}

void brightness(int n){

  if (n == 1){
    Serial.println(brightnessString);
    FastLED.setBrightness(20);
    Serial.println("setting to 20");
  }
  else if (n == 2){
    FastLED.setBrightness(60);
    Serial.println("setting to 60");
  }
  else if (n == 3){
    FastLED.setBrightness(120);
    Serial.println("setting to 120");
  }
  else if (n == 4){
    FastLED.setBrightness(200);
    Serial.println("setting to 120");
  }
  
}

void test1(){

  for (int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::Red;
  }
  FastLED.show();
}

void test2(){

  for (int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::Blue;
  }
  
  FastLED.show();
}

void test3(){
   fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16(13, 0, NUM_LEDS - 1);
  leds[pos] += CHSV(0, 255, 192);
  FastLED.show();
  int pos2 = beatsin16(15, 0, NUM_LEDS - 1);
  leds[pos2] += CRGB::Blue;
  int pos3 = beatsin16(17, 0, NUM_LEDS - 1);
  leds[pos3] += CRGB::Green;
  
  FastLED.show();
}

void off1(){
  for (int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::Black;
  }
  
  FastLED.show();
}

void newPattern(){

    for (int i = 0; i < NUM_LEDS; i++){
      leds[i] = CHSV(hue + (i * 10), 255, 255);
    }
    
    EVERY_N_MILLISECONDS(15){
      hue++;
    }
    
    FastLED.show();
}

void newPattern2(){

   for (int i = 0; i < NUM_LEDS; i++){
    leds[i] = ColorFromPalette(sunset, colorIndex[i]);
  }

  FastLED.show();

  EVERY_N_MILLISECONDS(20){
     for (int i = 0; i < NUM_LEDS; i++){
      colorIndex[i]++;
     }
  }

  FastLED.show();
}

void newPattern3(){

    for (int i = 0; i < NUM_LEDS; i++){
        leds[i] = CRGB::Black;
    }

    for (int i = 8; i < 16; i++){  
      leds[i] = CRGB::Chocolate;
    }
    
   FastLED.show();
}

void chocolate(){

  for (int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::Chocolate;
  }
  
  FastLED.show();
}

void rainbowFill(){

  int randomled = random(0, NUM_LEDS - 1);
      
  for (int i = 0; i < NUM_LEDS; i++){
      leds[randomled] = CHSV(random8(),255,255);
      wait(2000);
      FastLED.show();
  }
}

void new1(){

  for (int i = 0; i < NUM_LEDS; i++){
    leds[i] = ColorFromPalette(sunset, colorIndex[i]);
  }

  FastLED.show();

  EVERY_N_MILLISECONDS(50){
     for (int i = 0; i < NUM_LEDS; i++){
      colorIndex[i]++;
     }
  }
  
}

void new2(){

  for (int i = 0; i < NUM_LEDS; i++){
    leds[i] = ColorFromPalette(p2, colorIndex[i]);
  }

  FastLED.show();

  EVERY_N_MILLISECONDS(50){
     for (int i = 0; i < NUM_LEDS; i++){
      colorIndex[i]++;
     }
  }

}

CRGBPalette16 currentPalette(Sunset_Real_gp);
CRGBPalette16 targetPalette(ib06_gp);

void blend23(){
  
  EVERY_N_MILLIS(10) {
    nblendPaletteTowardPalette(currentPalette, targetPalette, 48);          // Blend towards the target palette over 48 iterations.
  }
  FastLED.show();
}

void blend32(){

  EVERY_N_MILLIS(10) {
    nblendPaletteTowardPalette(targetPalette, currentPalette, 48);          // Blend towards the target palette over 48 iterations.
  }
  FastLED.show();
  
}

void new3(){

  for (int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::Pink;
  }
  
  
}

#endif
