#include "problemas.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <array>
//#include <string>
using namespace std;
int valorRomano(char c);
int convertirRomanoAArabigo(string numeroRomano);
bool esCuadradoMagico(int** matriz, int n);
void imprimirMatriz(int** matriz,int n);
void llenarMatriz(int** matriz,int n);
void rotarMatriz(int** matriz, int n);
void calcularCaminos(int fila,int columna,int n,int *total);
string enesimaPermutacion(int* digitos,int n);
int Factorial(int n);

void problema2(){

    srand(time(NULL));

    char cadenaLetras[201] ={};
    char abc[26]={'A','B','C','D','E','F','G','H','I',
                  'J','K','L','M','N','O','P','Q','R',
                  'S','T','U','V','W','X','Y','Z'};
    char *punteroLetras = cadenaLetras;
    char *pAbc=abc;

    for(int i=0;i<sizeof(cadenaLetras);i++){
        int num2 =65+ rand() %(91-65);
        *(punteroLetras+i) = char(num2) ;

    }
    cadenaLetras[sizeof(cadenaLetras)-1]='\0';
    cout<<endl;
    cout << cadenaLetras <<endl;

    for(int i=0;i < sizeof(abc)-1;i++){
        int contador=0;
        for(int j=0;j < sizeof(cadenaLetras)-1;j++){
            if(*(punteroLetras+j)==*(pAbc+i))contador+=1;
        }
        if(contador>0)cout<<*(pAbc+i)<<": "<<contador<<endl;

    }

}
int stringToInt(const string& str) {
    int result = 0;
    bool isNegative = false;
    int i = 0;


    if (str[0] == '-') {
        isNegative = true;
        i = 1;
    }
    for (; i < str.length(); ++i) {
        if (isdigit(str[i])) {
            result = result * 10 + (str[i] - '0');
        } else {
            throw invalid_argument("La cadena contiene caracteres no numericos.");
        }
    }
    if (isNegative) {
        result = -result;
    }

    return result;
}

void problema4(){
    string input;
    cout << "Ingresa una cadena de caracteres numericos: ";
            cin >> input;
    try {
        int numero = stringToInt(input);
        cout << "El numero entero es: " << numero << endl;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

}

void problema6(){
    string cadena;
    cout << "Ingrese una cadena de caracteres: ";
    cin>>cadena;
    cout << "Original: " << cadena << endl;
    for (int i = 0; i < cadena.length(); ++i) {
        if (islower(cadena[i])) {
            cadena[i] = toupper(cadena[i]);
        }
    }



    cout << "En mayuscula: " << cadena << endl;

}

void problema8(){
    string cadena;
    cout << "Ingrese una cadena de caracteres: ";
    cin >> cadena;

    string texto = "";
    string numero = "";

    for (int i = 0; i < cadena.length(); ++i) {
        if (isdigit(cadena[i])) {
            numero += cadena[i];
        } else {
            texto += cadena[i];
        }
    }

    cout << "Original: " << cadena << endl;
    cout << "Texto: " << texto << endl;
    cout << "Numero: " << numero << endl;
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

int convertirRomanoAArabigo(string numeroRomano) {
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
    string numeroRomano;
    cout << "Ingrese un número romano: ";
            cin >> numeroRomano;

    int numeroArabigo = convertirRomanoAArabigo(numeroRomano);

    cout << "El número ingresado fue: " << numeroRomano << endl;
            cout << "Que corresponde a: " << numeroArabigo << endl;

}

void problema12(){

    int n;
    cout << "Ingrese el tamaño de la matriz cuadrada: ";
    cin >> n;
        int **pMatriz;
        pMatriz = new int* [n];
        for (int i = 0; i <n; i++) {
            pMatriz[i] = new int[n];
        }
        cout << "Ingrese los elementos de la matriz:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
            cin >> *(*(pMatriz+j)+i);
            }
        }
        imprimirMatriz(pMatriz,n);
        if (esCuadradoMagico(pMatriz, n)) {
            cout << "La matriz es un cuadrado magico." << endl;
        } else {
            cout << "La matriz no es un cuadrado magico." << endl;
        }
        for (int i = 0; i < n; i++) {
            delete[] pMatriz[i];
        }
        delete[] pMatriz;
        pMatriz = nullptr;
}

bool esCuadradoMagico(int** matriz, int n) {
    int sumaDiagonal1 = 0;
    int sumaDiagonal2 = 0;

    for (int i = 0; i < n; ++i) {
        sumaDiagonal1 += *(*(matriz+i)+i);
    }

    for (int i = 0; i < n; ++i) {
        //sumaDiagonal2 += matriz[i][n - 1 - i];
        sumaDiagonal2 += *(*(matriz+(n-1-i))+i);
    }

    if (sumaDiagonal1 != sumaDiagonal2) {
        return false;
    }

    for (int i = 0; i < n; ++i) {
        int sumaFila = 0;
        int sumaColumna = 0;
        for (int j = 0; j < n; ++j) {
            //sumaFila += matriz[i][j];
            sumaFila +=*(*(matriz+j)+i);
            //sumaColumna += matriz[j][i];
            sumaColumna += *(*(matriz+i)+j);
        }

        if (sumaFila != sumaDiagonal1 || sumaColumna != sumaDiagonal1) {
            return false;
        }
    }

    return true;
}

void imprimirMatriz(int** matriz,int n){
    for(int x=0;x<n;x++){
        for(int z=0; z<n;z++){
            cout << *(*(matriz+z)+x)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void problema14(){
    int n =5;
    int **pMatriz;
    pMatriz = new int* [n];
    for (int i = 0; i <n; i++) {
        pMatriz[i] = new int[n];
    }
    llenarMatriz(pMatriz,n);

    cout << "Matriz original:" << endl;
    imprimirMatriz(pMatriz,n);

    cout << "Matriz rotada 90 grados:" << endl;
    rotarMatriz(pMatriz,n);
    imprimirMatriz(pMatriz,n);

    cout << "Matriz rotada 180 grados:" << endl;
    rotarMatriz(pMatriz,n);
    imprimirMatriz(pMatriz,n);

    cout << "Matriz rotada 270 grados:" << endl;
    rotarMatriz(pMatriz,n);
    imprimirMatriz(pMatriz,n);

    for (int i = 0; i < n; i++) {
        delete[] pMatriz[i];
    }
    delete[] pMatriz;
    pMatriz = nullptr;

}

void llenarMatriz(int** matriz,int n) {
    int valor = 1;

    for (int fila = 0; fila < n; ++fila) {
        for (int columna = 0; columna < n; ++columna) {
//            matriz[fila][columna]= valor++;
            *(*(matriz+columna)+fila) = valor++;
        }
    }
}

void rotarMatriz(int** matriz, int n) {
    int temp[n][n];

    for (int fila = 0; fila < n; ++fila) {
        for (int columna = 0; columna < n; ++columna) {
            //temp[fila][columna] = matriz[columna][n - 1 - fila];
            temp[fila][columna] =*(*(matriz+columna)+(n-1-fila));
        }
    }
    for (int fila = 0; fila < n; ++fila) {
        for (int columna = 0; columna < n; ++columna) {
            *(*(matriz+columna)+fila) = *(*(temp+columna)+fila);
        }
    }
}

void calcularCaminos(int fila,int columna,int n,int *total) {
    if(columna+1<n)calcularCaminos(fila,columna+1,n,total);
    if(fila+1<n)calcularCaminos(fila+1,columna,n,total);
    if(fila == columna && fila == n-1) *total = *total+1;
}

void problema16(){
    int n;
    int total=0;
    cout<<"ingrese el tamanio de la malla nxn: "<<endl;
    cin>>n;
    calcularCaminos(0,0,n+1,&total);
    cout<<"el total de caminos es: "<<total<<endl;
}

int Factorial(int n) {
    int resultado = 1;
    for (int i = 1; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

string enesimaPermutacion(int* digitos,int n) {

    string permutacion;
    --n;

    for (int i = 9; i >= 0; --i) {
        int permutacionesTotales = Factorial(i);
        int indice = n / permutacionesTotales;
        permutacion += to_string(digitos[indice]);

        for (int j = indice; j < 9; ++j) {
            digitos[j] = digitos[j + 1];
        }
        n %= permutacionesTotales;
    }

    return permutacion;
}

void problema18(){
    int digitos[10]={0,1,2,3,4,5,6,7,8,9};
    int *pDigitos = digitos;
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;
    if (n < 1)cout<<"valor incorrecto, debe ser mayor que 1"<<endl;
    else {
        string permutacion = enesimaPermutacion(pDigitos,n);
        cout << "La permutación numero " << n << " es: " << permutacion << endl;
    }

}
