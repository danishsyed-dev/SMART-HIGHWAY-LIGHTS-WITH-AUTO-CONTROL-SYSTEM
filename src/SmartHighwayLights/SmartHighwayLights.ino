/*
 * Smart Highway Lights with Auto Control System
 * 
 * Diploma Major Project (2019)
 * Author: SYED DANISH ALI
 * 
 * Description:
 * This project implements an intelligent street lighting system that automatically
 * detects day/night cycles and vehicle movement to conserve energy.
 * 
 * Features:
 * - Automatic Day/Night detection using LDR
 * - Vehicle detection using IR Sensors
 * - Energy efficient: Lights only turn ON when vehicle is detected at night
 * - Real-time status display on LCD
 * 
 * Application:
 * - Highways
 * - Smart City Infrastructure
 */

#include <LiquidCrystal.h>

// PIN DEFINITIONS
// LCD Pins: RS=8, EN=9, D4=10, D5=11, D6=12, D7=13
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

// Sensor Pins
const int PIN_LDR = A0;    // Light Dependent Resistor for Day/Night detection
const int PIN_IR1 = 2;     // IR Sensor 1 (Entrance/Zone 1)
const int PIN_IR2 = 3;     // IR Sensor 2 (Zone 2/Exit)

// Actuator Pins (LEDs representing Highway Lights)
const int PIN_LED1 = 4;
const int PIN_LED2 = 5;
const int PIN_LED3 = 6;
const int PIN_LED4 = 7;

// Thresholds
const int LDR_THRESHOLD = 200; // Value below this is considered NIGHT

void setup() {
  // Initialize LCD
  lcd.begin(16, 2); 
  lcd.setCursor(0, 0);
  lcd.print("HIGHWAY LIGHTS");
  lcd.setCursor(0, 1);
  lcd.print("SMART CONTROL SYS");
  
  // Initialize LED Pins
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
  pinMode(PIN_LED4, OUTPUT);
  
  // Set Initial State (All LEDs ON for test)
  digitalWrite(PIN_LED1, HIGH);
  digitalWrite(PIN_LED2, HIGH);
  digitalWrite(PIN_LED3, HIGH);
  digitalWrite(PIN_LED4, HIGH); 
  
  // Initialize Sensor Pins
  pinMode(PIN_IR1, INPUT);
  pinMode(PIN_IR2, INPUT);
  pinMode(PIN_LDR, INPUT);
  
  delay(3000); // Wait for initialization
  
  // Set up Monitoring Display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("MODE  :");
  delay(50);
  lcd.setCursor(0, 1);
  lcd.print("LIGHTS:");
  delay(50);
}

void loop() {
  int sensorValue = analogRead(PIN_LDR);
  
  // Check Day/Night Condition
  if (sensorValue <= LDR_THRESHOLD) {
    // NIGHT MODE
    lcd.setCursor(7, 0);
    lcd.print("NIGHT");
    delay(50);
    
    // Check for Vehicle Movement
    if (digitalRead(PIN_IR1) == LOW) { // Vehicle detected at Sensor 1
      lcd.setCursor(7, 1);
      lcd.print("ON  ");
      
      // Turn ON first set of lights (Low logic triggers relay/LED in this setup?)
      // Note: Original comments and logic suggest LOW turns ON or OFF depending on wiring.
      // Based on original code: digitalWrite(led1,LOW) when IR1 is LOW (active).
      // Assuming Active LOW or Sink configuration for LEDs.
      digitalWrite(PIN_LED1, LOW);
      digitalWrite(PIN_LED2, LOW);
      
      // Keep next set OFF or previous state? Original code commented out led3/4 manipulation here
      // digitalWrite(PIN_LED3, HIGH);
      // digitalWrite(PIN_LED4, HIGH);
      
      delay(2000); 
    }
    else if (digitalRead(PIN_IR2) == LOW) { // Vehicle detected at Sensor 2
      lcd.setCursor(7, 1);
      lcd.print("ON  ");
      
      // Turn ON second set of lights
      digitalWrite(PIN_LED3, LOW);
      digitalWrite(PIN_LED4, LOW);
      
      // Turn OFF first set? Original code commented out led1/2 manipulation here
      // digitalWrite(PIN_LED1, HIGH);
      // digitalWrite(PIN_LED2, HIGH);
      
      delay(2000); 
    }
    else {
      // NO Vehicle Detected at Night -> Lights OFF (Energy Saving)
      lcd.setCursor(7, 1);
      lcd.print("OFF  ");
      
      digitalWrite(PIN_LED1, HIGH);
      digitalWrite(PIN_LED2, HIGH);
      digitalWrite(PIN_LED3, HIGH);
      digitalWrite(PIN_LED4, HIGH);
      
      delay(100); 
    }
  }
  else {
    // DAY MODE -> Lights Always OFF
    lcd.setCursor(7, 0);
    lcd.print("DAY   ");
    lcd.setCursor(7, 1);
    lcd.print("OFF  ");
    
    digitalWrite(PIN_LED1, HIGH);
    digitalWrite(PIN_LED2, HIGH);
    digitalWrite(PIN_LED3, HIGH);
    digitalWrite(PIN_LED4, HIGH);
    
    delay(100); 
  }
}
