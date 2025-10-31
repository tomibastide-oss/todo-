#include <EEPROM.h>     
#include <SPI.h>
#include <MFRC522.h>  

int successRead;    

byte storedCard[4];   
byte readCard[4]; 
byte masterCard[4]={0x8A, 0xBE, 0x63, 0x1A};   

// Create MFRC522 instance.
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 

///////////////////////////////////////// Setup /////////////////////////////////////////
void setup() {
//  Arduino Pin Configuration
  Serial.begin(9600); 
  SPI.begin();           
  mfrc522.PCD_Init();    
  Serial.println ("escaneee la targeta por favor...");
  Serial.println("si es configurador se le dara la entrada a modod configuracion");
}
///////////////////////////////////////// Main Loop ///////////////////////////////////
void loop () 
{
  getID();
        
  if ( isMaster(readCard)) 
  {
    Serial.println("Hello Master - Modo de programa ingresado");   
    Serial.println("Escanee un PICC para AGREGAR o QUITAR a EEPROM");
    Serial.println("Escanee la tarjeta maestra nuevamente para salir del modo de programa");
    Serial.println("-----------------------------");
    
    getID();    
    
    if ( isMaster(readCard)) 
    {    
        
    if ( findID(readCard) ) 
    { 
      Serial.println("Conozco este PICC, quitando ...");
      deleteID(readCard);
      Serial.println("-----------------------------");
      Serial.println("Escanee un PICC para AGREGAR o QUITAR a EEPROM");
    }
    else 
    {               
      Serial.println("No sé esta PICC, añadiendo ...");
      writeID(readCard);
      Serial.println("-----------------------------");
      Serial.println("Escanee un PICC para AGREGAR o QUITAR a EEPROM");
    }
  }
  else 
  {
    if ( findID(readCard) ) 
    { 
      Serial.println("Bienvenido, pasarás");
    }
    else 
    {      
      Serial.println("No pasarás");
    }
  }   
}
//////////////////////////////////////// Read an ID from EEPROM //////////////////////////////
void readID( int number ) {
    int start = (number * 4 ) + 2;    
    for ( int i = 0; i < 4; i++ ) {     
      storedCard[i] = EEPROM.read(start + i);   
    }
  }

///////////////////////////////////////// Add ID to EEPROM   ///////////////////////////////////
void writeID( byte a[] ) {
      if ( !findID( a ) ) {     
        int num = EEPROM.read(0);    
        int start = ( num * 4 ) + 6;  
        num++;              
        EEPROM.write( 0, num );     
        for ( int j = 0; j < 4; j++ ) {  
          EEPROM.write( start + j, a[j] );  
        }
        Serial.println("Registro de ID agregado exitosamente a EEPROM");
      }
      else { 
        Serial.println("¡Ha fallado! Hay algún problema con la identificación o EEPROM incorrecta");
      }
     
    }
/////////////////////////////////////////////////////escaneo/////////////////////////////////////////
void getID (){
   if ( ! mfrc522.PICC_IsNewCardPresent()) { 
    return ;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {  
    return ;
  }
 Serial.println("UID de PICC escaneado:");
  for ( int i = 0; i < 4; i++) {  //
    readCard[i] = mfrc522.uid.uidByte[i];
    Serial.print(readCard[i], HEX);
  }
  
  Serial.println("");
  mfrc522.PICC_HaltA(); 
}
///////////////////////////////////////// Remove ID from EEPROM   ///////////////////////////////////
void deleteID( byte a[] ){ 
      if ( !findID( a ) ) {    
        Serial.println("¡Ha fallado! Hay algún problema con la identificación o EEPROM incorrecta");
      }
      else {
        int num = EEPROM.read(0);   
        int slot;       
        int start;     
        int looping;    
        int j;
        int count = EEPROM.read(0); 
        slot = findIDSLOT( a );   
        start = (slot * 4) + 2;
        looping = ((num - slot) * 4);
        num--;     
        EEPROM.write( 0, num );   
        for ( j = 0; j < looping; j++ ) {        
          EEPROM.write( start + j, EEPROM.read(start + 4 + j));   
        }
        for ( int k = 0; k < 4; k++ ) {         
          EEPROM.write( start + j + k, 0);
        }
        Serial.println("Registro de identificación eliminado con éxito de EEPROM");
      }
      
    }

///////////////////////////////////////// Check Bytes   ///////////////////////////////////
bool checkTwo ( byte a[], byte b[] )    
{
   for ( int k = 0; k < 4; k++ ) 
   {  
      if ( a[k] != b[k] ) 
      {    
        return false;
      }
  }
      return true;  
}
///////////////////////////////////////// Find Slot   ///////////////////////////////////
uint8_t findIDSLOT( byte find[] ) {
    int count = EEPROM.read(0);       
      for (int i = 1; i <= count; i++ ) {    
        readID(i);               
       if ( checkTwo(find,storedCard)){   
          return i;      
          }}}
///////////////////////////////////////// Find ID From EEPROM   ///////////////////////////////////
bool findID ( byte find[] ) {
      int count = EEPROM.read(0);    
      for ( int i = 1; i < count; i++ ) 
      {   
       readID(i);        
         if (checkTwo(find,storedCard))
         {   
            return true;
         }
      }
    return false; 
    }

////////////////////// Check readCard IF is masterCard   ///////////////////////////////////
bool isMaster( byte test[] ) {
  return checkTwo(test, masterCard);
}
