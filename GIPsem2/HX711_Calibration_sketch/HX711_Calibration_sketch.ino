// Calibrating the load cell
#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 6;
const int LOADCELL_SCK_PIN = 7;
int i = 1;

HX711 scale;

void setup() {
  Serial.begin(57600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {

  if (scale.is_ready() && i == 1) {
    scale.set_scale();    
    Serial.println("Tare... remove any weights from the scale.");
    delay(10000);
    scale.tare();
    Serial.println("Tare done...");
    Serial.print("Place a known weight on the scale...");
    delay(10000);
    long reading = scale.get_units(10);
    Serial.print("Result: ");
    Serial.println(reading);
    i += 1;
  } 
  /*else {
    Serial.println("HX711 not found.");
  }
  delay(1000);*/
}

//calibration factor will be the (reading)/(known weight)