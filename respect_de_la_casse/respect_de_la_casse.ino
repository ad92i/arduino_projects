void setup() {
    Serial.begin(9600);
}

void loop() {
    int carDispo;
    char carLu = 0;
    carDispo = Serial.available();
    
    if (carDispo > 0){
        carLu = Serial.read();
        if ((carLu >= 'a')&&(carLu <= 'z')){
            carLu = carLu - 'a';
            carLu = carLu + 'A';
        }
        else if ((carLu >= 'A')&&(carLu <= 'Z')){
            carLu = carLu - 'A';
            carLu = carLu + 'a';
        }
        Serial.write(carLu);

    }
}