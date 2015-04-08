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

    //SD Functions
    void SDtest();
    void SDreadFile(char filename[]);
    void SDcreateFile(char filename[], char str[17]);    
    void SDdelFile(char filename[]);
    
    
    //RTC-LCD Functions
    int  displayRTCTimeToLCD(int tmHour, int tmMinute, int tmSecond, int tmDay, int tmMonth, int tmYear, boolean tformat);
    int  displayRTCTimeToLCD(tmElements_t tm, boolean tformat);

    //RTC Functions
    bool getDate(const char *str);
    bool getTime(const char *str);
    bool copySetPCTimetoRTCTime();
    void print2digits(int number);
    bool readRTCTime();
    
    //Stamping Functions
    int asciitodec(int ascii);
    int readStampReturntmHour(char* filename);
    int createStampFile(boolean debug);
    int createStampFile(int tmHour, int tmMinute, int tmSecond, int tmDay, int tmMonth, int tmYear, boolean debug);
    //int timelapse();
    
    
    


void setup(){

       Serial.begin(9600);
       while(!Serial);
      // delay(3000);
       lcd.begin(16, 2);//LCD       
       pinMode(53, OUTPUT); //SD    // change this to 53 on a mega SD
       
       int tmHour = 16;
       int tmMinute = 13;
       int tmSecond = 12;
       int tmDay = 53;
       int tmMonth = 12;
       int tmYear = 2015;
 
       
       //readRTCTime();
       
       //SDtest(); //SD       
       //createStampFile( tmHour,  tmMinute,  tmSecond,  tmDay,  tmMonth,  tmYear,  true); //STAMPING
      
       //createStampFile(true); //STAMPING
       //SDreadFile("DTstamp");
       int h = readStampReturntmHour("DTstamp");
       //SDdelFile("DTstamp");
       Serial.print("return hour is ");
       Serial.println(h);
       
       //SDtest(); //SD
       
       
  
}



void loop(){


  displayRTCTimeToLCD(tm,0);
  





}




