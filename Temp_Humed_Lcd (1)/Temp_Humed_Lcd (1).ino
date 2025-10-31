#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>

LiquidCrystal_I2C lcd(0x3f,16,2);
int sens = 2;
DHT dht(sens, DHT11);
float temp;
int humed;

void setup() {
  dht.begin();
  lcd.init();             //inicia el LCD
  lcd.backlight();        //enciende iluminacion
  lcd.clear();            //limpia display

}

void loop() {
  temp = dht.readTemperature();
  humed = dht.readHumidity();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.setCursor(6,0);
  lcd.print(temp);
  lcd.setCursor(12,0);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humedad: ");
  lcd.setCursor(9,1);
  lcd.print(humed);
  lcd.setCursor(12,1);
  lcd.print("%");
  delay(2000);
}
