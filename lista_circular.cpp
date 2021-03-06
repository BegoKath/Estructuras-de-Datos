#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//estructura de dato
struct NODO{
	int dato;
	NODO *sig;
};
//funciones
void menu();
NODO *crear(NODO *c);
void imprimir(NODO *c);
NODO *insertar_inicio(NODO *c);
void insertar_final(NODO *c);
void insertar_intermedio(NODO *c);
NODO *eliminar_inicio(NODO *c);
void eliminar_final(NODO *c);
void eliminar_intermedio(NODO *c);
NODO *destruir(NODO *c);
main(){
	int op;
	NODO *c;
	c= NULL;
	do{
		menu();
		cin >> op;
		switch(op){
			case 1:c=crear(c);
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
			case 6:c=eliminar_inicio(c);
				break;
			case 7:eliminar_final(c);
				break;
			case 8:eliminar_intermedio(c);
				break;
			case 9:c= destruir(c);
				break;
		}
	}while(op!=10);
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
	cout << "\t6.Eliminar inicio\n";
	cout << "\t7.Eliminar final\n";
	cout << "\t8.Eliminar intermedio\n";
	cout << "\t9.Destruir\n";
	cout << "\t10.Salir\n\n";
	cout << "Elija una opcion ==> ";
}
//Crear lista de datos
NODO *crear(NODO *c){
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
		//Enlazar el elemento
		if(c==NULL){
			c=nuevo;
			ultimo=nuevo;
		}else{
			ultimo->sig= nuevo;
			ultimo= nuevo;
		}
		nuevo->sig=c;//hace circular
	}
	return c;
}
//imprimir lista de datos
void imprimir(NODO *c){
	NODO *aux;
	aux=c;
	cout << "\tLista de Datos\n"<<"     --------------------\n";
	if(c!=NULL){
		do{
			cout<< aux->dato<<endl;
			aux= aux->sig;
		}while(aux!=c);
	}else{
		cout<<"La lista esta vacia...\n";
	}
}
//insertar inicio de la cabecera
NODO *insertar_inicio(NODO *c){
	NODO *nuevo,*aux;
	system("cls");
	cout << "\tInsertar al inicio\n"<<"     ------------------------\n";
	nuevo= new NODO;
	cout << "Ingrese un numero: ";
	cin>> nuevo->dato;
	nuevo->sig= NULL;
	//Enlazar
	aux=c;
	while(aux->sig!=c)
		aux=aux->sig;
	aux->sig=nuevo;
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
	while(aux->sig!=c)
		aux=aux->sig;
	nuevo->sig=c;
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
	while(aux->dato!=num && aux->sig!=c)
		aux=aux->sig;
	nuevo->sig= aux->sig;
	aux->sig= nuevo;
}
//eliminar el inicio
NODO *eliminar_inicio(NODO *c){
	NODO *aux,*ult;
 	system("cls");
	cout << "Inicio\n\tElemento eliminado\n"<<"     -----------------------\n";
	ult=c;
	c=c->sig;
 	delete ult;
	system("pause");
	return c;
}
//eliminar el final
void eliminar_final(NODO *c){
	NODO *aux,*pe;
	system("cls");
	aux=c;
	while(aux->sig!=c){
		pe=aux;
		aux=aux->sig;
	}
	if(aux!= c){
		pe->sig=c;
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
	while(aux->sig!=c && aux->dato!=num){
		ant=aux;
		aux=aux->sig;
	}
	if(aux==c){
		if(c->dato!=num){
			cout << "No existe ese dato.\n";
		}else{
			cout << "ERROR->Para borrar este elemento debe usar eliminar inicio\n";
		}
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

