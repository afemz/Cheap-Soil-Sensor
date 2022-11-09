#include <Arduino.h>

/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com
*********/

#include <OneWire.h>
#include <DallasTemperature.h>

// GPIO where the DS18B20 is connected to
#define ONE_WIRE_BUS 4
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);

float suhu;

void setup()
{
  // Start the Serial Monitor
  Serial.begin(9600);
  // Start the DS18B20 sensor
  sensors.begin();
}

void loop()
{
  sensors.setResolution(12);
  sensors.requestTemperatures();
  suhu = sensors.getTempCByIndex(0);
  Serial.println(suhu, 4);
}
