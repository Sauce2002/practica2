#include "problemas.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <array>
//#include <string>
using namespace std;

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
