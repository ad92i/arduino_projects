int pinLed[5] = {2, 3, 4, 5, 6};
int pinBouton = 7;
void setup() {
  randomSeed(analogRead(0));
  pinMode(pinBouton,INPUT_PULLUP);
  for (int i = 0; i < 5; i++){
    pinMode(pinLed[i],OUTPUT);
  }
  setZero();
}
void loop() {
  boolean etatBouton = digitalRead(pinBouton);
  if (!etatBouton) {
    setZero();
    delay(100);
    affichage(random(5));
  }
}

void setZero() {
  for (int j = 0; j < 5 ;j++){
    digitalWrite(pinLed[j],LOW);
    }  
}

void affichage(int n) {
  setZero();
  if (n == 1){
    digitalWrite(pinLed[2],HIGH);
  }
  if (n == 2){
    digitalWrite(pinLed[0],HIGH);
    digitalWrite(pinLed[4],HIGH);
  }
  if (n == 3) {
    for (int j = 1; j < 4 ;j++){
      digitalWrite(pinLed[j],HIGH);
    }
  }
  if (n == 4){
    for (int j = 0; j < 5 ;j++){
      digitalWrite(pinLed[j],HIGH);
    }
    digitalWrite(pinLed[2],LOW);
  }
  if (n == 5){
    for (int j = 0; j < 5 ;j++){
      digitalWrite(pinLed[j],HIGH);
    }      
  }
  delay(500);
}
