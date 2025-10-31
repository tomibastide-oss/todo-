const int ledVer = 3;
const int ledRoj = 4;
char ini;

void setup()
{
  pinMode(ledVer, OUTUT);
  pinMode(ledRoj, OUTFUT);
  Serial.begin(9600);
  ini = "V";
}

void loop()
{
if (ini == "V");
  {
     digitalWrite(ledRoj,1);
     digitalWrite(ledVer,1);
     delay(500);
     digitalWrite(ledVer,0);
     delay(500);
    }
    else 
    {
 digitalWrite(ledVer,1);
 digitalWrite(ledRoj,1);
 delay(500);
 digitalWrite(ledRoj,0);
 delay(500); 
    }
      
}