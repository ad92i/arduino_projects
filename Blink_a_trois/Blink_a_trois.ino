const int PINUN=2;
const int PINDEUX=4;
const int PINTROIS=7;
void setup()
{
  pinMode(PINUN,OUTPUT);
  pinMode(PINDEUX,OUTPUT);
  pinMode(PINTROIS,OUTPUT);
  
}
void loop()
{
  digitalWrite(PINUN,HIGH);
  digitalWrite(PINDEUX,HIGH);
  digitalWrite(PINTROIS,HIGH);
  delay(1000);
  digitalWrite(PINUN,LOW);
  digitalWrite(PINDEUX,LOW);
  digitalWrite(PINTROIS,LOW);
  delay(100);

  for (int i = 1000; i > 200; i = i-100)  {
    digitalWrite(PINTROIS,HIGH);
    delay(i);
    digitalWrite(PINTROIS,LOW);
    delay(100);

    digitalWrite(PINDEUX,HIGH);
    delay(i);
    digitalWrite(PINDEUX,LOW);
    delay(100);
    
    digitalWrite(PINUN,HIGH);
    delay(i);
    digitalWrite(PINUN,LOW);
    delay(100);
    
  }
}
