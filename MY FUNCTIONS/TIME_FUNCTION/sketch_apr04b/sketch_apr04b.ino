
#include <Time.h>

time_t tmConvert_t(int YYYY, byte MM, byte DD, byte hh, byte mm, byte ss)
{
  tmElements_t tmSet;
  tmSet.Year = YYYY - 1970;
  tmSet.Month = MM;
  tmSet.Day = DD;
  tmSet.Hour = hh;
  tmSet.Minute = mm;
  tmSet.Second = ss;
  return makeTime(tmSet);         //convert to time_t
}

void setup()
{
  Serial.begin(9600);
  time_t s_tm = tmConvert_t(2000,1,1,9,59,50); // ~10:00 Uhr
  
  Serial.print("Unix Time\t");  
  Serial.println(s_tm);
  

  String thisString = String(13, BIN);
  String thisString += String(2004, BIN);
  
  
  
  Serial.println(thisString);
  
  
  
}

void loop()
{
}
