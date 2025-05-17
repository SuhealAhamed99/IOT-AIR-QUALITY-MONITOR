#define BLYNK_TEMPLATE_ID "TMPL3aOJXbl1f"
#define BLYNK_TEMPLATE_NAME "IOT Air Quality Monitor Task 4"
#define BLYNK_AUTH_TOKEN "ejAeVoYji8w04tDLaveR7GEFzkJhebvW"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// WiFi credentials
char ssid[] = "Wokwi-GUEST";
char password[] = "";

// Pin definitions
#define POT_PIN      34   // Simulate MQ2 analog output with potentiometer
#define RED_LED      2
#define GREEN_LED    4
#define BUZZER_PIN   15

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variables
bool gasDetected = false;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  Serial.begin(115200);

  pinMode(POT_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Air Quality:");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);

  lcd.setCursor(0, 1);
  lcd.print("Monitoring...   ");
}

void loop() {
  Blynk.run();

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    int gasLevel = analogRead(POT_PIN); // Use potentiometer to simulate MQ2 analog output
    Serial.print("Gas Level: ");
    Serial.println(gasLevel);

    Blynk.virtualWrite(V2, gasLevel);   // Send to Custom Chart

    if (gasLevel > 2000 && !gasDetected) {
      gasDetected = true;

      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(BUZZER_PIN, HIGH);

      lcd.setCursor(0, 1);
      lcd.print("Gas Detected!   ");

      Serial.println("⚠️ Gas Detected! Sending to Blynk...");
      
    } 
    else if (gasLevel <= 2000 && gasDetected) {
      gasDetected = false;

      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(BUZZER_PIN, LOW);

      lcd.setCursor(0, 1);
      lcd.print("Air Clean       ");

      Serial.println("✅ Air is Clean. Sending to Blynk...");
    
    }
  }
}
