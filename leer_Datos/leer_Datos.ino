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
  Serial.println("Escanee Tarjeta para leer datos...");
}

void loop() {
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) 
    key.keyByte[i] = 0xFF;

  
  if (!rf.PICC_IsNewCardPresent())
    return;
  
  if (!rf.PICC_ReadCardSerial())
    return;

  Serial.print("UID: ");
  for(byte i=0; i<rf.uid.size; i++)
  {
    if (rf.uid.uidByte[i] < 0x10)
      Serial.print(" 0");
    else
      Serial.print(" ");
    Serial.print(rf.uid.uidByte[i], HEX);
  }
  Serial.println();

  
  byte block;
  MFRC522::StatusCode status;
  byte len = 18;
  byte buffer[18];
//-------------------------------------------------------------------------APELLIDO--------------------------------------------
  Serial.print("Apellido: ");
  block = 4;
  
  status = rf.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(rf.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Fallo en Autentificación");
    Serial.println(rf.GetStatusCodeName(status));
    return;
  }

  status = rf.MIFARE_Read(block, buffer, &len);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Fallo en lectura: ");
    Serial.println(rf.GetStatusCodeName(status));
    return;
  }

  for (int i=0; i<16; i++)
  {
    if (buffer[i] != 32)
    {
      Serial.write(buffer[i]);
    }
  }
  Serial.println(" ");
//-------------------------------------------------------------------------NOMBRE--------------------------------------------
  Serial.print("Nombre: ");
  block = 5;
  
  status = rf.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(rf.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Fallo en Autentificación");
    Serial.println(rf.GetStatusCodeName(status));
    return;
  }

  status = rf.MIFARE_Read(block, buffer, &len);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Fallo en lectura: ");
    Serial.println(rf.GetStatusCodeName(status));
    return;
  }

  for (int i=0; i<16; i++)
  {
    if (buffer[i] != 32)
    {
      Serial.write(buffer[i]);
    }
  }
  Serial.println(" ");
//-------------------------------------------------------------------------DOCUMENTO--------------------------------------------
 
  Serial.print("Documento: ");
  block = 6;
  
  status = rf.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(rf.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Fallo en Autentificación");
    Serial.println(rf.GetStatusCodeName(status));
    return;
  }

  status = rf.MIFARE_Read(block, buffer, &len);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Fallo en lectura: ");
    Serial.println(rf.GetStatusCodeName(status));
    return;
  }

  for (int i=0; i<16; i++)
  {
    if (buffer[i] != 32)
    {
      Serial.write(buffer[i]);
    }
  }
  Serial.println();
//---------------------------------------------------------------------------------------------------------------------------
  Serial.println(" ");
  rf.PICC_HaltA();
  rf.PCD_StopCrypto1(); 
}
