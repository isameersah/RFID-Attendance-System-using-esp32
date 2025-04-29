//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> RFID + LCD + Button (Combined)
//----------------------------------------Including the libraries.
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
//----------------------------------------

// Defines SS/SDA PIN and Reset PIN for RFID-RC522.
#define SS_PIN  5  
#define RST_PIN 4

// Defines the button PIN.
#define BTN_PIN 15

// LCD configuration
int lcdColumns = 20;
int lcdRows = 4;

// Variables
int readsuccess;
char str[32] = "";
String UID_Result = "--------";

// LCD object (address: 0x27, 20 cols, 4 rows)
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

// RFID object
MFRC522 mfrc522(SS_PIN, RST_PIN);

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

//________________________________________________________________________________getUID()
int getUID() {  
  if(!mfrc522.PICC_IsNewCardPresent()) {
    return 0;
  }
  if(!mfrc522.PICC_ReadCardSerial()) {
    return 0;
  }
  
  byteArray_to_string(mfrc522.uid.uidByte, mfrc522.uid.size, str);
  UID_Result = str;

  Serial.println();
  Serial.print("UID : ");
  Serial.println(UID_Result);
  
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
  
  return 1;
}
//________________________________________________________________________________

//________________________________________________________________________________setup()
void setup(){
  // Start serial
  Serial.begin(115200);
  delay(1000);
  Serial.println();
  Serial.println("Please tap your card or keychain...");

  // Setup button
  pinMode(BTN_PIN, INPUT_PULLUP);
  
  // Init LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Init SPI & RFID
  SPI.begin();      
  mfrc522.PCD_Init(); 
  delay(1000);
}
//________________________________________________________________________________

//________________________________________________________________________________loop()
void loop(){
  lcd.setCursor(0, 0);
  lcd.print("Tap your card/key  ");

  lcd.setCursor(0, 1);
  lcd.print("or keychain        ");

  lcd.setCursor(0, 2);
  lcd.print("UID: ");
  lcd.print(UID_Result);
  lcd.print("        "); // Clear extra space

  lcd.setCursor(0, 3);
  lcd.print("BTN: ");
  lcd.print(digitalRead(BTN_PIN));
  lcd.print("          "); // Clear old text

  readsuccess = getUID();
 
  if(readsuccess){
    delay(2000);
  }

  delay(100);
}



//________________________________________________________________________________
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
