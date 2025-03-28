#include <Arduino.h>
#include <LiquidCrystal.h>

const int pump[] = {5, 6, 7};
const int sens[] = {0, 1, 2};
int val[sizeof(sens)];

const int pumptime = 160000;
const int pumpval = 500;

void setup()
{
  for (int i = 0; i < 3; i++)
  {
    pinMode(pump[i], OUTPUT);
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
      digitalWrite(pump[i], HIGH);
      delay(pumptime);
    }
    digitalWrite(pump[i], LOW);
  }

  delay(500);
}
