/*
      Title: Hydroponics Project 6
      Library: RTHC.h
      Description: 
      Created Date: January 28, 2015
      Created By: Rolly Falco Villacacan
      http://www.mvsadnik.com/microcontrollers/
      https://www.facebook.com/groups/pinoymikrocontrollerscommunity/
      https://www.facebook.com/pages/Pinoy-Mikro-Controllers-Community/1397572657207414
*/
#ifndef RTHC_h
#define RTHC_h
#include "DHT.h"
#include "Arduino.h"

class RTHC {

	public:
	
		RTHC(int set_temp_hi,int temp_lo, int humidity_hi ,int humidity_lo ,int fan_pin, int sensor_in);
		float  temp(float PreSetTemp ,float tol ,int IDdebug, boolean debug);
		float humidity(float PreSetTemp ,float tol ,int IDdebug, boolean debug);
		DHT dht;     

	private:

		int _set_temp_hi;
		int _set_temp_lo;
		int _set_humidity_hi;
		int _set_humidity_lo;
		int _set_fan_hi;
		int _sensor_in;
 
};

#endif
          



