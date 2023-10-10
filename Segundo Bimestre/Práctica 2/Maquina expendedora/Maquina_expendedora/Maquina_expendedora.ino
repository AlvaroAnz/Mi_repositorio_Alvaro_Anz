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
//defino un grupo de variables especificas para los productos
struct producto {
  float precioU;
  word stock;
  String nombre;
  String reserva;
  float precioL;
};

//Ya defino cada variable por cada producto 
producto Gomitas ={0.50, 5, "Gomitas", "Disponible", Gomitas.precioU*Gomitas.stock};
producto Snacks ={4.25, 9, "Snacks", "No disponible", Snacks.precioU*Snacks.stock};
producto Gaseosa ={6.00, 7, "Gaseosa", "Disponible", Gaseosa.precioU*Gaseosa.stock};
producto Chocolate ={5.25, 6, "Chocolate", "No disponible", Chocolate.precioU*Chocolate.stock};

//Defino alguno pines, entradas y lecturas
#define Subir 2
#define Bajar 3
#define Entrada(pin) pinMode(pin, INPUT_PULLUP)
#define CBI(pin) digitalRead(pin)

int menu = 0;
bool menuMostrado = false; // Variable de estado
void setup() {  
  Entrada(Subir);
  Entrada(Bajar);
  Serial.begin(10000);
 }
void loop() {
  //si presionamos el pulsador, aumentamos un estado
  if (CBI(Subir) == LOW) {
    menu++;
    if (menu >3) {
      menu = 0;//si se pasa de tres, hace un reinicio a cero
    }
    menuMostrado = false; // Reiniciar la variable de estado al cambiar de opción
    delay(50);
  }

  if (CBI(Bajar) == LOW) {
    menu--;
    if (menu < 0) {
      menu = 3;
    }
    menuMostrado = false;  // Reiniciar la variable de estado al cambiar de opción
    delay(50);
  }

  // Mostrar el menú solo si no se ha mostrado ya en esta iteración
  ;
  if (!menuMostrado) {
    Serial.println("Bienvenido, producto seleccionado:");
    if (menu == 0) {
      Serial.println(Gomitas.nombre);
      Serial.print("Precio: Q");
      Serial.println(Gomitas.precioU);
      Serial.print("Stock: ");
      Serial.println(Gomitas.stock);
      Serial.print("Disponibilidad: ");
      Serial.println(Gomitas.reserva);
      Serial.println(Gomitas.precioL);
    } else if (menu == 1) {
      Serial.println(Snacks.nombre);
      Serial.print("Precio: Q");
      Serial.println(Snacks.precioU);
      Serial.print("Stock: ");
      Serial.println(Snacks.stock);
      Serial.print("Disponibilidad: ");
      Serial.println(Snacks.reserva);
      Serial.println(Snacks.precioL);
    } else if (menu == 2) {
      Serial.println(Gaseosa.nombre);
      Serial.print("Precio: Q");
      Serial.println(Gaseosa.precioU);
      Serial.print("Stock: ");
      Serial.println(Gaseosa.stock);
      Serial.print("Disponibilidad: ");
      Serial.println(Gaseosa.reserva);
      Serial.println(Gaseosa.precioL);
    } else if (menu == 3) {
      Serial.println(Chocolate.nombre);
      Serial.print("Precio: Q");
      Serial.println(Chocolate.precioU);
      Serial.print("Stock: ");
      Serial.println(Chocolate.stock);
      Serial.print("Disponibilidad: ");
      Serial.println(Chocolate.reserva);
      Serial.println(Chocolate.precioL);
    }
    menuMostrado = true; // Marcar el menú como mostrado para no repetirlo en esta iteracción
  }

  // Esperar a que se suelte el botón para evitar que el menú se muestre varias veces seguidas
  while (CBI(Subir) == LOW || CBI(Bajar) == LOW) {
    delay(100);
  }
}
