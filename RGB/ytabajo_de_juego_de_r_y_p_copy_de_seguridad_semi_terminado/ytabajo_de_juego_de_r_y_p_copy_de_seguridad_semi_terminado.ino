const int Pin1 = 3;
const int Pin2 = 4;
const int Pin3 = 5;
const int PinRCT = 2;

const int led1 = 8;
const int led2 = 9;
const int led3 = 10;

bool resp = false;

void setup()
{
pinMode(Pin1,INPUT);
pinMode(Pin2,INPUT);
pinMode(Pin3,INPUT);
pinMode(PinRCT,INPUT);
  
  
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
  
}
void loop ()
{
if ( (digitalRead(Pin1) == 1  && resp == false ))
{ 
  digitalWrite(led1,1);
  resp = true;
}
if ( (digitalRead(Pin2) == 1 && resp == false) )
{
  digitalWrite(led2,1);
  resp = true;
}
if ( (digitalRead(Pin3) == 1 && resp == false))
{ 
  digitalWrite(led3,1); 
  resp = true;
}
if ( (digitalRead(PinRCT) == 1))
{ 
 resp = false; 

  
 
  
  digitalWrite(led1,1);
  digitalWrite(led2,1);
  digitalWrite(led3,1);
  delay(500);
  digitalWrite(led1,0);
  digitalWrite(led2,0);
  digitalWrite(led3,0);
  delay(500);
  digitalWrite(led1,1);
  digitalWrite(led2,1);
  digitalWrite(led3,1);
  delay(500);
  digitalWrite(led1,0);
  digitalWrite(led2,0);
  digitalWrite(led3,0);
  delay(500);
  digitalWrite(led1,1);
  digitalWrite(led2,1);
  digitalWrite(led3,1);
  delay(500);
  digitalWrite(led1,0);
  digitalWrite(led2,0);
  digitalWrite(led3,0);
  delay(500);
  digitalWrite(led1,1);
  digitalWrite(led2,1);
  digitalWrite(led3,1);
  delay(500);
  digitalWrite(led1,0);
  digitalWrite(led2,0);
  digitalWrite(led3,0);
  delay(500);
}
}
