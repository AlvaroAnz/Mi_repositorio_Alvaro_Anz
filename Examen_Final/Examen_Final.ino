/*
  Fundación Kinal
  Centro Educativo Técnico Laboral Kinal
  Electrónica
  Grado: Quinto
  Sección: A
  Curso: Taller de Electrónica Digital y Reparación de Computadoras I
  Nombres: Álvaro Anzueto Rodas
  Carnés: 2019373
  Proyecto: Multímetro
*/

//Directivas de preprocesador
#define s_corriente A0
#define s_voltaje A1
#define s_ohmios A2
#define entrada(pin) pinMode(pin, INPUT)
#define salida(pin) pinMode(pin, OUTPUT)
#define R2 10000//Resistencia fija
#define Vcc 5//Fuente 


//Variables
float lec_corriente, lec_voltaje, lec_resist;
float sensorValue, sensibilidad=;
float Vout, dato, down, R1, dato2;
char infoB;
void calculo_V(), calculo_R(), calculo_A();


void setup() {
  // Configuración inicial
  Serial.begin(9600);
  salida(5);
  salida(4);
  salida(3);
  entrada(s_corriente);
  entrada(s_voltaje);
  entrada(s_ohmios);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void loop() {



  // Hará lecturas seriales
  if (Serial.available() > 0) { //Si el dato contiene información
    infoB = Serial.read(); //Se guardará el carácter que mandará la app
    //Serial.println(infoB);    //Y lo imprimirá

    if (infoB == 'A') { //Resistencia
      calculo_R();

    }

    if (infoB == 'B') { //Corriente
      calculo_A();
    }

    if (infoB == 'C') { //Voltaje
      calculo_V();
    }
  }
}



//*****************Funciones*************************************+++

void calculo_V() {
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  sensorValue = analogRead(A0);               // Realizar la lectura
  lec_voltaje = map(sensorValue, 0, 1023, 0.0, 25.0);  // Escalar a 0.0 - 25.0
  Serial.println(lec_voltaje, 2);
  if (Serial.available() > 0) { //Si el dato contiene información
    infoB = Serial.read();
  }
}

void calculo_R() {
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  dato = analogRead(s_ohmios);//Se guarda el dato en una variable
  if (dato) { //Si hay un dato
    dato2 = dato * Vcc;
    Vout = (dato2 / 1024.0);
    dato2 = (Vcc / Vout) - 1;
    R1 = dato2 * R2;
    lec_resist = (R1 / 19.0);
    Serial.println(lec_resist.);
    if (Serial.available() > 0)
    { //Si el dato contiene información
      infoB = Serial.read();
    }
  }

}

void calculo_A(){
  
}
