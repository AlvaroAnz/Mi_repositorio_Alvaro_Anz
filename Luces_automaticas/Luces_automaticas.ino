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
  
#define salida(pin) pinMode(pin, OUTPUT)
#define tiempo 50
int posicion;

void setup()
{
  salida(2);
  salida(3);
  salida(4);
  salida(5);
  salida(6);
  salida(7);
  salida(8);
  salida(9);
  salida(10);
  salida(11);
  
}

void loop()
{
  //ciclo para el inicio
  for(posicion=2; posicion<=11; posicion++)
  {
    
    digitalWrite(posicion, HIGH);
    delay(tiempo);
    digitalWrite(posicion, LOW);
  }
  //ciclo para el regreso
  for(posicion=10; posicion>=3; posicion--)
  {
    
    digitalWrite(posicion, HIGH);
    delay(tiempo);
    digitalWrite(posicion, LOW);
  }
}
