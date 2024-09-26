
#include <M5Atom.h> // Inclure la librairie M5 (version pour M5Atom) https://github.com/m5stack/M5Atom
CRGB pixel; 
unsigned long monChronoMessages; // Utilisé dans loop() plus bas pour limiter la vitesse d'envoi des messages
#define MA_BROCHE_ANGLE 32

#include <MicroOscSlip.h>

MicroOscSlip<128> monOsc(&Serial);

void setup() {
  M5.begin(false, false, false); // Démarrer la libraire M5 avec toutes les options désactivées
  Serial.begin(115200); // Démarrer la connexion sérielle avec l'ordinateur
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(&pixel, 1); // Ajouter le pixel du M5Atom à FastLED

  // Animation de démarrage
  while ( millis() < 5000) {
    // Allumer le pixel et attendre 100 millisecondes
    pixel = CRGB(255,255,255);
    FastLED.show();
    delay(100);
    // Éteindre le pixel et attendre 100 millisecondes
    pixel = CRGB(0,0,0);
    FastLED.show();
    delay(100);
  } 
}

void loop() {
  M5.update();  // Toujours inclure M5.update() au début de loop()
  if ( millis() - monChronoMessages >= 50 ) { // Si 50 millisecondes se sont écoulées
    monChronoMessages = millis(); // Repartir le compteur
    bool maLectureBouton = M5.Btn.isPressed();
    int maLectureAngle = analogRead(MA_BROCHE_ANGLE);
    Serial.println(maLectureAngle);
    Serial.print("");
    Serial.println(maLectureAngle);

    // Ajouter les messages à envoyer ici

  }
}
