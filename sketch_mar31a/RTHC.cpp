/*
      Title: Hydroponics Project 6
      Library: RTHC.cpp
      Description: 
      Created Date: January 28, 2015
      Created By: Rolly Falco Villacacan
      http://www.mvsadnik.com/microcontrollers/
      https://www.facebook.com/groups/pinoymikrocontrollerscommunity/
      https://www.facebook.com/pages/Pinoy-Mikro-Controllers-Community/1397572657207414
*/

#include "Arduino.h"


#include "RTHC.h"

#include "DHT.h"

RTHC::RTHC(int set_temp_hi,int set_temp_lo, int set_humidity_hi ,int set_humidity_lo ,int set_fan_hi, int sensor_in)

{
  

_set_temp_hi = set_temp_hi;
_set_temp_lo = set_temp_lo;
_set_humidity_hi = set_humidity_hi;
_set_humidity_lo = set_humidity_lo;
_set_fan_hi = set_fan_hi;
_sensor_in = sensor_in;           
 dht.setup(_sensor_in);
  

}



float RTHC::temp(float PreSetTemp ,float tol ,int IDdebug, boolean debug)

{
  

float val;
  
delay(dht.getMinimumSamplingPeriod());
  
  



val = dht.getTemperature(); 
 
 
if(debug){
  

Serial.println();
  
Serial.print("Debug ID: ");
  
Serial.print(IDdebug);
  
Serial.print("\tStatus: ");
  
Serial.print(dht.getStatusString());
  
Serial.print("\tTemperature:\t");
  
Serial.print(val, 1); 
Serial.print("c"); 
Serial.print("\ttmax:\t");

Serial.print(PreSetTemp + PreSetTemp*tol/100,1); 
  
Serial.print("\ttmin:\t");

Serial.print(PreSetTemp - PreSetTemp*tol/100,1); 
  
         } 



if(val < PreSetTemp - PreSetTemp*tol/100)
		{
		
		 digitalWrite(_set_temp_hi,HIGH); 
	      	 digitalWrite(_set_fan_hi,HIGH); 
              	
		}

if(val > PreSetTemp + PreSetTemp*tol/100)
		{
		
		 digitalWrite(_set_temp_lo,HIGH);
	      	 digitalWrite(_set_fan_hi,HIGH);
	      
              	}

digitalWrite(_set_fan_hi,LOW);
  
return val;  

}




float RTHC::humidity(float PreSetTemp ,float tol ,int IDdebug, boolean debug)

{
  

float val;

delay(dht.getMinimumSamplingPeriod());

  
val = dht.getHumidity(); 


 
if(debug){
  

Serial.println();
  
Serial.print("Debug ID: ");
  
Serial.print(IDdebug);
  
Serial.print("\tStatus: ");
  
Serial.print(dht.getStatusString());
  
Serial.print("\tHumidity:\t");
  
Serial.print(val, 1); 
Serial.print("%");
 
Serial.print("\ttmax:\t");

Serial.print(PreSetTemp + PreSetTemp*tol/100,1); 
  
Serial.print("\ttmin:\t");

Serial.print(PreSetTemp - PreSetTemp*tol/100,1); 
   
  
}


if(val < PreSetTemp - PreSetTemp*tol/100){
		digitalWrite(_set_humidity_hi,HIGH); 
	      	digitalWrite(_set_fan_hi,HIGH); 
              }

if(val > PreSetTemp + PreSetTemp*tol/100){
		digitalWrite(_set_temp_lo,HIGH);
	      	digitalWrite(_set_fan_hi,HIGH);	      
              }

digitalWrite(_set_fan_hi,LOW);

return val; 


}
