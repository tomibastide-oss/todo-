#include <ThreeWire.h>
#include <RtcDS1302.h>

ThreeWire conex(6, 5, 7);
RtcDS1302 <ThreeWire> rtc(conex);

void setup() {
 rtc.Begin();
 Serial.begin(9600);
 rtc.SetIsRunning(true);
 RtcDateTime fecha_hora = RtcDateTime(__DATE__,__TIME__); 
 rtc.SetDateTime(fecha_hora);
}

void loop() { 
RtcDateTime now = rtc.GetDateTime();
Serial.print(now.Day());
Serial.print(now.Month());
Serial.println(now.Year());
Serial.print(now.Hour());
Serial.print(now.Minute());
Serial.println(now.Second());



delay(1000);
}
