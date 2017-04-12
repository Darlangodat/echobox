#define trigPin 12
#define echoPin 11
#define motorpino 10

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 pinMode (motorpino,OUTPUT);
}
void loop() {
  int distancia = ultrassonic();
  if(distancia > 0 && distancia < 200){
    Serial.print("Objeto esta a: ");
    Serial.print(distancia);
    Serial.println(" cm");
    analogWrite(motorpino, vibraCall(distancia));
    //Serial.println(vibraCall(distancia));
    delay(250); 
  }else{
    analogWrite(motorpino, 0); 
  }
}
float ultrassonic(){
  float duration, distance;
  digitalWrite(trigPin, LOW);  //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
  delayMicroseconds(2); // delay de 2 microssegundos
  digitalWrite(trigPin, HIGH); //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
  delayMicroseconds(10);  //delay de 10 microssegundos
  digitalWrite(trigPin, LOW); //seta o pino 12 com pulso baixo novamente
  duration = pulseIn(echoPin, HIGH);  //pulseIn lê o tempo entre a chamada e o pino entrar em high
  distance = (duration/2) / 29.1;
  return distance;
}

int vibraCall(int distancia){
  float dist = 200,distA;
  distA  = dist-distancia;
  distA = distA + 3;
  return distA/2;
}
