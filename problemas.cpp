#include "problemas.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void problema2(){

    srand(time(NULL));

    int num = 65+ rand() %(90-65);
    char letra = num;
    cout << letra << endl;
    cout << num << endl;
    char cadenaLetras[10] ={};
    char *punteroLetras = cadenaLetras;

    for(int i=0;i<10;i++){
        int num2 =65+ rand() %(91-65);
        *(punteroLetras+i) = char(num2) ;
        cout << num2<<" ";

    }

    cout<<endl;
    cout << cadenaLetras <<endl;




}


