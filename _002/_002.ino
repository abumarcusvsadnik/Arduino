// Date and time functions using a DS1307 RTC connected via I2C and Wire lib

#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

void setup () {
  Serial.begin(57600);
  rtcInit();
  rtcSetNow();
  
  createStampFile(1);
  readStampReturntmHour("DTStamp");
  
  
}

void loop () {
    
}
