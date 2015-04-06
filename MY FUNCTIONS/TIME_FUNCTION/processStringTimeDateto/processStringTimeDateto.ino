#include <DS1307RTC.h>
#include <Time.h>
#include <LiquidCrystal.h>
#include <Wire.h>


tmElements_t tm;
LiquidCrystal lcd(7, 6, 5, 8, 3, 2);


void setup() {
  Serial.begin(19200);
  

  
  char  outstr[15] = "12520304042015";
 
  
  int h,m,s,d,mt,y;
  
  h = processStringTimeDatetoHour(outstr);
    m = processStringTimeDatetoMinute(outstr);
      s = processStringTimeDatetoSecond(outstr);
  
  d = processStringTimeDatetoDay(outstr);
    mt = processStringTimeDatetoMonth(outstr);
      y = processStringTimeDatetoYear(outstr);
      
   Serial.print("\n");   
   Serial.print(h);
   Serial.print(" ");
   
   Serial.print(m);
   Serial.print(" ");
   
   Serial.print(s);
   Serial.print(" ");
   
   Serial.print(d);
   Serial.print(" ");
   
   Serial.print(mt);
   Serial.print(" ");
   
   Serial.print(y);
   

  
}

void loop() {


  
}


int processStringTimeDatetoHour(char  outstr[15]){
char Hour[1];
Hour[0] = outstr[0];      
Hour[1] = outstr[1];   

int h0, h1, h2;
if(Hour[0]=='0')h0 = 0; 
if(Hour[0]=='1')h0 = 10; 
if(Hour[0]=='2')h0 = 20;
if(Hour[0]=='3')h0 = 30;
if(Hour[0]=='4')h0 = 40;
if(Hour[0]=='5')h0 = 50;
if(Hour[0]=='6')h0 = 60;
if(Hour[0]=='7')h0 = 70;
if(Hour[0]=='8')h0 = 80;
if(Hour[0]=='9')h0 = 90;
if(Hour[1]=='0')h1 = 0;
if(Hour[1]=='1')h1 = 1;
if(Hour[1]=='2')h1 = 2;
if(Hour[1]=='3')h1 = 3;
if(Hour[1]=='4')h1 = 4;
if(Hour[1]=='5')h1 = 5;
if(Hour[1]=='6')h1 = 6;
if(Hour[1]=='7')h1 = 7;
if(Hour[1]=='8')h1 = 8;
if(Hour[1]=='9')h1 = 9;
h2 = h0 + h1;
return h2;
}//

int processStringTimeDatetoMinute(char  outstr[15]){
char Minute[1];
/////////////////////////////////////////////
Minute[0] = outstr[2];      
Minute[1] = outstr[3];      

int m0, m1, m2;

if(Minute[0]=='0')m0 = 0;
if(Minute[0]=='1')m0 = 10;
if(Minute[0]=='2')m0 = 20;
if(Minute[0]=='3')m0 = 30;
if(Minute[0]=='4')m0 = 40;
if(Minute[0]=='5')m0 = 50;
if(Minute[0]=='6')m0 = 60;
if(Minute[0]=='7')m0 = 70;
if(Minute[0]=='8')m0 = 80;
if(Minute[0]=='9')m0 = 90;

if(Minute[1]=='0')m1 = 0;
if(Minute[1]=='1')m1 = 1;
if(Minute[1]=='2')m1 = 2;
if(Minute[1]=='3')m1 = 3;
if(Minute[1]=='4')m1 = 4;
if(Minute[1]=='5')m1 = 5;
if(Minute[1]=='6')m1 = 6;
if(Minute[1]=='7')m1 = 7;
if(Minute[1]=='8')m1 = 8;
if(Minute[1]=='9')m1 = 9;
m2 = m0 + m1;
return m2;
}//
  


////////////////////////////////////
int processStringTimeDatetoSecond(char  outstr[15]){
char Second[1];
Second[0] = outstr[4];      
Second[1] = outstr[5];      

int s0, s1, s2;

if(Second[0]=='0')s0 = 0;
if(Second[0]=='1')s0 = 10;
if(Second[0]=='2')s0 = 20;
if(Second[0]=='3')s0 = 30;
if(Second[0]=='4')s0 = 40;
if(Second[0]=='5')s0 = 50;
if(Second[0]=='6')s0 = 60;
if(Second[0]=='7')s0 = 70;
if(Second[0]=='8')s0 = 80;
if(Second[0]=='9')s0 = 90;

if(Second[1]=='0')s1 = 0;
if(Second[1]=='1')s1 = 1;
if(Second[1]=='2')s1 = 2;
if(Second[1]=='3')s1 = 3;
if(Second[1]=='4')s1 = 4;
if(Second[1]=='5')s1 = 5;
if(Second[1]=='6')s1 = 6;
if(Second[1]=='7')s1 = 7;
if(Second[1]=='8')s1 = 8;
if(Second[1]=='9')s1 = 9;
s2 = s0 + s1;
return s2;
}

//////////////////////////////////////////////

///////////////////////////////////////////////////
int processStringTimeDatetoDay(char  outstr[15]){
char Day[1];
Day[0] = outstr[6];      
Day[1] = outstr[7];      

int d0, d1, d2;

if(Day[0]=='0')d0 = 0;
if(Day[0]=='1')d0 = 10;
if(Day[0]=='2')d0 = 20;
if(Day[0]=='3')d0 = 30;
if(Day[0]=='4')d0 = 40;
if(Day[0]=='5')d0 = 50;
if(Day[0]=='6')d0 = 60;
if(Day[0]=='7')d0 = 70;
if(Day[0]=='8')d0 = 80;
if(Day[0]=='9')d0 = 90;

if(Day[1]=='0')d1 = 0;
if(Day[1]=='1')d1 = 1;
if(Day[1]=='2')d1 = 2;
if(Day[1]=='3')d1 = 3;
if(Day[1]=='4')d1 = 4;
if(Day[1]=='5')d1 = 5;
if(Day[1]=='6')d1 = 6;
if(Day[1]=='7')d1 = 7;
if(Day[1]=='8')d1 = 8;
if(Day[1]=='9')d1 = 9;
d2 = d0 + d1;
return d2;
}
////////////////////////////////////////

///////////////////////////////////////
int processStringTimeDatetoMonth(char  outstr[15]){
char Month[1];
Month[0] = outstr[8];      
Month[1] = outstr[9];      

int mt0, mt1, mt2;

if(Month[0]=='0')mt0 = 0;
if(Month[0]=='1')mt0 = 10;
if(Month[0]=='2')mt0 = 20;
if(Month[0]=='3')mt0 = 30;
if(Month[0]=='4')mt0 = 40;
if(Month[0]=='5')mt0 = 50;
if(Month[0]=='6')mt0 = 60;
if(Month[0]=='7')mt0 = 70;
if(Month[0]=='8')mt0 = 80;
if(Month[0]=='9')mt0 = 90;

if(Month[1]=='0')mt1 = 0;
if(Month[1]=='1')mt1 = 1;
if(Month[1]=='2')mt1 = 2;
if(Month[1]=='3')mt1 = 3;
if(Month[1]=='4')mt1 = 4;
if(Month[1]=='5')mt1 = 5;
if(Month[1]=='6')mt1 = 6;
if(Month[1]=='7')mt1 = 7;
if(Month[1]=='8')mt1 = 8;
if(Month[1]=='9')mt1 = 9;
mt2 = mt0 + mt1;
return mt2;
}
/////////////////////////////////////////////////

/////////////////////////////////////////////////
int processStringTimeDatetoYear(char  outstr[15]){
//Serial.println(outstr);
//Serial.println("");
char Year[3];

Year[0] = outstr[10];      
Year[1] = outstr[11];      
Year[2] = outstr[12]; 
Year[3] = outstr[13]; 

int y0, y1, y2, y3, y4;

if(Year[0]=='0')y0 = 0;
if(Year[0]=='1')y0 = 1000;
if(Year[0]=='2')y0 = 2000;
if(Year[0]=='3')y0 = 3000;
if(Year[0]=='4')y0 = 4000;
if(Year[0]=='5')y0 = 5000;
if(Year[0]=='6')y0 = 6000;
if(Year[0]=='7')y0 = 7000;
if(Year[0]=='8')y0 = 8000;
if(Year[0]=='9')y0 = 9000;

if(Year[1]=='0')y1 = 0;
if(Year[1]=='1')y1 = 100;
if(Year[1]=='2')y1 = 200;
if(Year[1]=='3')y1 = 300;
if(Year[1]=='4')y1 = 400;
if(Year[1]=='5')y1 = 500;
if(Year[1]=='6')y1 = 600;
if(Year[1]=='7')y1 = 700;
if(Year[1]=='8')y1 = 800;
if(Year[1]=='9')y1 = 900;

if(Year[2]=='0')y2 = 0;
if(Year[2]=='1')y2 = 10;
if(Year[2]=='2')y2 = 20;
if(Year[2]=='3')y2 = 30;
if(Year[2]=='4')y2 = 40;
if(Year[2]=='5')y2 = 50;
if(Year[2]=='6')y2 = 60;
if(Year[2]=='7')y2 = 70;
if(Year[2]=='8')y2 = 80;
if(Year[2]=='9')y2 = 90;

if(Year[3]=='0')y3 = 0;
if(Year[3]=='1')y3 = 1;
if(Year[3]=='2')y3 = 2;
if(Year[3]=='3')y3 = 3;
if(Year[3]=='4')y3 = 4;
if(Year[3]=='5')y3 = 5;
if(Year[3]=='6')y3 = 6;
if(Year[3]=='7')y3 = 7;
if(Year[3]=='8')y3 = 8;
if(Year[3]=='9')y3 = 9;
y4 = y0 + y1 + y2 + y3;
return y4;
}//









