#include <iostream>
#include "problemas.h"
using namespace std;

int main()
{
    cout << "practica 2" << endl;

    int opcion;

    cout << "ingrese el numeral del problema (solo pares): "<<endl;
    cin>>opcion;
    switch (opcion) {
    case 2:
        problema2();
        break;
    case 4:
        problema4();
        break;
    case 6:
        problema6();
        break;
    case 8:
        problema8();
        break;
    case 10:
        problema10();
        break;
    case 12:
        problema12();
        break;
    case 14:
        problema14();
        break;
    case 16:
        problema16();
        break;
    case 18:
        problema18();
        break;
    default:
        break;
    }
    return 0;
}
