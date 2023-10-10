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
#define barra_1 2 // para el display de barra
#define barra_2 3
#define barra_3 4
#define barra_4 5
#define barra_5 6
#define barra_6 7
#define barra_7 8
#define barra_8 9
#define barra_9 10
#define barra_10 11
#define Buzzer 12 //para el buzzer :v
#define encender(pin) digitalWrite(pin, HIGH); //para operaciones simplificadas
#define apagar(pin) digitalWrite(pin, LOW);

//Constructor para el lcd
LiquidCrystal_I2C lcd_Alvaro(direccion_lcd, columnas, filas);

int ultrasonico(int Emisor, int Receptor), lectura;
void pines()  ;

void setup() {
  // funcion que se encarga para inicializar
  Serial.begin(9600);
  pines();
}

void loop() {
  // funciones que cumplen un proceso
  lectura = ultrasonico( TRIG, ECO);
  display_barra();
  alarma();
  lcd_mensajes();
}

//************************************Funciones**********************************************

void pines() {
  pinMode(Buzzer, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(barra_1, OUTPUT);
  pinMode(barra_2, OUTPUT);
  pinMode(barra_3, OUTPUT);
  pinMode(barra_4, OUTPUT);
  pinMode(barra_5, OUTPUT);
  pinMode(barra_6, OUTPUT);
  pinMode(barra_7, OUTPUT);
  pinMode(barra_8, OUTPUT);
  pinMode(barra_9, OUTPUT);
  pinMode(barra_10, OUTPUT);
  inicio_lcd();
}

void inicio_lcd() {//inicializa la lcd
  lcd_Alvaro.init();
  lcd_Alvaro.backlight();
  // lcd_Alvaro.print("holis");
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

void display_barra () {

  if (lectura >= 46) { //Si el objeto se encuentra en una distancia mayor o igual a 46
    apagar(barra_1);
    apagar(barra_2);
    apagar(barra_3);
    apagar(barra_4);
    apagar(barra_5);
    apagar(barra_6);
    apagar(barra_7);
    apagar(barra_8);
    apagar(barra_9);
    apagar(barra_10);
  }

  if (lectura < 46 && lectura >= 40) { //Si el objeto se encuentra a una distancia menor de 46 pero mayor o igual a 40
    encender(barra_1);
    apagar(barra_2);
    apagar(barra_3);
    apagar(barra_4);
    apagar(barra_5);
    apagar(barra_6);
    apagar(barra_7);
    apagar(barra_8);
    apagar(barra_9);
    apagar(barra_10);
  }

  if (lectura < 40 && lectura >= 35) { //Si el objeto se encuentra a una distancia menor de 40 pero mayor o igual a 35
    encender(barra_1);
    encender(barra_2);
    apagar(barra_3);
    apagar(barra_4);
    apagar(barra_5);
    apagar(barra_6);
    apagar(barra_7);
    apagar(barra_8);
    apagar(barra_9);
    apagar(barra_10);
  }


  if (lectura < 35 && lectura >= 27) { //Si el objeto se encuentra a una distancia menor de 35 pero mayor o igual a 27
    encender(barra_1);
    encender(barra_2);
    encender(barra_3);
    encender(barra_4);
    apagar(barra_5);
    apagar(barra_6);
    apagar(barra_7);
    apagar(barra_8);
    apagar(barra_9);
    apagar(barra_10);
  }


  if (lectura < 27 && lectura >= 18) { //Si el objeto se encuentra a una distancia menor de 27 pero mayor o igual a 18
    encender(barra_1);
    encender(barra_2);
    encender(barra_3);
    encender(barra_4);
    encender(barra_5);
    encender(barra_6);
    apagar(barra_7);
    apagar(barra_8);
    apagar(barra_9);
    apagar(barra_10);
  }

  if (lectura < 18 && lectura >= 9) { //Si el objeto se encuentra a una distancia menor de 18 pero mayor o igual a 9
    encender(barra_1);
    encender(barra_2);
    encender(barra_3);
    encender(barra_4);
    encender(barra_5);
    encender(barra_6);
    encender(barra_7);
    encender(barra_8);
    apagar(barra_9);
    apagar(barra_10);
  }

    if (lectura < 9 && lectura >= 6) { //Si el objeto se encuentra a una distancia menor de 9 pero mayor o igual a 6
    encender(barra_1);
    encender(barra_2);
    encender(barra_3);
    encender(barra_4);
    encender(barra_5);
    encender(barra_6);
    encender(barra_7);
    encender(barra_8);
    encender(barra_9);
    apagar(barra_10);
  }

  if (lectura < 6) { //Si el objeto se encuentra a una distancia menor de 6
    encender(barra_1);
    encender(barra_2);
    encender(barra_3);
    encender(barra_4);
    encender(barra_5);
    encender(barra_6);
    encender(barra_7);
    encender(barra_8);
    encender(barra_9);
    encender(barra_10);
  }
}

void alarma() {
  if (lectura < 20 && lectura >= 11) {//si se encuentra en una distancia media, el buzzer sonará una melodia
    tone(Buzzer, 523);
    delay(800);
    noTone(Buzzer);
    delay(150);
  }
  if (lectura < 11 && lectura >= 1) {//si se encuentra en una distancia baja, sonara una tipo alarma
    tone(Buzzer, 523);
    delay(2000);
    noTone(Buzzer);
    delay(150);
  }
}

void lcd_mensajes(){

  if (lectura >= 45) { //Si el objeto se encuentra en una distancia mayor o igual a 45
    lcd_Alvaro.print("                ");
    lcd_Alvaro.setCursor(0, 0);
    lcd_Alvaro.print("FUERA DE ALCANCE");
    lcd_Alvaro.setCursor(0, 1);
    lcd_Alvaro.print("                ");
    
  }
  
  if (lectura < 45 && lectura >= 30) { //Si el objeto se encuentra a una distancia menor de 45 pero mayor o igual a 30
    lcd_Alvaro.setCursor(0, 0);
    lcd_Alvaro.print(" PERSONA/OBJETO ");
    lcd_Alvaro.setCursor(0, 1);
    lcd_Alvaro.print("  ACERCANDOSE   ");
  }

  if (lectura < 30 && lectura >= 15) { //Si el objeto se encuentra a una distancia menor de 30 pero mayor o igual a 15
    lcd_Alvaro.setCursor(0, 0);
    lcd_Alvaro.print(" CUIDADO ESPACIO ");
    lcd_Alvaro.setCursor(0, 1);
    lcd_Alvaro.print("     PRIVADO     ");
  }

  if (lectura < 15 && lectura >= 5) { //Si el objeto se encuentra a una distancia menor de 15 pero mayor o igual a 5
    lcd_Alvaro.setCursor(0, 0);
    lcd_Alvaro.print("   INVADIENDO    ");
    lcd_Alvaro.setCursor(0, 1);
    lcd_Alvaro.print(" ESPACIO PRIVADO ");
  }
}
