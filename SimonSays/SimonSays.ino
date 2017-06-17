int pinBouton[4] = {2, 6, 8, 11}, pinLed[5] = {3, 4, 7, 9, 12}, freqBuz[4] = {880, 659, 494, 741}, pinNiveau[4] = {0, 1, 5, 13};
int simonCouleur[20], saisieCouleur[20];
int level = 1, pinBuzzer = 10;

void setup(){
    for (int a = 0; a < 5; a++){
        if (a < 4){
            pinMode(pinBouton[a], INPUT_PULLUP);
            pinMode(pinNiveau[a], OUTPUT);
        }
        pinMode(pinLed[a], OUTPUT);
    }
    delay(1000);
    for (int i = 0; i < 5; i++){
        digitalWrite(pinLed[i], HIGH);
    }
    genSimon();
}
void loop(){
    while (level < 20){
        for (int aff = 0; aff < level; aff++){
            afficheCouleur(simonCouleur[aff]);
        }
        initAffichage();
        saisie(level);
        initAffichage();
        if (checkVictoire(saisieCouleur, simonCouleur, level)){
            level++;
        } else {
            error();
        }
    }

}
void afficheCouleur(int couleur){
    for (int i = 0; i < 5; i++){
        digitalWrite(pinLed[i], HIGH);
    }
    delay(100);
    switch (couleur){
        case 3:
        case 4:
            digitalWrite(pinLed[0], LOW);
            digitalWrite(pinLed[1], LOW);
            tone(pinBuzzer,freqBuz[0]);
            break;
        case 7:
            digitalWrite(pinLed[2], LOW);
            tone(pinBuzzer,freqBuz[1]);
            break;
        case 9:
            digitalWrite(pinLed[3], LOW);
            tone(pinBuzzer,freqBuz[2]);
            break;
        case 12:
            digitalWrite(pinLed[4], LOW);
            tone(pinBuzzer,freqBuz[3]);
            break;
    }
    delay(500);
    noTone(pinBuzzer);
}
void genSimon(){
    int temp;
    randomSeed(analogRead(0));
    for (int i = 0; i < 20; i++){
        temp = (random() % 5);
        if (temp == 0){
            temp++;
        }
        simonCouleur[i] = pinLed[temp];
        delay(20);
    }
}
int checkVictoire(int * saisie, int * simon, int level){
    for (int i = 0; i < level; i++){
        if (simon[i] != saisie[i]){
            return 0;
        }
    }
    return 1;
}
void initAffichage(){
    for (int i = 0; i < 5; i++){
        digitalWrite(pinLed[i], HIGH);
    }
    delay(100);
    for (int i = 0; i < 5; i++){
        digitalWrite(pinLed[i], LOW);
    }
    delay(200);
    for (int i = 0; i < 5; i++){
        digitalWrite(pinLed[i], HIGH);
    }
}
void saisie(int lvl){
    saisieCouleur[20];
    int cmb = 0;
    while (cmb < lvl){
        if (!digitalRead(pinBouton[0])){
            saisieCouleur[cmb] = pinLed[1];
            afficheCouleur(saisieCouleur[cmb]);
            cmb++;
        }
        if (!digitalRead(pinBouton[1])){
            saisieCouleur[cmb] = pinLed[2];
            afficheCouleur(saisieCouleur[cmb]);
            cmb++;
        }
        if (!digitalRead(pinBouton[2])){
            saisieCouleur[cmb] = pinLed[3];
            afficheCouleur(saisieCouleur[cmb]);
            cmb++;
        }
        if (!digitalRead(pinBouton[3])){
            saisieCouleur[cmb] = pinLed[4];
            afficheCouleur(saisieCouleur[cmb]);
            cmb++;
        }
    }
}
void error(){
    for (int j = 0; j < 4; j++){
        tone(pinBuzzer, 5000);
        for (int i = 0; i < 5; i++){
            digitalWrite(pinLed[i], HIGH);
        }
        delay(100);
        for (int i = 0; i < 5; i++){
            digitalWrite(pinLed[i], LOW);
        }
        delay(300);
        for (int i = 0; i < 5; i++){
            digitalWrite(pinLed[i], HIGH);
        }
        noTone(pinBuzzer);
        delay(100);
    }
    delay(600);






    
}