
#include <LiquidCrystal.h>
LiquidCrystal lcd (30,31,32,33,34,35);

#include <Servo.h>
Servo myservo;
int pos=0;

#define LS 36
#define RS 37

#define LM11 38
#define LM12 39
#define RM11 40
#define RM12 41
#define LM21 42
#define LM22 43
#define RM21 44
#define RM22 45

#define buzzerPin 3

const int trigPin1=4;
const int echoPin1=5;
long duration1;
int distance1;

const int trigPin2=6;
const int echoPin2=7;
long duration2;
int distance2;

void ultraBlock()
{
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration1= pulseIn(echoPin1, HIGH);
  distance1= duration1*0.034/2;

  if (distance1<=50 && distance1>=0)
  {
    digitalWrite(buzzerPin, HIGH);
    delay(2000);
    digitalWrite(buzzerPin,LOW);
    digitalWrite(LM11, LOW);
    digitalWrite(LM12, LOW);
    digitalWrite(RM11, LOW);
    digitalWrite(RM12, LOW);
    digitalWrite(LM21, LOW);
    digitalWrite(LM22, LOW);
    digitalWrite(RM21, LOW);
    digitalWrite(RM22, LOW);
    delay(2000);

     
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(LM11, HIGH);
    digitalWrite(LM12, LOW);
    digitalWrite(RM11, HIGH);
    digitalWrite(RM12, LOW);
    digitalWrite(LM21, HIGH);
    digitalWrite(LM22, LOW);
    digitalWrite(RM21, HIGH);
    digitalWrite(RM22, LOW);
    
  }
}


void ultraDisp()
{
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2= pulseIn(echoPin2, HIGH);
  distance2= duration2*0.034/2;

  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("DISTANCE= ");
   lcd.print(distance);

  if (distance2>=0 && distance2<=5)
  {
    lcd.setCursor(1,1);
    lcd.print("TRASH BIN FULL");
  }
  if (distance2>5 && distance2<=10)
  {
    lcd.setCursor(4,1);
    lcd.print("75% FULL");
  }
  if (distance2>10 && distance2<=15)
  {
    lcd.setCursor(4,1);
    lcd.print("50% FULL");
  }
  if (distance2>15 && distance2<=20)
  {
    lcd.setCursor(4,1);
    lcd.print("25% FULL");
  }
}

void setup() 
{
 
 myservo.attach(2);
 
 lcd.begin(16,2);
 lcd.setCursor(1,0);
 lcd.print("SMART TRASH BIN");
 delay(5000);
 lcd.clear();
 lcd.setCursor(4,0);
 lcd.print("ATHMARAM");
 lcd.setCursor(4,1);
 lcd.print("SABARJED");
 delay(2000);
 lcd.clear();
 lcd.setCursor(4,0);
 lcd.print("RADHIKA");
 lcd.setCursor(5,1);
 lcd.print("ARUNA");
 delay(2000);
 lcd.clear();

 pinMode(LS, INPUT);
 pinMode(RS, INPUT);
 
 pinMode(LM11, OUTPUT);
 pinMode(LM12, OUTPUT);
 pinMode(RM11, OUTPUT);
 pinMode(RM12, OUTPUT);
 pinMode(LM21, OUTPUT);
 pinMode(LM22, OUTPUT);
 pinMode(RM21, OUTPUT);
 pinMode(RM22, OUTPUT);

 pinMode(buzzerPin,OUTPUT);

 pinMode(trigPin1,OUTPUT);
 pinMode(echoPin1, INPUT);

 pinMode(trigPin2,OUTPUT);
 pinMode(echoPin2, INPUT);
 
 }

void loop() 
{
  ultraDisp();
  
  if(digitalRead(LS) && digitalRead(RS))     // Move Forward
  {
    digitalWrite(LM11, HIGH);
    digitalWrite(LM12, LOW);
    digitalWrite(RM11, HIGH);
    digitalWrite(RM12, LOW);
    digitalWrite(LM21, HIGH);
    digitalWrite(LM22, LOW);
    digitalWrite(RM21, HIGH);
    digitalWrite(RM22, LOW);
    ultraBlock();
  }

  if(!(digitalRead(LS)) && digitalRead(RS))     // Turn left
  {
    digitalWrite(LM11, LOW);
    digitalWrite(LM12, LOW);
    digitalWrite(RM11, HIGH);
    digitalWrite(RM12, LOW);
    digitalWrite(LM21, LOW);
    digitalWrite(LM22, LOW);
    digitalWrite(RM21, HIGH);
    digitalWrite(RM22, LOW);
    ultraBlock();
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // turn right
  {
    digitalWrite(LM11, HIGH);
    digitalWrite(LM12, LOW);
    digitalWrite(RM11, LOW);
    digitalWrite(RM12, LOW);
    digitalWrite(LM21, HIGH);
    digitalWrite(LM22, LOW);
    digitalWrite(RM21, LOW);
    digitalWrite(RM22, LOW);
    ultraBlock();
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
  {
    digitalWrite(LM11, LOW);
    digitalWrite(LM12, LOW);
    digitalWrite(RM11, LOW);
    digitalWrite(RM12, LOW);
    digitalWrite(LM21, LOW);
    digitalWrite(LM22, LOW);
    digitalWrite(RM21, LOW);
    digitalWrite(RM22, LOW);

    for (pos=0;pos<=90;pos++)
    {
      myservo.write(pos);
      delay(15);
    }
    delay(5000);
    for (pos=90;pos>=0;pos--)
    {
      myservo.write(pos);
      delay(15);
    }
   }
  delay(1000);
  
  digitalWrite(LM11, HIGH);
  digitalWrite(LM12, LOW);
  digitalWrite(RM11, LOW);
  digitalWrite(RM12, HIGH);
  digitalWrite(LM21, HIGH);
  digitalWrite(LM22, LOW);
  digitalWrite(RM21, LOW);
  digitalWrite(RM22, HIGH);
  
  delay(1000);

  ultraBlock();
  if(digitalRead(LS) && digitalRead(RS))     // Move Forward
  {
    digitalWrite(LM11, HIGH);
    digitalWrite(LM12, LOW);
    digitalWrite(RM11, HIGH);
    digitalWrite(RM12, LOW);
    digitalWrite(LM21, HIGH);
    digitalWrite(LM22, LOW);
    digitalWrite(RM21, HIGH);
    digitalWrite(RM22, LOW);
    ultraBlock();
  }

  if(!(digitalRead(LS)) && digitalRead(RS))     // Turn left
  {
    digitalWrite(LM11, LOW);
    digitalWrite(LM12, LOW);
    digitalWrite(RM11, HIGH);
    digitalWrite(RM12, LOW);
    digitalWrite(LM21, LOW);
    digitalWrite(LM22, LOW);
    digitalWrite(RM21, HIGH);
    digitalWrite(RM22, LOW);
    ultraBlock();
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // turn right
  {
    digitalWrite(LM11, HIGH);
    digitalWrite(LM12, LOW);
    digitalWrite(RM11, LOW);
    digitalWrite(RM12, LOW);
    digitalWrite(LM21, HIGH);
    digitalWrite(LM22, LOW);
    digitalWrite(RM21, LOW);
    digitalWrite(RM22, LOW);
    ultraBlock();
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
  {
    digitalWrite(LM11, LOW);
    digitalWrite(LM12, LOW);
    digitalWrite(RM11, LOW);
    digitalWrite(RM12, LOW);
    digitalWrite(LM21, LOW);
    digitalWrite(LM22, LOW);
    digitalWrite(RM21, LOW);
    digitalWrite(RM22, LOW);
    ultraBlock();
  }

  delay(1000);
  
  digitalWrite(LM11, HIGH);
  digitalWrite(LM12, LOW);
  digitalWrite(RM11, LOW);
  digitalWrite(RM12, HIGH);
  digitalWrite(LM21, HIGH);
  digitalWrite(LM22, LOW);
  digitalWrite(RM21, LOW);
  digitalWrite(RM22, HIGH);
  
  delay(1000);  

}
