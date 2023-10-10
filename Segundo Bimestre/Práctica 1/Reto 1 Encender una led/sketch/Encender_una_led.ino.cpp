#include <Arduino.h>
#line 1 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\Archivos binarios\\Reto 1 Encender una led\\Encender_una_led\\Encender_una_led.ino"
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

#define LED 13

#line 14 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\Archivos binarios\\Reto 1 Encender una led\\Encender_una_led\\Encender_una_led.ino"
void setup();
#line 20 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\Archivos binarios\\Reto 1 Encender una led\\Encender_una_led\\Encender_una_led.ino"
void loop();
#line 14 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\Archivos binarios\\Reto 1 Encender una led\\Encender_una_led\\Encender_una_led.ino"
void setup() {
  pinMode(LED, OUTPUT);

}


void loop() {
  digitalWrite(LED, HIGH);

}

