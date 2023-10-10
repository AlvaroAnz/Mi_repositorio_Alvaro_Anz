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
  char nombre[10];
  float precioU;
  int stock;
  char reserva[20];
  float precioL;
};

//Ya defino cada variable por cada producto 
producto Gomitas ={"Gomitas", 2.50, 7, "Disponible", Gomitas.precioU*Gomitas.stock};
producto Snacks ={"Snacks", 4.50, 12, "No disponible", Snacks.precioU*Snacks.stock};
producto Gaseosa ={"Gaseosa", 6.00, 9, "Disponible", Gaseosa.precioU*Gaseosa.stock};
producto Chocolate ={"Chocolate", 5.75, 16, "No disponible", Chocolate.precioU*Chocolate.stock};

//Defino alguno pines, entradas y lecturas

#define Entrada(pin) pinMode(pin, INPUT_PULLUP)
#define CBI(pin) digitalRead(pin)
int menu   = 0;
int Botton1 = 2;
int Botton2 = 3;

void setup() 
{
  // put your setup code here, to run once:
  Entrada(Botton1);
  Entrada(Botton2); 
  Serial.begin(9600);
  Serial.println("Maquina expendedora, siguientes productos: ");
}

void loop() 
{
  
  //defino que si presiono el primer pulsador, cambia al siguiente producto
  if(CBI(Botton1)== LOW)
  {
    menu++;
    if(menu >=4)
    {
      menu = 0;
    }
    while(!CBI(Botton1));
  }

  //defino que si presiono el segundo pulsador, cambia al anterior producto
  if(CBI(Botton2)== LOW)
  {
    menu--;
    if(menu < 0)
    {
      menu = 3;
      }
   
    while(!CBI(Botton2));
  }

  int interfaz = menu;
  //voy diseñando mi menu por medio de la variable "menu"
  switch(interfaz)
  {
    case(0):Serial.println("============================");
    Serial.println(Gomitas.nombre);
            Serial.print("Precio unitario: Q");
            Serial.println(Gomitas.precioU);
            Serial.print("Unidades: ");
            Serial.println(Gomitas.stock);
            Serial.print("En reserva: ");
            Serial.println(Gomitas.reserva);
            Serial.print("Precio lote: ");
            Serial.println(Gomitas.precioL);
            break;
    case(1):Serial.println("============================");
    Serial.println(Snacks.nombre);
            Serial.print("Precio unitario: Q");
            Serial.println(Snacks.precioU);
            Serial.print("Unidades: ");
            Serial.println(Snacks.stock);
            Serial.print("En reserva: ");
            Serial.println(Snacks.reserva);
            Serial.print("Precio lote: ");
            Serial.println(Snacks.precioL);
            break;
    case(2):Serial.println("============================");
    Serial.println(Gaseosa.nombre);
            Serial.print("Precio unitario: Q");
            Serial.println(Gaseosa.precioU);
            Serial.print("Unidades: ");
            Serial.println(Gaseosa.stock);
            Serial.print("En reserva: ");
            Serial.println(Gaseosa.reserva);
            Serial.print("Precio lote: ");
            Serial.println(Gaseosa.precioL);
            break;
    case(3):Serial.println("============================");
    Serial.println(Chocolate.nombre);
            Serial.print("Precio unitario: Q");
            Serial.println(Chocolate.precioU);
            Serial.print("Unidades: ");
            Serial.println(Chocolate.stock);
            Serial.print("En reserva: ");
            Serial.println(Chocolate.reserva);
            Serial.print("Precio lote: ");
            Serial.println(Chocolate.precioL);
            break;
  }
  while(CBI(Botton1) && CBI(Botton2));

}
