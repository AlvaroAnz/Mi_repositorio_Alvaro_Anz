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

#define A A1
#define B A2
#define C A5
#define D A4
#define E A3
#define F A0
#define G 10

#include <Keypad.h>  // importa libreria Keypad


const byte FILAS = 4;           // define numero de filas
const byte COLUMNAS = 4;        // define numero de columnas
char keys[FILAS][COLUMNAS] = {  // define la distribucion de teclas
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte pinesFilas[FILAS] = { 9, 8, 7, 6 };        // pines correspondientes a las filas
byte pinesColumnas[COLUMNAS] = { 5, 4, 3, 2 };  // pines correspondientes a las columnas

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);  // crea objeto

char tecla;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {

  tecla = teclado.getKey();  // obtiene tecla presionada y asigna a variable

  if (teclado.getState() == NO_KEY) { //si el estado del teclado es que nada está pulsado, sacará cero

    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);

  }

  else { //si una tecla se presiona, mostrará un simbolo, durante este se mantenga presionado
    switch (tecla) {//sacará un número diferente

      case ('1'):
        {
          digitalWrite(A, LOW);
          digitalWrite(B, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(D, LOW);
          digitalWrite(E, LOW);
          digitalWrite(F, LOW);
          digitalWrite(G, LOW);
          break;
        }


      case ('2'):
        {
          digitalWrite(A, HIGH);
          digitalWrite(B, HIGH);
          digitalWrite(C, LOW);
          digitalWrite(D, HIGH);
          digitalWrite(E, HIGH);
          digitalWrite(F, LOW);
          digitalWrite(G, HIGH);
          break;
        }

      case ('3'):
        {
          digitalWrite(A, HIGH);
          digitalWrite(B, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(D, HIGH);
          digitalWrite(E, LOW);
          digitalWrite(F, LOW);
          digitalWrite(G, HIGH);
          break;
        }

      case ('4'):
        {
          digitalWrite(A, LOW);
          digitalWrite(B, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(D, LOW);
          digitalWrite(E, LOW);
          digitalWrite(F, HIGH);
          digitalWrite(G, HIGH);
          break;
        }

      case ('5'):
        {
          digitalWrite(A, HIGH);
          digitalWrite(B, LOW);
          digitalWrite(C, HIGH);
          digitalWrite(D, HIGH);
          digitalWrite(E, LOW);
          digitalWrite(F, HIGH);
          digitalWrite(G, HIGH);
          break;
        }

      case ('6'):
        {
          digitalWrite(A, HIGH);
          digitalWrite(B, LOW);
          digitalWrite(C, HIGH);
          digitalWrite(D, HIGH);
          digitalWrite(E, HIGH);
          digitalWrite(F, HIGH);
          digitalWrite(G, HIGH);
          break;
        }

      case ('7'):
        {
          digitalWrite(A, HIGH);
          digitalWrite(B, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(D, LOW);
          digitalWrite(E, LOW);
          digitalWrite(F, LOW);
          digitalWrite(G, LOW);
          break;
        }

      case ('8'):
        {
          digitalWrite(A, HIGH);
          digitalWrite(B, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(D, HIGH);
          digitalWrite(E, HIGH);
          digitalWrite(F, HIGH);
          digitalWrite(G, HIGH);
          break;
        }

      case ('9'):
        {
          digitalWrite(A, HIGH);
          digitalWrite(B, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(D, LOW);
          digitalWrite(E, LOW);
          digitalWrite(F, HIGH);
          digitalWrite(G, HIGH);
          break;
        }

      case ('A'):
        {
          digitalWrite(A, HIGH);
          digitalWrite(B, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(D, LOW);
          digitalWrite(E, HIGH);
          digitalWrite(F, HIGH);
          digitalWrite(G, HIGH);
          break;
        }

      case ('B'):
        {
          digitalWrite(A, LOW);
          digitalWrite(B, LOW);
          digitalWrite(C, HIGH);
          digitalWrite(D, HIGH);
          digitalWrite(E, HIGH);
          digitalWrite(F, HIGH);
          digitalWrite(G, HIGH);
          break;
        }

      case ('C'):
        {
          digitalWrite(A, HIGH);
          digitalWrite(B, LOW);
          digitalWrite(C, LOW);
          digitalWrite(D, HIGH);
          digitalWrite(E, HIGH);
          digitalWrite(F, HIGH);
          digitalWrite(G, LOW);
          break;
        }

      case ('D'):
        {
          digitalWrite(A, LOW);
          digitalWrite(B, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(D, HIGH);
          digitalWrite(E, HIGH);
          digitalWrite(F, LOW);
          digitalWrite(G, HIGH);
          break;
        }

      case ('*'):
        {
          digitalWrite(A, HIGH);
          digitalWrite(B, LOW);
          digitalWrite(C, LOW);
          digitalWrite(D, HIGH);
          digitalWrite(E, HIGH);
          digitalWrite(F, HIGH);
          digitalWrite(G, HIGH);
          break;
        }

      case ('0'):
        {
          digitalWrite(A, HIGH);
          digitalWrite(B, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(D, HIGH);
          digitalWrite(E, HIGH);
          digitalWrite(F, HIGH);
          digitalWrite(G, LOW);
          break;
        }

      case ('#'):
        {
          digitalWrite(A, HIGH);
          digitalWrite(B, LOW);
          digitalWrite(C, LOW);
          digitalWrite(D, LOW);
          digitalWrite(E, HIGH);
          digitalWrite(F, HIGH);
          digitalWrite(G, HIGH);
          break;
        }

    }

  }

}
