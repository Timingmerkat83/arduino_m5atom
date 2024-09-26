#include <M5Atom.h>

CRGB pixel; //let pixel = new CRGB();

void setup() {
  // put your setup code here, to run once:
  M5.begin(false,false,false);
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(&pixel, 1);
  pixel = CRGB(255,255,255);
  FastLED.show();

  while( millis() <= 5000) {
  pixel = CRGB(255,0,255);
  FastLED.show();
  delay(200);

  pixel = CRGB(0,0,0);
  FastLED.show();
  delay(100);
  }
  
  pixel = CRGB(0,0,0);
  FastLED.show();

}

void loop() {
  // put your main code here, to run repeatedly:
  M5.update();

  if (millis() - chronoDepart >= 1000 ) {
    chronoDepart = millis();
    // A CHAQUE SECONDE
  }
}



