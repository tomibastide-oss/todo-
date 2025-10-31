#include <LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd(0x3f,16,2); // direcciones (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

void setup() {
  lcd.init();             //inicia el LCD
  lcd.backlight();        //enciende iluminacion
  lcd.clear();            //limpia display
}
void loop() { 
  lcd.setCursor(0,0);                   //Ubica cursor en fila 0 columna 0             
  lcd.print("Linea Texto 1");         //Muestra el texto
  lcd.setCursor(0,1);                   //Ubica cursor en fila 1 columna 0             
  lcd.print("Segunda Linea");   //Muestra el texto
  delay(1000);
}
