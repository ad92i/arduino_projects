#define TAILLE_MATRICE 5

const int pinLigne[TAILLE_MATRICE] = {2, 3, 4, 5, 6};
const int pinColonne[TAILLE_MATRICE] = {8, 9, 10, 11, 12};

void setup(){
    for (int i = 0; i < TAILLE_MATRICE; i++){
        pinMode(pinLigne[i], OUTPUT);
        pinMode(pinColonne[i], OUTPUT);
    } 
}
void loop(){
    displayMatriceLEDs(map(analogRead(5),0, 1023, 0, 5), map(analogRead(0),0, 1023,  0, 5));
    delay(10);
}
void allHIGH(char ligne_ou_colonne){
    if (ligne_ou_colonne == 'c'){
        for (int i = 0; i < TAILLE_MATRICE; i++){
            digitalWrite(pinColonne[i], HIGH);
        }
    } else if (ligne_ou_colonne == 'l'){
        for (int i = 0; i < TAILLE_MATRICE; i++){
            digitalWrite(pinLigne[i], HIGH);
        }
    } 
}
void allLOW(char ligne_ou_colonne){
    if (ligne_ou_colonne == 'c'){
        for (int i = 0; i < TAILLE_MATRICE; i++){
            digitalWrite(pinColonne[i], LOW);
        }
    } else if (ligne_ou_colonne == 'l'){
        for (int i = 0; i < TAILLE_MATRICE; i++){
            digitalWrite(pinLigne[i], LOW);
        }
    } 
}
void displayMatriceLEDs(int x, int y){
    allLOW('l');
    allHIGH('c');
    digitalWrite(pinLigne[x], HIGH);
    digitalWrite(pinColonne[y], LOW);
}