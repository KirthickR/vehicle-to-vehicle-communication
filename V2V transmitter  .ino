// This example shows how to connect to Cayenne using an ESP8266 and send/receive sample data.
// Make sure you install the ESP8266 Board Package via the Arduino IDE Board Manager and select the correct ESP8266 board before compiling.

//#define CAYENNE_DEBUG
//#define CAYENNE_PRINT Serial
//#include <CayenneMQTTESP8266.h>



//#include <SoftwareSerial.h>
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
#include<EEPROM.h>
  
#include <ESP8266WiFi.h>;
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int r=8,hb,ti;

int error,sc,bb;
int show = -1;



void setup() {
 Serial.begin(9600);
 pinMode(D4, INPUT_PULLUP);
 pinMode(D5, INPUT_PULLUP);
 pinMode(D6, INPUT_PULLUP);
 pinMode(D7, INPUT_PULLUP);
 
   Serial.print("welcome");
   delay(3000);
Wire.begin();
  Wire.beginTransmission(0x27);
  error = Wire.endTransmission();
  Serial.print("Error: ");
  Serial.print(error);
  if (error == 0) {
    Serial.println(": LCD found.");
    show = 0;
    lcd.begin(16, 2);  // initialize the lcd
  } else {
    Serial.println(": LCD not found.");
  }  // if
   
     delay(20);
 lcd.home();
 lcd.setBacklight(255);
    lcd.clear();
    lcd.print("WELCOME");
     //lcd.print(hu);
    lcd.setCursor(0, 1);
        lcd.print(" ");
delay(1000); 

  }

void loop() 
{
if(digitalRead(D5)==0)
{
lcd.clear();
    lcd.print("medical");
    lcd.setCursor(0, 1);
     lcd.print("emergency");
delay(1500);
Serial.println("1,0,0");
}

if(digitalRead(D6)==0)
{
lcd.clear();
    lcd.print("brake");
    lcd.setCursor(0, 1);
     lcd.print("applied");
delay(1500);
Serial.println("2,0,0");
}

if(digitalRead(D7)==0)
{
lcd.clear();
    lcd.print("speed");
    lcd.setCursor(0, 1);
     lcd.print("limiting");
delay(1500);
Serial.println("3,0,0");
}

if(digitalRead(D4)==0)
{
lcd.clear();
lcd.print("vehicle");
lcd.setCursor(0, 1);
lcd.print("breakdown");

delay(1500);
Serial.println("4,0,0");
}
}
