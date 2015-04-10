

void initLCD() { lcd.begin(16, 2);}





int  displayRTCTimeToLCD(int tmHour, int tmMinute, int tmSecond, int tmDay, int tmMonth, int tmYear, boolean tformat) {

  
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


int  displayRTCTimeToLCD(boolean tformat) {
  ////////////////////////////////////////

  ////////////////////////////////////////
  DateTime now = rtc.now();


  
  lcd.setCursor(0, 0);
   if (tformat)
  { // 24 Hours

    if (now.hour() < 10)  {
      //lcd.print("0");
     lcd.print("0");          
     lcd.print(now.hour());
  }           
    else 
    lcd.print(now.hour());
  } else {
    if (now.hour() < 10)  {
     lcd.print("0");
     lcd.print(now.hour());
    }
    if (now.hour() >= 10 && now.hour() <= 12)  {
       lcd.print(now.hour());    
    }
    if (now.hour() > 12 && (now.hour() - 12) < 10)  {
     lcd.print("0");
     lcd.print((now.hour() - 12));
    }

    if (now.hour() > 12 && (now.hour() - 12) >= 10)  {

      if ((now.hour() - 12) < 12)
      {
        
       lcd.print((now.hour() - 12));
        
        
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
  if (now.minute() < 10) {
    lcd.print('0');    
  }
  lcd.print(now.minute());
  lcd.print(":");
  ////////////////////////////////////////

  ////////////////////////////////////////
  //Second
  if (now.second() < 10) {
    lcd.print('0');
  }
  lcd.print(now.second());
  ////////////////////////////////////////

  ////////////////////////////////////////

  if (!tformat) {
    if (now.hour() > 12) {
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
  if (now.day() < 10) {
    lcd.print('0');
  }
  lcd.print(now.day());
  lcd.print("/");
  ////////////////////////////////////////

  ////////////////////////////////////////
  //Month
  if (now.month() < 10) {
    lcd.print('0');
  }
  lcd.print(now.month());
  lcd.print("/");
  ////////////////////////////////////////

  ////////////////////////////////////////
  //Year
  lcd.print(now.year());

  ////////////////////////////////////////
  
 
  return 0;
}//displayRTCTimeToLCD




