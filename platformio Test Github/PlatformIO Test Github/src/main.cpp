#include <Arduino.h>

const int pump[] = {7, 8};
const int sens[] = {2, 5};
const int nop = sizeof(sens); // number of pots(pumps and senors)
int val[nop];

const long pumptime = 100000;
const int pumpdivider = 2;

const int pumpval = 500;

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
        delay(pumptime);
      }
      /*
      digitalWrite(pump[i], LOW);
      delay(pumptime);
      digitalWrite(pump[i], HIGH);
      delay(pumptime);
      digitalWrite(pump[i], LOW);
      delay(pumptime);

    }
    digitalWrite(pump[i], HIGH);
    */
    }
  }

  delay(10000);
}
