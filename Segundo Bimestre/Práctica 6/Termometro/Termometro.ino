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
#define sensor_t 2
#define d_azul 3
#define d_amarillo 4
#define d_rojo 5
#define encender(pin) digitalWrite(pin, HIGH); //para operaciones simplificadas
#define apagar(pin) digitalWrite(pin, LOW);

//librerías a usar
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

//Constructores
OneWire miWire(sensor_t); //para comunicación de un solo cable en el pin 2
DallasTemperature sensors(&miWire);//para el sensor de temperatura

LiquidCrystal_I2C lcd_Alvaro(0x27, 16, 2);//para nuestra lcd

//caracteres especiales
byte termometro[] = {
  B01110,
  B01010,
  B01010,
  B01010,
  B10001,
  B11111,
  B11111,
  B01110
};

byte frio[] = {
  B01110,
  B01010,
  B01010,
  B01010,
  B10001,
  B10001,
  B11111,
  B01110
};

byte copo[] = {
  B00100,
  B10101,
  B01110,
  B10101,
  B00100,
  B01000,
  B00001,
  B10100
};

byte templado[] = {
  B01110,
  B01010,
  B01010,
  B01010,
  B11111,
  B11111,
  B11111,
  B01110
};

byte hoja[] = {
  B01100,
  B00110,
  B01110,
  B01110,
  B11111,
  B01110,
  B00100,
  B00100
};

byte caliente[] = {
  B01110,
  B01010,
  B01110,
  B01110,
  B11111,
  B11111,
  B11111,
  B01110
};

byte volcan[] = {
  B10101,
  B00100,
  B10001,
  B01010,
  B00000,
  B00100,
  B01110,
  B11111
};

byte grado_simbolo[] = {
  B00000,
  B01110,
  B01010,
  B01110,
  B00000,
  B00000,
  B00000,
  B00000
};

float temp1, temp2;

void setup() {
  //no usaré funcion para esto
  Serial.begin(9600);
  sensors.begin();//inicio el sensor de temperatura
  lcd_Alvaro.init();//inicio la lcd
  lcd_Alvaro.backlight();
  lcd_Alvaro.createChar(0, termometro);//defino caracteres
  lcd_Alvaro.createChar(1, grado_simbolo);
  lcd_Alvaro.createChar(2, frio);
  lcd_Alvaro.createChar(3, templado);
  lcd_Alvaro.createChar(4, caliente);
  lcd_Alvaro.createChar(5, copo);
  lcd_Alvaro.createChar(6, hoja);
  lcd_Alvaro.createChar(7, volcan);
  pinMode(d_azul, OUTPUT);//pines para los leds
  pinMode(d_amarillo, OUTPUT);
  pinMode(d_rojo, OUTPUT);
}

void loop() {
  //sera un proceso casi sin funciones
  temp1 = calculo_C();
  temp2 = calculo_F();
  interfaz_lcd();
  etapas_temperatura();
}

//*******************************FUNCIONES*********************************

float calculo_C() { //Funcion para sacar temperatura en grados C
  float grados_c;
  sensors.requestTemperatures();
  grados_c = sensors.getTempCByIndex(0);
  return grados_c;
}

float calculo_F() { //Funcion para sacar temperatura en grados F
  float grados_f;
  sensors.requestTemperatures();
  grados_f = sensors.getTempFByIndex(0);
  return grados_f;
}

void interfaz_lcd() {
  lcd_Alvaro.setCursor(0, 0);
  lcd_Alvaro.write(0);
  lcd_Alvaro.print("  TERMOMETRO ");
  lcd_Alvaro.setCursor(2, 1);
  lcd_Alvaro.print(temp1);
  lcd_Alvaro.write(1);
  lcd_Alvaro.print("C ");
  lcd_Alvaro.setCursor(9, 1);
  lcd_Alvaro.print(temp2);
  lcd_Alvaro.write(1);
  lcd_Alvaro.print("F ");
  delay(600);
}

void etapas_temperatura() {
  if (temp1 < 15) {//si la temperatura es fría
    encender(d_azul);
    apagar(d_rojo);
    apagar(d_amarillo);
    lcd_Alvaro.setCursor(0, 1);
    lcd_Alvaro.write(2);
    lcd_Alvaro.write(5);
  }

  if (temp1 >= 15 && temp1 <= 30) {//Si la temperatura es templada
    encender(d_amarillo);
    apagar(d_azul);
    apagar(d_rojo);
    lcd_Alvaro.setCursor(0, 1);
    lcd_Alvaro.write(3);
    lcd_Alvaro.write(6);
  }

  if (temp1 > 30) {//Si la temperatura es caliente
    encender(d_rojo);
    apagar(d_azul);
    apagar(d_amarillo);
    lcd_Alvaro.setCursor(0, 1);
    lcd_Alvaro.write(4);
    lcd_Alvaro.write(7);
  }
}
