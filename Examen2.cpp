//Examen Segundo Parcial
//Autor: Mishell Cárdenas
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using namespace std;

struct NODO {
	char cedula[30];
	char nombre[30];
	char terceraEDAD[30];
	int prioridad;
	NODO *sig,*ant;
};

struct COLA {
	int longitud;
	NODO *c,*u;
};

//funciones
void menu();
NODO *cargarDatos(NODO *c,NODO *u,COLA m,char nombre[]);
NODO *encolar(NODO *c, NODO *u,NODO*aux);
NODO *prioridad(NODO *c);
NODO *desencolar(NODO *c);
void imprimir(NODO *c);
bool vacia(NODO *c);
//principal
main(){
	int op,sw=1;
	char nombre[]="datos.txt";
	COLA m;
	m.c=NULL;
	m.u=NULL;
	m.longitud=0;
	do{
		menu();
		cin>>op;
		system("cls");
		switch (op){
			case 1:
				if(sw==1){
					m.c=cargarDatos(m.c,m.u,m,nombre);
					imprimir(m.c);
					cout <<"\nEXITO--> Los datos han sido cargados";
					sw=0;
				}else{
					cout <<"El archivo de datos ya ha sido cargado\n";
				}
				break;
			case 2:
				if (vacia(m.c)==false) {
					cout<<"\n\tDesencolar Dato\n";
					cout <<"\tCedula\t\tNombre\t\t\tTercera Edad\n";
					cout<<"\t"<<m.c->cedula<<"\t"<<m.c->nombre<<"\t\t"<<m.c->terceraEDAD<<endl;
					m.c=desencolar(m.c);
					m.longitud--;
					cout<<"\n\tHa sido eliminado\n\t";
				}else{
						cout<<"\n\tCargue datos con la opcion 1\n\t";
				}
				break;
			case 3:
			if (vacia(m.c)==false) {
					cout<<"\n\tDesencolar Datos";
					cout<<"\t\tCOLA DE DATOS\t\n";
					imprimir(m.c);
					do{
						m.c=desencolar(m.c);
						m.longitud--;
					}while(m.c!=NULL);
					cout<<"\n\tLa cola ha sido eliminada\n\t";
			}else{
				cout<<"\n\tCargue datos con la opcion 1\n\t";
			}
			break;
			case 4:cout<<"Gracias por usar el programa"<<endl;
				break;
			default:
				cout<<"Opcion incorrecta...\n";
		}
		cout << "\n";
		system("pause");
	}while(op!=4);
}
void menu(){
	system("cls");
	cout <<"\n\t\t\tExamen 2do Parcial\n";
	cout <<"\n\t\t\tESTRUCTURAS DE DATOS\n";
	cout <<"\t\tAPLICACION DE COLAS DE PRIORIDAD\n";
	cout <<"1. Cargar Datos"<<endl;
	cout <<"2. Desencolar 1 Dato"<<endl;
	cout <<"3. Desencolar todos los Datos"<<endl;
	cout <<"4. Salir"<<endl;
	cout <<"\nElija una opcion => ";
}
NODO *cargarDatos(NODO *c,NODO *u,COLA m,char nombre[]){
	NODO *aux;
	FILE *archivo;
	archivo= fopen(nombre,"r");
	while(!feof(archivo)){
		aux= new NODO;
		fgets(aux->nombre,30,archivo);
        fgets(aux->terceraEDAD,30,archivo);
		fgets(aux->cedula,30,archivo);
        strtok(aux->cedula,"\n");
        strtok(aux->nombre,"\n");
        strtok(aux->terceraEDAD,"\n");
		aux->sig= NULL;
		aux->ant=NULL;
		//cout<<"\t    "<<aux->cedula<<"\t "<<aux->nombre<<"\t  "<<aux->terceraEDAD<<endl;
		if(strcmp(aux->terceraEDAD,"SI")==0){
			//cout << aux->terceraEDAD;
			aux->prioridad=1;
		}else{
			aux->prioridad=0;
			//cout << aux->terceraEDAD;
		}
		u=encolar(c,u,aux);
		m.longitud++;
		if(m.longitud==1)
			c=u;
		prioridad(c);
		
	}
	fclose(archivo);
	return c;
}
NODO *encolar(NODO *c, NODO *u,NODO*aux){
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
}
NODO *prioridad(NODO *c){
	NODO *aux,*aux1;
	int paux;
	char ce[30],no[30],te[30];
	aux=c;
	while(aux->sig!=NULL){
		aux1=aux->sig;
		while(aux1!=NULL){
			if(aux->prioridad < aux1->prioridad){
				paux= aux->prioridad;
				strcpy(ce,aux->cedula);
				strcpy(no,aux->nombre);
				strcpy(te,aux->terceraEDAD);
				aux->prioridad=aux1->prioridad;
				strcpy(aux->cedula,aux1->cedula);
				strcpy(aux->nombre,aux1->nombre);
				strcpy(aux->terceraEDAD,aux1->terceraEDAD);
				aux1->prioridad=paux;
				strcpy(aux1->cedula,ce);
				strcpy(aux1->nombre,no);
				strcpy(aux1->terceraEDAD,te);
			}
			aux1= aux1->sig;
			}
			aux=aux->sig;
		}
}
bool vacia(NODO *c){
	NODO *aux;
	aux=c;
	if(c==NULL){
		return true;
	}else{
		return false;
	}
}
NODO *desencolar(NODO *c){
	NODO *aux;
	//cout<<"\n\tDesencolar Dato";
	if(vacia(c)){
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
	}
	return c;
	system("pause");
}
void imprimir(NODO *c){
	NODO *aux;
		cout <<"\tCedula\t\tNombre\t\t\tTercera Edad\n";
		aux=c;
		while(aux!=NULL){
			cout<<"\t"<<aux->cedula<<"\t"<<aux->nombre<<"\t\t"<<aux->terceraEDAD<<endl;
			aux=aux->sig;
		}
	cout<<"\n\t";
}


























