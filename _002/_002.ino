// Date and time functions using a DS1307 RTC connected via I2C and Wire lib

#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

void setup () {
  Serial.begin(57600);
  rtcInit();
  rtcSetNow();
  char* filename = "DTStamp";
  
    //createStampFile(filename,1);
    readStampReturnHour(filename,1);
    long unsigned time,date;
    
    
    time = readStampReturnTime(filename,0);

    Serial.println("Before ");
    Serial.println(time);
    
//    h = abs(time / 10000);
    unsigned int h = time / 10000;    
                 time = time % 10000;
    
    unsigned int m = time / 100;        
                 time = time % 100;
                 
    unsigned int s = time ;    

    
    
    Serial.println("h ");
    Serial.println(h);
    
    Serial.println("m ");
    Serial.println(m);    
    
    Serial.println("s ");
    Serial.println(s);    
    
    
    
    
    



    
    //readStampReturnDate(filename,1);
  
  
  
  
  
}

void loop () {
    
}
