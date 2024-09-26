#include <M5Atom.h>

bool monEtatLampe;

CRGB pixel; //let pixel = new CRGB();

void setup() {

  monEtatLampe = false;
  // put your setup code here, to run once:
  M5.begin(false,false,false);
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(&pixel, 1);
  pixel = CRGB(255,255,255);
  FastLED.show();

    if(monEtatLampe == true() ) { 
    pixel = CRGB(255,0,245);
    } else {
      pixel = CRGB(0,0,0);
    }
    FastLED.show();

  unsigned long chronoDepart = millis();
  while( millis() <= 5000) {
  pixel = CRGB(255,0,255);
  FastLED.show();
  delay(200);

  pixel = CRGB(0,0,0);
  FastLED.show();
  delay(100);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  M5.update();

/*
    if(M5.Btn.wasPressed()) {
      if(monEtatLampe == true){
        monEtatLampe == false;
       } else if (monEtatLampe == false) {
        monEtatLampe = true;
       }
    }
*/
    if (M5.Btn.wasPressed()) {
      monEtatLampe = !monEtatLampe;
    }

    if ( monEtatLampe ) {
 monEtatLampe = false; // si monEtatLampe est vrai, monEtatLampe devient faux
} else {
 monEtatLampe = true; // sinon (i.e. monEtatLampe est faux), monEtatLampe devient vrai
}
if ( monEtatLampe ) {
    pixel = CRGB(255,255,255); 
} else {
    pixel = CRGB(0,0,0); 
}
FastLED.show();

}



