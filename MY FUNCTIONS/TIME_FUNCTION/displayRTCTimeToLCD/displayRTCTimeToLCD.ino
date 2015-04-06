#include <DS1307RTC.h>
#include <Time.h>
#include <LiquidCrystal.h>
#include <Wire.h>


tmElements_t tm;
LiquidCrystal lcd(7, 6, 5, 8, 3, 2);


void setup() {
  Serial.begin(19200);
  initLCD();
}

void loop() {

  displayRTCTimeToLCD(tm, false);
}

void initLCD() {

  lcd.begin(16, 2);

}

void displayRTCTimeToLCD(tmElements_t tm, boolean tformat) {
  ////////////////////////////////////////

  ////////////////////////////////////////
  RTC.read(tm);
  lcd.setCursor(0, 0);
  ////////////////////////////////////////

  ////////////////////////////////////////
  //Day
  if (tm.Day < 10) {
    lcd.print('0');
  }
  lcd.print(tm.Day);
  lcd.print("/");
  ////////////////////////////////////////

  ////////////////////////////////////////
  //Month
  if (tm.Month < 10) {
    lcd.print('0');
  }
  lcd.print(tm.Month);
  lcd.print("/");
  ////////////////////////////////////////

  ////////////////////////////////////////
  //Year
  lcd.print(tmYearToCalendar(tm.Year));
  ////////////////////////////////////////
  ///////////// Hour /////////////////////
  ////////////////////////////////////////
  lcd.setCursor(0, 1);
  if (tformat) { //true 24 Hour
    if (tm.Hour < 10) lcd.print("0");
    lcd.print(tm.Hour);
    lcd.print(":");
  }
  else { // false 12-Hour Format
    if (tm.Hour > 12) {
      if (tm.Hour - 12 < 10) lcd.print("0");
      lcd.print(tm.Hour - 12);
    }
    else {
      lcd.print(tm.Hour);
    }
    lcd.print(":");
  }
  ////////////////////////////////////////

  ////////////////////////////////////////
  //Minute
  if (tm.Minute < 10) {
    lcd.print('0');
  }
  lcd.print(tm.Minute);
  lcd.print(":");
  ////////////////////////////////////////

  ////////////////////////////////////////
  //Second
  if (tm.Second < 10) {
    lcd.print('0');
  }
  lcd.print(tm.Second);
  ////////////////////////////////////////

  ////////////////////////////////////////

  if (!tformat) {
    if (tm.Hour > 12) {
      lcd.print("PM");
    }
    else {
      lcd.print("AM ");
    }
  }
  ////////////////////////////////////////
}//displayRTCTimeToLCD





