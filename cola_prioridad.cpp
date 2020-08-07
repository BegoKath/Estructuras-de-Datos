#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct NODO {
	int dato;
	int prioridad;
	NODO *sig,*ant;
};

struct COLA {
	int longitud;
	NODO *c,*u;
};
void menu(int n);
NODO *crear(NODO *c);
NODO *prioridad(NODO *c);
void imprimir (NODO *c);
void imprimir_inverso(NODO *u);
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
					prioridad(m.c);
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
						cout <<"\n\tLa Cola tiene datos\n";
				break;
			case 6: imprimir(m.c);
				break;
			case 7:imprimir_inverso(m.u);
				break;
			case 8: longitud(m);
				break;
			case 9:cout<<"Gracias por usar el programa"<<endl;
				break;
			default:
				cout<<"Opcion incorrecta...\n";
		}
		cout << "\n";
		system("pause");
	}while(op!=9);
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
	cout <<"7. Imprimir inverso"<<endl;
	cout <<"8. Longitud"<<endl;
	cout <<"9. Salir"<<endl;
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
void imprimir_inverso(NODO *u){
	NODO *aux;
	aux=u;
	system("cls");
	cout << "\tCOLA DE DATOS\n"<<"     --------------------\n";
	cout <<"\tPrioridad\tDato\n";
	while(aux != NULL){
		cout<<"\t    "<<aux->prioridad<<"\t         "<<aux->dato<<endl;
		aux= aux->ant;
	}
}
void imprimir (NODO *c){
	NODO *aux;
		system("cls");
		cout<<"\tCOLA DE DATOS\t\n";
		cout <<"\tPrioridad\tDato\n";
		aux=c;
		while(aux!=NULL){
			cout<<"\t    "<<aux->prioridad<<"\t         "<<aux->dato<<endl;
			aux=aux->sig;
	}
	cout<<"\n\t";
}

NODO *encolar(NODO *c, NODO *u){
	NODO *aux,*aux1;
	bool sw=true;
	system("cls");
	cout<<"\t\tEncolar Dato";
	aux = new NODO;
	cout<<"\n\tIngrese dato: ";
	cin>>aux->dato;
	cout <<"Prioridad: ";
	cin>> aux->prioridad;
	aux->sig=NULL;
	aux->ant=NULL;
	if(c==NULL){
		c=aux;
		u=aux;
	}
	else{
			u->sig=aux;
			aux->ant=u;
			u=aux;
	}
 	return u;
	system("pause");
}
NODO *prioridad(NODO *c){
	NODO *aux,*aux1;
	int paux;
	int caux;
	aux=c;
	while(aux->sig!=NULL){
		aux1=aux->sig;
		while(aux1!=NULL){
			if(aux->prioridad > aux1->prioridad){
				paux=aux->prioridad;
				caux=aux->dato;
				aux->prioridad=aux1->prioridad;
				aux->dato=aux1->dato;
				aux1->prioridad= paux;
				aux1->dato=caux;
			}
			aux1= aux1->sig;
			}
			aux=aux->sig;
		}
}

NODO *desencolar(NODO *c){
	NODO *aux;
	system("cls");
	cout<<"\n\tDesencolar Dato";
	if(c==NULL){
		cout<<"\n\tLa Cola esta vacia\n\t";
	}else{
		aux=c;
		if(c->sig==NULL){
			c=NULL;
			cout << "\n\t La cola esta vacia";
		}else{
		 c=c->sig;
		 c->ant=NULL;
		}
		delete (aux);
		cout<<"\n\tHa sido eliminado\n\t";
	}
	return c;
	system("pause");
}

int frente(COLA cola){
	system("cls");
	cout<<"\tFrente\n\t";
	cout<<"El frente de la Cola es => "<<cola.c->dato<<"\n";
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
	cout<<"\tLa longitud de la Cola es => "<<cola.longitud<<"\n";
}
