


#include <DS1307RTC.h>
#include <Time.h>
#include <LiquidCrystal.h>
#include <Wire.h>

boolean tformat;
tmElements_t tm;





void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

RTC.read(tm);

  ////////////////////////////////////////
  ///////////// Hour /////////////////////
  ////////////////////////////////////////


tformat=0;
int tmHour = 23;



  if (tformat)
  { // 24 Hours

    if (tmHour < 10)  {
      //Serial.print("0");
     Serial.print("0");          
     Serial.print(tmHour);
  }
              
              
    else 
    
    Serial.print(tmHour);
    
    
    
    
  } else {

    if (tmHour < 10)  {

      
     Serial.print("0");
     Serial.print(tmHour);
      
      
      //sprintf(th, "%s%d", "0", tmHour);
    }
    if (tmHour >= 10 && tmHour <= 12)  {

      //Serial.print(tmHour);
     Serial.print(tmHour);
      
      //sprintf(th, "%d", tmHour);
    }

    if (tmHour > 12 && (tmHour - 12) < 10)  {
      
      //Serial.print("0");
      //Serial.print(tmHour - 12);
      
     Serial.print("0");
     Serial.print((tmHour - 12));


      //sprintf(th, "%s%d", "0", (tmHour - 12));
    }

    if (tmHour > 12 && (tmHour - 12) > 10)  {

      if ((tmHour - 12) < 12)
      {
        //Serial.print(tmHour - 12);
       Serial.print((tmHour - 12));
        
        //sprintf(th, "%d", (tmHour - 12));
      }
      else
      {
        //Serial.print("00");
        
       Serial.print("00");
        
        //sprintf(th, "%s", "00");
      }
    }


 
  
  }//if(tformat)
  
    Serial.print(":");
     


}




void loop() {
  // put your main code here, to run repeatedly:



}




