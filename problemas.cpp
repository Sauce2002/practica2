#include "problemas.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <array>
using namespace std;

void problema2(){

    srand(time(NULL));

    char cadenaLetras[11] ={};
    char abecedario[26]={A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};
    char *punteroLetras = cadenaLetras;

    for(int i=0;i<sizeof(cadenaLetras);i++){
        int num2 =65+ rand() %(91-65);
        *(punteroLetras+i) = char(num2) ;

    }
    cadenaLetras[sizeof(cadenaLetras)-1]='\0';
    cout<<endl;
    cout << cadenaLetras <<endl;




}


