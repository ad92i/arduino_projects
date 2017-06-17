int pinBoutonDown = 11;
int pinBoutonUp = 12;
bool etatBoutonUp, etatBoutonDown;
int reste = 0;
void setup() {
    pinMode(pinBoutonDown, INPUT_PULLUP);
    pinMode(pinBoutonUp, INPUT_PULLUP);
    for (int i = 2; i < 11; i++){
        pinMode(i, OUTPUT);
    }
    affichage(reste);
}

void loop() {
    etatBoutonDown = digitalRead(pinBoutonDown);
    etatBoutonUp = digitalRead(pinBoutonUp);
if (reste == 9 || reste == 0) {
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
    } else if (reste < 9 && reste > 0) {
        digitalWrite(9, LOW);
        digitalWrite(10,HIGH);
    }
    if (!etatBoutonUp && etatBoutonDown && reste != 9){
        reste++;
        offAll();
        affichage(reste);
    } else if (etatBoutonUp && ! etatBoutonDown && reste != 0){
        reste--;
        offAll();
        affichage(reste);
    }n
}
void offAll(){
    for (int i = 2; i < 9; i++){
        digitalWrite(i, LOW);
    }
    delay(40);
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