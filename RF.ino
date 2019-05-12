#define ledPin 13
#define rfPin 8
#define buzzPin 10
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode(rfPin,INPUT);
  pinMode(buzzPin,OUTPUT);
  
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(rfPin)==HIGH)
  {
digitalWrite(ledPin,HIGH);
digitalWrite(buzzPin,HIGH);
delay(2000);
  }
  else
  digitalWrite(ledPin,LOW);
  digitalWrite(buzzPin,LOW);
}
