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








unsigned long  converttosec(int Day,int Hour,int Minute,int Second, bool debug)
{
 
    unsigned long  x = ((Day*86400) + (Hour*3600) + (Minute*60) + (Second));
    
    if(debug){
      Serial.println("<!--------------------------------------------------------------------------!>");
      Serial.println("Function Name: converttosec() ");
      Serial.println("**********************");
      Serial.println("Input*");
      Serial.print("Variable Day: ");
      Serial.println(Day);
      Serial.print("Variable Hour: ");
      Serial.println(Hour);
      Serial.print("Variable Minute: ");
      Serial.println(Minute);
      Serial.print("Variable Second: ");
      Serial.println(Second);
      Serial.println("**********************");
      Serial.println("Output*");          
      Serial.print("Total Converted Seconds: ");
      Serial.println(x);
      Serial.println("<!--------------------------------------------------------------------------!>");
    } 
    return x;
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



