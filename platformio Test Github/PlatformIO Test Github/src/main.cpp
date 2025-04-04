#include <Arduino.h>

const int pump[] = {6, 7, 8};
const int sens[] = {0, 2, 5};
int val[sizeof(sens)];

const long pumptime = 160000;
const int pumpval = 500;

void setup()
{
  for (int i = 0; i < 3; i++)
  {
    pinMode(pump[i], OUTPUT);
    digitalWrite(pump[i], HIGH);
  }
}

void loop()
{
  for (int i = 0; i < 3; i++)
  {
    val[i] = analogRead(sens[i]);
  }

  for (int i = 0; i < 3; i++)
  {
    if (val[i] >= pumpval)
    {
      digitalWrite(pump[i], LOW);
      delay(pumptime);
    }
    digitalWrite(pump[i], HIGH);
  }

  delay(10000);
}
