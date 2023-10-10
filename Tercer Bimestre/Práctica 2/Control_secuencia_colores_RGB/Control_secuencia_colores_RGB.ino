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

//Directivas de preprocesador
#define Rojo 3
#define Azul 6
#define Verde 5
#define Potem A0

//Variables a usar
int tiempo = 0;//se guarda el valor del potenciometro

void setup() {
  // put your setup code here, to run once:
  pinMode(Rojo, OUTPUT);
  pinMode(Verde, OUTPUT);
  pinMode(Azul, OUTPUT);
  pinMode(Potem, INPUT);//La entrada analogica no requieren inicialización
}

void loop() {
  // put your main code here, to run repeatedly:
  tiempo = map(analogRead(Potem), 0, 1023, 100, 1000); //La variable del potem, lo ajusta al rango de tiempo
  secuencia_led();
}

//Funciones
void secuencia_led() {
  analogWrite(Rojo, 174);
  analogWrite(Verde, 92);
  analogWrite(Azul, 230);
  delay(tiempo);
  analogWrite(Rojo, 255);
  analogWrite(Verde, 255);
  analogWrite(Azul, 255);
  delay(tiempo);
  analogWrite(Rojo, 0);
  analogWrite(Verde, 255);
  analogWrite(Azul, 255);
  delay(tiempo);
  digitalWrite(Rojo, 189);
  digitalWrite(Verde, 174);
  digitalWrite(Azul, 20);
  delay(tiempo);
  analogWrite(Rojo, 225);
  analogWrite(Verde, 87);
  analogWrite(Azul, 35);
  delay(tiempo);
}
