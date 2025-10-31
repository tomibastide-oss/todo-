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
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(led2,1);
  prenderApagar(ledVer,5000,"verde:");
  delay(500);
 prenderApagar(ledAmar,1000, "amarillo:");
   prenderApagar(ledAmar,1000, "amarillo:");
   prenderApagar(ledAmar,1000, "amarillo:");// le puse un titileo para que aprezca mas real//
digitalWrite(led2,0);                     //pero cumple laos 3 segundos.
  digitalWrite(led1,1);
prenderApagar(ledRoj,10000,"rojo:");
delay(1000);
  digitalWrite(led1,0);
  delay(500);
}
void prenderApagar(byte led,int tiempo,String txt)
{
  digitalWrite(led,1);
  Serial.print("pase de veiculos");
  Serial.print(txt);
  Serial.println("ENCENDIDO ");
  delay(tiempo);
  digitalWrite(led,0);
   Serial.print("led..");
  Serial.print(txt);
  Serial.println("apagado;");
  delay(500);
}
