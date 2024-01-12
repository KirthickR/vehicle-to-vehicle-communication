// This example shows how to connect to Cayenne using an ESP8266 and send/receive sample data.
// Make sure you install the ESP8266 Board Package via the Arduino IDE Board Manager and select the correct ESP8266 board before compiling.

//#define CAYENNE_DEBUG
//#define CAYENNE_PRINT Serial
//#include <CayenneMQTTESP8266.h>



#include <SoftwareSerial.h>
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


int error;
int show = -1;


String inputString = "";         // a String to hold incoming data
bool stringComplete = false; 


//#include <SimpleTimer.h> // Download from https://github.com/jfturcot/SimpleTimer
//#include <SimpleDHT.h> // Download from https://github.com/adafruit/DHT-sensor-library


String a,re,re1,re2,re3,re4,re5,re6,data;
String value1, value2, value3, value4,value5, value6,value7;


void setup() {
 Serial.begin(9600);
 pinMode(D5, INPUT_PULLUP);
  pinMode(D7, INPUT);
  //pinMode(D1, OUTPUT);
  pinMode(D6, OUTPUT);
   digitalWrite(D6, HIGH);

     pinMode(D0, OUTPUT);
   digitalWrite(D0, LOW);
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
delay(2000);
}

void loop() 
{
    lcd.clear();
    lcd.print("D:");
    lcd.print(value1);
delay(1000);
if(value1[0]=='1')
{
    lcd.clear();
    lcd.print("medical");
      lcd.setCursor(0, 1);
        lcd.print("emergency");
delay(1000);
digitalWrite(D6, LOW);
}

if(value1[0]=='2')
{
    lcd.clear();
    lcd.print("brake applied");
      lcd.setCursor(0, 1);
delay(1000);
digitalWrite(D6, LOW);
}

if(value1[0]=='3')
{
    lcd.clear();
    lcd.print("speed limit");
      lcd.setCursor(0, 1);
delay(1000);
digitalWrite(D6, LOW);
}

if(value1[0]=='4')
{
    lcd.clear();
    lcd.print("vehicle brake");
      lcd.setCursor(0, 1);
      lcd.print("down");
delay(1000);
digitalWrite(D6, LOW);
}



  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }



  if (stringComplete) {
    Serial.println(inputString);
    Serial.println("string");
    a=inputString;
    // clear the string:
    inputString = "";
    stringComplete = false;
  }


//while(Serial.available()) 
{

//a= Serial.readString();// read the incoming data as string
//Serial.println("data");
Serial.println(a);
//Serial.println("end");

if(a[0]=='@')
{
  Serial.println("copy");
  for(int x=0;x<16;x++)
  {
   EEPROM.write(x,a[x+1]);
   Serial.println(a[x+1]);
    }
 EEPROM.commit(); 
 a[0]='_';
}


if(a[0]=='!')
{
  Serial.println("copy");
  for(int x=20;x<52;x++)
  {
   EEPROM.write(x,a[x-19]);
   Serial.println(a[x-19]);
    }
 EEPROM.commit(); 
 a[0]='_';
}







for (int i = 0; i < a.length(); i++) {


  if (a.substring(i, i+1) == ",")
  {
  
      
    value1=a.substring(0, i);
    re=a.substring(i+1);
   
    break;
  }
}

for (int i = 0; i < re.length(); i++) {


  if (re.substring(i, i+1) == ",") {
    value2=re.substring(0, i);
    re1=re.substring(i+1);
    break;
  }
}

for (int i = 0; i < re1.length(); i++) {


  if (re1.substring(i, i+1) == ",") {
    value3=re1.substring(0, i);
    re2=re1.substring(i+1);
    break;
  }
}


for (int i = 0; i < re2.length(); i++) {


  if (re2.substring(i, i+1) == ",") {
    value4=re2.substring(0, i);
    re3=re2.substring(i+1);
    break;
  }
}


for (int i = 0; i < re3.length(); i++) {


  if (re3.substring(i, i+1) == ",") {
    value5=re3.substring(0, i);
    re4=re3.substring(i+1);
    break;
  }
}


for (int i = 0; i < re4.length(); i++) {


  if (re4.substring(i, i+1) == ",") {
    value6=re4.substring(0, i);
    re5=re4.substring(i+1);
    break;
  }
}



for (int i = 0; i < re5.length(); i++) {


  if (re5.substring(i, i+1) == ",") {
    value7=re5.substring(0, i);
    re6=re5.substring(i+1);
    break;
  }
}
}






Serial.println(value1);
delay(100);
Serial.println(value2);
delay(100);
Serial.println(value3);
delay(100);
Serial.println(value4);
delay(100);
Serial.println(value5);
delay(100);
Serial.println(value6);
delay(100);
Serial.println(re5);
delay(100);

 
// Cayenne.begin(username, password, clientID, ssid, wifiPassword);
}


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:  
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
