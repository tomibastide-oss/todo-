#include <Stepper.h>

int valIng = 0;
const float angPaso = 0.17578;
Stepper motor(2048,2,4,3,5); 
void setup() 
{
  Serial.begin(9600);
  motor.setSpeed(10);
  Serial.println("ingrese angulo a girar");
}

void loop() 
{
 if (Serial.available ())
{
  valIng = Serial.parseInt();
  if (valIng != 0)
  {
  Serial.println("girando....");
  int pas = valIng / angPaso;
  motor.step (pas);
  Serial.println("giro finalizado");
  Serial.println("ingrese angulo a girar");
}
}
    
}
