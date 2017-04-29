/*
 Scroll
 * this sketch scrolls text left when tilted
 * text scrolls right when not tilted.
*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const int numRows = 2;
const int numCols = 16;
int potPin = 3;    // Input pin for the potentiometer

int x = -1;

LiquidCrystal_I2C lcd(0x27,numCols,numRows);

void setup()
{
  lcd.init();
  lcd.backlight();
  //lcd.print(textString);
  //delay(5000);
  Serial.begin(9600);
}

void loop()
{
  
  int val = analogRead(potPin);    // read the value from the sensor
  val = map(val, 0, 1023, 0, 255);
  Serial.println(val);
  
  lcd.clear();
  lcd.setCursor(val / 16,1);
  lcd.print(val / 16);
  delay(150);
  /*
  x += 1;
  delay(1000);

  if(x > 13){
    x = 0;
  }
  */

}

