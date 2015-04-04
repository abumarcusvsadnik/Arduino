void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  String str;
  str += 1231231312;
  str += ",";
  str += "fsdfasdfasdf";
  
  Serial.println(str);
  
}
