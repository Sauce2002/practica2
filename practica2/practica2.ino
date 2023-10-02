void setup() {
  Serial.begin(9600);

}

void loop() {
   Serial.println("Practica 2");
  int opcion;

  Serial.print("Ingrese el numeral del problema (solo pares): ");
  while (Serial.available() == 0) {
}
  
  opcion = Serial.parseInt(); 
  Serial.println(char(opcion));
  switch (opcion) {
    case 6:
      problema6();
      break;
    case 10:
      problema10();
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
      Serial.println("Opcion no valida.");
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

int valorRomano(char c) {
    switch (c) {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
        default:
            return 0;
    }
}
int convertirRomanoAArabigo(String numeroRomano) {
    int resultado = 0;
    int prevValor = 0;

    for (int i = numeroRomano.length() - 1; i >= 0; i--) {
        int valor = valorRomano(numeroRomano[i]);

        if (valor < prevValor) {
            resultado -= valor;
        } else {
            resultado += valor;
        }

        prevValor = valor;
    }

    return resultado;
}
void problema10(){
  String numeroRomano;
    Serial.println("Ingrese un numero romano: ");

    while (Serial.available() == 0) {
        // Esperar hasta que haya datos disponibles en el puerto serie
    }
    numeroRomano = Serial.readStringUntil('\n'); // Leer el número ingresado desde el puerto serie

    int numeroArabigo = convertirRomanoAArabigo(numeroRomano);

    Serial.print("El numero ingresado fue: ");
    Serial.println(numeroRomano);
    Serial.print("Que corresponde a: ");
    Serial.println(numeroArabigo);
}
