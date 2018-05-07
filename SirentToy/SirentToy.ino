
#include <Adafruit_NeoPixel.h>

#define NUMPIXELS      8

const byte sound1PIN = 2;
const byte sound2PIN = 3;
const byte sound3PIN = 4;
const byte sound4PIN = 5;
const byte sound5PIN = 6;
const byte sound6PIN = 7;

const byte neoPixData = 8;

const byte switch1PIN = 10;
const byte switch2PIN = 11;
const byte switch3PIN = 12;

byte lightSwitchDelay = 700;
long lastSwitchTime = 0;

byte lightstep = 0;

Adafruit_NeoPixel lights = Adafruit_NeoPixel(NUMPIXELS, neoPixData, NEO_GRB + NEO_KHZ800);

void setup() {

  pinMode(neoPixData, OUTPUT);
  digitalWrite(neoPixData, LOW);

  pinMode(sound1PIN, OUTPUT);
  pinMode(sound2PIN, OUTPUT);
  pinMode(sound3PIN, OUTPUT);
  pinMode(sound4PIN, OUTPUT);
  pinMode(sound5PIN, OUTPUT);
  pinMode(sound6PIN, OUTPUT);

  digitalWrite(sound1PIN, HIGH);
  digitalWrite(sound2PIN, HIGH);
  digitalWrite(sound3PIN, HIGH);
  digitalWrite(sound4PIN, HIGH);
  digitalWrite(sound5PIN, HIGH);
  digitalWrite(sound6PIN, HIGH);

  pinMode(switch1PIN, INPUT_PULLUP);
  pinMode(switch2PIN, INPUT_PULLUP);
  pinMode(switch3PIN, INPUT_PULLUP);

  lights.begin();
  lights.show();

}

void loop() {

  lightStep();

  delay(700);

  if( (millis() - lastSwitchTime) > lightSwitchDelay) {
    
    //lastSwitchTime = millis();

    //lightStep();
    
  }

  if(switch1PIN) {
    // play siren
  }

}

void lightStep() {

  lights.setPixelColor(0, lights.Color(0,0,150));
  lights.setPixelColor(1, lights.Color(255,150,0));
  lights.setPixelColor(2, lights.Color(150,0,0));
  lights.setPixelColor(3, lights.Color(150,0,0));
  lights.setPixelColor(4, lights.Color(0,0,150));
  lights.setPixelColor(5, lights.Color(0,0,150));
  lights.setPixelColor(6, lights.Color(0,0,150));
  lights.setPixelColor(7, lights.Color(0,0,150));

  lights.show(); 

/**
  if(lightstep == 0) {
    for(int i = 0 ; i < 4 ; i++){
  
      lights.setPixelColor(i, lights.Color(150,0,0)); 

    }

    lightstep = 1;
  }

  if(lightstep == 1) {
    for(int i = 4 ; i < 8 ; i++){
  
      lights.setPixelColor(i, lights.Color(0,0,150)); 

    }

    lightstep = 0;
  }

  **/

}

