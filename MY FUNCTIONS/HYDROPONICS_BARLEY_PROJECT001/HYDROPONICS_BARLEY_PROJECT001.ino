//SD Card    
    #include <SPI.h>
    #include <SD.h>

    #include <LiquidCrystal.h>//LCD

//  include the RTC library:
    #include <Time.h>
    #include <DS1307RTC.h>
    #include <Wire.h>

tmElements_t tm;


LiquidCrystal lcd(7, 6, 5, 8, 3, 2);//LCD

const int chipSelect = 53; // SD CLK
// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;


    void SDtest();
    void SDreadFile(char filename[]);
    void SDcreateFile(char filename[], char str[17]);    
    void SDdelFile(char filename[]);
    
    int  displayRTCTimeToLCD(int tmHour, int tmMinute, int tmSecond, int tmDay, int tmMonth, int tmYear, boolean tformat);
    int  displayRTCTimeToLCD(tmElements_t tm, boolean tformat);
    boolean displayStringToLCD(char str[], unsigned int col, unsigned int row, bool debug);
    
    bool getDate(const char *str);
    bool getTime(const char *str);
    bool copySetPCTimetoRTCTime();
    void print2digits(int number);
    bool readRTCTime();

void setup(){

       Serial.begin(9600);
       while(!Serial);
       delay(3000);
       lcd.begin(16, 2);//LCD       
       pinMode(53, OUTPUT); //SD    // change this to 53 on a mega SD
       
       int tmHour = 12;
       int tmMinute = 13;
       int tmSecond = 12;
       int tmDay = 53;
       int tmMonth = 12;
       int tmYear = 2015;
 
       
       readRTCTime();
       
       SDtest(); //SD       
       //createStampFile( tmHour,  tmMinute,  tmSecond,  tmDay,  tmMonth,  tmYear,  true); //STAMPING
      
       //createStampFile2(true); //STAMPING
       SDreadFile("DTstamp");
       //SDdelFile("DTstamp");
       
       SDtest(); //SD
       
       
  
}



void loop(){
  displayStringToLCD("this is shit",0,0,0);
  delay(2000);
  //displayStringToLCD("noooooo!!!!",0,1,0);
  //delay(2000);
  
  //displayRTCTimeToLCD(tm,0);
  //displayRTCTimeToLCD(2,2,2,2,2,2019,0);

}




