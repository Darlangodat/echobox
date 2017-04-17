#include <avr/power.h>

#define trigPin 12
#define echoPin 11
#define motorpino 10
#define vibraCall(a)((300-a))/2

void setup() {
  power_spi_disable();  
  power_twi_disable(); 
  power_timer1_disable();
  power_timer2_disable(); 
  byte distancia,distanciaAnterior;
  pinMode(trigPin, OUTPUT);
  pinMode (motorpino,OUTPUT);
  analogWrite(motorpino, 150);
  delay(500);
  analogWrite(motorpino, 0);
  delay(500);
  //Serial.begin (9600);

  while(true){
    distancia = ultrassonic();
    if(distanciaAnterior != distancia){
        if(200 > distancia > 0){
          //Serial.print("A distancia em CM: ");
          //Serial.println(distancia);
          //Serial.println(vibraCall(distancia));
          distanciaAnterior = distancia;
          analogWrite(motorpino, vibraCall(distancia));
        }else{
          analogWrite(motorpino, 0);
        }
    }
  }
}

float ultrassonic(){
  digitalWrite(trigPin, HIGH); //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
  delayMicroseconds(10);  //delay de 10 microssegundos
  digitalWrite(trigPin, LOW); //seta o pino 12 com pulso baixo novamente
  
  //pulseIn lê o tempo entre a chamada e o pino entrar em high
  return pulseIn(echoPin, HIGH)/58.2;
}
