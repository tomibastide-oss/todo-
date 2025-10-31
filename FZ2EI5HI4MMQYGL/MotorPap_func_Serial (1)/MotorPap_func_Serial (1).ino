#include <Stepper.h>      
const float angPas = 0.1758; 
int valIng = 0;

Stepper motor1(2048, 2, 4, 3, 5);   
 
void setup() {
  motor1.setSpeed(3);      
  Serial.begin(9600);
  Serial.println("Ingrese angulo a girar: ");
}
 
void loop() {
  if (Serial.available())
  {
    valIng = Serial.parseInt();
    if (valIng !=0)
    {
      Serial.print("Girando... ");
      Serial.print(valIng);
      Serial.println("grados");
      gira_grados(valIng);
      Serial.println("Giro finalizado");
      Serial.println("------------------------------");
      Serial.println("Ingrese angulo a girar: ");
    }
  }
}

void gira_grados(float grad)
{
  int pas = grad / angPas;
  motor1.step(pas); 
  digitalWrite(2,0); 
  digitalWrite(3,0); 
  digitalWrite(4,0); 
  digitalWrite(5,0); 
}
