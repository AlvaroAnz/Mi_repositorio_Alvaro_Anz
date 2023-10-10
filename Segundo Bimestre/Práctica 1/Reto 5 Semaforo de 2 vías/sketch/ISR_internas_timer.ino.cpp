#include <Arduino.h>
#line 1 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\PRUEBA\\ISR_internas_timer\\ISR_internas_timer.ino"
/*

Uso de interrupciones de temporizador por medio de Ticker
*/
//Librerias
#include <Ticker.h> //Esta libreria me permite hacer uso del timer

//Directivas de preprocesador
#define led_arduino 13 //led on board, que posee mi arduino

//Funciones de ISR
void isr_led(void);

//Vatiables
volatile static bool estado_led;

//Constructores
Ticker isr_accion_led(isr_led, 3000);//cada tres segundos se encedera/apagara el led del pin 13

#line 20 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\PRUEBA\\ISR_internas_timer\\ISR_internas_timer.ino"
void setup();
#line 28 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\PRUEBA\\ISR_internas_timer\\ISR_internas_timer.ino"
void loop();
#line 20 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\PRUEBA\\ISR_internas_timer\\ISR_internas_timer.ino"
void setup() {
  Serial.begin(19200);
  pinMode(led_arduino, OUTPUT);
  digitalWrite(led_arduino, LOW);
  isr_accion_led.start();//Iniciando la interrupción que esperaría se repitiera cada 3 segundos
  estado_led = LOW;
}

void loop() {
  
  isr_accion_led.update();
  
}

//Funciones ISR
void isr_led(void)
{
  estado_led = digitalRead(led_arduino); //Leo el estado digital del pin que uso como salida
  digitalWrite(led_arduino, !estado_led);
  Serial.println("Ha ocurrido una interrupcion");
}

