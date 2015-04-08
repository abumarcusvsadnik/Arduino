

void readStamp(char filename[20]) {
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

