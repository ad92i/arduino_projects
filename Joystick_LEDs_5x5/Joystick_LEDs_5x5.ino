void setup(){
    for (int i = 2; i < 13; i++){
        pinMode(i, OUTPUT);
/*        if (i > 6){
            digitalWrite(i, HIGH);
        }*/
        if (i < 7){
            digitalWrite(i,HIGH);
        }
    } 
}
void loop(){

}