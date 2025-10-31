#include <Stepper.h>     

Stepper motor(2048, 2, 4, 3, 5);   // Configuracion: Pasos para vuelta completa (2048) - pines de control IN1, IN3, IN2, IN4
 
void setup() {
  motor.setSpeed(3);       // en RPM (valores de 1, 2 o 3 para 28BYJ-48)
}
 
void loop() {
  motor.step(1024);
  delay(1000);
  motor.step(-1024);
  delay(1000); 
}
