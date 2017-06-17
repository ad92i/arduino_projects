int pinBouton = 12;
bool etatBouton;
void setup() {
    Serial.begin(9600);
    pinMode(pinBouton,INPUT_PULLUP);
    for (int i = 2; i < 9; i++){
        pinMode(i, OUTPUT);
    }
    randomSeed(analogRead(0));
}

void loop() {
    etatBouton = digitalRead(pinBouton);
    if (!etatBouton){
        offAll();
        affichage(random(10));
    }
}
void offAll(){
    for (int i = 2; i < 9; i++){
        digitalWrite(i, LOW);
    }
    delay(300);
}
void affichage(int n) {
    switch(n) {
        case 0:
            digitalWrite(2,HIGH);
            digitalWrite(3,HIGH);
            digitalWrite(4,HIGH);
            digitalWrite(5,HIGH);
            digitalWrite(6,HIGH);
            digitalWrite(7,HIGH);
            break;
        case 1:
            digitalWrite(3,HIGH);
            digitalWrite(4,HIGH);
            break;
        case 2:
            digitalWrite(2,HIGH);
            digitalWrite(3,HIGH);
            digitalWrite(5,HIGH);
            digitalWrite(6,HIGH);
            digitalWrite(8,HIGH);
            break;
        case 3:
            digitalWrite(2,HIGH);
            digitalWrite(3,HIGH);
            digitalWrite(4,HIGH);
            digitalWrite(5,HIGH);
            digitalWrite(8,HIGH);
            break;
        case 4:
            digitalWrite(3,HIGH);
            digitalWrite(4,HIGH);
            digitalWrite(7,HIGH);
            digitalWrite(8,HIGH);
            break;
        case 5:
            digitalWrite(2,HIGH);
            digitalWrite(4,HIGH);
            digitalWrite(5,HIGH);
            digitalWrite(7,HIGH);
            digitalWrite(8,HIGH);
            break;
        case 6:
            digitalWrite(2,HIGH);
            digitalWrite(4,HIGH);
            digitalWrite(5,HIGH);
            digitalWrite(6,HIGH);
            digitalWrite(7,HIGH);
            digitalWrite(8,HIGH);
            break;
        case 7:
            digitalWrite(2,HIGH);
            digitalWrite(3,HIGH);
            digitalWrite(4,HIGH);
            break;
        case 8:
            digitalWrite(2,HIGH);
            digitalWrite(3,HIGH);
            digitalWrite(4,HIGH);
            digitalWrite(5,HIGH);
            digitalWrite(6,HIGH);
            digitalWrite(7,HIGH);
            digitalWrite(8,HIGH);
            break;
        case 9:
            digitalWrite(2,HIGH);
            digitalWrite(3,HIGH);
            digitalWrite(4,HIGH);
            digitalWrite(5,HIGH);
            digitalWrite(7,HIGH);
            digitalWrite(8,HIGH);
            break;
    }
    delay(1000);
}