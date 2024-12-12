/*
  SHTC3

  Programme basique sur Arduino Mega 
  Compileur : Visual Studio Code v1.95.3
  IDE : PlatformIO v3.3.3

  Programme fait par Adafruit
  Modifié par Mathis BENOIT

  Constituant : 
    - Carte Arduino Mega 
    - Module Adafruit Sensirion SHTC3

  version  : 1.3
  dernière modification : 12/12/2024


*/


#include <Arduino.h>            //Pas besoin d'utiliser la librairie Arduino.h, visiblement elle est intégré dans la librairie DHTC3
#include <SPI.h>
#include <Wire.h>
#include "Adafruit_SHTC3.h"       //On appelle la librairie SHTC3 d'Adafruit (constructeur du module utilisé)

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

  delay(1000);            //On attend 1s avant de refaire une mesure 
}