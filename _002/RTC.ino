/* REQUIREMENTS
//global
#include <Wire.h>
#include "RTClib.h"
///////////////////////////////////////////////////////////////////////
//global
RTC_DS1307 rtc;
///////////////////////////////////////////////////////////////////////
//inside setup or loop
#ifdef AVR
  Wire.begin();
#else
  Wire1.begin(); // Shield I2C pins connect to alt I2C bus on Arduino Due
#endif
///////////////////////////////////////////////////////////////////////
//inside setup
rtc.begin();
///////////////////////////////////////////////////////////////////////
//inside setup
if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
///////////////////////////////////////////////////////////////////////
//inside setup or loop
DateTime now = rtc.now();

    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
///////////////////////////////////////////////////////////////////////
*/




bool rtcInit()
{
#ifdef AVR
  Wire.begin();
#else
  Wire1.begin(); // Shield I2C pins connect to alt I2C bus on Arduino Due
#endif
  rtc.begin();
  return true;
}
bool rtcSetNow(int Year, int Month, int Day, int Hour, int Minute, int Second ,int debugid)
{
  if (rtc.isrunning())
  {
    //Serial.println("RTC is running!");
    rtc.adjust(DateTime(Year, Month, Day, Hour, Minute, Second));
  }
  
    //////////////////////////////////////// 
  if (debugid != 0) {

   Serial.print("debugid"); 
   Serial.println(debugid); 
   Serial.print("rtcSetNow(,,,)");  
   Serial.println("input values");     
   Serial.println("output values");            
  }
  //////////////////////////////////////// 
  
  
  return true;
}

bool rtcSetNow(int debugid)
{
  if (rtc.isrunning())
  {
    //Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
  }

  ////////////////////////////////////////
  if (debugid != 0) {

   Serial.print("debugid"); 
   Serial.println(debugid); 
   Serial.print("rtcSetNow(,)");  
    Serial.println("input values");
    Serial.println("output values");
  }
  ////////////////////////////////////////


  return true;
}





