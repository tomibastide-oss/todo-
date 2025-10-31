#include <Stepper.h>

const int btnInicio = 8;
int valMap1 = 0;
int velocidad = A0;

Stepper motor (2048, 2, 4, 3, 5);

void setup()
{
  Serial.begin(9600);
  pinMode(btnInicio, INPUT);
  Serial.begin(9600);
  motor.setSpeed(15);
}
void loop()
{
  if (digitalRead(btnInicio) == 1)
 {
    motor.step(2048);
    delay(1000);
  }
}
