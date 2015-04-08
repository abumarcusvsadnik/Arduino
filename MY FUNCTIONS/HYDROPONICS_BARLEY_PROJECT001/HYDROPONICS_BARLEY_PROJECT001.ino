#include <SPI.h>
#include <SD.h>

#include <LiquidCrystal.h>//LCD

// include the RTC library:
#include <Time.h>
#include <DS1307RTC.h>
#include <Wire.h>

tmElements_t tm;

int createStampFile1(int tmHour, int tmMinute, int tmSecond, int tmDay, int tmMonth, int tmYear, boolean debug);

LiquidCrystal lcd(7, 6, 5, 8, 3, 2);//LCD

const int chipSelect = 53; // SD CLK
// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;




void setup(){

       Serial.begin(9600);
       while(!Serial);
       lcd.begin(16, 2);//LCD       
       pinMode(53, OUTPUT); //SD    // change this to 53 on a mega SD
       
       int tmHour = 12;
       int tmMinute = 13;
       int tmSecond = 12;
       int tmDay = 53;
       int tmMonth = 12;
       int tmYear = 2015;
 
       
       readTimeNow();
       
       SDtest(); //SD       
       //createStampFile( tmHour,  tmMinute,  tmSecond,  tmDay,  tmMonth,  tmYear,  true); //STAMPING
       
       createStampFile2(true); //STAMPING
       SDreadDirectory("DTstamp");
       //SDdelFile("DTstamp");
       
       SDtest(); //SD
       
       
  
}



void loop(){
  
  displayRTCTimeToLCD(tm,0);
//displayRTCTimeToLCD(2,2,2,2,2,2019,0);

}




