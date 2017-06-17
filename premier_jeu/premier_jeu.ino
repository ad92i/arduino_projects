#include <LiquidCrystal.h>
#define NB_BOUTON 4
#define NB_CHARJEU 6
#define NB_CHARSENS 2
#define NB_INTJEU 6

char ligneJeu[NB_CHARJEU] = "", ligneSens[NB_CHARSENS] = "";
int bouton[NB_BOUTON] =  {3, 4, 5, 12}, jeu[NB_INTJEU], secondes = 0;
bool boutonRota = 0, boutonGauche, boutonAll, boutonDroit, win = 0;
LiquidCrystal ecran(11, 10, 9, 8, 7, 6);

void setup(){
    randomSeed(analogRead(0));
    Serial.begin(9600);
    ecran.begin(16, 2);
    for (int i = 0; i < NB_BOUTON; i++){
        pinMode(bouton[i], INPUT_PULLUP);
    }
    while (digitalRead(bouton[3])){
        affichageDebut();
    }
    randJeu(jeu);
}
void loop(){
    while (!win) {
        boutonGauche = digitalRead(bouton[2]);
        boutonAll = digitalRead(bouton[1]);
        boutonDroit = digitalRead(bouton[0]);
        
        if (!digitalRead(bouton[3])){
            if (boutonRota){
                boutonRota = 0;
            }
            else {
                boutonRota = 1;
            }
        }
        if (!boutonGauche){
            modifGauche(boutonRota);
        }
        if (!boutonDroit){
            modifDroit(boutonRota);
        }
        if (!boutonAll){
            modifAll(boutonRota);
        }
        affichageJeu(boutonRota);
        secondes++;
        win = victoire(jeu);
        delay(1000);
    }
    vicMessage(secondes);
    delay(100);
}
void affichageJeu(bool etat){
    ecran.clear(); 
    ecran.home();
    ecran.setCursor(6, 0);
    sprintf(ligneJeu, "%d %d %d", jeu[0], jeu[1], jeu[2]);
    ecran.print(ligneJeu);
    ecran.setCursor(6, 1);
    sprintf(ligneJeu, "%d %d %d", jeu[3], jeu[4], jeu[5]);
    ecran.print(ligneJeu);
    if (etat) {
        ecran.setCursor(14, 0);
        sprintf(ligneSens, "|");
        ecran.print(ligneSens);
        ecran.setCursor(14, 1);
        sprintf(ligneSens, "v");
        ecran.print(ligneSens);
    } 
    else {
        ecran.setCursor(1, 0);
        sprintf(ligneSens, "|");
        ecran.print(ligneSens);
        ecran.setCursor(1, 1);
        sprintf(ligneSens, "v");
        ecran.print(ligneSens);
    }
}
void affichageDebut(){
    ecran.home();
    ecran.write("Appuyer pour");
    ecran.setCursor(0, 1);
    ecran.write("commencer ...");
}
void modifGauche(bool etat){
    int buffer = jeu[0];
    if (etat) {
        jeu[0] = jeu[3];
        jeu[3] = jeu[4];
        jeu[4] = jeu[1];
        jeu[1] = buffer;
    }
    else {
        jeu[0] = jeu[1];
        jeu[1] = jeu[4];
        jeu[4] = jeu[3];
        jeu[3] = buffer;
    }
}
void modifDroit(bool etat){
    int buffer = jeu[1];
    if (etat) {
        jeu[1] = jeu[4];
        jeu[4] = jeu[5];
        jeu[5] = jeu[2];
        jeu[2] = buffer;
    }
    else {
        jeu[1] = jeu[2];
        jeu[2] = jeu[5];
        jeu[5] = jeu[4];
        jeu[4] = buffer;
    }
}
void modifAll(bool etat){
    int buffer = jeu[0];
    if (etat) {
        jeu[0] = jeu[3];
        jeu[3] = jeu[4];
        jeu[4] = jeu[5];
        jeu[5] = jeu[2];
        jeu[2] = jeu[1];
        jeu[1] = buffer;
    }
    else {
        jeu[0] = jeu[1];
        jeu[1] = jeu[2];
        jeu[2] = jeu[5];
        jeu[5] = jeu[4];
        jeu[4] = jeu[3];
        jeu[3] = buffer;
    }
}
void randJeu(int * jeu){
    int age, i, ran, compteur;
    for (age = 0; age < 6; age++){
        jeu[age] = -1;
    }
    for (age = 0; age < 6; age++) {
        ran = random() % (6 - age);
        compteur = 0;
        for (i = 0; i < 6; i++) {
            if (jeu[i] != -1) continue;
            if (compteur == ran) {
                jeu[i] = age;
                break;
            }
            compteur++;
        }
    }
}
bool victoire(int * jeu){
    for (int k = 0; k < 6; k++){
        if (jeu[k] != k){
            return 0;
        }
    }
    return 1;
}
void vicMessage(int secondes){
    ecran.clear();
    ecran.home();
    ecran.write("Victoire !!");
    horloge(secondes);
}
void horloge(int secondes){
    char temps[16] = "";
    int minutes = secondes / 60, heures = minutes / 60;
    secondes%=60;
    sprintf(temps, "en : %2d:%2d:%2d", heures, minutes, secondes);
    ecran.setCursor(2, 1);
    ecran.print(temps);
}