

int  displayRTCTimeToLCD(int tmHour, int tmMinute, int tmSecond, int tmDay, int tmMonth, int tmYear, boolean tformat) {
  ////////////////////////////////////////

  ////////////////////////////////////////
  //RTC.read(tm);

  ////////////////////////////////////////
  ///////////// Hour /////////////////////
  ////////////////////////////////////////
  //tm.Hour = 22;
  
  lcd.setCursor(0, 0);
   if (tformat)
  { // 24 Hours

    if (tmHour < 10)  {
      //lcd.print("0");
     lcd.print("0");          
     lcd.print(tmHour);
  }
              
              
    else 
    
    lcd.print(tmHour);
    
    
    
    
  } else {

    if (tmHour < 10)  {

      
     lcd.print("0");
     lcd.print(tmHour);
      
      
   
    }
    if (tmHour >= 10 && tmHour <= 12)  {

       lcd.print(tmHour);
      
     
    }

    if (tmHour > 12 && (tmHour - 12) < 10)  {      
     lcd.print("0");
     lcd.print((tmHour - 12));    
    }
    if (tmHour > 12 && (tmHour - 12) >= 10)  {
      if ((tmHour - 12) < 12)
      {        
       lcd.print((tmHour - 12));        
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
  if (tmMinute < 10) {
    lcd.print('0');    
  }
  lcd.print(tmMinute);
  lcd.print(":");
  ////////////////////////////////////////

  ////////////////////////////////////////
  //Second
  if (tmSecond < 10) {
    lcd.print('0');
  }
  lcd.print(tmSecond);
  ////////////////////////////////////////

  ////////////////////////////////////////

  if (!tformat) {
    if (tmHour > 12) {
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
  if (tmDay < 10) {
    lcd.print('0');
  }
  lcd.print(tmDay);
  lcd.print("/");
  ////////////////////////////////////////

  ////////////////////////////////////////
  //Month
  if (tmMonth < 10) {
    lcd.print('0');
  }
  lcd.print(tmMonth);
  lcd.print("/");
  ////////////////////////////////////////

  ////////////////////////////////////////
  //Year
  lcd.print(tmYear);

  ////////////////////////////////////////
  
 
  return 0;
}//displayRTCTimeToLCD


int  displayRTCTimeToLCD(tmElements_t tm, boolean tformat) {
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
  
 
  return 0;
}//displayRTCTimeToLCD




