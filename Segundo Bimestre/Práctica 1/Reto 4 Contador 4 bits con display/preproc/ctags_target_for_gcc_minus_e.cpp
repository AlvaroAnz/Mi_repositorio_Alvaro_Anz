# 1 "C:\\Users\\Familia Anzueto\\Documents\\Arduino\\Archivos binarios\\Reto 4 Contador 4 bits con display\\Contador_4_bits_diplay\\Contador_4_bits_diplay.ino"
/*Fundación Kinal

 * Centro Educativo Técnico Laboral Kinal

 * Electrónica

 * Grado: Quinto

 * Sección: A

 * Nombre: Álvaro Anzueto Rodas

 * Carne: 2019373

 */


void setup() {
  // defino los pines como salidas
  pinMode(2 /*Les cambié el nombre de los pines como si fueran los pines de un display, para relacionarlos*/, 0x1);
  pinMode(3, 0x1);
  pinMode(4, 0x1);
  pinMode(5, 0x1);
  pinMode(6, 0x1);
  pinMode(7, 0x1);
  pinMode(8, 0x1);

}

void loop() {
  // Como si fuera un bcd, voy enciendendo cada pin para formar el número que quiero

  //0
  digitalWrite(2 /*Les cambié el nombre de los pines como si fueran los pines de un display, para relacionarlos*/, 0x1);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x1);
  digitalWrite(7, 0x1);
  digitalWrite(8, 0x0);
  delay(500);//cambia de número cada medio segundo

  //1
  digitalWrite(2 /*Les cambié el nombre de los pines como si fueran los pines de un display, para relacionarlos*/, 0x0);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x0);
  digitalWrite(7, 0x0);
  digitalWrite(8, 0x0);
  delay(500);

  //2
  digitalWrite(2 /*Les cambié el nombre de los pines como si fueran los pines de un display, para relacionarlos*/, 0x1);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x0);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x1);
  digitalWrite(7, 0x0);
  digitalWrite(8, 0x1);
  delay(500);

  //3
  digitalWrite(2 /*Les cambié el nombre de los pines como si fueran los pines de un display, para relacionarlos*/, 0x1);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x0);
  digitalWrite(7, 0x0);
  digitalWrite(8, 0x1);
  delay(500);

  //4
  digitalWrite(2 /*Les cambié el nombre de los pines como si fueran los pines de un display, para relacionarlos*/, 0x0);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x0);
  digitalWrite(7, 0x1);
  digitalWrite(8, 0x1);
  delay(500);

  //5
  digitalWrite(2 /*Les cambié el nombre de los pines como si fueran los pines de un display, para relacionarlos*/, 0x1);
  digitalWrite(3, 0x0);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x0);
  digitalWrite(7, 0x1);
  digitalWrite(8, 0x1);
  delay(500);

  //6
  digitalWrite(2 /*Les cambié el nombre de los pines como si fueran los pines de un display, para relacionarlos*/, 0x1);
  digitalWrite(3, 0x0);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x1);
  digitalWrite(7, 0x1);
  digitalWrite(8, 0x1);
  delay(500);

  //7
  digitalWrite(2 /*Les cambié el nombre de los pines como si fueran los pines de un display, para relacionarlos*/, 0x1);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x0);
  digitalWrite(6, 0x0);
  digitalWrite(7, 0x0);
  digitalWrite(8, 0x0);
  delay(500);

  //8
  digitalWrite(2 /*Les cambié el nombre de los pines como si fueran los pines de un display, para relacionarlos*/, 0x1);
  digitalWrite(3, 0x1);
  digitalWrite(4, 0x1);
  digitalWrite(5, 0x1);
  digitalWrite(6, 0x1);
  digitalWrite(7, 0x1);
  digitalWrite(8, 0x1);
  delay(500);
}
