const int Pin1 = 3;
const int Pin2 = 4;
const int Pin3 = 5;
const int PinRCT = 2;

const int led1 = 8;
const int led2 = 9;
const int led3 = 10;

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
if(digitalRead(Pin1) == 1)
{
  digitalWrite(led1,1);
digitalRead(Pin2) == 0;

digitalRead(Pin3) == 0;
  }
  
  if (digitalRead(Pin2) == 1)
{
    digitalWrite(led2,1);
digitalRead(Pin1) == 0;

digitalRead(Pin3) == 0;
  }
  
if (digitalRead(Pin3) == 1)
{
  digitalWrite(led3,1);
  digitalRead(Pin1) == 0;
  
  digitalRead(Pin2) == 0;
}

if ( digitalRead(PinRCT) == 1)
 {
  digitalRead(Pin1) == 0;
  
  digitalRead(Pin2) == 0; 
  
  digitalRead(Pin3) == 0; 
  
  
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
  
  
  
  
