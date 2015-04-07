#include <DS1307RTC.h>
#include <Time.h>

#include <Wire.h>


tmElements_t tm;



void setup() {
  Serial.begin(9600);
  processRTCTimeToStamp(tm);
}

void loop() {

  
}

void processRTCTimeToStamp(tmElements_t tm) {
  ////////////////////////////////////////

  ////////////////////////////////////////
  RTC.read(tm);
  ////////////////////////////////////////
  ///////////// Hour /////////////////////
  ////////////////////////////////////////

   //int h;   
   //char Hour[1];
  // if(tm.Hour < 10) h = 0;   
//   sprintf(Hour,"%d%d:%d:%d",h,tm.Hour);
String tmp;

int Hour = 9;
int Minute = 15;
int Second = 56;

char stamp[] = "07,25,25,4,6,2015";











}//processRTCTimeToStamp





