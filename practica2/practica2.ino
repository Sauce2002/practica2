void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

}

void problema6(){
  String cadena;
  Serial.println("Ingrese una cadena de caracteres:");
  
  while (Serial.available() == 0) {
    // Esperar hasta que haya datos disponibles en el puerto serie
  }
  
  // Leer la línea de texto desde el puerto serie
  cadena = Serial.readStringUntil('\n');
  
  Serial.print("Original: ");
  Serial.println(cadena);
  
  // Recorrer la cadena y convertir las letras minúsculas a mayúsculas
  for (int i = 0; i < cadena.length(); ++i) {
    if (isLowerCase(cadena.charAt(i))) {
      cadena.setCharAt(i, toUpperCase(cadena.charAt(i)));
    }
  }
  
  Serial.print("En mayúscula: ");
  Serial.println(cadena);
}
