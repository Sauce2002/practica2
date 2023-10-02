void setup() {
  Serial.begin(9600);

}

void loop() {
   Serial.println("Practica 2");
  int opcion;

  Serial.print("Ingrese el numeral del problema (solo pares): ");
  while (Serial.available() == 0) {
}
  Serial.println(opcion);
  Serial.println(char(opcion));
  switch (opcion) {
    case 6:
      problema6();
      break;
    case 8:
      // problema8();
      break;
    case 10:
      // problema10();
      break;
    case 12:
      // problema12();
      break;
    case 14:
      // problema14();
      break;
    case 16:
      // problema16();
      break;
    default:
      Serial.println("Opción no válida.");
      break;
  }

}

void problema6(){
  String cadena;
  Serial.print("Ingrese una cadena de caracteres:");
  
  while (Serial.available() == 0) {
  }
  
  cadena = Serial.readStringUntil('\n');
  Serial.println(cadena);
  Serial.print("Original: ");
  Serial.println(cadena);
  
  for (int i = 0; i < cadena.length(); ++i) {
        if (islower(cadena[i])) {
            cadena[i] = toupper(cadena[i]);
        }
    } 
  Serial.print("En mayuscula: ");
  Serial.println(cadena);
}
