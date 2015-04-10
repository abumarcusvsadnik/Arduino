///////////////////////////////////////////////////////////////////
void addZero(int x){ 
 if(x<10)Serial.print("0");   
}
///////////////////////////////////////////////////////////////////
//this routine add adding zero to an array hour if less than ten.
int createStampFile(int tmHour, int tmMinute, int tmSecond, int tmDay, int tmMonth, int tmYear, boolean debug){      
	//////////////////////////////////////////////////////////////////

        char Hour[3];
	char Minute[3];
	char Second[3];

	char Day[3];
	char Month[3];
	char Year[5];

	char stamp[17];

	//////////////////////////////////////////////////////////////////

	if(tmHour < 10) sprintf(Hour,"%c%d",'0',tmHour);
		else sprintf(Hour,"%d",tmHour);

      
	if(tmMinute < 10) sprintf(Minute,"%c%d",'0',tmMinute);
		else sprintf(Minute,"%d",tmMinute);

	if(tmSecond < 10) sprintf(Second,"%c%d",'0',tmSecond);
		else sprintf(Second,"%d",tmSecond);

	if(tmDay < 10) sprintf(Day,"%c%d",'0',tmDay);
		else sprintf(Day,"%d",tmDay);


	if(tmMonth < 10) sprintf(Month,"%c%d",'0',tmMonth);
		else sprintf(Month,"%d",tmMonth);

	if(tmYear < 10) sprintf(Year,"%c%d",'0',tmYear);
			else sprintf(Year,"%d",tmYear);      

	if(debug){
	Serial.println("<!--------------------------------------------------------!>");
        Serial.println("(*)createStampFile2");
        Serial.println("Time/Date Got from RTC Clock!");
        Serial.println("Debug Enabled");
	Serial.print("The Hour ");
	Serial.println(Hour);

	Serial.print("The Minute ");
	Serial.println(Minute);

	Serial.print("The Second ");
	Serial.println(Second);

	Serial.print("The Day ");
	Serial.println(Day);

	Serial.print("The Month ");
	Serial.println(Month);


	Serial.print("The Year ");
	Serial.println(Year);

	//concat all string into string stamp
	sprintf(stamp,"%s%s%s%s%s%s",Hour,Minute,Second,Day,Month,Year);
	Serial.print("Stamp value is "); 
	Serial.println(stamp); 
        Serial.println("<!--------------------------------------------------------!>");
        }//if(debug)

        
        SDdelFile("DTstamp");
        SDcreateFile("DTstamp", stamp);
        

         return 0;


  }
  
  
  
  int createStampFile(boolean debug){       
        
        
        DateTime now = rtc.now();

	//////////////////////////////////////////////////////////////////

        char Hour[3];
	char Minute[3];
	char Second[3];

	char Day[3];
	char Month[3];
	char Year[5];


	char stamp[17];


	//////////////////////////////////////////////////////////////////

	if(now.hour() < 10) sprintf(Hour,"%c%d",'0',now.hour());
		else sprintf(Hour,"%d",now.hour());

      
	if(now.minute() < 10) sprintf(Minute,"%c%d",'0',now.minute());
		else sprintf(Minute,"%d",now.minute());

	if(now.second() < 10) sprintf(Second,"%c%d",'0',now.second());
		else sprintf(Second,"%d",now.second());

	if(now.day() < 10) sprintf(Day,"%c%d",'0',now.day());
		else sprintf(Day,"%d",now.day());


	if(now.month() < 10) sprintf(Month,"%c%d",'0',now.month());
		else sprintf(Month,"%d",now.month());

	if(now.year() < 10) sprintf(Year,"%c%d",'0',now.year());
			else sprintf(Year,"%d",now.year());      

	if(debug){
	Serial.println("<!--------------------------------------------------------!>");
        Serial.println("(*)createStampFile2");
        Serial.println("Time/Date Got from RTC Clock!");
        Serial.println("Debug Enabled");
	Serial.print("The Hour ");
	Serial.println(Hour);

	Serial.print("The Minute ");
	Serial.println(Minute);

	Serial.print("The Second ");
	Serial.println(Second);

	Serial.print("The Day ");
	Serial.println(Day);

	Serial.print("The Month ");
	Serial.println(Month);


	Serial.print("The Year ");
	Serial.println(Year);

	//concat all string into string stamp
	sprintf(stamp,"%s%s%s%s%s%s",Hour,Minute,Second,Day,Month,Year);
	Serial.print("Stamp value is "); 
	Serial.println(stamp); 
        Serial.println("<!--------------------------------------------------------!>");
        }//if(debug)

        
        SDdelFile("DTstamp");
        SDcreateFile("DTstamp",stamp);
        SDreadFileContent("DTstamp");
        

         return 0;


  }
  
  
  
//!--------------------------------------------------------------------------------------------!//  
  int readStampReturntmHour(char* filename) {
  SD.begin(chipSelect);
  int i,h, h0, h1, h2;

  // re-open the file for reading:
  File myFile = SD.open(filename);
  int stamp[13];
  if (myFile) {
    
    Serial.println("<!--------------------------------------------------------!>");
    Serial.println("(*)readStampReturntmHour()");

    Serial.print("\tFilename\t: ");
    Serial.println(filename);
    
    // read from the file until there's nothing else in it:
    

   i = 0;
   while(myFile.available()){   
    stamp[i] = myFile.read();   
    i++;
   }
    

    // close the file:
    myFile.close();

  } else {
    // if the file didn't open, print an error:
    Serial.print("\nerror opening\t");
    Serial.println(filename);
    Serial.println();
  }

Serial.println("\n\nHour Value is: ");
for(i=0;i  <= 13 ;i++){

Serial.print("Stamp[");
Serial.print(i);
Serial.print("] = [");
Serial.print(stamp[i]);
Serial.print("]");
Serial.println("");
}

Serial.println();
Serial.println("<!--------------------------------------------------------!>");



h0 = asciitodec(stamp[0]);       
h1 = asciitodec(stamp[1]);  
        
        h2 = h0*10 + h1*1;
        
        Serial.print("h0 ");
        Serial.println(h0);        
        Serial.print("h1 ");
        Serial.println(h1);        
        Serial.print("h2 ");
        Serial.println(h2);        
        
        
        
        return h2;

}//end function
//!--------------------------------------------------------------------------------------------!//



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













  
int asciitodec(int ascii){ 

int h0;
 
switch(ascii){
   case 48 : h0 = 0; break;
   case 49 : h0 = 1; break;
   case 50 : h0 = 2;  break;
   case 51 : h0 = 3;  break;
    case 52 : h0 = 4;  break;
     case 53 : h0 = 5;  break;
      case 54 : h0 = 6;  break;
       case 55 : h0 = 7;  break;
        case 56 : h0 = 8;  break;
         case 57 : h0 = 9;  break;           
}

return h0;

}//end function
