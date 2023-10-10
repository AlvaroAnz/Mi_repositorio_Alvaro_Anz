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

//Librerías para el LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Directivas de preprocesador
#define muestra A0
#define R2 10000//Resistencia fija
#define Vcc 5//Fuente 

//Constructor para la lcd
LiquidCrystal_I2C lcd_Alvaro(0x27, 16, 2);

//Variables para la ecuación
float Vout, dato, down, R1;

//Decoración
byte Ohmio[] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01010,
  B11011,
  B00000
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(muestra, INPUT);
  lcd_Alvaro.init();
  lcd_Alvaro.backlight();
  lcd_Alvaro.createChar(1, Ohmio);
  lcd_Alvaro.setCursor(2, 0);
  lcd_Alvaro.print("Ohmimetro");
  lcd_Alvaro.setCursor(2, 1);
  lcd_Alvaro.write(1);
  lcd_Alvaro.setCursor(10, 1);
  lcd_Alvaro.print("     ");
}

void loop() {
  //Variables para la ecuacion
  Vout = analogRead(muestra);//Se guarda el dato en una variable
  Vout = ((5 * Vout) / 1023); //Se ajusta el rango
  Serial.println(Vout);

  if (Vout) { //Si hay un dato
    dato = Vcc - Vout;
    down = Vout;
    R1 = (dato / down) * R2;
      lcd_Alvaro.setCursor(10, 1);
  lcd_Alvaro.print("     ");
    lcd_Alvaro.setCursor(4,1);
    lcd_Alvaro.print(R1);
    delay(500);
  }

}
