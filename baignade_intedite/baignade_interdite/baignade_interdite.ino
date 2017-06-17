int carDispo, resultat, led = 1;
bool rouge = false, jaune = false;
char mot[15];

void setup() {
    Serial.begin(9600);
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
}
void loop(){

    if (!digitalRead(3)) {
        Serial.println("Alerte !");
        while (digitalRead(2)) {
            appuiBoutonRouge();
        }
        Serial.println("Retour à la normal :)");
        appuiBoutonJaune(led);
    }

    carDispo = Serial.available();
    
    if (carDispo > 0){
        int i = 0;
        while (i < carDispo){
            mot[i] = Serial.read();
            delay(20);
            i++;
        }
        delay(10);
//        mot[i] = '\0';
        Serial.println(strcmp(mot, "meduse"));
        if (strcmp(mot, "meduse") == 0){
            digitalWrite(8, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, HIGH);
            led = 3;
        }/*
        if (strcmp(mot, "tempete")){
            digitalWrite(8, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, HIGH);
            led = 3;
        }
        if (strcmp(mot, "requin")){
            digitalWrite(8, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, HIGH);
            led = 3;
        }
        if (strcmp(mot, "vague")){
            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, LOW);
            led = 2;
        }*/
    }
}
void appuiBoutonRouge() {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(10, HIGH);
    delay(500);
    digitalWrite(10, LOW);
    delay(500);
    digitalWrite(10, HIGH);
    delay(100);
    digitalWrite(10, LOW);
    delay(100);
}
void appuiBoutonJaune(int led){
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
    digitalWrite(7 + led, HIGH);
}
