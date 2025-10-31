//EEPROM
#include <EEPROM.h>  
///////////////////////
//modulo reloj
#include <ThreeWire.h>
#include <RtcDS1302.h>
ThreeWire conex(10,11,12);
RtcDS1302 <ThreeWire> rtc(conex);
//////////////////////////////////
//teclado
#include <Keypad.h> 
char keys[4][4] = {   
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'#','0','*','D'}
};
byte pinesFilas[4] = {9,8,7,6};   
byte pinesColumnas[4] = {5,4,3,2}; 
Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, 4, 4);  // crea objeto
char tecla;     
int cont = 0;
//////////////////////////////////////
//LCD
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0X27, 16, 2);
////////////////////
//RELEE
int Relee = 13;
////////////////////
//LEDS
int ledR = A0;
int ledV = A1;

int horaON = 17;
int minutoON = 30;
int horaOFF = 20;
int minutoOFF = 54;


void setup() {
 rtc.Begin();
 
 Serial.begin(9600);
 pinMode(Relee,OUTPUT);
 pinMode(ledR,OUTPUT);
 pinMode(ledV,OUTPUT);
 
 lcd.init();
 lcd.backlight();
 lcd.clear();
 rtc.SetIsRunning(true);
 
  /*
 RtcDateTime Fecha_Hora = RtcDateTime(__DATE__,__TIME__);
rtc.SetDateTime(Fecha_Hora);*/

}

void loop() { 
tecla = teclado.getKey();

if(tecla)
{
  if (tecla == 'A')
  {
    mostrarH ();
    delay(5000);
  }
  if(tecla == 'B')
  {
   defineON();
   delay(500);
   defineOFF();
   delay(500);
  }


}

 mostrarHora();

 RtcDateTime now = rtc.GetDateTime();
 
 EEPROM.get(0,horaON);
 EEPROM.get(4,minutoON);

if(now.Hour() == horaON && now.Minute() == minutoON)
{
 digitalWrite(Relee,1);
 digitalWrite(ledR,0);
 digitalWrite(ledV,1);
}

EEPROM.get(8,horaOFF);
EEPROM.get(12,minutoOFF);

 
if(now.Hour() == horaOFF && now.Minute() == minutoOFF)
{
 digitalWrite(Relee,0);
 digitalWrite(ledV,0);
 digitalWrite(ledR,1);
}


}


void mostrarHora (){
 lcd.clear();
RtcDateTime now = rtc.GetDateTime();
char form1 [30];
char form2 [30];
sprintf(form1,"%02d/%02d/%04d",now.Day(),now.Month(),now.Year());
sprintf(form2,"%02d:%02d:%02d",now.Hour(),now.Minute(),now.Second());
lcd.setCursor(0,0);                                          
lcd.print(form1);  
lcd.setCursor(0,1);                                          
lcd.print(form2); 
delay(500);   
}

void mostrarH ()
{
  EEPROM.get(0,horaON);
  EEPROM.get(4,minutoON);
 EEPROM.get(8,horaOFF);
  EEPROM.get(12,minutoOFF);
 
   lcd.clear();
char horaEN [30];
char horaAP [30];
sprintf(horaEN,"HORA ON: %02d:%02d",horaON,minutoON);
sprintf(horaAP,"HORA OFF: %02d:%02d",horaOFF,minutoOFF);
lcd.setCursor(0,0);                                          
lcd.print(horaEN);  
lcd.setCursor(0,1);                                          
lcd.print(horaAP); 
                              
}
void defineON()
{
char Hora_In_En[3];
char Min_In_En[3];

int HoraEN = 0 ;
int MinEN = 0;

int cont = 0;

lcd.clear();
lcd.setCursor(0,0);                                          
lcd.print("ingrese Horario");  
lcd.setCursor(0,1);                                          
lcd.print("ON(hhmm):");

while (cont < 4)
{
  char T = teclado.getKey();
  if (T)
  {
    if (cont < 2){
      Hora_In_En[cont] = T;
      cont++;
    }
    else{
      Min_In_En[cont - 2] = T;
      cont++;
    }

    ////Como se usa un ternario!

    // cont < 2 ? Hora_In_En[cont] = T : Min_In_En[cont - 2] = T;
  
    // int i = 0;

    // if(condicion){
    //   i = 1;
    // }
    // else{
    //   i = 2;
    // }

    // int i = condcion ? 1 : 2;

    ////
    
    lcd.setCursor(10 + cont, 1);
    lcd.print(T);
  }
}
HoraEN = atoi( Hora_In_En);
MinEN = atoi(Min_In_En);

EEPROM.put(0,HoraEN);
EEPROM.put(4,MinEN);
}

void defineOFF()
{

char Hora_In_Ap[3];
char Min_In_Ap[3];

int HoraAP = 0;
int MinAP = 0;


int cont = 0;


lcd.clear();
lcd.setCursor(0,0);                                          
lcd.print("ingrese Horario");  
lcd.setCursor(0,1);                                          
lcd.print("OFF(hhmm):"); 

while(cont < 4)
{
char T = teclado.getKey();
    if(T)
    {
     if(cont < 2)
     {
      Hora_In_Ap[cont] = T;
      cont++;
     }
     else
     {
      Min_In_Ap[cont-2] = T;
      cont++;
     }
     lcd.setCursor(10+cont,1);                                          
     lcd.print(T);
    }
    

}
HoraAP = atoi( Hora_In_Ap);
MinAP = atoi(Min_In_Ap);

EEPROM.put(8,HoraAP);
EEPROM.put(12,MinAP);
 
}
