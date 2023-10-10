# 1 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\PRUEBA\\ISR_internas_timer\\ISR_internas_timer.ino"
/*



Uso de interrupciones de temporizador por medio de Ticker

*/
# 5 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\PRUEBA\\ISR_internas_timer\\ISR_internas_timer.ino"
//Librerias
# 7 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\PRUEBA\\ISR_internas_timer\\ISR_internas_timer.ino" 2

//Directivas de preprocesador


//Funciones de ISR
void isr_led(void);

//Vatiables
volatile static bool estado_led;

//Constructores
Ticker isr_accion_led(isr_led, 3000);//cada tres segundos se encedera/apagara el led del pin 13

void setup() {
  Serial.begin(19200);
  pinMode(13 /*led on board, que posee mi arduino*/, 0x1);
  digitalWrite(13 /*led on board, que posee mi arduino*/, 0x0);
  isr_accion_led.start();//Iniciando la interrupción que esperaría se repitiera cada 3 segundos
  estado_led = 0x0;
}

void loop() {

  isr_accion_led.update();

}

//Funciones ISR
void isr_led(void)
{
  estado_led = digitalRead(13 /*led on board, que posee mi arduino*/); //Leo el estado digital del pin que uso como salida
  digitalWrite(13 /*led on board, que posee mi arduino*/, !estado_led);
  Serial.println("Ha ocurrido una interrupcion");
}
