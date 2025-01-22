#include<LiquidCrystal_I2C.h>
#include<Wire.h>


char data;
int GreenLED = 13;
int RedLED = 12;
int YellowLED = 11;
int Buzzer = 10;
LiquidCrystal_I2C LCD(0x27, 16, 2);


void setup()
{
  Serial.begin(9600);
  pinMode(GreenLED, OUTPUT);
  pinMode(YellowLED, OUTPUT);
  pinMode(RedLED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  LCD.init();
  LCD.backlight();
}

//W = Waiting for Input
//B = Begin Scan
//S = Borrowing Scan Successful
//F = Scan Failed
//R = First Scan Success, Proceed to Second Scan
//G = Second Scan and Return Successful
//N = None

void loop()
{
  digitalWrite(GreenLED, LOW);
  digitalWrite(RedLED, LOW);
  noTone(Buzzer);
  if (Serial.available()>0)
  {
    data = Serial.read();
    if (data == 'W')
    {
      LCD.clear();
      LCD.setCursor(0,0);
      LCD.print("Waiting For");
      LCD.setCursor(0,1);
      LCD.print("Input");
      digitalWrite(GreenLED, LOW);
      digitalWrite(YellowLED, LOW);
      digitalWrite(RedLED, LOW);
      delay(110);
    }
    if (data == 'B')
    {
      LCD.clear();
      LCD.setCursor(0,0);
      LCD.print("Please Begin");
      LCD.setCursor(0,1);
      LCD.print("Scan Now");
      digitalWrite(GreenLED, LOW);
      digitalWrite(YellowLED, HIGH);
      digitalWrite(RedLED, LOW);
      delay(110);
    }
    if (data == 'S')
    {
      LCD.clear();
      LCD.setCursor(0,0);
      LCD.print("Scan");
      LCD.setCursor(0,1);
      LCD.print("Successful!");
      digitalWrite(GreenLED, HIGH);
      digitalWrite(YellowLED, LOW);
      digitalWrite(RedLED, LOW);
      tone(Buzzer, 50);
      delay(50);
      noTone(Buzzer);
      delay(1950);
      LCD.clear();
      LCD.setCursor(0,0);
      LCD.print("Thank");
      LCD.setCursor(0,1);
      LCD.print("You!");
      delay(1500);
      LCD.clear();
    }
    if (data == 'F')
    {
      LCD.clear();
      LCD.setCursor(0,0);
      LCD.print("Scan");
      LCD.setCursor(0,1);
      LCD.print("Failed!");
      digitalWrite(GreenLED, LOW);
      digitalWrite(YellowLED, LOW);
      digitalWrite(RedLED, HIGH);
      tone(Buzzer, 50);
      delay(300);
      noTone(Buzzer);
      delay(300);
      tone(Buzzer, 50);
      delay(300);
      noTone(Buzzer);
      delay(1100);
      LCD.clear();
    }
    if (data == 'R')
    {
      LCD.clear();
      LCD.setCursor(0,0);
      LCD.print("First Scan");
      LCD.setCursor(0,1);
      LCD.print("Successful!");
      digitalWrite(GreenLED, HIGH);
      digitalWrite(YellowLED, HIGH);
      digitalWrite(RedLED, LOW);
      tone(Buzzer, 50);
      delay(50);
      noTone(Buzzer);
      delay(1950);
      LCD.clear();
      LCD.setCursor(0,0);
      LCD.print("Please Begin");
      LCD.setCursor(0,1);
      LCD.print("Second Scan");
    }
    if (data == 'G')
    {
      LCD.clear();
      LCD.setCursor(0,0);
      LCD.print("Second Scan");
      LCD.setCursor(0,1);
      LCD.print("Successful!");
      digitalWrite(GreenLED, HIGH);
      digitalWrite(YellowLED, LOW);
      digitalWrite(RedLED, LOW);
      tone(Buzzer, 50);
      delay(50);
      noTone(Buzzer);
      delay(1950);
      LCD.clear();
      LCD.setCursor(0,0);
      LCD.print("Thank");
      LCD.setCursor(0,1);
      LCD.print("You!");
      delay(1500);
      LCD.clear();
    }
    if (data == 'N')
    {
      LCD.clear();
      digitalWrite(GreenLED, LOW);
      digitalWrite(YellowLED, LOW);
      digitalWrite(RedLED, LOW);
    }
  }
}
