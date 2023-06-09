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
#define Potem A0

//Variables a usar
int brillo = 0;//se guarda el valor del potenciometro

void setup() {
  pinMode(Rojo, OUTPUT);
  pinMode(Potem, INPUT);//La entrada analogica no requieren inicialización
}

void loop() {//Map es una regla de 3 para el rango de la variable
  brillo = map(analogRead(Potem), 0, 1023, 0, 255);//Usamos un mapa para dejar un margen de 0 a 255, guardado en una variable
  analogWrite(Rojo, brillo); //Cambia la intesidad del led
}
