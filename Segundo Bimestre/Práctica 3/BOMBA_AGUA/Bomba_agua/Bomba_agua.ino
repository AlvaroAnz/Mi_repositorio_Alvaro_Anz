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

#define limite 2 //Es el colector  del transistor
#define rele_bomba 3 //El relé acciona la bomba
#define led_azul 5 //indica que esta vacío
#define led_rojo 4 //indica que esta lleno
#define entrada(pin) pinMode(pin, INPUT)
#define salida(pin) pinMode(pin, OUTPUT)
#define lectura(pin) digitalRead(pin)
#define encender(pin) digitalWrite(pin, HIGH) 
#define apagar(pin) digitalWrite(pin, LOW)




void setup() {
  // defino la entrada y salidas
  entrada(limite);
  salida(rele_bomba);
  salida(led_azul);
  salida(led_rojo);

}

void loop() {
  // constantemente va a sacar una lectura del sensor limite
  

  if (lectura(limite) ==  HIGH) { // si el sensor no recibe señal
    encender(rele_bomba);
    encender(led_azul);
    apagar(led_rojo);
  }

  if (lectura(limite) ==  LOW) { // si el sensor recibe señal (el transistor pasa a corte y saturación)
    apagar(rele_bomba);
    apagar(led_azul);
    encender(led_rojo);
  }

}
