// This code only takes the UID in string form.
// If you want to see more detailed information about an RFID card or keychain, please run the program code "DumpInfo".
// The "DumpInfo" program code is located at :
// Library folder "MFRC522" -> "examples" folder -> "DumpInfo" folder -> DumpInfo.ino
// or
// From Arduino IDE : File -> Examples -> MFRC522 -> DumpInfo
// or
// From Arduino IDE : File -> Examples -> INCOMPATIBLE-> MFRC522 -> DumpInfo

//----------------------------------------Including the libraries.
#include <SPI.h>
#include <MFRC522.h>
//----------------------------------------

// Defines SS/SDA PIN and Reset PIN for RFID-RC522.
#define SS_PIN  5  
#define RST_PIN 4

// Variable to read data from RFID-RC522.
int readsuccess;
char str[32] = "";
String UID_Result = "";

// Create MFRC522 object as "mfrc522" and set SS/SDA PIN and Reset PIN.
MFRC522 mfrc522(SS_PIN, RST_PIN);

//________________________________________________________________________________getUID()
// Subroutine to obtain UID/ID when RFID card or RFID keychain is tapped to RFID-RC522 module.
int getUID() {  
  if(!mfrc522.PICC_IsNewCardPresent()) {
    return 0;
  }
  if(!mfrc522.PICC_ReadCardSerial()) {
    return 0;
  }
  
  byteArray_to_string(mfrc522.uid.uidByte, mfrc522.uid.size, str);
  UID_Result = str;
  
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
  
  return 1;
}
//________________________________________________________________________________

//________________________________________________________________________________byteArray_to_string()
void byteArray_to_string(byte array[], unsigned int len, char buffer[]) {
  for (unsigned int i = 0; i < len; i++) {
    byte nib1 = (array[i] >> 4) & 0x0F;
    byte nib2 = (array[i] >> 0) & 0x0F;
    buffer[i*2+0] = nib1  < 0xA ? '0' + nib1  : 'A' + nib1  - 0xA;
    buffer[i*2+1] = nib2  < 0xA ? '0' + nib2  : 'A' + nib2  - 0xA;
  }
  buffer[len*2] = '\0';
}
//________________________________________________________________________________

//________________________________________________________________________________VOID SETUP()
void setup(){
  // put your setup code here, to run once:

  Serial.begin(115200);
  Serial.println();
  delay(1000);

  // Init SPI bus.
  SPI.begin();      
  // Init MFRC522.
  mfrc522.PCD_Init(); 

  delay(1000);

  Serial.println();
  Serial.println("Please tap your card or key chain to the RFID-RC522 module.");
}
//________________________________________________________________________________

//________________________________________________________________________________VOID LOOP()
void loop(){
  // put your main code here, to run repeatedly:
  
  readsuccess = getUID();
 
  if(readsuccess){
    Serial.println();
    Serial.print("UID : ");
    Serial.println(UID_Result);
    delay(2000);
  }
  delay(10);
}
//________________________________________________________________________________
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
