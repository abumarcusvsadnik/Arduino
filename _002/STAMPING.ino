///////////////////////////////////////////////////////////////////
void addZero(int x) {
        if (x < 10) Serial.print("0");
    }
    ///////////////////////////////////////////////////////////////////
    //this routine add adding zero to an array hour if less than ten.
int createStampFile(char * filename, int tmHour, int tmMinute, int tmSecond, int tmDay, int tmMonth, int tmYear, int debugid) {
    //////////////////////////////////////////////////////////////////
    char Hour[3];
    char Minute[3];
    char Second[3];
    char Day[3];
    char Month[3];
    char Year[5];
    char stamp[14];
    //////////////////////////////////////////////////////////////////
    if (tmHour < 10) sprintf(Hour, "%c%d", '0', tmHour);
    else sprintf(Hour, "%d", tmHour);
    if (tmMinute < 10) sprintf(Minute, "%c%d", '0', tmMinute);
    else sprintf(Minute, "%d", tmMinute);
    if (tmSecond < 10) sprintf(Second, "%c%d", '0', tmSecond);
    else sprintf(Second, "%d", tmSecond);
    if (tmDay < 10) sprintf(Day, "%c%d", '0', tmDay);
    else sprintf(Day, "%d", tmDay);
    if (tmMonth < 10) sprintf(Month, "%c%d", '0', tmMonth);
    else sprintf(Month, "%d", tmMonth);
    if (tmYear < 10) sprintf(Year, "%c%d", '0', tmYear);
    else sprintf(Year, "%d", tmYear);

    if (debugid != 0) {
        Serial.print("debugid");
        Serial.println(debugid);
        Serial.print("createStampFile(,,,)");

        Serial.println("<!--------------------------------------------------------!>");

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
        sprintf(stamp, "%s%s%s%s%s%s", Hour, Minute, Second, Day, Month, Year);
        Serial.print("Stamp value is ");
        Serial.println(stamp);
        Serial.println("<!--------------------------------------------------------!>");
    } //if(debug)
    SDdelFile(filename, debugid);
    SDcreateFile(filename, stamp, debugid);
    return 0;
}

int createStampFile(char * filename, int debugid) {
        DateTime now = rtc.now();
        //////////////////////////////////////////////////////////////////
        char Hour[3];
        char Minute[3];
        char Second[3];
        char Day[3];
        char Month[3];
        char Year[5];
        char stamp[14];
        //////////////////////////////////////////////////////////////////
        if (now.hour() < 10) sprintf(Hour, "%c%d", '0', now.hour());
        else sprintf(Hour, "%d", now.hour());
        if (now.minute() < 10) sprintf(Minute, "%c%d", '0', now.minute());
        else sprintf(Minute, "%d", now.minute());
        if (now.second() < 10) sprintf(Second, "%c%d", '0', now.second());
        else sprintf(Second, "%d", now.second());
        if (now.day() < 10) sprintf(Day, "%c%d", '0', now.day());
        else sprintf(Day, "%d", now.day());
        if (now.month() < 10) sprintf(Month, "%c%d", '0', now.month());
        else sprintf(Month, "%d", now.month());
        if (now.year() < 10) sprintf(Year, "%c%d", '0', now.year());
        else sprintf(Year, "%d", now.year());
        if (debugid != 0) {
            Serial.print("debugid");
            Serial.println(debugid);
            Serial.print("createStampFile(,,)");
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
            sprintf(stamp, "%s%s%s%s%s%s", Hour, Minute, Second, Day, Month, Year);
            Serial.print("Stamp value is ");
            Serial.println(stamp);
            Serial.println("<!--------------------------------------------------------!>");
        } //if(debug)
        SDdelFile(filename, debugid);
        SDcreateFile(filename, stamp, debugid);
        return 0;
    } //createstampfile
    //!--------------------------------------------------------------------------------------------!//
long unsigned readStampReturnTime(char * filename, int debugid) {
        SD.begin(chipSelect);
        byte i;
        // re-open the file for reading:
        File myFile = SD.open(filename);
        int stamp[14];
        if (myFile) {
            Serial.println("<!--------------------------------------------------------!>");
            Serial.println("(*)readStampReturnTime()");
            Serial.print("\tFilename\t: ");
            Serial.println(filename);
            // read from the file until there's nothing else in it:
            i = 0;
            while (myFile.available()) {
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
            //debugid = 0;
        }
        if (debugid != 0) {
            Serial.println("\n\nHour Value is: ");
            for (i = 0; i <= 13; i++) {
                Serial.print("Stamp[");
                Serial.print(i);
                Serial.print("] = [");
                Serial.print(stamp[i]);
                Serial.print("]");
                Serial.println("");
            } //debug
        } //debug
        Serial.println();
        Serial.println("<!--------------------------------------------------------!>");
        //unsinged long 2,147,483,647
        //word/unsigned int 65,535
        //byte 0-255
        //  long tmp;
        unsigned long t0, t1, t2, t3, t4, t5, tmp; //dont change the datatypes (unsigned long) error happens

        t0 = asciitodec(stamp[0], debugid);
        t1 = asciitodec(stamp[1], debugid);
        t2 = asciitodec(stamp[2], debugid);
        t3 = asciitodec(stamp[3], debugid);
        t4 = asciitodec(stamp[4], debugid);
        t5 = asciitodec(stamp[5], debugid);

        tmp = t0 * 100000 + t1 * 10000 + t2 * 1000 + t3 * 100 + t4 * 10 + t5;

        if (debugid != 0) {
            Serial.print("debugid");
            Serial.println(debugid);
            Serial.print("readStampReturnTime(,,)");

            Serial.print("h0 ");
            Serial.println(t0);
            Serial.print("h1 ");
            Serial.println(t1);
            Serial.print("m0 ");
            Serial.println(t2);
            Serial.print("m1 ");
            Serial.println(t3);
            Serial.print("s0 ");
            Serial.println(t4);
            Serial.print("s1 ");
            Serial.println(t5);
            Serial.print("returned value ");
            Serial.println(tmp);
        }


        return tmp;
    } //end function
    //!--------------------------------------------------------------------------------------------!//

//!--------------------------------------------------------------------------------------------!//
long unsigned readStampReturnDate(char * filename, int debugid) {
        SD.begin(chipSelect);
        byte i;

        // re-open the file for reading:
        File myFile = SD.open(filename);
        int stamp[14];
        if (myFile) {

            Serial.println("<!--------------------------------------------------------!>");
            Serial.println("(*)readStampReturnTime()");
            Serial.print("\tFilename\t: ");
            Serial.println(filename);
            // read from the file until there's nothing else in it:
            i = 0;
            while (myFile.available()) {
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
        if (debugid != 0) {
            Serial.println("\n\nHour Value is: ");
            for (i = 0; i <= 13; i++) {

                Serial.print("Stamp[");
                Serial.print(i);
                Serial.print("] = [");
                Serial.print(stamp[i]);
                Serial.print("]");
                Serial.println("");
            } //debug
        } //debug
        Serial.println();
        Serial.println("<!--------------------------------------------------------!>");
        //unsinged long 2,147,483,647
        //word/unsigned int 65,535
        //byte 0-255
        unsigned long t6, t7, t8, t9, t10, t11, t12, t13, tmp; //dont change the datatypes (unsigned long) error happens

        t6 = asciitodec(stamp[6], debugid);
        t7 = asciitodec(stamp[7], debugid);
        t8 = asciitodec(stamp[8], debugid);
        t9 = asciitodec(stamp[9], debugid);
        t10 = asciitodec(stamp[10], debugid);
        t11 = asciitodec(stamp[11], debugid);
        t12 = asciitodec(stamp[12], debugid);
        t13 = asciitodec(stamp[13], debugid);

        tmp = t6 * 10000000 + t7 * 1000000 + t8 * 100000 + t9 * 10000 + t10 * 1000 + t11 * 100 + t12 * 10 + t13;

        if (debugid != 0) {
            Serial.print("t6 ");
            Serial.println(t6);
            Serial.print("t7 ");
            Serial.println(t7);
            Serial.print("t8 ");
            Serial.println(t8);
            Serial.print("t9 ");
            Serial.println(t9);
            Serial.print("t10 ");
            Serial.println(t10);
            Serial.print("t11 ");
            Serial.println(t11);
            Serial.print("t12 ");
            Serial.println(t12);
            Serial.print("t13 ");
            Serial.println(t13);
            Serial.print("returned value ");
            Serial.println(tmp);

        }

        ////////////////////////////////////////
        if (debugid != 0) {
            Serial.print("debugid");
            Serial.println(debugid);
            Serial.print("readStampReturnDate(,,)");

            Serial.println("input values");
            Serial.println("output values");
        }
        ////////////////////////////////////////



        return tmp;
    } //end function

//////////////////////////////////////////////
unsigned int processDatetoDay(char * filename, int debugid) {
        long unsigned date;
        unsigned int d, m, y;
        date = readStampReturnDate(filename, debugid);
        d = date / 1000000;
        date = date % 1000000;
        m = date / 10000;
        date = date % 10000;
        y = date;

        ////////////////////////////////////////
        if (debugid != 0) {
            Serial.print("debugid");
            Serial.println(debugid);
            Serial.print("processTimetoDay(,,)");
            Serial.println("input values");
            Serial.println("output values");
        }
        ////////////////////////////////////////

        return d;
    } //
    //////////////////////////////////////////////
unsigned int processDatetoMonth(char * filename, int debugid) {
        long unsigned date;
        unsigned int d, m, y;
        date = readStampReturnDate(filename, debugid);
        d = date / 1000000;
        date = date % 1000000;
        m = date / 10000;
        date = date % 10000;
        y = date;

        ////////////////////////////////////////
        if (debugid != 0) {
            Serial.println("debugid");
            Serial.println("function name");
            Serial.println("input values");
            Serial.println("output values");
        }
        ////////////////////////////////////////

        return m;
    } //
    //////////////////////////////////////////////
unsigned int processDatetoYear(char * filename, int debugid) {
        long unsigned date;
        unsigned int d, m, y;
        date = readStampReturnDate(filename, debugid);
        d = date / 1000000;
        date = date % 1000000;
        m = date / 10000;
        date = date % 10000;
        y = date;

        ////////////////////////////////////////
        if (debugid != 0) {
            Serial.println("debugid");
            Serial.println("function name");
            Serial.println("input values");
            Serial.println("output values");
        }
        ////////////////////////////////////////

        return y;
    } //
    //////////////////////////////////////////////
unsigned int processTimetoHour(char * filename, int debugid) {
        long time;
        unsigned long h, m, s;
        time = readStampReturnTime(filename, debugid);
        h = time / 10000;
        time = time % 10000;
        m = time / 100;
        time = time % 100;
        s = time;

        ////////////////////////////////////////
        if (debugid != 0) {
            Serial.println("debugid");
            Serial.println("function name");
            Serial.println("input values");
            Serial.println("output values");
        }
        ////////////////////////////////////////



        return h;
    } //
    //////////////////////////////////////////////
unsigned int processTimetoMin(char * filename, int debugid) {
        long unsigned time;
        unsigned int h, m, s;
        time = readStampReturnTime(filename, debugid);
        h = time / 10000;
        time = time % 10000;
        m = time / 100;
        time = time % 100;
        s = time;


        ////////////////////////////////////////
        if (debugid != 0) {
            Serial.println("debugid");
            Serial.println("function name");
            Serial.println("input values");
            Serial.println("output values");
        }
        ////////////////////////////////////////


        return m;
    } //
    //////////////////////////////////////////////
unsigned int processTimetoSec(char * filename, int debugid) {
        long unsigned time;
        unsigned int h, m, s;
        time = readStampReturnTime(filename, debugid);
        h = time / 10000;
        time = time % 10000;
        m = time / 100;
        time = time % 100;
        s = time;

        ////////////////////////////////////////
        if (debugid != 0) {
            Serial.println("debugid");
            Serial.println("function name");
            Serial.println("input values");
            Serial.println("output values");
        }
        ////////////////////////////////////////



        return s;
    } //
    //////////////////////////////////////////////
    //////////////////////////////////////////////
unsigned long converttosec(int Day, int Hour, int Minute, int Second, int debugid) {

        unsigned long x = ((Day * 86400) + (Hour * 3600) + (Minute * 60) + (Second));

        if (debugid != 0) {
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

        ////////////////////////////////////////
        if (debugid != 0) {
            Serial.println("debugid");
            Serial.println("function name");
            Serial.println("input values");
            Serial.println("output values");
        }
        ////////////////////////////////////////


        return x;
    }
    //////////////////////////////////////////////
int asciitodec(int ascii, int debugid) {
        int h0;
        switch (ascii) {
            case 48:
                h0 = 0;
                break;
            case 49:
                h0 = 1;
                break;
            case 50:
                h0 = 2;
                break;
            case 51:
                h0 = 3;
                break;
            case 52:
                h0 = 4;
                break;
            case 53:
                h0 = 5;
                break;
            case 54:
                h0 = 6;
                break;
            case 55:
                h0 = 7;
                break;
            case 56:
                h0 = 8;
                break;
            case 57:
                h0 = 9;
                break;
        }

        ////////////////////////////////////////
        if (debugid != 0) {
            Serial.println("debugid");
            Serial.println("function name");
            Serial.println("input values");
            Serial.println("output values");
        }
        ////////////////////////////////////////



        return h0;
    } //end function
