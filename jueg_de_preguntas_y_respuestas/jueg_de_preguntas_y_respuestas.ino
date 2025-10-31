const int Puls1 = 3;
const int Puls2 = 4;
const int Puls3 = 5;
const int PulsRCT = 2;

const int led1 = 8;
const int led2 = 9;
const int led3 = 10;

void setup()
{
  pinMode (Puls1, INPUT);
  pinMode (Puls2, INPUT);
  pinMode (Puls3, INPUT);
  pinMode (PulsRCT, INPUT);

  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
}
void loop()
{
  
  if ((digitalRead(Puls1) == 1))

{     digitalRead(Puls2) == 0;
      digitalRead(Puls3) == 0;
      digitalWrite(led1, 1);
}
if ((digitalRead(Puls2) == 1))
{
  digitalRead(Puls1) == 0;
  digitalRead(Puls3) == 0;
  digitalWrite(led2, 1);
}
if ((digitalRead(Puls3) == 1))
{
  digitalRead(Puls1) == 0;
  digitalRead(Puls2) == 0;
  digitalWrite(led3, 1);
}
  if ((digitalRead(PulsRCT) == 1))
  {
    digitalRead(Puls1) == 0;
    digitalRead(Puls2) == 0;
    digitalRead(Puls3) == 0;
     parpadeo(led1,led2,led3 == ledA,ledB,ledC);
     parpadeo(led1,led2,led3 == ledA,ledB,ledC);
     parpadeo(led1,led2,led3 == ledA,ledB,ledC);

  }
  void parpadeo (byte ledA,byte ledB,byte ledC,int tiempo)
    
  digitalWrite(ledA,ledB,ledC == 1);
  delay(500);
  digitalWrite(ledA,ledB,ledC == 0);
  delay(500);
  digitalWrite(ledA,ledB,ledC == 1);
  delay(500);
  digitalWrite(ledA,ledB,ledC == 0;
  delay(500);

  
}
