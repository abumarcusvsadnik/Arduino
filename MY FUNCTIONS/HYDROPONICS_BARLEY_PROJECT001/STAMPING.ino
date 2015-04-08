
//this routine add adding zero to an array hour if less than ten.
int createStampFile1(int tmHour, int tmMinute, int tmSecond, int tmDay, int tmMonth, int tmYear, boolean debug){


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
        
        
        SDcreateFile("DTstamp", stamp);

         return 0;


  }
  
  
  
  int createStampFile2(boolean debug){
    
        
        RTC.read(tm);
        
        


	//////////////////////////////////////////////////////////////////

        char Hour[3];
	char Minute[3];
	char Second[3];

	char Day[3];
	char Month[3];
	char Year[5];


	char stamp[17];


	//////////////////////////////////////////////////////////////////

	if(tm.Hour < 10) sprintf(Hour,"%c%d",'0',tm.Hour);
		else sprintf(Hour,"%d",tm.Hour);

      
	if(tm.Minute < 10) sprintf(Minute,"%c%d",'0',tm.Minute);
		else sprintf(Minute,"%d",tm.Minute);

	if(tm.Second < 10) sprintf(Second,"%c%d",'0',tm.Second);
		else sprintf(Second,"%d",tm.Second);

	if(tm.Day < 10) sprintf(Day,"%c%d",'0',tm.Day);
		else sprintf(Day,"%d",tm.Day);


	if(tm.Month < 10) sprintf(Month,"%c%d",'0',tm.Month);
		else sprintf(Month,"%d",tm.Month);

	if(tmYearToCalendar(tm.Year) < 10) sprintf(Year,"%c%d",'0',tmYearToCalendar(tm.Year));
			else sprintf(Year,"%d",tmYearToCalendar(tm.Year));


      

	if(debug){
	Serial.println("<!--------------------------------------------------------!>");
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
  
