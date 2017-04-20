#include <NewPing.h>

#define trigPin 12
#define echoPin 11
#define motorpino 10
#define distanciaMax 200
#define vibraCall(a)((300-a))/2

void setup() {
  Serial.begin (9600);
  byte distanciaMedia;
  NewPing sensor(trigPin, echoPin, distanciaMax);

  while(true){
    Serial.print("Ping em cm: ");
    distanciaMedia = sensor.convert_cm(sensor.ping_median(3));
    Serial.println(distanciaMedia);
    analogWrite(motorpino, vibraCall(distanciaMedia));
    delay(500);
  }
}

//analogWrite(motorpino, 0);
//analogWrite(motorpino, vibraCall(distancia));
