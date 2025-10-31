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
  Serial.println("Escanee Tarjeta par Ingresar datos...");
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

  byte buffer[16];
  byte block;
  MFRC522::StatusCode status;
  byte len;

  Serial.setTimeout(20000);

//-------------------------------------------------------------------------APELLIDO--------------------------------------------
  Serial.println("Ingrese Apellido (Finalice con #):");
  len = Serial.readBytesUntil('#', (char *) buffer, 16) ;
  for (byte i = len; i < 16; i++) 
    buffer[i] = ' ';

  block = 4;
  status = rf.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(rf.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Fallo en Autentificación");
    Serial.println(rf.GetStatusCodeName(status));
    return;
  }

  status = rf.MIFARE_Write(block, buffer, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Fallo en escritura: ");
    Serial.println(rf.GetStatusCodeName(status));
    return;
  }
  else 
    Serial.println("Escritura Exitosa.");
    
  Serial.end();
  Serial.begin(9600);

//-------------------------------------------------------------------------NOMBRE--------------------------------------------
  Serial.println("Ingrese Nombre (Finalice con #):");
  len = Serial.readBytesUntil('#', (char *) buffer, 15) ;
  for (byte i = len; i < 15; i++) buffer[i] = ' ';

  block = 5;
  status = rf.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(rf.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Fallo en Autentificaión");
    Serial.println(rf.GetStatusCodeName(status));
    return;
  }

  status = rf.MIFARE_Write(block, buffer, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Fallo en escritura: ");
    Serial.println(rf.GetStatusCodeName(status));
    return;
  }
  else 
    Serial.println("Escritura Exitosa.");
    
  Serial.end();
  Serial.begin(9600);
//-------------------------------------------------------------------------DOCUMENTO--------------------------------------------
  Serial.println("Ingrese Documento de Identidad (Finalice con #):");
  len = Serial.readBytesUntil('#', (char *) buffer, 16) ;
  for (byte i = len; i < 16; i++) buffer[i] = ' ';

  block = 6;
  status = rf.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(rf.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Fallo en Autentificaión");
    Serial.println(rf.GetStatusCodeName(status));
    return;
  }

  status = rf.MIFARE_Write(block, buffer, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("Fallo en escritura: ");
    Serial.println(rf.GetStatusCodeName(status));
    return;
  }
  else 
    Serial.println("Escritura Exitosa.");
  
//---------------------------------------------------------------------------------------------------------------------------
  Serial.println(" ");
  Serial.println("-------------FINALIZADO----------");
  rf.PICC_HaltA();
  rf.PCD_StopCrypto1(); 
}
