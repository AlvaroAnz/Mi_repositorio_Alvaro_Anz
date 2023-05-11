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
#define SensorT 2
#define Buzzer 3
#define RGB_Rojo  4//hay que definir
#define RGB_Verde 5
#define RGB_Azul 6
#define yellow_botton 7
#define green_botton 8
#define red_botton 9
#define servo_pin 10
#define Neopixel A0
#define Radar A3
#define foco1 A1
#define foco2 A2

#define cantidad_leds 7
#define encender(pin) digitalWrite(pin, HIGH); //para operaciones simplificadas
#define apagar(pin) digitalWrite(pin, LOW);
#define salida(pin) pinMode(pin, OUTPUT);
#define entrada(pin) pinMode(pin, INPUT);

//Librerias a usar
#include <LiquidCrystal_I2C.h>//Para la lcd
#include <DallasTemperature.h>//Para el sensor de temperatura
#include <OneWire.h>
#include <Adafruit_NeoPixel.h>//Para la rueda neopixel
#include <Servo.h>//Para el servo


//constructores
OneWire miWire(SensorT); //para comunicación de un solo cable en el pin 2
DallasTemperature sensor_t(&miWire);//para el sensor de temperatura
LiquidCrystal_I2C lcd_Alvaro(0x27, 16, 2); //objeto para la lcd
Adafruit_NeoPixel rueda_led(cantidad_leds, Neopixel, NEO_GRB + NEO_KHZ800); //para la rueda neopixel
Servo servo_Alvaro;//Servo

//caracteres especiales para la lcd

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

byte encendido[] = {
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B00000,
  B11111,
  B10001
};

byte apagado[] = {
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000,
  B11111,
  B10001
};

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

enum colores //Colores para el neopixel
{
  turquesa,
  bhueso,
  rojo,
  amarillo,
  verde,
};

//Variables a usar
float temp;
int estado_pulsadorY = 0, estado_pulsadorG = 0, estado_pulsadorR = 0; //variable para el pulsador

//Llamo las funciones
void pines(), lcd_interfaz(), luminaria1(), luminaria2(), puerta();

void setup() {
  // configuramos pines y los objetos
  Serial.begin(9600);
  pines();
}

void loop() {
  // En orden pasarán las siguientes funciones:
  lcd_interfaz();
  luminaria1();
  luminaria2();
  puerta();
  temp = calculo_C();
  etapa_temp();
  presencia();
  luminaria1();
  luminaria2();
  puerta();
}

//*****FUNCIONES*****

void pines() {//configura los pines e inicializa la lcd y el sensor de temperatura
  sensor_t.begin();
  rueda_led.begin();
  servo_Alvaro.attach(servo_pin);
  lcd_Alvaro.init();
  lcd_Alvaro.backlight();
  lcd_Alvaro.createChar(0, caliente);
  lcd_Alvaro.createChar(1, templado);
  lcd_Alvaro.createChar(2, frio);
  lcd_Alvaro.createChar(3, encendido);
  lcd_Alvaro.createChar(4, apagado);
  lcd_Alvaro.createChar(5, amugus);
  lcd_Alvaro.createChar(6, muerto1);
  salida(RGB_Azul);//hay que definir
  salida(RGB_Rojo);
  salida(RGB_Verde);
  salida(A2);
  salida(A1);
  entrada(Radar);
  entrada(red_botton);
  entrada(yellow_botton);
  entrada(green_botton);
  encender(foco1);
  encender(foco2);
}

void lcd_interfaz() {
  lcd_Alvaro.setCursor(0, 0);
  lcd_Alvaro.print("TEMP:");
  //caracter de la temperatura
  lcd_Alvaro.setCursor(7, 0);
  lcd_Alvaro.print("B1:");
  //caracter del primer foco
  lcd_Alvaro.setCursor(12, 0);
  lcd_Alvaro.print("B2:");
  //caracter del segundo foco
  lcd_Alvaro.setCursor(0, 1);
  lcd_Alvaro.print("Radar:");
  //caracter del radar
  lcd_Alvaro.setCursor(9, 1);
  lcd_Alvaro.print("P:");
  //puerts
  delay(600);
}

float calculo_C() { //Funcion para sacar temperatura en grados C
  float grados_c;
  sensor_t.requestTemperatures();
  grados_c = sensor_t.getTempCByIndex(0);
  Serial.println(grados_c);
  return grados_c;
}

void etapa_temp() {//Con la función, dependiendo de la temperatura que mida el sensor

  if (temp < 46 && temp >= 26) {//si es muy alta, prende el rgb rojo y tira un caracter
    apagar(RGB_Azul);
    encender(RGB_Rojo);
    apagar(RGB_Verde);
    lcd_Alvaro.setCursor(5, 0);
    lcd_Alvaro.write(0);
  }
  if (temp < 26 && temp >= 21) {//si es nuetro, prende el rgb verde y tira un caracter
    apagar(RGB_Azul);
    apagar(RGB_Rojo);
    encender(RGB_Verde);
    lcd_Alvaro.setCursor(5, 0);
    lcd_Alvaro.write(1);
  }
  if (temp < 21 && temp >= 15) {//si es muy baja, prende el rgb rojo y azul = morado, y tira un caracter
    encender(RGB_Azul);
    encender(RGB_Rojo);
    apagar(RGB_Verde);
    lcd_Alvaro.setCursor(5, 0);
    lcd_Alvaro.write(2);
  }
}

void presencia() {//Funcion para detección del radar
  int lectura = digitalRead(Radar);

  if (lectura == HIGH) {//Si presenta una lectura, lanza una alarma
    lcd_Alvaro.setCursor(6, 1);
    lcd_Alvaro.write(5);//vivo
    setColor(turquesa);
    tone(Buzzer, 523);
    delay(250);
    setColor(bhueso);
    tone(Buzzer, 261);
    delay(250);
    setColor(rojo);
    tone(Buzzer, 587);
    delay(250);
    setColor(amarillo);
    tone(Buzzer, 391);
    delay(250);
    noTone(Buzzer);
  }
  if (lectura == LOW) {//Si no detecta nada, lo apaga
    lcd_Alvaro.setCursor(6, 1);
    lcd_Alvaro.write(6);//muerto
    setColor(verde);
    noTone(Buzzer);
  }
}

void setColor(int color) {//Configura el color del neopixel dependiendo del caso
  switch (color) {

    case turquesa:
      for (int i = 0; i < 8; i++) {
        rueda_led.setPixelColor(i, rueda_led.Color(0, 139, 139));//Defino el color con codigo
        rueda_led.show();//Muestra el color
      }
      break;

    case bhueso:
      for (int i = 0; i < 8; i++) {
        rueda_led.setPixelColor(i, rueda_led.Color(250, 235, 215));
        rueda_led.show();
      }
      break;

    case rojo:
      for (int i = 0; i < 8; i++) {
        rueda_led.setPixelColor(i, rueda_led.Color(220, 20, 60));
        rueda_led.show();
      }
      break;

    case amarillo:
      for (int i = 0; i < 8; i++) {
        rueda_led.setPixelColor(i, rueda_led.Color(255, 215, 0));
        rueda_led.show();
      }
      break;

    case verde:
      for (int i = 0; i < 8; i++) {
        rueda_led.setPixelColor(i, rueda_led.Color(50, 205, 50));
        rueda_led.show();
      }
      break;
  }
}

void luminaria1() {//Funcion para encender el primer foco
  if (digitalRead(green_botton) && estado_pulsadorG == 1) {
    apagar(foco1);
    lcd_Alvaro.setCursor(10, 0);
    lcd_Alvaro.write(3);//encendido
    delay(220);
    estado_pulsadorG = 0;
  }

  if (digitalRead(green_botton) && estado_pulsadorG == 0) {
    encender(foco1);
    lcd_Alvaro.setCursor(10, 0);
    lcd_Alvaro.write(4);//apagado
    delay(220);
    estado_pulsadorG = 1;
  }
}

void luminaria2() {//Funcion para encender el segundo foco
  if (digitalRead(red_botton) && estado_pulsadorR == 1) {
    apagar(foco2);
    lcd_Alvaro.setCursor(15, 0);
    lcd_Alvaro.write(3);//encendido
    delay(220);
    estado_pulsadorR = 0;
  }

  if (digitalRead(red_botton) && estado_pulsadorR == 0) {
    encender(foco2);
    lcd_Alvaro.setCursor(15, 0);
    lcd_Alvaro.write(4);//apagado
    delay(220);
    estado_pulsadorR = 1;
  }
}

void puerta() {//Función para el tercer foco, activando la puerta
  if (digitalRead(yellow_botton) && estado_pulsadorY == 1) {
    servo_Alvaro.write(0);//Se mantiene la posición en 0 grados
    lcd_Alvaro.setCursor(11, 1);
    lcd_Alvaro.print("CLOSE");
    delay(220);
    estado_pulsadorY = 0;
  }

  if (digitalRead(yellow_botton) && estado_pulsadorY == 0) {
    servo_Alvaro.write(135);//mueve la pieza a 135 grados
    lcd_Alvaro.setCursor(11, 1);
    lcd_Alvaro.print("OPEN ");
    delay(220);
    estado_pulsadorY = 1;
  }
}
