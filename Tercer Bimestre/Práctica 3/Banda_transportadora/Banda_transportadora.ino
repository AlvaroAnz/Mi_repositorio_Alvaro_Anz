
/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Electronica
   Grado: Quinto
   Sección: A
   Curso: Taller de electronica digital y reparación de computadoras I
   Nombre: Álvaro Anzueto Rodas y Francisco Barillas
   Carnet: 2019376 y 2019373
   Proyecto: Banda transportadora
*/

//Librerias
#include <Servo.h>
#include <Stepper.h>

//Directivas del preprocesador
//LDR en pulldown
#define ch_LDR    A0  //pin A0 del arduino, conectado a Vcc y con una reistencia de 10k a negativo
#define led_Azul  3   //led azul conectado al pin 3
#define led_Verde 4   //led verde conectado al pin 4
#define led_Rojo  5   //led rojo conectado al pin 5, todos del rgb
#define obstaculo 7 //Sensor de obstaculos
#define tiempo 150 //Cuanto tarda el encender de los leds
#define servo 6 //Servomotor y en pin de PWM
//aparte
#define velocidad 6 //Velocidad del stepper
#define revoluciones 2048 //Revoluciones del stepper por minuto

//Variables
//Valores de cada color
int resultado_azul, resultado_rojo, resultado_verde;
//Que son captados por la ldr
int resultado;

//Constructores
Servo separador; //Separa el cubo de color
Stepper banda_t(revoluciones, 8, 10, 9, 10);

void setup() {
  // Llamamos a nuestro servo y stepper
  separador.attach(servo);
  banda_t.setSpeed(velocidad);

  //Comunicacion serial
  Serial.begin(9600);
  Serial.println("Prueba de color");

  //Configuracion de I/O
  pinMode(ch_LDR, INPUT); //pin A0 como entrada
  pinMode(led_Azul, OUTPUT); //pin 3 como salida
  pinMode(led_Verde, OUTP UT); //pin 4 como salida
  pinMode(led_Rojo, OUTPUT);  //pin 5 como salida
  pinMode(obstaculo, INPUT); //pin 7 como sensor de obstaculos

  //Los leds inician en un estado de bajo
  digitalWrite(led_Azul, LOW);
  digitalWrite(led_Verde, LOW);
  digitalWrite(led_Rojo, LOW);
}

void loop() {

  banda_t.step(revoluciones);

  // put your main code here, to run repeatedly:
  if (digitalRead(obstaculo) == LOW) {
    escaneo_color();
    delay(tiempo);
    banda_t.step(-150);
  }
  else {
    banda_t.step(revoluciones);
  }
}

//////////////FUNCIONES///////////////////{
int escaneo_color() {
  //Enviendo el led rojo
  digitalWrite(led_Rojo, HIGH);
  //espero 150 milisegundos
  delay(tiempo);

  //Leo el valor captado por la LDR
  resultado = analogRead(ch_LDR);
  resultado_rojo = map(resultado, 0, 1023, 0, 255); //lo linealizo
  //Lo muestro por medio del monitor serial
  Serial.print("Rojo = ");
  Serial.println(resultado_rojo);
  digitalWrite(led_Rojo, LOW);
  delay(tiempo);

  //Enviendo el led verde
  digitalWrite(led_Verde, HIGH);
  //espero 150 milisegundos
  delay(tiempo);

  //Leo el valor captado por la LDR
  resultado = analogRead(ch_LDR);
  resultado_verde = map(resultado, 0, 1023, 0, 255); //lo linealizo
  //Lo muestro por medio del monitor serial
  Serial.print("Verde = ");
  Serial.println(resultado_verde);
  digitalWrite(led_Verde, LOW);
  delay(tiempo);

  //Enviendo el led azul
  digitalWrite(led_Azul, HIGH);
  //espero 150 milisegundos
  delay(tiempo);

  //Leo el valor captado por la LDR
  resultado = analogRead(ch_LDR);
  resultado_azul = map(resultado, 0, 1023, 0, 255); //lo linealizo
  //Lo muestro por medio del monitor serial
  Serial.print("Azul = ");
  Serial.println(resultado_azul);
  digitalWrite(led_Azul, LOW);
  delay(tiempo);

  if(resultado_verde > resultado_azul && resultado_verde > resultado_rojo){
    banda_t.step(1100);
    separador.write(180);
    delay(300);
    separador.write(0);
  }
}
