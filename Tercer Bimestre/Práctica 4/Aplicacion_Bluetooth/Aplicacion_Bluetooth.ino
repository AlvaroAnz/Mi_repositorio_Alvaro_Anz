/*
  Fundacion Kinal
    Centro educativo tecnico laboral Kinal
  Electronica
  Grado: Quinto
  Sección: A
  Curso: Taller de electronica digital y reparación de computadoras I
  ombre: Álvaro Anzueto Rodas
  Carnet: 2019373
  Proyecto: Comunicacion serial - Aplicación para encender o apagar un led y dar la temperatura
*/

//***Librerías
#include <DallasTemperature.h>//Para la sonda de temperatura
#include <OneWire.h>
#include <Ticker.h>//Para las interrupciones

//***Directivas de preprocesador
#define led 12   //led conectado al pin 13 del arduino
#define SerialBaudRate 9600 //velocidad de la comunicacion serial
#define Sensor_t 11 //sensor de temperatura

//***Funciones ISR
void ISR_Temp(); //Toma lectura de temperatura

//***Constructores
OneWire miWire(Sensor_t);//para la comunicación de un solo cable para el pin 3
DallasTemperature sensor_t(&miWire); //Declaro mi sensor de temperatura
Ticker ticker_temp(ISR_Temp, 10000);//cada diez segundos leerá el estado del pin 3 o sensor

void setup()
{
  Serial.begin(SerialBaudRate); //Inicializo la comunicacion serial a una velocidad de 9600 baudios.
  sensor_t.begin();//Inicio mi sensor de temperatura
  ticker_temp.start();

  pinMode(led, OUTPUT); //Pin 2 como salida
  digitalWrite(led, LOW); //Inicia con el led apagado
}

void loop()
{
  ticker_temp.update(); //Comienza a contar

  //Mientras tengo datos disponibles para leer por medio de la comunicacion serial
  if (Serial.available() > 0)
  {
 char inf_led = Serial.read(); //Declaro una variable tipo char para definir el estado del led


    if (inf_led == '2') { //Si el caracter es L, se apaga el led
      digitalWrite(led, LOW);
    }

    else if (inf_led == '1') { //Si el caracter es H, se enciende el led
      digitalWrite(led, HIGH);
    }
  }
}

//********************Funciones********************************
void ISR_Temp(void) { //para el sensor de temperatura
  sensor_t.requestTemperatures();//Saca lectura del sensor
  float temp = sensor_t.getTempCByIndex(0);//lo guarda en la variable
  Serial.println(temp);
}
