#include "problemas.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <array>
using namespace std;

void problema2(){

    srand(time(NULL));
    char cadenaLetras[10] ={};
    char *punteroLetras = cadenaLetras;

    for(int i=0;i<sizeof(cadenaLetras);i++){
        int num2 =65+ rand() %(91-65);
        *(punteroLetras+i) = char(num2) ;
        cout << num2<<" ";
    }

    cout<<endl;
    cout << cadenaLetras <<endl;


}

