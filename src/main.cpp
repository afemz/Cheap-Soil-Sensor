#include <Arduino.h>

/*	Arduino Tutorial - How to use a Soil Hygrometer Module
  Dev: Michalis Vasilakis // Date: 18/05/2016 // www.ardumotive.com	*/

// Constants
const int hygrometer = 13; // Hygrometer sensor analog pin output at pin A0 of Arduino
// Variables
int value;

void setup()
{

  Serial.begin(9600);
  pinMode(hygrometer, INPUT);
}

void loop()
{

  // When the plant is watered well the sensor will read a value 380~400, I will keep the 400
  // value but if you want you can change it below.

  value = analogRead(hygrometer);        // Read analog value
  value = constrain(value, 400, 1023);   // Keep the ranges!
  value = map(value, 400, 1023, 0, 100); // Map value : 400 will be 100 and 1023 will be 0
  Serial.print("Soil humidity: ");
  Serial.print(value);
  Serial.println("%");
  delay(500); // Read every 2 sec.
}