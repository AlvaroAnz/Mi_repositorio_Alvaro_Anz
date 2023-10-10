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

#define TRIG  3//pines del sensor ultrasónico
#define ECO  2
#define A 6//pines del display 7 segmentos
#define B 7
#define C 10
#define D 9
#define E 8
#define F 5
#define G 4
#define foco 11// pin del módulo relé

#define encender(pin) digitalWrite(pin, HIGH)
#define apagar(pin) digitalWrite(pin, LOW)

int duracion;
int distancia;
int conteo = 0; //cuenta para el display


void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(foco, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // mando a llamar mis funciones
  calculo_distancia();
  estado_display();
  estado_rele(conteo);
}

//******************* Mis Funciones *********************************************

int calculo_distancia () {//Primera función: saca el cálculo para la distancia
  encender(TRIG);
  delayMicroseconds(10);
  apagar(TRIG);
  duracion = pulseIn(ECO, HIGH);
  distancia = duracion / 59; //ecuación para sacar distancia, 59 por que mi ultrasónico tiene 5 pines
  Serial.println(distancia);
  delay(600);
  return distancia;//lo saca en centímetros
}

void estado_display () { //Segunda función: dependiendo del conteo, el display sacará un número diferente
  if (distancia < 11 && distancia >4 ) { // Si la distancia es de 4-10cm, aumenta un numero el conteo
    conteo = conteo+1;
    delay(100);
  }

  switch (conteo) {

    case (0):
      {
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, LOW);
        break;
      }

    case (1):
      {
        digitalWrite(A, LOW);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, LOW);
        digitalWrite(G, LOW);
        break;
      }

    case (2):
      {
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, LOW);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, LOW);
        digitalWrite(G, HIGH);
        break;
      }

    case (3):
      {
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, LOW);
        digitalWrite(F, LOW);
        digitalWrite(G, HIGH);
        break;
      }

    case (4):
      {
        digitalWrite(A, LOW);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
      }

    case (5):
      {
        digitalWrite(A, HIGH);
        digitalWrite(B, LOW);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, LOW);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
      }

    case (6):
      {
        digitalWrite(A, HIGH);
        digitalWrite(B, LOW);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
      }

    case (7):
      {
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, LOW);
        digitalWrite(G, LOW);
        break;
      }

    case (8):
      {
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
      }

    case (9):
      {
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
      }
  }
}

void estado_rele (int num1) {//Tercera función: si el conteo llega a nueve, encenderá el módulo relé, es decir, el foco
  if (num1 >8) {
    apagar(foco);
  }
  else {
    encender(foco);
  }
  }
