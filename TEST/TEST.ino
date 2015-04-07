void setup()
{
  Serial.begin(9600);//setting communication baud rate

  int i=10; //initializing variables
  char c=char(i);  

  Serial.print("Integer i = \t");
  Serial.println(i);//display value of integer i
  Serial.print("Character c = \t");
  Serial.println(c);//display value of character c
}

void loop()
{
}
