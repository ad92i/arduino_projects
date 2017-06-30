byte ligne[3] = {2, 3, 4};
byte colonne[3] = {5, 6, 7};

void setup(){
    for (int i = 2; i < 8; i++){
        pinMode(i, OUTPUT);
        if (i >= 5){
            digitalWrite(i, HIGH);
        }
    }
}
void loop(){
    digitalWrite(ligne[1], HIGH);
    digitalWrite(colonne[1], LOW);
}