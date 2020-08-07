#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//estructura de dato
struct NODO{
	int dato;
	NODO *sig,*ant;
};
//funciones
void menu();
NODO *crear(NODO *c,NODO **u);
void imprimir(NODO *c);
void imprimir_inverso(NODO *u);
NODO *insertar_inicio(NODO *c);
void insertar_final(NODO *c);
void insertar_intermedio(NODO *c);
NODO *eliminar_inicio(NODO *c);
void eliminar_final(NODO *c);
void eliminar_intermedio(NODO *c);
NODO *destruir(NODO *c);
main(){
	int op;
	NODO *c,*u;
	c= NULL,u=NULL;
	do{
		menu();
		cin >> op;
		switch(op){
			case 1:c=crear(c,&u);
				break;
			case 2:c= insertar_inicio(c);
				break;
			case 3:insertar_final(c);
				break;
			case 4:insertar_intermedio(c);
				break;
  			case 5:
			  system("cls");
			  imprimir(c);
			  system("pause");
				break;
   			case 6:
			  system("cls");
			  imprimir_inverso(u);
			  system("pause");
				break;
			case 7:c=eliminar_inicio(c);
				break;
			case 8:eliminar_final(c);
				break;
			case 9:eliminar_intermedio(c);
				break;
			case 10:c= destruir(c);
				break;
			default:
				system("pause");
				break;
		}
	}while(op!=11);
}
//menu de opciones
void menu(){
	system("cls");
	cout << "\t\tMENU:\n";
	cout << "**********************************************\n";
	cout << "\t1.Crear lista\n";
	cout << "\t2.Insertar inicio\n";
	cout << "\t3.Insertar final\n";
	cout << "\t4.Insertar intermedio\n";
	cout << "\t5.Recorrer - Imprimir\n";
	cout << "\t6.Recorrer - Imprimir-Inverso\n";
	cout << "\t7.Eliminar inicio\n";
	cout << "\t8.Eliminar final\n";
	cout << "\t9.Eliminar intermedio\n";
	cout << "\t10.Destruir\n";
	cout << "\t11.Salir\n\n";
	cout << "Elija una opcion ==> ";
}
//Crear lista de datos
NODO *crear(NODO *c,NODO **u){
	NODO *nuevo,*ultimo;
	int n,i;
	system("cls");
	cout << "\t\tCrear lista de datos\n"<<"\t     --------------------------\n";
	cout << "Ingrese numero de elementos: ";
	cin >> n;
	cout << endl;
	for(i=1;i<=n;i++){
		//Crear nuevo espacio
		nuevo= new NODO;
		cout << "Ingrese un numero: ";
		cin>> nuevo->dato;
		nuevo->sig=NULL;
		nuevo->ant=NULL;
		//Enlazar el elemento
		if(c==NULL){
			c=nuevo;
			ultimo=nuevo;
		}else{
			ultimo->sig= nuevo;
			nuevo->ant= ultimo;
			ultimo= nuevo;
		}
	}
	*u=ultimo;//devolver por referencia
	return c;
}
//imprimir lista de datos
void imprimir(NODO *c){
	NODO *aux;
	aux=c;
	cout << "\tLista de Datos\n"<<"     --------------------\n";
	while(aux != NULL){
		cout<< aux->dato<<endl;
		aux= aux->sig;
	}
}
void imprimir_inverso(NODO *u){
	NODO *aux;
	aux=u;
	cout << "\tLista de Datos\n"<<"     --------------------\n";
	while(aux != NULL){
		cout<< aux->dato<<endl;
		aux= aux->ant;
	}
}
//insertar inicio de la cabecera
NODO *insertar_inicio(NODO *c){
	NODO *nuevo;
	system("cls");
	cout << "\tInsertar al inicio\n"<<"     ------------------------\n";
	nuevo= new NODO;
	cout << "Ingrese un numero: ";
	cin>> nuevo->dato;
	nuevo->sig= NULL;
	//Enlazar
	nuevo->sig=c;
	c=nuevo;
	return c;
}
//insertar al final
void insertar_final(NODO *c){
	NODO *nuevo,*aux;
	system("cls");
	cout << "\tInsertar al final \n"<<"     -----------------------\n";
	nuevo= new NODO;
	cout << "Ingrese un numero: ";
	cin>> nuevo->dato;
	nuevo->sig= NULL;
	//enlazar
	aux=c;
	while(aux->sig!=NULL)
		aux=aux->sig;
	aux->sig=nuevo;
}
//insertar intermedio
void insertar_intermedio(NODO *c){
	NODO *nuevo, *aux;
	int num;
	system("cls");
	cout << "\tInsertar al Intermedio \n"<<"     -----------------------\n";
	nuevo= new NODO;
	cout << "Ingrese el numero nuevo: ";
	cin>> nuevo->dato;
	nuevo->sig= NULL;
	//buscar la posicion
	imprimir(c);
	cout <<"Despues de que elemento se insertara: ";
	cin >>num;
	aux=c;
	while(aux->dato!=num && aux->sig!=NULL)
		aux=aux->sig;
	nuevo->sig= aux->sig;
	aux->sig= nuevo;
}
//eliminar el inicio
NODO *eliminar_inicio(NODO *c){
	NODO *aux;
 	system("cls");
	cout << "Inicio\n\tElemento eliminado\n"<<"     -----------------------\n";
	aux=c;
	c=c->sig;
	delete(aux);
	system("pause");
	return c;
}
//eliminar el final
void eliminar_final(NODO *c){
	NODO *aux,*pe;
	system("cls");
	aux=c;
	while(aux->sig!=NULL){
		pe=aux;
		aux=aux->sig;
	}
	if(aux!= c){
		pe->sig=NULL;
		delete(aux);
		cout << "Final\n\tElemento eliminado\n"<<"     -----------------------\n";
	}else{
		cout << "ERROR->Para borrar este elemento debe usar eliminar inicio\n";
	}
	system("pause");
}
//eliminar intermedio
void eliminar_intermedio(NODO *c){
	NODO *aux,*ant;
	int num;
	system("cls");
	cout << "Que numero desea eliminar: ";
	cin >> num;
	aux=c;
	while(aux!=NULL && aux->dato!=num){
		ant=aux;
		aux=aux->sig;
	}
	if(aux==NULL){
		cout << "No existe ese dato.\n";
	}else if(aux==c){
		cout << "ERROR->Para borrar este elemento debe usar eliminar inicio\n";
	}else{
		ant->sig=aux->sig;
		delete aux;
		cout << "Intermedio\n\tElemento eliminado\n"<<"     -----------------------\n";
	}
	system("pause");
}
//destruir
NODO *destruir(NODO *c){
	NODO *aux;
	system("cls");
	while(c!= NULL){
		aux=c;
		c=c->sig;
		delete aux;
	}
	cout << "la lista fue eliminada";
	system("pause");
	return c;
}

