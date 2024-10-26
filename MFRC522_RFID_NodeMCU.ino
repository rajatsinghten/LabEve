#include <SPI.h>
#include <MFRC522.h>

// RFID configuration
#define RST_PIN D1
#define SS_PIN D2
MFRC522 rfid(SS_PIN, RST_PIN);

// LED configuration
#define LED_PIN1 D3 // LED pin 1
#define LED_PIN2 D8 // LED pin 2

void setup() {
  Serial.begin(115200);

  // Initialize SPI and RFID
  SPI.begin();
  rfid.PCD_Init();

  // Set up LED pins
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  digitalWrite(LED_PIN1, LOW); // Turn off LEDs initially
  digitalWrite(LED_PIN2, LOW);
}

void loop() {
  // Check for new RFID card
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    delay(50);
    return;
  }

  // Read the RFID UID and store it as a string
  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    uid += String(rfid.uid.uidByte[i] < 0x10 ? "0" : ""); // Add leading zero if needed
    uid += String(rfid.uid.uidByte[i], HEX);
  }

  Serial.print("UID: ");
  Serial.println(uid);

  // Blink LEDs as feedback for successful scan
  digitalWrite(LED_PIN1, HIGH);
  delay(300);  // LED on duration
  digitalWrite(LED_PIN1, LOW);

  digitalWrite(LED_PIN2, HIGH);
  delay(300);
  digitalWrite(LED_PIN2, LOW);

  // Halt PICC to allow a new reading
  rfid.PICC_HaltA();
  delay(1000); // Wait before the next read
}
