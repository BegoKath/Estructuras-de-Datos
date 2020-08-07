#include <iostream>
#include <stdio.h>
#include<string.h>
using namespace std;
struct NODO{
	char elemento[40];
	NODO *sig;
};
int primo(int M);
void menu();
NODO *cargar_datos(NODO *c[100],int n,int m);
int Dispersion1(char clave[20], int tClave, int N);
NODO *apilar(NODO *u,NODO *nuevo);
void imprimir(NODO *c[100], int num);
void buscar(NODO *c[100],int num);
main(){
	int n,m,op;
	bool carga=true;
	cout<<"Cuantos elementos deseas ingresar: ";
	cin >> m;
	n= primo (m);
	cout <<" N=  "<<n <<endl;
	NODO *c[n];
	for(int i=0; i<n; i++)
            c[i] = NULL;
	system("pause");
	do{
		system("cls");
		menu();
		cin >>op;
		system("cls");
		switch(op){
			case 1:
			if(carga){
				cargar_datos(c,n,m);
				carga=false;
				}else{
					cout<< "el vector ya se a cargado";
				}
				break;
			case 2: buscar(c,n);
				break;
			case 3: imprimir(c,n);
				break;
   			case 4:cout<< "\nGracias por usar el sistema...\n";
				break;
			default: cout<<"\nOpcion Incorrecta...\n";
			break;
		}
		system("pause");
	}while(op!=4);
}
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
void menu(){
	cout << "\nAplicacion de Pilas en HASH\n\n";
	cout << "\tMENU:\n";
	cout << "1. Cargar datos."<<endl;
	cout << "2. Buscar dato."<<endl;
	cout << "3. Imprimir datos."<<endl;
	cout << "4. Salir"<<endl;
	cout <<"\nElija una opcion =>  ";
}
NODO *cargar_datos(NODO *c[100],int n,int m){
	NODO *nuevo,*u;
    int posicion=0, tc;
    for(int i=0; i<m; i++){
        nuevo = new NODO;
        cout << "Ingrese el elemento "<<i+1<<" :";
        cin >> nuevo->elemento;
        nuevo->sig = NULL;
        tc = strlen(nuevo->elemento);
        posicion = Dispersion1(nuevo->elemento, tc,n);
        if(c[posicion] == NULL){
			u=c[posicion];
			c[posicion]= apilar(u, nuevo);
            cout <<"===> EXITO, indice -> "<<posicion<<"\n";
        } else if(c[posicion] != NULL && c[posicion]->elemento != nuevo->elemento){
        	u=c[posicion];
            c[posicion] = apilar(u,nuevo);
            cout<<"===> COLISION, indice ->"<<posicion<<"\n";
        }else if(c[posicion]== nuevo){
				cout<< "Error el elemento ya existe--> Vuelva a ingresar\n";
				i--;
		}
    }
}
NODO *apilar(NODO *u,NODO *nuevo){
	if(u==NULL){
		u= nuevo;
	}else{
		nuevo->sig=u;
		u=nuevo;
	}
	return u;
}
void imprimir(NODO *c[100], int num){
    printf("\n");
    NODO *aux[num];
    for(int i=0; i<num; i++){
    	aux[i]=c[i];
        cout << "Posicion  "<<i<<": ";
        while(aux[i] != NULL){
            cout << aux[i]->elemento <<" ";
            aux[i] = aux[i]->sig;
        }
        cout <<"\n";
    }
}
void buscar(NODO *c[100],int num){
	char palabra[20];
	NODO *aux;
	int posicion=0,tc,i=0,pos;
	cout << "Que palabra desea buscar: ";
	cin >> palabra;
	posicion=Dispersion1(palabra,strlen(palabra),num);
	//bool encontrado= false
	aux=c[posicion];
	if(aux==NULL){
		cout << "\t No se encontro la palabra\n";
	}else{
		while(aux!= NULL){
			if(strcmp(aux->elemento,palabra)==0){
					cout << "Se encontro la palabra en " << posicion<<endl;
					break;
			}
			aux=aux->sig;
		}
}
}

