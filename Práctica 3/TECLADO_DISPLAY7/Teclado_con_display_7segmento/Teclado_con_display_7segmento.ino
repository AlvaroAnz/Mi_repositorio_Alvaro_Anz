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

#include <Keypad.h>

//defino la cantidad de columnas y filas del teclado
const byte filas_teclado = 4;//const porque no requieren punto decimal
const byte columnas_teclado = 4; 

//hago el arreglo para las teclas del teclado
char config_teclado[filas_teclado][columnas_teclado] = {
  {'1', '2', '3', 'A'}, //Solo una comilla porque se identifican como caracteres
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//aclaro en que pines se ubican cada tecla
byte filas_pines [filas_teclado] = {A7, A6, A5, A4};
byte columnas_pines [columnas_teclado] = {A3, A2, A1, A0};

Keypad llaves = Keypad(makeKeymap(config_teclado), filas_pines, columnas_pines, filas_teclado, columnas_teclado);

#define a_pin 4 
#define b_pin 5
#define c_pin 8
#define d_pin 7
#define e_pin 6
#define f_pin 3
#define g_pin 2
#define salida(pin) pinMode(pin, OUTPUT)
#define entrada(pin) pinMode(pin, INPUT)
#define ALTO(pin) digitalWrite(pin, HIGH)
#define BAJO(pin) digitalWrite(pin, LOW)


void setup() {
  // defino las salidas hacia el display
 salida(a_pin);
 salida(b_pin);
 salida(c_pin);
 salida(d_pin);
 salida(e_pin);
 salida(f_pin);
 salida(g_pin);
 Serial.begin(9600);
}

void loop() {
  // indico que si se presiona una de las teclas, tendrá que mandar una cierta señal, dependiendo de la tecla
  char config_teclado = llaves.getKey();
  //indico que luces debe encender dependiendo que tecla se presionó
 Serial.println(config_teclado);
 
}

