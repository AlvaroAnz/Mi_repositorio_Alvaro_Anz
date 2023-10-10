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

//Librerias
#include <Ticker.h>
#include <LedControl.h>

//Directivas de preprocesador
#define gas_sensor A0
#define dataDin 5
#define dataClock 6
#define dataCS 4

//Función ISR
void ISR_lectura(), llamas(), copos();

//Constructores
Ticker lectura_sensor(ISR_lectura, 5000); //Hará una interrupción cada 5s para poder sacar medida del sensor de gas
LedControl matriz_alarma = LedControl(dataDin, dataClock, dataCS, 1);

//Variables
static int lectura, convert, prom; //Lectura del sensor, su conversión y el promedio de 5 lecturas

//Caracteres de la matriz
byte fuego[8] = {
  B00101000,
  B00101100,
  B01100110,
  B01110111,
  B01111111,
  B01111110,
  B00111110,
  B00011100
};

byte fuego2[8] = {
  B00101000,
  B01001100,
  B01101100,
  B01100110,
  B01111111,
  B01111110,
  B00111110,
  B00011100
};

byte copito[8] = {
  B00000000,
  B00101010,
  B01101011,
  B00011100,
  B00011100,
  B01101011,
  B00101010,
  B00000000
};

byte copito2[8] = {
  B00001000,
  B01001001,
  B00101010,
  B00011100,
  B00011100,
  B00101010,
  B01001001,
  B00001000
};

void setup() {
  Serial.begin(9600);  // put your setup code here, to run once:
  pinMode(gas_sensor, INPUT); //Entrada analógica del sensor de gas
  matriz_alarma.shutdown(0, false); //Enciendo el max7219 para mostrar los estados
  matriz_alarma.setIntensity(0, 15); //Brillo a la mitad
  matriz_alarma.clearDisplay(0); //Limpia la matriz
  lectura_sensor.start(); //Defino la interrupción
}

void loop() {
  lectura_sensor.update();  // Doy inicio a la interrupción
  if (lectura > 100 && lectura <= 269) { //Si el sensor no detecta algo
    //Serial.println(F("Area libre de gases"));
    copos(); //Sigue igual
  }
  if (lectura >= 270) { //Si el sensor SI detecta algo
    //Serial.println(F("Precauncion, se ha detectado un gas"));
    llamas(); //Ativa la alarma
  }
}

void ISR_lectura() {
  lectura = analogRead(gas_sensor);
  Serial.println(lectura);
}

//Funciones para cuando detecte o no

void llamas() { //Pone el caracter de fuego
  for (int x = 0; x < 8; x++) {
    matriz_alarma.setRow(0, x, fuego[x]);
  }
  delay(900);
  for (int a = 0; a < 8; a++) {
    matriz_alarma.setRow(0, a, fuego2[a]);
  }
  delay(900);
}

void copos() { //Pone el caracter de copos
  for (int b = 0; b < 8; b++) {
    matriz_alarma.setRow(0, b, copito[b]);
  }
  delay(900);
  for (int c = 0; c < 8; c++) {
    matriz_alarma.setRow(0, c, copito2[c]);
  }
  delay(900);
}
