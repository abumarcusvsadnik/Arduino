


// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 rtc;





void setup () {
Serial.begin(57600);
pinMode(53, OUTPUT);     // change this to 53 on a mega SD

rtcInit();
rtcSetNow();
//rtcSetNow(2078,2,23,0,5,8);
//converttosec(0,0,0,32,1);


unsigned long long i=600851475143;
printf("%llu",i);

//SDdelFile("DTStamp"); 
//SDcreateFile("DTStamp","hello"); 
//createStampFile2(1);

//readStampReturnString("DTStamp");


//SDreadFileContent("DTStamp");


}


void loop () {  
  
  
  
  
  
  
  
}




