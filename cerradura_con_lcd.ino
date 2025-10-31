#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#include <Keypad.h>

const int ledR = 10;
const int ledV = 11;
const int buzz = 12;

char keys[4][4] = {   
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinesFilas[4] = {9,8,7,6};   
byte pinesColumnas[4] = {5,4,3,2}; 

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, 4, 4); 

char tecla;       
char claveUsu[5];        
char claveMaestra[5];   
byte cont = 0;    
byte claveMaes = false;

void setup()
{
    lcd.init();
    lcd.backlight();
    lcd.clear();
          
 pinMode(ledR, OUTPUT);
 pinMode(ledV, OUTPUT);
 lcd.setCursor(0,0);
 lcd.print("ingrese la clave Maestra");
}
void loop()
{
if (!claveMaes)
    {
  tecla = teclado.getKey();   
  if (tecla)        
  {
    claveMaestra[cont] = tecla;   
    cont++;
     lcd.setCursor(0,1);
 lcd.print("tecla");
  } 
  if (cont == 4)
  {
    if(!strcmp(claveUsu, claveMaestra))    
      cont = 0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print ("CLAVE MAESTRA GUARDADA");
      delay(1000);
      lcd.setCursor(0,1);
      lcd.print ("--------------------------");
      delay(1000);
      lcd.clear();
      lcd.
      setCursor(0,0);
      lcd.print ("Ingrese la clave");
      delay(1000);
    claveMaes = true;
  }
}  
  
else
  {
  tecla = teclado.getKey();
  if (tecla)       
  {
    claveUsu[cont] = tecla;   
    cont++;             
lcd.clear();
      lcd.setCursor(0,0);
      lcd.print ("Ingrese la clave");
  }
  if (cont == 4)       
  {
    if  (!strcmp(claveUsu, claveMaestra)) 
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print ("clave Correcta");
      digitalWrite(ledV,1);
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print ("ABIERTO...");
      lcd.setCursor(0,1);
      lcd.print ("5");
      delay(1000);
       lcd.setCursor(0,1);
      lcd.print ("4");
      delay(1000);
       lcd.setCursor(0,1);
      lcd.print ("3");
      delay(1000);
       lcd.setCursor(0,1);
      lcd.print ("2");
      delay(1000);
       lcd.setCursor(0,1);
       lcd.print ("1");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
       lcd.print ("Cerrado....");
      delay(1000);
      lcd.setCursor(0,1);
       lcd.print ("closed...");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
       lcd.print ("INGRESE");
      delay(1000);
      lcd.setCursor(0,1);
       lcd.print ("CLAVE");
      delay(1000);
    }
    else
    {
     lcd.clear();
      lcd.setCursor(0,0);
       lcd.print ("incorrecto");
      delay(1000);
      digitalWrite(ledR,1);
      delay(1000);
    }
   
    cont = 0;
  digitalWrite(ledR,0);
  digitalWrite(ledV,0);
    
}
}
}
