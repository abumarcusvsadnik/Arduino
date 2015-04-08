#include <DS1307RTC.h>
#include <Time.h>
#include <LiquidCrystal.h>
#include <Wire.h>


tmElements_t tm;
LiquidCrystal lcd(7, 6, 5, 8, 3, 2);


void setup() {
  Serial.begin(19200);
  initLCD();
}

void loop() {

  displayRTCTimeToLCD(tm,1);
}

void initLCD() {

  lcd.begin(16, 2);

}

void displayRTCTimeToLCD(tmElements_t tm, boolean tformat) {
  ////////////////////////////////////////

  ////////////////////////////////////////
  RTC.read(tm);

  ////////////////////////////////////////
  ///////////// Hour /////////////////////
  ////////////////////////////////////////
  //tm.Hour = 22;
  
  lcd.setCursor(0, 0);
   if (tformat)
  { // 24 Hours

    if (tm.Hour < 10)  {
      //lcd.print("0");
     lcd.print("0");          
     lcd.print(tm.Hour);
  }
              
              
    else 
    
    lcd.print(tm.Hour);
    
    
    
    
  } else {

    if (tm.Hour < 10)  {

      
     lcd.print("0");
     lcd.print(tm.Hour);
      
      
   
    }
    if (tm.Hour >= 10 && tm.Hour <= 12)  {

       lcd.print(tm.Hour);
      
     
    }

    if (tm.Hour > 12 && (tm.Hour - 12) < 10)  {
      
   
      
     lcd.print("0");
     lcd.print((tm.Hour - 12));


      
    }

    if (tm.Hour > 12 && (tm.Hour - 12) >= 10)  {

      if ((tm.Hour - 12) < 12)
      {
        
       lcd.print((tm.Hour - 12));
        
        
      }
      else
      {
        
        
       lcd.print("00");
        
      
      }
    }


 
  
  }//if(tformat)
  
    lcd.print(":");
     
     

  ////////////////////////////////////////

  ////////////////////////////////////////
  
  
  //Minute
  if (tm.Minute < 10) {
    lcd.print('0');    
  }
  lcd.print(tm.Minute);
  lcd.print(":");
  ////////////////////////////////////////

  ////////////////////////////////////////
  //Second
  if (tm.Second < 10) {
    lcd.print('0');
  }
  lcd.print(tm.Second);
  ////////////////////////////////////////

  ////////////////////////////////////////

  if (!tformat) {
    if (tm.Hour > 12) {
      lcd.print("PM");
    }
    else {
      lcd.print("AM ");
    }
  }


  lcd.setCursor(0, 1);
  ////////////////////////////////////////

  ////////////////////////////////////////
  //Day
  if (tm.Day < 10) {
    lcd.print('0');
  }
  lcd.print(tm.Day);
  lcd.print("/");
  ////////////////////////////////////////

  ////////////////////////////////////////
  //Month
  if (tm.Month < 10) {
    lcd.print('0');
  }
  lcd.print(tm.Month);
  lcd.print("/");
  ////////////////////////////////////////

  ////////////////////////////////////////
  //Year
  lcd.print(tmYearToCalendar(tm.Year));

  ////////////////////////////////////////
  
 
  
}//displayRTCTimeToLCD





