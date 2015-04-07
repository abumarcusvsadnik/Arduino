void setup() {
  // put your setup code here, to run once:
  
Serial.begin(9600);

int i,h,m,s;
i = 0;
h = 0;
m = 0;
int x;


char Hour[2];
char Minute[2];
char Second[2];


char h0[1];
char tmp[25] = "10,15,51,2,2,2015";

int slength;

for(slength=0;slength<100;slength++){
  
  if(tmp[slength]==NULL) break;
  
  
}




/////////////////////////////////////////////////////////////  
x=0;
i=0;

do{  
  if(tmp[i] ==',')
  {    
    x++;
    if(x==1)
            { 
        h = i;
        break;   
            }
            
                
   } 
  i++; 
  
}while(i<(slength-1));

//Serial.println(h);


i = 0;

do{
  
  //Serial.print(i);
  //Serial.println(tmp[i]);
  Hour[i] = tmp[i];
  i++;
}while(i < h);

Serial.print("Hour: ");
Serial.println(Hour);
Serial.print("h: ");
Serial.println(h);

//////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////  
x=0;
i=0;

do{  
  if(tmp[i] ==',')
  {    
    x++;
    if(x==2)
            { 
        m = i;
        break;   
            }
            
                
   } 
  i++; 
  
}while(i<(slength-1));

//Serial.println(h);


i = 0;

do{
  
  //Serial.print(i);
// Serial.println(tmp[i]);
  Minute[i+h] = tmp[i+h];
  i++;
  
}while(i < m);

Serial.print("Minute: ");
Serial.println(Minute);

//////////////////////////////////////////////////////////




}

void loop() {
  // put your main code here, to run repeatedly:

}
