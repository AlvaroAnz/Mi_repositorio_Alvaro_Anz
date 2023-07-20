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

//Libreria
#include <LedControl.h> //Para la matriz led
#include <SparkFun_ADXL345.h> //No brilla,para el acelerómetro
#include <Wire.h>

//Constructores
ADXL345 acelerometro = ADXL345(); //Objeto del acelerómetro
LedControl matriz_led = LedControl(5, 6, 4, 1); //Objeto de la matriz led

//Variables y caracteres
byte der1[8] = {
  B11000011,
  B01000010,
  B01000010,
  B01000010,
  B01011010,
  B01011010,
  B01000010,
  B11000011
};

byte der2[8] = {
  B11000011,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01011010,
  B01011010,
  B11000011
};

byte der3[8] = {
  B11000011,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01011010,
  B11011011
};

byte centro[8] = {
  B11000011,
  B01000010,
  B01000010,
  B01011010,
  B01011010,
  B01000010,
  B01000010,
  B11000011
};

byte izq1[8] = {
  B11000011,
  B01000010,
  B01011010,
  B01011010,
  B01000010,
  B01000010,
  B01000010,
  B11000011
};

byte izq2[8] = {
  B11000011,
  B01011010,
  B01011010,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B11000011
};

byte izq3[8] = {
  B11011011,
  B01011010,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B11000011
};

int x;

void setup() {
  //Inicio
  Serial.begin(9600);
  acelerometro.powerOn(); //Enciende el acelerometro
  acelerometro.setRangeSetting(8); //Saca una escala de 8 gravedades
  matriz_led.shutdown(0, false); //Enciendo el max7219 para mostrar los estados
  matriz_led.setIntensity(0, 25); //Brillo a la mitad
  matriz_led.clearDisplay(0); //Limpia la matriz
}

void loop() {
  //La lectura del eje x
  lectura_g();
  if (x > 48 && x <= 64) { //Si el rango es de 64-48
    for (int a = 0; a < 8; a++) {
      matriz_led.setRow(0, a, der3[a]);//Aparece izq3
    }
  }
  if (x > 28 && x <= 48) { //Si el rango es de 48-28
    for (int b = 0; b < 8; b++) {
      matriz_led.setRow(0, b, der2[b]);//Aparece izq2
    }
  }
  if (x > 8 && x <= 28) { //Si el rango es de 28-8
    for (int c = 0; c < 8; c++) {
      matriz_led.setRow(0, c, der1[c]);//Aparece izq1
    }
  }
  if (x >= -8 && x <= 8) { //Si el rango es de 8 -8
    for (int d = 0; d < 8; d++) {
      matriz_led.setRow(0, d, centro[d]);//Aparece centro
    }
  }
  if (x >= -28 && x <= -8) { //Si el rango es de -8 -28
    for (int e = 0; e < 8; e++) {
      matriz_led.setRow(0, e, izq1[e]);//Aparece der1
    }
  }
  if (x >= -48 && x <= -28) { //Si el rango es de -28 -48
    for (int f = 0; f < 8; f++) {
      matriz_led.setRow(0, f, izq2[f]);//Aparece der2
    }
  }
   if (x >= -65 && x <= -48) { //Si el rango es de -28 -48
    for (int g = 0; g < 8; g++) {
      matriz_led.setRow(0, g, izq3[g]);//Aparece der2
    }
  }
}

void lectura_g() {
  acelerometro.readAccel(&x); //Saca lectura de la dimensión X y la guarda en la variable
  Serial.println(x);
  delay(200);
}
