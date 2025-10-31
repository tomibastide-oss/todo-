const int buzz = 2;
const int Puls1 = 4;
const int Puls2 = 3;
int tiempo = 10;

void setup()
{
pinMode(buzz,OUTPUT);
pinMode(Puls1,INPUT);
pinMode(Puls2,INPUT);
}
void loop()
{
if (digitalRead(Puls1) == 1)
{
alarma (900,500,tiempo);
}
  if (digitalRead(Puls2) == 1)
{
alarma (1200,900,tiempo);
}
}
  void alarma (int Tono1, int Tono2, int tiempo)
 {
    for (int i=0; i < tiempo; i++)
    {
 tone(buzz,Tono1);
 delay(500);
 tone(buzz,Tono2);
 delay(500); 
 noTone (buzz);
    }

  
}
