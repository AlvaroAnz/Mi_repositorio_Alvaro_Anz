
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
#define btn_rising 2
#define btn_falling 3
#define unidades_A 4
#define unidades_B 5
#define unidades_C 6
#define unidades_D 7
#define decenas_A 8
#define decenas_B 9
#define decenas_C 10
#define decenas_D 11

//Llamando funciones ISR
void funcion_ISR_rising(void);
void funcion_ISR_falling(void);

//Variables
volatile static bool b_estado = false;
volatile static int unidades = 0;
volatile static int decenas = 0;

void setup() {
  Serial.begin(19200);
  pinMode(btn_rising, INPUT);//Primer pulsador
  pinMode(btn_falling, INPUT);//Segundo pulsador
  attachInterrupt(digitalPinToInterrupt(btn_rising), funcion_ISR_rising, RISING);//se activa cuando haya una subida del estado del pulsador
  attachInterrupt(digitalPinToInterrupt(btn_falling), funcion_ISR_falling, FALLING);//se activa cuando haya una baja del estado del pulsador
  pinMode(unidades_A, OUTPUT);//Primer display
  pinMode(unidades_B, OUTPUT);
  pinMode(unidades_C, OUTPUT);
  pinMode(unidades_D, OUTPUT);//mas siginificativo
  pinMode(decenas_A, OUTPUT);//Segundo display
  pinMode(decenas_B, OUTPUT);
  pinMode(decenas_C, OUTPUT);
  pinMode(decenas_D, OUTPUT);//mas significativo
}

void loop() {

  //----- Estado del botón
  if (b_estado) {
    b_estado = false;//Bandera, indica que aumenta o disminuye la cuenta
    Serial.println(unidades);//Imprime el caracter
  }

  //----- Limites de la cuenta decimal, que es del 0 al 9 -------
  if (unidades < 0) {//Si la cuenta llega a un numero menos de 0
    unidades = 9;//Regresa a nueve
    decenas--;//aumenta un valor las decenas
  }
  if (unidades > 9) {//Si la cuenta llega a un numero mayor a nueve
    unidades = 0;//Regresa a cero
    decenas++;//disminuye un valor las decenas
  }
  if (decenas < 0) { //si la cuenta llega a un numero menos de 0
    decenas = 5;//regresa a 5
    unidades = 0;//regresa a 0, es decir 50
  }
  if (decenas == 5 && unidades > 0) { //si la cuenta llega a un numero mayor a cincuenta
    decenas = 0;//regresa a cero
    unidades = 0;// regresa a cero, es decir a 0
  }

  //----- Funciones ------
  c_unidades(unidades);
  c_decenas(decenas);
}

//Funciones ISR
void funcion_ISR_rising(void) {//si se presiona el primer pulsador
  b_estado = true;
  //aumenta el valor de la variable
  unidades++;
}

void funcion_ISR_falling(void) {//si se presiona el segundo pulsador
  b_estado = true;
  //decrementa el valor de la variable
  unidades--;
}

//Funciones aparte
void display1(int num1, int num2, int num3, int num4) { //Así se resume el encendido o apagado del integrado del primer display, es de unidades
  digitalWrite(unidades_A, num1);//Primer display
  digitalWrite(unidades_B, num2);
  digitalWrite(unidades_C, num3);
  digitalWrite(unidades_D, num4);//Numero más significativo
}
void display2( int numA, int numB, int numC, int numD) { //Así se resume el encendido o apagado del integrado del segundo display, es de decenas
  digitalWrite(decenas_A, numA);//Segundo display
  digitalWrite(decenas_B, numB);
  digitalWrite(decenas_C, numC);
  digitalWrite(decenas_D, numD);//Numero más signicativo
}


void c_unidades(int num1) {//Dependiendo de la cuenta y el numero
  switch (num1) { //cada caso o numero muestra un numero diferente en el display
    case (0): //sin unidad
      display1(0, 0, 0, 0);
      break;
    case (1)://con una unidad
      display1(1, 0, 0, 0);
      break;
    case (2):
      display1(0, 1, 0, 0);
      break;
    case (3):
      display1(1, 1, 0, 0);
      break;
    case (4):
      display1(0, 0, 1, 0);
      break;
    case (5):
      display1(1, 0, 1, 0);
      break;
    case (6):
      display1(0, 1, 1, 0);
      break;
    case (7):
      display1(1, 1, 1, 0);
      break;
    case (8):
      display1(0, 0, 0, 1);
      break;
    case (9)://con nueve unidades
      display1(1, 0, 0, 1);
      break;
  }
}

void c_decenas(int num1) {//Dependiendo de la cuenta de decimales y el numero
  switch (num1) { //cada caso o numero muestra un numero diferente en el display 2
    case (0): // sin decena
      display2(0, 0, 0, 0);
      break;
    case (1):// con un decimal
      display2(1, 0, 0, 0);
      break;
    case (2): //con dos decimales
      display2(0, 1, 0, 0);
      break;
    case (3): //con tres decimales
      display2(1, 1, 0, 0);
      break;
    case (4): //con cuatro decimales
      display2(0, 0, 1, 0);
      break;
    case (5): //con cinco decimales
      display2(1, 0, 1, 0);
      break;
  }
}
