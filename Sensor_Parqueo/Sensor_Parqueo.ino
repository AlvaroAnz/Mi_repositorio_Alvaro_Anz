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

//Incluyo mis librerias a usar
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Directivas de preprocesador
#define direccion_lcd 0x27 //para la lcd
#define columnas 16
#define filas 2
#define TRIG A3 //para el ultrasónico
#define ECO A2
#define encender(pin) digitalWrite(pin, HIGH); //para operaciones simplificadas
#define apagar(pin) digitalWrite(pin, LOW);

//Constructor para el lcd
LiquidCrystal_I2C lcd_Alvaro(direccion_lcd, columnas, filas);

int ultrasonico(int Emisor, int Receptor), lectura, etapa;
void pines();

byte lcd_bloque[] = {//El caracter que se llena dependiendo la distancia
  B11011,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11011
};


void setup() {
  // configuro todo en una sola función
  pines();
}

void loop() {
  // guardo algunos datos en variables
  lectura = ultrasonico(TRIG, ECO);
  etapas(lectura);
  lcd_mensajes(etapa);
}

//************************************Funciones**********************************************

void pines() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  Serial.begin(9600);
  lcd_Alvaro.init();
  lcd_Alvaro.backlight();
  lcd_Alvaro.createChar(1, lcd_bloque);
  lcd_Alvaro.setCursor(0, 0);

}

int ultrasonico(int Emisor, int Receptor) {// función: con retorno devuelve la medida en centimetros del ultrasónico
  int duracion, distancia;
  encender(Emisor);
  delayMicroseconds(10);
  apagar(Emisor);
  duracion = pulseIn(Receptor, HIGH);
  distancia = duracion / 59;
  Serial.print(distancia);
  Serial.println(" cm");
  delay(350);
  return distancia;
}

void etapas(int num1) {
  if (num1 > 50) { //Si la distancia es mayor, sera la etapa 0
    etapa = 0;
  }
  if (num1 <= 50 && num1 >= 31) { //Si la distancia es entre 50-30cm, sera la etapa 1
    etapa = 1;
  }
  if (num1 <= 30 && num1 >= 11) { //Si la distancia es entre 30-10cm, sera la etapa 2
    etapa = 2;
  }
  if (num1 <= 10 && num1 >= 3) { //Si la distancia es entre 10-3cm, sera la etapa 3
    etapa = 3;
  }
}

void lcd_mensajes(int num1) {
  switch (num1) {

    case 0:
      lcd_Alvaro.setCursor(0, 0);
      lcd_Alvaro.print("                ");
      lcd_Alvaro.setCursor(0, 1);
      lcd_Alvaro.print("                ");
      break;

    case 1:
      lcd_Alvaro.setCursor(4, 0);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.setCursor(7, 0);
      lcd_Alvaro.print("50");
      lcd_Alvaro.setCursor(9, 0);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.setCursor(3, 1);
      lcd_Alvaro.print("  LIBRE!  ");
      break;

    case 2:
      lcd_Alvaro.setCursor(2, 0);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.setCursor(7, 0);
      lcd_Alvaro.print("30");
      lcd_Alvaro.setCursor(9, 0);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.setCursor(4, 1);
      lcd_Alvaro.print("CUIDADO!");
      break;

      
    case 3:
      lcd_Alvaro.setCursor(0, 0);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.setCursor(7, 0);
      lcd_Alvaro.print("10");
      lcd_Alvaro.setCursor(9, 0);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.write(1);
      lcd_Alvaro.setCursor(4, 1);
      lcd_Alvaro.print("  ALTO  ");
      break;
  }
}
