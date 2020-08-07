#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
using namespace std;

struct NODO {
	int dato;
	NODO *sig;
};

struct COLA {
	int longitud;
	NODO *c,*u;
};
void menu(int n);
NODO *crear(NODO *c);
void imprimir (NODO *c);
NODO *encolar(NODO *c, NODO *u);
NODO *desencolar(NODO *c);
int frente(COLA cola);
bool vacia(NODO *c);
int longitud (COLA cola);
main(){
	int n=100,op,ult=-1,i, valor;
	COLA m;
	m.c=NULL;
	m.u=NULL;
	m.longitud=0;
	do{
		menu(n);
		cin>>op;
		switch (op){
			case 1:	m.c=crear(m.c);
			m.longitud=0;
				break;
			case 2: m.u=encolar(m.c,m.u);	
					m.longitud++;	
						if(m.longitud==1)
							m.c=m.u;
				break;
			case 3: if (m.c!=NULL) {
						m.c=desencolar(m.c);
						m.longitud--;
					}else{
						cout<<"\n\tCree la Cola con la opcion 1\n\t";
					}
				break;
			case 4: if (m.c!=NULL)
						frente(m);
					else 
						cout<<"\n\tNo hay ninguna Cola";
				break;
			case 5: if(vacia(m.c))
						cout <<"\n\tLa Cola esta vacia\n";
					else
						cout <<"\n\tLa Cola no esta vacia\n";
				break;
			case 6: imprimir(m.c);
				break;
			case 7: longitud(m);
				break;
			case 8:cout<<"Gracias por usar el programa"<<endl;
				break;
			default:
				cout<<"Opcion incorrecta...\n";
		}
		cout << "\n";
		system("pause");
	}while(op!=8);
}
void menu(int n){
	system("cls");
	cout << "SISTEMA DE COLAS DE "<<n<<" ELEMENTOS\n\n";
	cout <<"1. Crear"<<endl;
	cout <<"2. Encolar"<<endl;
	cout <<"3. Desencolar"<<endl;
	cout <<"4. Frente"<<endl;
	cout <<"5. Vacia"<<endl;
	cout <<"6. Imprimir"<<endl;
	cout <<"7. Longitud"<<endl;
	cout <<"8. Salir"<<endl;
	cout <<"\nElija una opcion => ";
}

NODO *crear(NODO *c){
	system("cls");
	if(c!=NULL){
		c=NULL;
		cout<<"\n\t Se destruyo la cola\n Cola vacia creada";
	}else{
		c=NULL;
		cout<<"\n\t Cola vacia creada";
	}
	return c;
}

void imprimir (NODO *c){
	NODO *aux;
		system("cls");
		cout<<"\tCOLA DE DATOS";
		aux=c;
		while(aux!=NULL){
			cout<<"\n\t"<<aux->dato;
			aux=aux->sig;
	}
	cout<<"\n\t";
}

NODO *encolar(NODO *c, NODO *u){
	NODO *aux;
	system("cls");
	cout<<"\t\tEncolar Dato";
	aux = new NODO;
	cout<<"\n\tIngrese dato: ";
	cin>>aux->dato;
	aux->sig=NULL;
	if(c==NULL)
		u=aux;
	else
		u->sig=aux;
		u=aux;

	return u;
	system("pause");
}

NODO *desencolar(NODO *c){
	NODO *aux;
	system("cls");
	cout<<"\n\tDesencolar Dato";
	if(c==NULL){
		cout<<"\n\tLa Cola esta vacia\n\t";
	}else{
		aux=c;
		c=c->sig;
		delete (aux);
		cout<<"\n\tHa sido eliminado\n\t";
	}
	return c;
	system("pause");
}

int frente(COLA cola){
	system("cls");
	cout<<"\tFrente\n\t";
	cout<<"El frente de la Cola es: "<<cola.c->dato<<"\n";
}

bool vacia(NODO *c){
	NODO *aux;
	system("cls");
	cout<<"\tVaciar";
	aux=c;
	if(c==NULL){
		return true;
	}else{
		return false;
	}
}

int longitud (COLA cola){
	system("cls");
	cout<<"\tLongitud\n";
	cout<<"\tLa longitud de la Cola es: "<<cola.longitud<<"\n";
}
