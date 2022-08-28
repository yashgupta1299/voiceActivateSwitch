#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define ONE 8
#define TWO 9
#define THREE 10
#define FOUR 11

String command;
bool one, two, three, four;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void oneOn()
{
  digitalWrite(ONE, LOW);
  lcd.setCursor(0,0);
  lcd.print("1 - ON  ");
  one = true;
}

void oneOff()
{
  digitalWrite(ONE, HIGH);
  lcd.setCursor(0,0);
  lcd.print("1 - OFF ");
  one = false;
}

void twoOn()
{
  digitalWrite(TWO, LOW);
  lcd.setCursor(8,0);
  lcd.print("2 - ON  ");
  two = true;
}

void twoOff()
{
  digitalWrite(TWO, HIGH);
  lcd.setCursor(8,0);
  lcd.print("2 - OFF ");
  two = false;
}

void threeOn()
{
  digitalWrite(THREE, LOW);
  lcd.setCursor(0,1);
  lcd.print("3 - ON  ");
  three = true;
}

void threeOff()
{
  digitalWrite(THREE, HIGH);
  lcd.setCursor(0,1);
  lcd.print("3 - OFF ");
  three = false;
}

void fourOn()
{
  digitalWrite(FOUR, LOW);
  lcd.setCursor(8, 1);
  lcd.print("4 - ON  ");
  four = true;
}

void fourOff()
{
  digitalWrite(FOUR, HIGH);
  lcd.setCursor(8, 1);
  lcd.print("4 - OFF ");
  four = false;
}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  pinMode(ONE, OUTPUT);
  pinMode(TWO, OUTPUT);
  pinMode(THREE, OUTPUT);
  pinMode(FOUR, OUTPUT);

  digitalWrite(ONE, HIGH);
  digitalWrite(TWO, HIGH);
  digitalWrite(THREE, HIGH);
  digitalWrite(FOUR, HIGH);

  lcd.begin();
  lcd.backlight();

  lcd.print("Hello World");
  delay(2000);

  oneOff();
  twoOff();
  threeOff();
  fourOff();
}

void loop() {
  // put your main code here, to run repeatedly:

  while (Serial.available())
  {
    delay(10);
    
    char c = Serial.read();
    if (c == '#') break;
    command += c;
    
  }

  if (command.length() > 0) 
  {
    Serial.println(command);

    if (command == "*one on")
    {
      oneOn();
    }
    else if (command == "*one off")
    {
      oneOff();
    }
    else if (command == "*one toggle")
    {
      if (one)
        oneOff();
      else
        oneOn();
    }
    else if (command == "*two on")
    {
      twoOn();
    }
    else if (command == "*two off")
    {
      twoOff();
    }
    else if (command == "*two toggle")
    {
      if (two)
        twoOff();
      else
        twoOn();
    }
    else if (command == "*three on")
    {
      threeOn();
    }
    else if (command == "*three off")
    {
      threeOff();
    }
    else if (command == "*three toggle")
    {
      if (three)
        threeOff();
      else
        threeOn();
    }
    else if (command == "*four on")
    {
      fourOn();
    }
    else if (command == "*four off")
    {
      fourOff();
    }
    else if (command == "*four toggle")
    {
      if (four)
        fourOff();
      else
        fourOn();
    }
    else if (command == "*all on")
    {
      oneOn();
      twoOn();
      threeOn();
      fourOn();
    }
    else if (command == "*all off")
    {
      oneOff();
      twoOff();
      threeOff();
      fourOff();
    }

    command = "";
  }
}
