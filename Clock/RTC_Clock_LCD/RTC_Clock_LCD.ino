#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

uint8_t hour,minute,second,month,day,AMorPM;
uint16_t year;

void setup () {
  //Serial.begin(9600);
  lcd.begin(16,2);
#ifndef ESP8266
  while (!Serial); // wait for serial port to connect. Needed for native USB
#endif

  //if (! rtc.begin()) {
  //  Serial.println("Couldn't find RTC");
  //  Serial.flush();
  //  abort();
  //}

 // if (! rtc.isrunning()) {
  //  Serial.println("RTC is NOT running, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
     //Serial.print("Date and Time is adjusted");
 // }
    rtc.begin();
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // rtc.adjust(DateTime(2023, 11, 12, 11, 39, 0));
}

void loop () {
    DateTime now = rtc.now();
     
    hour = now.hour();
    minute = now.minute();
    second = now.second();

    year = now.year();
    month = now.month();
    day = now.day();

  /*  Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println(); */

    //lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Time:");
   //Serial.print("\nTime: ");
    lcd.setCursor(5,0);

    AMorPM = 0;
    if(hour >= 13)
    {
      AMorPM = 1;
      hour -= 12;
    }
    if(hour <= 9)
    {
      lcd.print("0");
      lcd.setCursor(6,0);
      lcd.print(hour);
    }
    else
    {
      lcd.print(hour);
    }
    lcd.setCursor(7,0);
    lcd.print(":");
    lcd.setCursor(8,0);   
    if(minute <= 9)
    {
      lcd.print("0");
      lcd.setCursor(9,0);
      lcd.print(minute);
    }
    else
    {
      lcd.print(minute);
    }
    lcd.setCursor(10,0);
    lcd.print(":");
    lcd.setCursor(11,0);   
    if(second <= 9)
    {
      lcd.print("0");
      lcd.setCursor(12,0);
      lcd.print(second);
    }
    else
    {
      lcd.print(second);
    }

    lcd.setCursor(14,0);
    if(AMorPM == 0)
    lcd.print("AM");
    else
    lcd.print("PM");

    lcd.setCursor(0,1);
    lcd.print("Date:");
   //Serial.print("\nTime: ");
    lcd.setCursor(5,1);
    if(day <= 9)
    {
      lcd.print("0");
      lcd.setCursor(6,1);
      lcd.print(day);
    }
    else
    {
      lcd.print(day);
    }
    lcd.setCursor(7,1);
    lcd.print("/");
    lcd.setCursor(8,1);   
    if(month <= 9)
    {
      lcd.print("0");
      lcd.setCursor(9,1);
      lcd.print(month);
    }
    else
    {
      lcd.print(month);
    }
    lcd.setCursor(10,1);
    lcd.print("/");
    lcd.setCursor(11,1);   
    lcd.print(year);

    //lcd.setCursor(0,1);
    //lcd.print("Date:");
   //Serial.print("\nDate: ");
   //lcd.setCursor(6,0);
   //lcd.print(day);
   //Serial.print(day, DEC);
   //lcd.setCursor(9,0);
   //lcd.print(".");
   //Serial.print(".");
   //lcd.setCursor(10,0);
   //lcd.print(month);
   //Serial.print(month, DEC);
   //lcd.setCursor(11,0);
   //lcd.print(".");
   //Serial.print(".");
   //lcd.setCursor(12,0);
   //lcd.print(year);
   //Serial.print(year, DEC);

  //wait a second
  //delay(1000);

   // delay(3000);
}