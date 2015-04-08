

/*

#include <SPI.h>
#include <SD.h>

const int chipSelect = 53; // SD CLK
// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;

pinMode(53, OUTPUT);     // change this to 53 on a mega SD

*/


  void SDtest() {
   Serial.println("<!--------------------------------------------------------!>");
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
  Serial.println("<!--------------------------------------------------------!>");



}//END


void SDreadFile(char filename[]) {
  SD.begin(chipSelect);


  // re-open the file for reading:
  File myFile = SD.open(filename);
  if (myFile) {
    
    Serial.println("<!--------------------------------------------------------!>");
    Serial.println("(*)SDreadDirectory()");

    Serial.print("Filename: ");
    Serial.println(filename);
    Serial.print("Content: ");
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }


    // close the file:
    myFile.close();

  } else {
    // if the file didn't open, print an error:
    Serial.print("\nerror opening\t");
    Serial.println(filename);
    Serial.println();
  }
Serial.println("<!--------------------------------------------------------!>");

}


void SDcreateFile(char filename[], char str[17]) {
  SD.begin(chipSelect);
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File myFile = SD.open(filename, FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.println("<!--------------------------------------------------------!>");
    Serial.println("\n(*)SDCreateFile()");
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

    Serial.println("<!--------------------------------------------------------!>");

}






void SDdelFile(char filename[]) {
  //File myFile = SD.open(filename);
  SD.begin(chipSelect);
  File myFile = SD.open(filename);

  Serial.println("<!--------------------------------------------------------!>");
  Serial.println("\n(*)SDdelFile()\n");
  
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
    Serial.println("<!--------------------------------------------------------!>");

}//






