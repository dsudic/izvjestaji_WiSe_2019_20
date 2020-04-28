#include "Sensors.h"
#include <LowPower.h>
SENSORS sensor;

void setup() {
  Serial.begin(9600);
  sensor.DHT_init();
  sensor.BH1750_init();
}

void loop() {
  sensor.readTempHum();
  sensor.readLight();
  delay(50);
  int i = 0;
  while(i < 8){
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
  i++;
  }
  delay(50);
}
