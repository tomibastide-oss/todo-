#include <SPI.h>
#include <MFRC522.h>

int resetPin = 9;
int ssPin = 10;

MFRC522 rf(ssPin, resetPin);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rf.PCD_Init();
  delay(10);
  rf.PCD_DumpVersionToSerial();
  Serial.println("Escanee Tarjeta...");
}

void loop() {
  if (!rf.PICC_IsNewCardPresent())
    return;

  if (!rf.PICC_ReadCardSerial())
    return;

  Serial.print("UID: ");

  for (byte i = 0; i < rf.uid.size; i++)
  {
    if (rf.uid.uidByte[i] < 0x10)
      Serial.print(" 0");
    else
      Serial.print(" ");
    Serial.print(rf.uid.uidByte[i], HEX);
  }
  Serial.println();
  rf.PICC_HaltA();
}
