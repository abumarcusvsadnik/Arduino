

bool rtcInit(){
 
 #ifdef AVR
  Wire.begin();
#else
  Wire1.begin(); // Shield I2C pins connect to alt I2C bus on Arduino Due
#endif
  rtc.begin();      
//   
  return true;  
}









 


bool rtcSetNow(int Year,int Month,int Day,int Hour,int Minute,int Second){
       
 if (rtc.isrunning()) {
    //Serial.println("RTC is running!");
    rtc.adjust(DateTime(Year, Month, Day, Hour, Minute, Second));
  }  
  return true;
}

bool rtcSetNow(){
       
 if (rtc.isrunning()) {
    //Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:    
  }  
  return true;
}


