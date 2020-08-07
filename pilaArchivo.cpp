//Autor: Mishell Cardenas
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct NODO{
	int dato;
	int longitud=0;
	NODO *sig;
};
int nDatosArchivo(char* nombre);
void menu (int n);
NODO *crear(NODO *c);
NODO *apilar(NODO *c);
NODO *desapilar(NODO *c);
int cima(NODO *c);
bool vacia(NODO *c);
void imprimir(NODO *c);
int longitud(NODO *c);
NODO *procesarArchivo(NODO *c);
main(){
	NODO *c=NULL;
	int n,op,u=-1;
	n=nDatosArchivo("pila.dat");
	do{
		menu(n);
		cin >> op;
		system("cls");
		switch(op){
			case 1:c=procesarArchivo(c);
				break;
			case 2: imprimir(c);
				break;
   			case 3:cout<< "\nGracias por usar el sistema...\n";
				break;
			default: cout<<"\nOpcion Incorrecta...\n";
		}
		cout <<endl;
		system("pause");
	}while(op!=3);
}
int nDatosArchivo(char* nombre){
	FILE *archivo;
	int aux, n=0;

		archivo=fopen(nombre,"r");
		while(!feof(archivo))//O(n)
		{
		fscanf(archivo,"%d",&aux);
		n++;
		}
	return n;
}
void menu (int n){
	system("cls");
	cout << "APLICACION DE PILAS DE "<<n<<" DATOS\n\n";
	cout <<"1. Procesar Archivo"<<endl;
	cout <<"2. Imprimir pila"<<endl;
	cout <<"3. Salir"<<endl;
	cout <<"\nElija una opcion => ";
}
NODO *crear(NODO *c){
	NODO *aux;
	if(c!=NULL){
		while(c!= NULL){
		aux=c;
		c=c->sig;
		delete aux;
		}
		//cout <<" Pila destruida\n";
	}
	c=NULL;
	//cout << "Pila vacia creada";
	return c;
}
NODO *apilar(NODO *c,NODO *nuevo){
	//cout << "\tAPILAR DATOS\n"<<"     ------------------------\n";
	if(c==NULL){
		nuevo->longitud=1;
		c= nuevo;
	}else{
		nuevo->sig=c;
		nuevo->longitud = c->longitud + 1;
		c=nuevo;
	}
	return c;
}
NODO *desapilar(NODO *c){
	NODO *aux;
	if(c==NULL){
		//cout<< "La pila es vacia";
	}else{
		aux=c;
		c=c->sig;
		delete(aux);
		//cout << "DESAPILAR\n\tElemento eliminado\n"<<"     -----------------------\n";
	}
	return c;
}
int cima(NODO *c){
	int cima=c->dato;
	return cima;
}
bool vacia(NODO *c){
	bool vacia=false;
	if(c==NULL){
		vacia=true;
	}
	return vacia;
}
void imprimir(NODO *c){
	NODO *aux;
	aux=c;
	cout << "\tPILA\n"<<"     --------------------\n";
	cout << "De longitud => "<< longitud (c)<<endl;
	while(aux != NULL){
		cout<< aux->dato<<endl;
		aux= aux->sig;
	}
}
int longitud(NODO *c){
	int l = c->longitud;
	return l;
}
NODO *procesarArchivo(NODO *c){
	NODO *nuevo;
	int ci;
	crear(c);
	FILE *archivo;
	int i=0;
	archivo=fopen("pila.dat","r");
	while(!feof(archivo))
	{
		nuevo= new NODO;
	   	fscanf(archivo,"%d",&nuevo->dato);
		nuevo->sig=NULL;
		if(vacia(c)){
			c=apilar(c,nuevo);
		}else{
			ci=cima(c);
			if(nuevo->dato>=ci){
				c=apilar(c,nuevo);
			}else{
				delete(nuevo);
				c=desapilar(c);
			}
		}
	}
	cout <<"EL ARCHIVO HA SIDO PROCESADO \n";
	
	fclose(archivo);
	return c;
}
