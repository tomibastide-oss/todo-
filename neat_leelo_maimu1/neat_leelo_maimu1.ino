const byte ledRoj = 2;
const byte ledAmar = 3;
const byte ledVer = 4;
const byte led1 = 5;
const byte led2 = 6;
   
void setup()
{
pinMode(ledRoj,OUTPUT);
pinMode(ledAmar,OUTPUT);
pinMode(ledVer,OUTPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
}
void loop()
{
  digitalWrite(led2,1);
  prenderApagar(ledVer,5000);
  delay(500);
 prenderApagar(ledAmar,3000);
digitalWrite(led2,0);
  digitalWrite(led1,1);
prenderApagar(ledRoj,10000);
delay(1000);
  digitalWrite(led1,0);
  delay(500);
}
void prenderApagar(byte led,int tiempo)
{
  digitalWrite(led,1);
  delay(tiempo);
  digitalWrite(led,0);
  delay(100);
}
