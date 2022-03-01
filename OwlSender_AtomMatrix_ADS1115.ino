#include "M5Atom.h"
#include <Wire.h>
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads1115;
int16_t adc0, adc1, adc2, adc3;
void setup(void)
{
  M5.begin();
  Wire.begin(26, 32);
  Serial.begin(115200);
  ads1115.begin();
  ads1115.setGain(GAIN_EIGHT);
}

void loop(void)
{
  adc0 = ads1115.readADC_SingleEnded(0);
  adc1 = ads1115.readADC_SingleEnded(1);
  adc2 = ads1115.readADC_SingleEnded(2);
  adc3 = ads1115.readADC_SingleEnded(3);
  Serial.print(adc0);
  Serial.print(",");
  Serial.print(adc1);
  Serial.print(",");
  Serial.print(adc2);
  Serial.print(",");
  Serial.println(adc3);
  Serial.flush();
}
