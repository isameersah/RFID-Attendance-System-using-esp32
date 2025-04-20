#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

// Define the SS/SDA PIN and Reset PIN for RFID-RC522
#define SS_PIN  5  
#define RST_PIN 4

// Define the button PIN
#define BTN_PIN 15

// Set LCD Columns and Rows
int lcdColumns = 20;
int lcdRows = 4;

int readsuccess;
char str[32] = "";
String UID_Result = "--------";

// Initialize the LCD
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

// Create MFRC522 object for RFID
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup(){
  pinMode(BTN_PIN, INPUT_PULLUP);
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  
  // Initialize SPI and MFRC522
  SPI.begin();      
  mfrc522.PCD_Init(); 
  
  delay(1000);
  lcd.clear();
  
  // Display the initial message
  lcd.setCursor(0, 0);
  lcd.print("Please tap your");
  lcd.setCursor(0, 1);
  lcd.print("card or keychain");
  delay(2000);  // Display for 2 seconds
}

void loop(){
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("UID: ");
  lcd.setCursor(0, 1);
  lcd.print(UID_Result);  // Display the UID

  // Read the RFID
  readsuccess = getUID();
  if (readsuccess){
    lcd.setCursor(0, 2);
    lcd.print("Card Detected");
    delay(500); // Display for 0.5 second
  }
  
  delay(10);  // Small delay
}

// Get the UID of the RFID card
int getUID() {  
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return 0;
  }
  if (!mfrc522.PICC_ReadCardSerial()) {
    return 0;
  }
  
  byteArray_to_string(mfrc522.uid.uidByte, mfrc522.uid.size, str);
  UID_Result = str;
  
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
  
  return 1;
}

// Convert byte array to string
void byteArray_to_string(byte array[], unsigned int len, char buffer[]) {
  for (unsigned int i = 0; i < len; i++) {
    byte nib1 = (array[i] >> 4) & 0x0F;
    byte nib2 = (array[i] >> 0) & 0x0F;
    buffer[i*2+0] = nib1  < 0xA ? '0' + nib1  : 'A' + nib1  - 0xA;
    buffer[i*2+1] = nib2  < 0xA ? '0' + nib2  : 'A' + nib2  - 0xA;
  }
  buffer[len*2] = '\0';
}
