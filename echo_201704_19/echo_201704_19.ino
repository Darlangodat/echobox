#include <Narcoleptic.h>
#include <avr/power.h>

#define trigPin 12
#define echoPin 11
#define motorpino 10
#define botao 9
#define vibraCall(a)((300-a))/2

void setup() {
  power_spi_disable();  
  power_twi_disable();
  power_timer2_disable(); 
  byte distancia, distanciaAnterior;
  unsigned long tempo;
  bool desligado = true;
  pinMode(trigPin, OUTPUT);
  pinMode(motorpino,OUTPUT);
  pinMode(botao,INPUT_PULLUP);
  //Serial.begin (9600);

  while(true){
    if(digitalRead(9) ){
      if(desligado){
        analogWrite(motorpino, 150);
        delay(500);
        analogWrite(motorpino, 0);
        delay(500);
        desligado = false;
      }
      distancia = ultrassonic();
      
      if( !(distanciaAnterior*1.06 >= distancia && distanciaAnterior*0.94 <= distancia) ){
          if(200 > distancia > 0){
             //Serial.print("A distancia em CM: ");
             //Serial.println(distancia);
             //delay(500);
             //Serial.println(vibraCall(distancia));
             analogWrite(motorpino, vibraCall(distancia));
             distanciaAnterior = distancia;
             tempo = millis();
          }else{
             analogWrite(motorpino, 0);
          }
      }else{
          //Serial.println(millis() - tempo);
          if( millis() - tempo > 3000 ){
            Narcoleptic.delay(500);
          }else if( millis() - tempo > 2000 ){
            analogWrite(motorpino, 0);
          }
      }
    }else{
      desligado = true;
      Narcoleptic.delay(500);
    }
  }
}

byte ultrassonic(){
  digitalWrite(trigPin, HIGH); //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
  delayMicroseconds(10);  //delay de 10 microssegundos
  digitalWrite(trigPin, LOW); //seta o pino 12 com pulso baixo novamente
  
  //pulseIn lê o tempo entre a chamada e o pino entrar em high
  return pulseIn(echoPin, HIGH)/58.2;
}
