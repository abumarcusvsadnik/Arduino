
void setup()
{
 Serial.begin(9600);
 Serial.print("Initializing SD card...");
 // For Mega boards with an Ethernet shield, make sure the Wiznet
 // chip is not selected:
 pinMode(53, OUTPUT);
 digitalWrite(10, HIGH); // davekw7x: If it's low, the Wiznet chip corrupts the SPI bus
 
 // see if the card is present and can be initialized:
 if (!SD.begin(53)) {
   Serial.println("Card failed, or not present");
   // don't do anything more:
   return;
 }
 Serial.println("card initialized.");
}


void loop() {
  // put your main code here, to run repeatedly:

}
