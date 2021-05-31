const int sensorTemp = A5;
double temperatura;
const int redTemp = 2;
const int orangeTemp = 4;
const int greenTemp = 5;
int vetorTemp[10];

const int pinGas = A1;
const int redGas = 9;
const int orangeGas = 11;
const int greenGas = 13;
int vetorGas[10];

void setup(){
  pinMode(sensorTemp, INPUT);
  pinMode(redTemp, OUTPUT);
  pinMode(orangeTemp, OUTPUT);
  pinMode(greenTemp, OUTPUT);
  
  pinMode(pinGas, INPUT);
  pinMode(redGas, OUTPUT);
  pinMode(orangeGas, OUTPUT);
  pinMode(greenGas, OUTPUT);
  
  Serial.begin(9600);
}

void loop(){
  //gás
  int somaGas = 0;
  
  for(int i = 0; i < 10; i++){
    vetorGas[i] = analogRead(pinGas);
  	delay(500);
  	Serial.println(vetorGas[i]);
  	somaGas += vetorGas[i];
  }
  
  int mediaGas = somaGas/10;
  
  Serial.print("Media do Gas: ");
  Serial.println(mediaGas);
  delay(5000);
  
  if(mediaGas >= 30 && mediaGas < 100){
    digitalWrite(greenGas, HIGH);
    digitalWrite(orangeGas, LOW);
    digitalWrite(redGas, LOW);
  } else if(mediaGas >= 100 && mediaGas < 200){
    digitalWrite(greenGas, LOW);
    digitalWrite(orangeGas, HIGH);
    digitalWrite(redGas, LOW);
  }else if(mediaGas >= 200){
    digitalWrite(greenGas, LOW);
    digitalWrite(orangeGas, LOW);
    digitalWrite(redGas, HIGH);
  }
  
  //temperatura
  int sensorTempInput = analogRead(sensorTemp);
  temperatura = (double)sensorTempInput / 1024;
  temperatura = temperatura * 5;
  temperatura = temperatura - 0.5;
  temperatura = temperatura * 100;  
  
  int somaTemp = 0;
  
  for(int i = 0; i < 10; i++){
    vetorTemp[i] = analogRead(sensorTemp);
  	delay(500);
  	Serial.println(vetorTemp[i]);
  	somaTemp += vetorTemp[i];
  }
  
  int mediaTemp = somaTemp/10;
  
  Serial.print("Media da Temperatura: ");
  Serial.println(mediaTemp);
  delay(500);
  
  if(mediaTemp >= 30 && mediaTemp < 100){
    digitalWrite(greenTemp, HIGH);
    digitalWrite(orangeTemp, LOW);
    digitalWrite(redTemp, LOW);
  } else if(mediaTemp >= 100 && mediaTemp < 200){
    digitalWrite(greenTemp, LOW);
    digitalWrite(orangeTemp, HIGH);
    digitalWrite(redTemp, LOW);
  }else if(mediaTemp >= 200){
    digitalWrite(greenTemp, LOW);
    digitalWrite(orangeTemp, LOW);
    digitalWrite(redTemp, HIGH);
  }
}