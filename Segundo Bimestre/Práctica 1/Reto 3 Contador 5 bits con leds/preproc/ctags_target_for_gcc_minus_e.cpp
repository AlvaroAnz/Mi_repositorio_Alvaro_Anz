# 1 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\binarios\\Reto 3 Contador 5 bits con leds\\Contador_5_bits_leds\\Contador_5_bits_leds.ino"
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
# 12 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\binarios\\Reto 3 Contador 5 bits con leds\\Contador_5_bits_leds\\Contador_5_bits_leds.ino"
//Les definí un nuevo nombre para diferenciar los leds






void setup() {
  pinMode(2/*es el lsb*/, 0x1);//Definí todos los pines como salidas
  pinMode(3, 0x1);
  pinMode(4, 0x1);
  pinMode(5, 0x1);
  pinMode(6, 0x1);

}

void loop() {
  //recuerda, es un contador binario, comenzando con el lsb
  //0
  digitalWrite(2/*es el lsb*/, 0x0);//1
  digitalWrite(3, 0x0);//2
  digitalWrite(4, 0x0);//4
  digitalWrite(5, 0x0);//8
  digitalWrite(6, 0x0);//16
  delay(750);//se pausa por 0.75 segundos :v

  //1
  digitalWrite(2/*es el lsb*/, 0x1);
  digitalWrite(3, 0x0);
  digitalWrite(4, 0x0);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x0);
  delay(750);

  //2
  digitalWrite(2/*es el lsb*/, 0x0);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x0);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x0);
  delay(750);

  //3
  digitalWrite(2/*es el lsb*/, 0x1);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x0);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x0);
  delay(750);

  //4
  digitalWrite(2/*es el lsb*/, 0x0);
  digitalWrite(3, 0x0);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x0);
  delay(750);

  //5
  digitalWrite(2/*es el lsb*/, 0x1);
  digitalWrite(3, 0x0);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x0);
  delay(750);

  //6
  digitalWrite(2/*es el lsb*/, 0x0);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x0);
  delay(750);

  //7
  digitalWrite(2/*es el lsb*/, 0x1);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x0);
  delay(750);

  //8
  digitalWrite(2/*es el lsb*/, 0x0);
  digitalWrite(3, 0x0);
  digitalWrite(4, 0x0);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x0);
  delay(750);

  //9
  digitalWrite(2/*es el lsb*/, 0x1);
  digitalWrite(3, 0x0);
  digitalWrite(4, 0x0);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x0);
  delay(750);

  //10
  digitalWrite(2/*es el lsb*/, 0x0);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x0);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x0);
  delay(750);

  //11
  digitalWrite(2/*es el lsb*/, 0x1);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x0);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x0);
  delay(750);

  //12
  digitalWrite(2/*es el lsb*/, 0x0);
  digitalWrite(3, 0x0);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x0);
  delay(750);

  //13
  digitalWrite(2/*es el lsb*/, 0x1);
  digitalWrite(3, 0x0);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x0);
  delay(750);

  //14
  digitalWrite(2/*es el lsb*/, 0x0);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x0);
  delay(750);

  //15
  digitalWrite(2/*es el lsb*/, 0x1);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x0);
  delay(750);

  //16
  digitalWrite(2/*es el lsb*/, 0x0);
  digitalWrite(3, 0x0);
  digitalWrite(4, 0x0);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x1);
  delay(750);

  //17
  digitalWrite(2/*es el lsb*/, 0x1);
  digitalWrite(3, 0x0);
  digitalWrite(4, 0x0);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x1);
  delay(750);

  //18
  digitalWrite(2/*es el lsb*/, 0x0);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x0);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x1);
  delay(750);

  //19
  digitalWrite(2/*es el lsb*/, 0x1);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x0);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x1);
  delay(750);

  //20
  digitalWrite(2/*es el lsb*/, 0x0);
  digitalWrite(3, 0x0);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x1);
  delay(750);

  //21
  digitalWrite(2/*es el lsb*/, 0x1);
  digitalWrite(3, 0x0);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x1);
  delay(750);

  //22
  digitalWrite(2/*es el lsb*/, 0x0);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x1);
  delay(750);

  //23
  digitalWrite(2/*es el lsb*/, 0x1);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x1);
  delay(750);

  //24
  digitalWrite(2/*es el lsb*/, 0x0);
  digitalWrite(3, 0x0);
  digitalWrite(4, 0x0);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x1);
  delay(750);

  //25
  digitalWrite(2/*es el lsb*/, 0x1);
  digitalWrite(3, 0x0);
  digitalWrite(4, 0x0);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x1);
  delay(750);

  //26
  digitalWrite(2/*es el lsb*/, 0x0);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x0);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x1);
  delay(750);

  //27
  digitalWrite(2/*es el lsb*/, 0x1);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x0);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x1);
  delay(750);

  //28
  digitalWrite(2/*es el lsb*/, 0x0);
  digitalWrite(3, 0x0);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x1);
  delay(750);

  //29
  digitalWrite(2/*es el lsb*/, 0x1);
  digitalWrite(3, 0x0);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x1);
  delay(750);

  //30
  digitalWrite(2/*es el lsb*/, 0x0);//1
  digitalWrite(3, 0x1);//2
  digitalWrite(4, 0x1);//4
  digitalWrite(5, 0x1);//8
  digitalWrite(6, 0x1);//16
  delay(750);

}
