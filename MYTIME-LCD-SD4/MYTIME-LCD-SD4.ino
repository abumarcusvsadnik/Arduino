#include <DRAGONFLY.h>
#include <DRAGONFLY2.h>

// include the LCD library:



#include <LiquidCrystal.h>
#include <Wire.h>


// include the SD library:
#include <SPI.h>
#include <SD.h>

const char *monthName[12] = {
  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

tmElements_t tm;
const int chipSelect = 53; // SD CLK

#define EXHAUST_PIN 24
#define FAN_PIN 25
#define COMPRESSOR_PIN 26
#define HEATER_PIN 27
#define WATERPUMP_PIN 28
#define SENSOR_PIN 22



DRAGONFLY aha( EXHAUST_PIN, FAN_PIN, COMPRESSOR_PIN, HEATER_PIN, WATERPUMP_PIN,  SENSOR_PIN);
//DRAGONFLY aha( EXHAUST_PIN, FAN_PIN, COMPRESSOR_PIN, HEATER_PIN, WATERPUMP_PIN,  4);

// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;


//--------------------------------------------------

LiquidCrystal lcd(7, 6, 5, 8, 3, 2);


void setup() {

  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  delay(200);

  aha.initSensor(); // DHT
  aha.TEMP(26, 2, 1001);
  aha.HUMIDITY(26, 2, 1002);

  delay(1000);

  pinMode(53, OUTPUT);     // change this to 53 on a mega SD



  char fname[20] = "initData.txt";

  //deleteStamp(fname);
  //writeStamp(fname, "03/4/2015/18:15:25");
  readStamp(fname);


  testSD();






  //*

  //setNow();

  /*
    lcd.begin(16, 2);
    int i;
    for (i = 0; i < 100000000; i++) {
      RTC.read(tm);

      lcd.setCursor(0, 0);
      //lcd.print("D/M/Y:");
      lcd.print(tm.Day);
      lcd.print("/");
      lcd.print(tm.Month);
      lcd.print("/");
      lcd.print(tmYearToCalendar(tm.Year));

      lcd.setCursor(0, 1);
      //lcd.print("Time:");
      lcd.print(tm.Hour);
      lcd.print(":");
      lcd.print(tm.Minute);
      lcd.print(":");
      lcd.print(tm.Second);

    }

    */
  lcd.begin(16, 2);
}

void loop() {

  //aha.TEMP(26, 2, 1001);
  //aha.HUMIDITY(26, 2, 1002);




  formatTimetToLCDDisplay( tm, 0);


}





bool readTimeNow() {

  if (RTC.read(tm)) {
    Serial.print("Ok, Time = ");
    print2digits(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.write(':');
    print2digits(tm.Second);
    Serial.print(", Date (D/M/Y) = ");
    Serial.print(tm.Day);
    Serial.write('/');
    Serial.print(tm.Month);
    Serial.write('/');
    Serial.print(tmYearToCalendar(tm.Year));
    Serial.println();
  } else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
    }
    delay(9000);
  }
  delay(1000);


}


void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);

} //
bool setNow() {

  bool parse = false;
  bool config = false;



  // get the date and time the compiler was run
  if (getDate(__DATE__) && getTime(__TIME__)) {
    parse = true;
    // and configure the RTC with this info
    if (RTC.write(tm)) {
      config = true;
    }
  }


  if (parse && config) {
    Serial.print("DS1307 configured Time=");
    Serial.print(__TIME__);
    Serial.print(", Date=");
    Serial.println(__DATE__);
  } else if (parse) {
    Serial.println("DS1307 Communication Error :-{");
    Serial.println("Please check your circuitry");
  } else {
    Serial.print("Could not parse info from the compiler, Time=\"");
    Serial.print(__TIME__);
    Serial.print("\", Date=\"");
    Serial.print(__DATE__);
    Serial.println("\"");
  }

  return true;
}//


///////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////




bool getTime(const char *str)
{
  int Hour, Min, Sec;

  if (sscanf(str, "%d:%d:%d", &Hour, &Min, &Sec) != 3) return false;
  tm.Hour = Hour;
  tm.Minute = Min;
  tm.Second = Sec;
  return true;
}

bool getDate(const char *str)
{
  char Month[12];
  int Day, Year;
  uint8_t monthIndex;

  if (sscanf(str, "%s %d %d", Month, &Day, &Year) != 3) return false;
  for (monthIndex = 0; monthIndex < 12; monthIndex++) {
    if (strcmp(Month, monthName[monthIndex]) == 0) break;
  }
  if (monthIndex >= 12) return false;
  tm.Day = Day;
  tm.Month = monthIndex + 1;
  tm.Year = CalendarYrToTm(Year);
  return true;
}

//------ SD CARD FUNCTIONS ---------------

void testSD() {

  Serial.print("\nInitializing SD card...");



  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card is inserted?");
    Serial.println("* Is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
    return;
  } else {
    Serial.println("Wiring is correct and a card is present.");
  }

  // print the type of card
  Serial.print("\nCard type: ");
  switch (card.type()) {
    case SD_CARD_TYPE_SD1:
      Serial.println("SD1");
      break;
    case SD_CARD_TYPE_SD2:
      Serial.println("SD2");
      break;
    case SD_CARD_TYPE_SDHC:
      Serial.println("SDHC");
      break;
    default:
      Serial.println("Unknown");
  }

  // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
  if (!volume.init(card)) {
    Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
    return;
  }


  // print the type and size of the first FAT-type volume
  uint32_t volumesize;
  Serial.print("\nVolume type is FAT");
  Serial.println(volume.fatType(), DEC);
  Serial.println();

  volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
  volumesize *= volume.clusterCount();       // we'll have a lot of clusters
  volumesize *= 512;                            // SD card blocks are always 512 bytes
  Serial.print("Volume size (bytes): ");
  Serial.println(volumesize);
  Serial.print("Volume size (Kbytes): ");
  volumesize /= 1024;
  Serial.println(volumesize);
  Serial.print("Volume size (Mbytes): ");
  volumesize /= 1024;
  Serial.println(volumesize);


  Serial.println("\nFiles found on the card (name, date and size in bytes): ");
  root.openRoot(volume);

  // list all files in the card with date and size
  root.ls(LS_R | LS_DATE | LS_SIZE);



}//END



void readStamp(char filename[]) {
  SD.begin(chipSelect);


  // re-open the file for reading:
  File myFile = SD.open(filename);
  if (myFile) {

    Serial.println("\n(*)readStamp()");

    Serial.print("Filename\t");
    Serial.print(filename);
    Serial.print("\t");
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }

    Serial.print("\n");
    // close the file:
    myFile.close();

  } else {
    // if the file didn't open, print an error:
    Serial.print("error opening\t");
    Serial.println(filename);
    Serial.println();
  }

}


void writeStamp(char filename[20], char str[20]) {
  SD.begin(chipSelect);
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File myFile = SD.open(filename, FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.println("\n(*)writeStamp()");
    //  Serial.println("");
    Serial.print("Writing to\t");
    Serial.print(filename);
    Serial.print("\tthe string\t");
    Serial.print(str);

    myFile.println(str);
    // close the file:
    myFile.close();
    Serial.println("\tdone.\n");


  } else {
    // if the file didn't open, print an error:
    Serial.print("error opening\t");
    Serial.print(filename);
    Serial.println();

  }


}






void deleteStamp(char filename[20]) {
  //File myFile = SD.open(filename);
  SD.begin(chipSelect);
  File myFile = SD.open(filename);


  Serial.println("\n(*)deleteStamp()");

  Serial.print("Filename\t");
  Serial.print(filename);

  if (SD.exists(filename))
  {
    SD.remove(filename);
    Serial.print("\tfile removed\t");
    Serial.println(filename);
  }
  else
  {
    Serial.print("\tno file remove\t");
    Serial.println(filename);
  }


}//



void formatTimetToLCDDisplay(tmElements_t tm, boolean tformat) {  
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  RTC.read(tm);
  lcd.setCursor(0, 0);
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  //Day
  if (tm.Day < 10) {
    lcd.print('0');
  }
  lcd.print(tm.Day);
  lcd.print("/");
  ////////////////////////////////////////
  
  ////////////////////////////////////////  
  //Month
  if (tm.Month < 10) {
    lcd.print('0');
  }
  lcd.print(tm.Month);
  lcd.print("/");  
  ////////////////////////////////////////
  
  ////////////////////////////////////////  
  //Year
  lcd.print(tmYearToCalendar(tm.Year));
  ////////////////////////////////////////
  ///////////// Hour /////////////////////
  ////////////////////////////////////////
  lcd.setCursor(0, 1);
  if (tformat) { //true 24 Hour
    if (tm.Hour < 10) lcd.print("0");
    lcd.print(tm.Hour);
    lcd.print("/");
  }
  else { // false 12-Hour Format
    if (tm.Hour > 12) {
      if (tm.Hour - 12 < 10) lcd.print("0");
      lcd.print(tm.Hour - 12);
    }
    else {
      lcd.print(tm.Hour);
    }
    lcd.print(":");
  }
  ////////////////////////////////////////

  ////////////////////////////////////////
  //Minute
  if (tm.Minute < 10) {
    lcd.print('0');
  }
  lcd.print(tm.Minute);
  lcd.print(":");
  ////////////////////////////////////////

  ////////////////////////////////////////
  //Second
  if (tm.Second < 10) {
    lcd.print('0');
  }
  lcd.print(tm.Second);
  ////////////////////////////////////////

  ////////////////////////////////////////
  if (tm.Hour > 12) {
    lcd.print("PM");
  }
  else {
    lcd.print("AM ");
  }
  ////////////////////////////////////////
}//formatTimetToLCDDisplay

