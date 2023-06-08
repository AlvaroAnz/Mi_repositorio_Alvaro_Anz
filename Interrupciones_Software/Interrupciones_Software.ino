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

//Incluir librerias
#include <Ticker.h> //me permite el uso del timer
#include <OneWire.h> //me permite conectar la conexión de un solo alambre(sensor)
#include <DallasTemperature.h> //me permite el uso del sensor de temperatura

//Directivas de preprocesador
#define boton 2 //para el boton 
#define sensor_temp 3 //sensor de temperatura 

//Funciones ISR
void isr_boton(void); //para el botón
void isr_sensorT(void); //para el sensor de temperatura

//Constructor
OneWire miWire(sensor_temp);//para la comunicación de un solo cable para el pin 3
DallasTemperature sensor_t(&miWire); //Declaro mi sensor de temperatura
Ticker isr_accion_sensor_t(isr_sensorT, 3000);//cada tres segundos leerá el estado del pin 3 o sensor
Ticker isr_accion_boton(isr_boton, 6000);//cada seis segundos leerá el estado del pin 2 o botón

//Variables globales a usar
volatile static bool b_estado = false; //para el estado del botón
float temp; //para la temperatura captada

void setup() {
  sensor_t.begin();//inicio mi sensor de temperatura
  Serial.begin(9600); //Inicio la comunicacion serial
  pinMode(boton, INPUT); //Se definen como entradas de datos
  pinMode(sensor_temp, INPUT);
  isr_accion_boton.start();   //Iniciando la interrupción que esperaria se repitiera cada 3 segundos
  isr_accion_sensor_t.start(); //Iniciando la interrupcción que esperaría se repitiera cada 6 segundos  
  Serial.println("Inicio programa");
}

void loop() {
  isr_accion_boton.update(); //Constantemente se actualizan
  isr_accion_sensor_t.update();
}

//*Funciones ISR*
void isr_boton(void) { //para el botón
  b_estado = digitalRead(boton);
  if (b_estado == HIGH) {
    Serial.println("Boton presionado");
  }
  if(b_estado == LOW){
    Serial.println("Boton no presionado");
  }
}

void isr_sensorT(void) { //para el sensor de temperatura
  sensor_t.requestTemperatures();//Saca lectura del sensor
  temp = sensor_t.getTempCByIndex(0);//lo guarda en la variable
  Serial.println(temp);
}
