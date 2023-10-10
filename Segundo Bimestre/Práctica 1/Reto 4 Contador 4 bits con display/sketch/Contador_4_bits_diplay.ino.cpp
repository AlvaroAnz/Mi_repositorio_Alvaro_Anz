#include <Arduino.h>
#line 1 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\Archivos binarios\\Reto 4 Contador 4 bits con display\\Contador_4_bits_diplay\\Contador_4_bits_diplay.ino"
/*Fundación Kinal
 * Centro Educativo Técnico Laboral Kinal
 * Electrónica
 * Grado: Quinto
 * Sección: A
 * Nombre: Álvaro Anzueto Rodas
 * Carne: 2019373
 */
#define A 2 //Les cambié el nombre de los pines como si fueran los pines de un display, para relacionarlos
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8

 
#line 18 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\Archivos binarios\\Reto 4 Contador 4 bits con display\\Contador_4_bits_diplay\\Contador_4_bits_diplay.ino"
void setup();
#line 30 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\Archivos binarios\\Reto 4 Contador 4 bits con display\\Contador_4_bits_diplay\\Contador_4_bits_diplay.ino"
void loop();
#line 18 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\Archivos binarios\\Reto 4 Contador 4 bits con display\\Contador_4_bits_diplay\\Contador_4_bits_diplay.ino"
void setup() {
  // defino los pines como salidas
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

}

void loop() {
  // Como si fuera un bcd, voy enciendendo cada pin para formar el número que quiero

  //0
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  delay(500);//cambia de número cada medio segundo

  //1
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  delay(500);

  //2
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  delay(500);

  //3
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  delay(500);

  //4
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  delay(500);

  //5
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  delay(500);

  //6
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  delay(500);

  //7
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  delay(500);

  //8
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  delay(500);
}

