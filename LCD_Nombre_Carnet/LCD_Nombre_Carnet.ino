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

// Incluyo libreria
#include <LiquidCrystal.h>

// Definiciones de pre-procesador
#define RS 12
#define Enable 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2
#define columnas 16
#define filas 2

// Constructor
LiquidCrystal LCD_Alvaro(RS, Enable, D4, D5, D6, D7);// Me permite usar la lcd

void setup() {

  LCD_Alvaro.begin(columnas, filas);// Objeto de una lcd de 16 columnas x 2 filas
  LCD_Alvaro.print("Alvaro Anzueto");
  delay(1000);
  LCD_Alvaro.setCursor(0, 1); // el cursor se mueve a columna 0 fila 1
  LCD_Alvaro.print("2019373");
}

void loop() {
  // Solo necesitaba que lo imprimiera una vez

}
