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

// Incluyo Libreria
#include <LiquidCrystal.h>

// Definiciones de pre-procesador
#define TRIG 10
#define ECO 9
#define Buzzer 11
#define RS 8
#define Enable 7
#define D4 6
#define D5 5
#define D6 4
#define D7 2
#define columnas 16
#define filas 2
//también para algunas operaciones
#define encender(pin) digitalWrite(pin, HIGH)
#define apagar(pin) digitalWrite(pin, LOW)

//contructor
LiquidCrystal LCD_Alvaro(RS, Enable, D4, D5, D6, D7);// Permite usar la lcd

//variables a usar
int conteo = 0, lectura, ultrasonico(int Emisor, int Receptor);

//llamo las funciones que voy a usar
void pines(), inicio_lcd(), contador(int num1), caracter_lcd(), caracter_lcd(unsigned char columna_caracter), caracter_animacion(int num1);

byte amugus[] = {
  B01110,
  B11111,
  B11000,
  B11000,
  B11111,
  B11111,
  B11011,
  B11011
};

byte muerto1[] = {
  B00000,
  B01010,
  B01110,
  B00100,
  B11111,
  B11111,
  B11011,
  B11011
};

byte quienfue[] = {
  B11111,
  B11011,
  B11001,
  B00000,
  B00000,
  B11001,
  B11011,
  B11111
};


void setup() {
  // put your setup code here, to run once:
  pines();
}

void loop() {
  // put your main code here, to run repeatedly:
  lectura = ultrasonico(TRIG, ECO);
  contador(lectura);

}

//****Funciones******
void pines() {//Primera función: configuración de pines
  pinMode(Buzzer, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  Serial.begin(9600);
  inicio_lcd();
  LCD_Alvaro.createChar(1, amugus);
  LCD_Alvaro.createChar(2, muerto1);
  LCD_Alvaro.createChar(3, quienfue);
}

void inicio_lcd() {
  LCD_Alvaro.begin(columnas, filas);
  LCD_Alvaro.print("Bienvenido!");
  LCD_Alvaro.setCursor(0, 0);
  delay(1000);
  LCD_Alvaro.print("           ");
}

int ultrasonico(int Emisor, int Receptor) {// función: con retorno devuelve la medida en centimetros del ultrasónico
  int duracion, distancia;
  encender(Emisor);
  delayMicroseconds(10);
  apagar(Emisor);
  duracion = pulseIn(Receptor, HIGH);
  distancia = duracion / 59;
  Serial.println(distancia);
  delay(400);
  return distancia;
}

void contador(int num1) {
  if (num1 < 15 && num1 > 4) {
    conteo++;
    LCD_Alvaro.setCursor(0, 0);
    LCD_Alvaro.print(conteo);
    caracter_lcd(conteo);
  }
  while (conteo > 15) {
    limite_contador();
  }

}

void caracter_lcd(unsigned char columna_caracter) {

  LCD_Alvaro.setCursor(columna_caracter - 1, 1);
  caracter_animacion(1);
}

void caracter_animacion(int num1) {
  LCD_Alvaro.write(1);
}

void limite_contador() {
  LCD_Alvaro.setCursor(0, 0);
  LCD_Alvaro.print("  !CUPO LLENO!  ");
  animacion_final();
}


void animacion_final() {
  LCD_Alvaro.setCursor(0, 1);
  LCD_Alvaro.print("                ");
  LCD_Alvaro.setCursor(2, 1);
  LCD_Alvaro.write(1);
  tone(Buzzer, 261);
  delay(600);
  LCD_Alvaro.setCursor(13, 1);
  LCD_Alvaro.write(1);
  tone(Buzzer, 329);
  delay(600);
  LCD_Alvaro.setCursor(6, 1);
  LCD_Alvaro.write(1);
  tone(Buzzer, 523);
  delay(600);
  LCD_Alvaro.setCursor(9, 1);
  LCD_Alvaro.write(1);
  tone(Buzzer, 261);
  delay(600);
  LCD_Alvaro.setCursor(0, 1);
  LCD_Alvaro.write(1);
  tone(Buzzer, 329);
  delay(600);
  LCD_Alvaro.setCursor(12, 1);
  LCD_Alvaro.write(1);
  tone(Buzzer, 523);
  delay(600);
  LCD_Alvaro.setCursor(7, 1);
  LCD_Alvaro.write(1);
  tone(Buzzer, 261);
  delay(600);
  LCD_Alvaro.setCursor(15, 1);
  LCD_Alvaro.write(1);
  tone(Buzzer, 329);
  delay(600);

  LCD_Alvaro.setCursor(6, 1);
  LCD_Alvaro.write(2);
  tone(Buzzer, 523);
  delay(600);
  LCD_Alvaro.setCursor(9, 1);
  LCD_Alvaro.write(2);
  tone(Buzzer, 261);
  delay(600);
  LCD_Alvaro.setCursor(2, 1);
  LCD_Alvaro.write(2);
  tone(Buzzer, 329);
  delay(600);
  LCD_Alvaro.setCursor(13, 1);
  LCD_Alvaro.write(2);
  tone(Buzzer, 523);
  delay(600);
  LCD_Alvaro.setCursor(7, 1);
  LCD_Alvaro.write(2);
  tone(Buzzer, 261);
  delay(600);
  LCD_Alvaro.setCursor(12, 1);
  LCD_Alvaro.write(2);
  tone(Buzzer, 329);
  delay(600);
  LCD_Alvaro.setCursor(0, 1);
  LCD_Alvaro.write(2);
  tone(Buzzer, 523);
  delay(600);
  LCD_Alvaro.setCursor(14, 1);
  LCD_Alvaro.write(3);
  tone(Buzzer, 261);
  delay(400);

}
