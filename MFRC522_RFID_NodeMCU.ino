#include <ESP8266WiFi.h>   // Library for Wi-Fi
#include <SPI.h>           // Library for SPI communication
#include <MFRC522.h>       // Library for RFID

// Wi-Fi credentials
#define WIFI_SSID "TESTNET"
#define WIFI_PASSWORD "India@123"


// Firebase setup (add these if needed later)
#define FIREBASE_HOST "https://esp8266-1e5b0-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "GUgDc9XQaeObaNRaF5tRCCtM7MPiF7x96Qf2BS6f"
// FirebaseData firebaseData;

// RFID Configuration
#define RST_PIN D1         // Reset pin for MFRC522 (connect to D1 on NodeMCU)
#define SS_PIN D2          // Slave Select (SS) pin for MFRC522 (connect to D2 on NodeMCU)

// Create MFRC522 instance
MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(115200);  // Initialize serial communication
  SPI.begin();           // Initialize SPI bus for RFID reader
  rfid.PCD_Init();       // Initialize RFID reader
}
  

void loop() {
  // Look for new RFID cards
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    delay(50);
    return;
  }

  // Print UID of the RFID tag
  Serial.print("RFID Tag UID: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
    Serial.print(rfid.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  // String rfidTagUID = "";  // Variable to store the UID as a string

  // Halt PICC to stop reading additional tags
  rfid.PICC_HaltA();
  delay(1000);  // Delay for readability
}