/*
Fundación Kinal
Centro Educativo Técnico Labral Kinal 
Electrónica
Grado: Quinto
Sección: A
Curso: Taller de Electrónica Digital y Reparación de Computadoras I
Nombre: Álvaro Anzueto Rodas
Carné: 2019373 
*/

//defino los pulsadores y salidas del rgb
#define pROJO  2
#define pVERDE 3
#define pinR   4
#define pinG   5
#define pinB   6

//aclaro la variable que me servirá para el switch
int estado;


void setup() {
  // defino los pulsadores como entradas y las patillas del rgb como salidas apartes
  pinMode(pROJO, INPUT);
  pinMode(pVERDE, INPUT);
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
  

}

void loop() {
  // si presiono el primer pulsador
  while(digitalRead(pROJO)== LOW && digitalRead(pVERDE)== HIGH)
  {
   digitalWrite(pinR, HIGH);
   digitalWrite(pinG, HIGH);
   digitalWrite(pinB, LOW);
  }
  //Si presiono el segundo pulsador
  while(digitalRead(pROJO)== HIGH && digitalRead(pVERDE)== LOW)
  {
   digitalWrite(pinR, LOW);
   digitalWrite(pinG, HIGH);
   digitalWrite(pinB, HIGH);
  }
  //si presiono ambos pulsadores
  while(digitalRead(pROJO)== LOW && digitalRead(pVERDE)== LOW)
  {
   digitalWrite(pinR, HIGH);
   digitalWrite(pinG, LOW);
   digitalWrite(pinB, HIGH);
  }
  
  //Esta es la secuencia si no se presionan los pulsadores
  digitalWrite(pinB, LOW); 
    digitalWrite(pinR, HIGH);
    digitalWrite(pinG, LOW);
    delay(500);
    digitalWrite(pinR, LOW);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinB, LOW);
    delay(500);
    digitalWrite(pinG, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinR, LOW);
    delay(500);
}
