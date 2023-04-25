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

#define TRIG 7 //nombramos algunos pines
#define ECO 8
#define Buzzer 3
#define encender(pin) digitalWrite(pin, HIGH)
#define apagar(pin) digitalWrite(pin, LOW)


int duracion; //definimos algunas variables importantes

int nota_do = 261;//definimos las frecuencias que serían las notas musicales
int nota_re = 294;
int nota_mi = 329;
int nota_fa = 349;
int nota_sol = 392;
int nota_la = 440;
float nota_si = 494.883;
float nota_doS = 523.163;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(Buzzer, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  calculo_distancia(duracion);
  melodia();

}

//******************************Mis funciones***********************************************

//******Primera función: saca el cálculo para la distancia
int calculo_distancia (int num1) {

  int distancia;//defino la variable en que guardo el resultado

  encender(TRIG);//envía el disparon el pin Trigger
  delayMicroseconds(10);
  apagar(TRIG);
  num1 = pulseIn(ECO, HIGH);//recibe la señal el pin ECO
  distancia = num1 / 58.7; //ecuación para sacar distancia, 59 por que mi ultrasónico tiene 5 pines
  Serial.println(distancia);
  delay(100);

  return distancia;//lo saca en centímetros
}

//******Segunda función, solo configura el buzzer
void nota_sonido(int num1) {
  tone(Buzzer, num1);
}

//******Tercera función, llama la primera función para comparar distancias, luego llama la segunda para tocar la nota deseada
void melodia (void) {

  int nota = calculo_distancia(duracion);//llamo la función de distancia y la guardo en la variable local

  if (nota > 0 && nota < 5) {
    nota_sonido(nota_do);
  }
  else if (nota >=5  && nota <= 8) {
    nota_sonido(nota_re);
  }
  else if (nota >= 9 && nota <= 12) {
    nota_sonido(nota_mi);
  }
  else if (nota >= 13 && nota <= 16) {
    nota_sonido(nota_fa);
  }
  else if (nota >= 17  && nota <=20) {
    nota_sonido(nota_sol);
  }
  else if (nota >= 21 && nota <= 24) {
    nota_sonido(nota_la );
  }
  else if (nota >= 25 && nota <= 28) {
    nota_sonido(nota_si);
  }
  else if (nota >= 29 && nota <= 32) {
    nota_sonido(nota_doS);
  }
  else {
    noTone(Buzzer);//silencia el buzzer si no coincidde la nota
  }
}
