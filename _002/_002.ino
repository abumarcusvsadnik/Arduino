// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

void setup () {
  Serial.begin(57600);
  rtcInit();
  rtcSetNow();
  char* filename = "DTStamp";
  
    createStampFile(filename,1);
    SDreadFileContent(filename);
    
    int h  = processTimetoHour(filename);
    int m  = processTimetoMin(filename);
    int s  = processTimetoSec(filename);
    int d  = processTimetoDay(filename);
    int mt = processTimetoMonth(filename);
    int y  = processTimetoYear(filename);

    Serial.print("Hour: ");
    Serial.println(h);    
    
    Serial.print("Minute: ");
    Serial.println(m);        
 
     Serial.print("Second: ");
    Serial.println(s);    
    
    Serial.print("Day: ");
    Serial.println(d);      
 
     Serial.print("Month: ");
    Serial.println(mt);    
    
    Serial.print("Year: ");
    Serial.println(y);      
   
}

void loop(){}
