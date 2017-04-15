//#include <Narcoleptic.h>

#define trigPin 12
#define echoPin 11
#define motorpino 10
#define vibraCall(a)((300-a))/2

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (motorpino,OUTPUT);
}
void loop() {
  int distancia = ultrassonic();
  if(200 > distancia > 0){
    Serial.print("A distancia em CM: ");
    Serial.println(distancia);
    analogWrite(motorpino, vibraCall(distancia));
    Serial.println(vibraCall(distancia));
    //Narcoleptic.delay(250);
  }else{
    analogWrite(motorpino, 0);
    //Narcoleptic.delay(50);
  }
  
}
float ultrassonic(){
  digitalWrite(trigPin, LOW);  //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
  delayMicroseconds(2); // delay de 2 microssegundos
  digitalWrite(trigPin, HIGH); //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
  delayMicroseconds(10);  //delay de 10 microssegundos
  digitalWrite(trigPin, LOW); //seta o pino 12 com pulso baixo novamente
  
  //pulseIn lê o tempo entre a chamada e o pino entrar em high
  return pulseIn(echoPin, HIGH)/58.2;
}
