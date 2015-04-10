    // Date and time functions using a DS1307 RTC connected via I2C and Wire lib
    #include <Wire.h> 
    #include "RTClib.h"
    #include <LiquidCrystal.h>
    #include <SPI.h> 
    #include <SD.h>
    
    
    // set up variables using the SD utility library functions:
    Sd2Card card;
    SdVolume volume;
    SdFile root;


    const int chipSelect = 53; // SD CLK
    LiquidCrystal lcd(7, 6, 5, 8, 3, 2);
    RTC_DS1307 rtc;

void setup() {
    Serial.begin(57600);
    rtcInit();
    rtcSetNow(1009);
    initLCD();



    char * filename = "DTStamp";

    //SDtest();

    createStampFile(filename, 1001);
    SDreadFileContent(filename, 1002);

    unsigned int h, m, s, d, mt, y;

    d = processTimetoDay(filename, 1003);
    mt = processTimetoMonth(filename, 1004);
    y = processTimetoYear(filename, 1005);

    h = processTimetoHour(filename, 1006);
    m = processTimetoMin(filename, 1007);
    s = processTimetoSec(filename, 1008);


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

void loop() {




    displayRTCTimeToLCD(0, 0);


}
