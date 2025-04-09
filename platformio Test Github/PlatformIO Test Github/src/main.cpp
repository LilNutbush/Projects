#include <Arduino.h>

const int pump[] = {6, 7, 8}; // pumpen stecker
const int sens[] = {0, 2, 5}; // sensor stecker
const int nop = sizeof(sens); // anzahl an pflanzen(nop = number of pots)
int val[nop];                 // variable für sensorwerte

const long pumptime = 100000; // gesamte gießzeit
const int pumpdivider = 15;   // Aufteilung der gießzeit
const long pumpwait = 60000;

const int pumpval = 500; // Schwellwert für sensor

void setup()
{
  for (int i = 0; i < nop; i++)
  {
    pinMode(pump[i], OUTPUT);
    digitalWrite(pump[i], HIGH);
  }
}

void loop()
{
  for (int i = 0; i < nop; i++)
  {
    val[i] = analogRead(sens[i]);
  }

  for (int i = 0; i < nop; i++)
  {
    if (val[i] >= pumpval)
    {
      for (int x = 0; x < pumpdivider; x++)
      {
        digitalWrite(pump[i], LOW);
        delay(pumptime / pumpdivider);
        digitalWrite(pump[i], HIGH);
        delay(pumpwait);
      }
    }
  }

  delay(10000);
}
