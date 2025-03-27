#include <Arduino.h>
#include <LiquidCrystal.h>

const int rs = 3, e = 4, d4 = 6, d5 = 7, d6 = 8, d7 = 9;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
const int pump[] = {10, 11, 12};
const int sens[] = {0, 1, 2};
int val[sizeof(sens)];

const int pumptime = 1000;
const int pumpval = 500;

void setup()
{
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  for (int i = 0; i < 3; i++)
  {
    pinMode(pump[i], OUTPUT);
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  /*
  int val[0] = analogRead(sens[0]);
  int val[1] = analogRead(sens[1]);
  int val[2] = analogRead(sens[2]);
*/
  for (int i = 0; i < 3; i++)
  {
    val[i] = analogRead(sens[i]);
  }

  lcd.setCursor(0, 0);
  lcd.print(val[0]);
  lcd.setCursor(5, 0);
  lcd.print(val[1]);
  lcd.setCursor(10, 0);
  lcd.print(val[2]);

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
