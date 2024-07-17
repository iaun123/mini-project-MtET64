#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

void set_lcd()
{
  lcd.begin();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("status");
  lcd.setCursor(0, 1);
  lcd.print("address1");
  lcd.setCursor(0, 2);
  lcd.print("address2");

  lcd.setCursor(9, 1);
  lcd.print("0");
  lcd.setCursor(9, 2);
  lcd.print("0");

  lcd.setCursor(7, 0);
  lcd.print("start");

  lcd.setCursor(0, 3);
  lcd.print("plase put the box");
}

void down() {
  lcd.setCursor(0, 3);
  lcd.print("                   ");
  delay(100);
  lcd.setCursor(0, 3);
  lcd.print("plase put the box");
}

void work() {
  lcd.setCursor(0, 3);
  lcd.print("                   ");
  delay(100);
  lcd.setCursor(0, 3);
  lcd.print("working");
}
