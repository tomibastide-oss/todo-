const int ledR = 3;
const int ledG = 5;
const int ledB = 6;



const int btnRGB  = 9;
const int PMas = 10;
const int PMenos = 11;

int btnPmas = 0;
int btnPmenos = 0;

int estadoantbtnRGB = 0;
char valRGB = "r";

int btnVer = 0;
int btnAzu = 0;
int btnRoj = 0;


void setup()
{
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
 pinMode (ledB, OUTPUT);

  pinMode(btnRGB, INPUT);
  pinMode(PMas, INPUT);
  pinMode(PMenos, INPUT);
}
void loop()
{
if (digitalRead(btnRGB) == 1)
{
  if (valRGB == "r" )
  {
  valRGB = "g";
  }

else if(valRGB == "g")
{
  valRGB = "b";;
}
 else(valRGB == "b");
 {
  valRGB == "r";
 }
 }

 if (valRGB == "r")
  {
   btnRoj = btnRoj + digitalRead(PMas) * 15;
   btnRoj = btnRoj - digitalRead(PMenos) * 15;
  }
  
  
  if (valRGB == "g")
  {
  btnVer = btnVer + digitalRead(PMas) * 15;
  btnVer = btnVer - digitalRead(PMenos) * 15;
  }
  
  
    if (valRGB == "b")
    {
  btnAzu = btnAzu + digitalRead(PMas) * 15;
  btnAzu = btnAzu - digitalRead(PMenos) * 15;
    }


}
