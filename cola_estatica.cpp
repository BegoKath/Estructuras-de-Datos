#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void menu (int n){
	system("cls");
	cout << "SISTEMA DE COLAS DE "<<n<<" ELEMENTOS\n\n";
	cout <<"1. Crear"<<endl;
	cout <<"2. Insertar"<<endl;
	cout <<"3. Eliminar"<<endl;
	cout <<"4. Imprimir"<<endl;
	cout <<"5. Salir"<<endl;
	cout <<"\nElija una opcion => ";
}
//crear la cola de datos
int crear(int v[],int n){
	int num ,i;
	system("cls");
	cout <<"Cuantos elementos desea crear: ";
	cin >>num;
	if(num<=n){
		for(i=0;i<num;i++){
		cout << "Elemento "<<i+1<<": ";
		cin >> v[i];
	}
	return num-1;
	}else{
		cout << "No se puede crear lista de más de "<<n<< "elementos";
		return -1;
	}
}
//insertar en la cola
int insertar(int v[],int u){
	system("cls");
	cout <<"INSERTAR 1 DATO EN LA COLA\n"<<endl;
	u++;
	cout <<"Ingrese el elemento "<< u+1 <<": ";
	cin>> v[u];
	return u;
}
//eliminar un elemento de la cola
int borrar(int v[],int u){
	system("cls");
	cout <<"BORRAR 1 ELEMENTO DE LA COLA\n\n";
	for(int i=0;i<u;i++){
		v[i]=v[i+1];
	}
	cout << "El elemento 0 fue eleminado\n\n";
	u--;
	return u;
}
//imprimir la pila de elementos
void imprimir(int v[],int u){
	int i;
	system("cls");
	cout<<"COLA DE ELEMENTOS\n";
	for(i=0;i<=u;i++){
		cout <<v[i]<<endl;
	}
	cout<<endl;
}
main(){
	int n=10,v[n],op,u=-1;
	do{
		menu(n);
		cin >> op;
		switch(op){
			case 1:
			if(u==-1){
			u=crear(v,n);
			}else
			{
				cout <<"la cola fue creada , use insertar";
			}
				break;
			case 2:
			if(u<n-1)
				u=insertar(v,u);
			else
				cout <<"La cola esta llena";
				break;
			case 3:
			if(u>=0)
				u=borrar(v,u);
			else
				cout << "No existe ningun elemento en la cola";
				break;
			case 4:
			if(u>=0)
				imprimir(v,u);
			else
				cout <<"La cola esta vacia.\n";
				break;
			case 5:cout<< "\nGracias por usar el sistema...\n";
				break;
			default: cout<<"\nOpcion Incorrecta...\n";
		}
		cout <<endl;
		system("pause");
	}while(op!=5);
}
