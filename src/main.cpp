//#include <Arduino.h>            //Pas besoin d'utiliser la librairie Arduino.h, visiblement elle est intégré dans la librairie DHTC3
#include "Adafruit_SHTC3.h"       //On appelle la librairie SHTC3 d'Adafruit

Adafruit_SHTC3 shtc3 = Adafruit_SHTC3();       //On créer un objet de classe SHTC3 qui s'appelle SHTC3

void setup() {
  Serial.begin(115200);         //Inititalisation du moniteur série

  while (!Serial)
    delay(10);     // On attend que le moniteur série s'ouvre

  Serial.println("SHTC3 test");
  if (! shtc3.begin()) {                  //On vérifie si on peut initialiser une conversation avec le DHTC3
    Serial.println("Couldn't find SHTC3");
    while (1) delay(1);
  }
  Serial.println("Found SHTC3 sensor");     
}


void loop() {
  sensors_event_t humidity, temp;         
  
  shtc3.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  
  Serial.print("Temperature: "); Serial.print(temp.temperature);      //On affiche la température
  Serial.println(" degrees C");    
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity);       //On affiche l'humidité relative
  Serial.println("% rH");

  delay(1000);            //On refait une mesure toutes les 1 secondes
}