#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int primo(int M){
    int N, aux = 0;
    float nf, mf, car=0;
    bool primo = false;
    N = M;
    mf = M;
    while(primo == false){
        nf = N;
        for(int i=1; i<=N; i++){
            if(N%i == 0)
                aux++;
        }
        car = mf/nf;
        if(aux == 2 && car <=1 )
            primo = true;
        else
            N++;
        aux = 0;
    }
    return N;
}
int Dispersion1(char clave[20], int tClave, int N){
    int valor = 0,r;
    valor = clave[0];
    for (int i = 1; i<tClave; i++)
    valor += clave[i];
	return valor%N;
}
int nDatosArchivo(char* nombre){
	FILE *archivo;
	char aux[30];
	int  n=0;

		archivo=fopen(nombre,"r");
		while(!feof(archivo))//O(n)
		{
		fgets(aux,30,archivo);
		n++;
		}
	return n;
}
