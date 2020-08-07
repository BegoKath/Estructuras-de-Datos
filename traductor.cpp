#include <iostream>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include "dispercion1.h"
#include<locale.h>
#include <windows.h>
#include <conio.h>

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

using namespace std;

struct DATO
{
		char palabra[30];
		char significado[30];
		DATO *sig;
};

//gotoxy
int gotoxy(USHORT x,USHORT y) {
   COORD cp = {x,y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}
//funciones
void entrada();
DATO *cargar_datos(DATO *ve[],int n,char nombre[]);
void imprimir(DATO *ve[], int n);
void buscar_palabra(DATO *ve[], int n );
int ingresar_palabra(DATO *ve[],int m,int n,char nombre[]);
DATO *apilar(DATO *u,DATO *nuevo);
bool palabraColision(DATO *ve,char buscar[]);
void insertar_Archivo(char nombre[],DATO *ve);
int menu1(const char *titulo, const char *opciones[], int n,int m,int num);
//////////////////////////
main(){
	//para configurar la salida de  acentos
 	setlocale(LC_ALL,"spanish");
 	SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows
    //
	int op,m,n,sw=0;
	FILE *archivo;
	char nombre[]="palabras2.dat";//nombre del archivo
	m=nDatosArchivo(nombre);
	m/=2;
	n= primo(m);
	DATO *ve[n];
	for(int i=0;i<n;i++)
		ve[i]=NULL;
	entrada();
	gotoxy(45,30);system("pause");
	do{
		
  		const char *titulo="TRADUCTOR   ESPAÑOL-PORTUGUES";
		const char *opciones[]={"Cargar datos.","Agregar una nueva palabra.","Buscar una traduccion.","Imprimir datos.","Salir"};
		op=menu1(titulo,opciones,5,m,n);
		system("cls");
		
		switch(op){
			case 1:if(sw==0){
				cargar_datos(ve,n,nombre);
				sw=1;
			}else{
				gotoxy(45,15);cout<< "ERROR => el archivo ya se ha cargado";
			}
			gotoxy(45,30);system("pause");
				break;
			case 2:
			if(sw==1){
				m=ingresar_palabra(ve,m,n,nombre);
			}else{
				gotoxy(45,15);cout<< "ERROR => Cargue el archivo";
			}
			gotoxy(45,30);system("pause");
				break;
			case 3:
			if(sw==1){
				buscar_palabra(ve,n);
			}else{
				gotoxy(45,15);cout<< "ERROR => Cargue el archivo";
			}
			gotoxy(45,30);system("pause");
				break;
			case 4:
			if(sw==1){
				imprimir(ve,n);
			}else{
				gotoxy(45,15);cout<< "ERROR => Cargue el archivo";
			}
			cout <<"\n";
			system("pause");
				break;
			case 5:
				entrada();
				gotoxy(45,25);cout<< "GRACIAS POR USAR EL SISTEMA...";
				gotoxy(45,30);system("pause");
			break;
		}
		
		system("cls");
	}while(op!=5);
}
void entrada(){
		system("color 0B");
		gotoxy(41,7);cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		gotoxy(41,8);cout<<"|  UNIVERSIDAD DE LAS FUERZAS ARMADAS  |";
		gotoxy(41,9);cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		gotoxy(41,11);cout<<"          ESTRUCTURAS DE DATOS";
		gotoxy(21,12);cout<<"INTEGRANTES";
		gotoxy(21,13);cout <<"--> Kevin Armas";
		gotoxy(21,14);cout <<"--> Mishell Cardenas";
		gotoxy(81,13);cout<< "Fecha: 24/07/2020";
		gotoxy(58,18);cout<<"TRADUCTOR";
		gotoxy(54,19);cout<<"Español-Portugues";
		for(int i =1;i<=100;i++){
			gotoxy(10+i,5);cout<<"=";
			gotoxy(10+i,22);cout<<"=";
		}
  		for(int i =1;i<=16;i++){
			gotoxy(11,5+i);cout<<"|";
			gotoxy(110,5+i);cout<<"|";
		}
}
int menu1(const char *titulo, const char *opciones[], int n,int m,int num){
   int opcionSeleccionada = 1;
   int tecla;
   bool repite = true;

   do {
      system("cls");
      system("color 0D");

      gotoxy(45, 11 + opcionSeleccionada); cout << "==>";
      // Imprime el título
      gotoxy(45, 8); cout << titulo;
      // Imprime las opciones
      for (int i = 0; i < n; i++) {
         gotoxy(50, 12+ i); cout << i + 1 << ") " << opciones[i];
      }
      	for(int i =1;i<=100;i++){
			gotoxy(10+i,5);cout<<"=";
			gotoxy(10+i,22);cout<<"=";
		}
  		for(int i =1;i<=16;i++){
			gotoxy(11,5+i);cout<<"|";
			gotoxy(110,5+i);cout<<"|";
		}
		gotoxy(5,30);cout <<"Archivo de "<<m<<" palabras. Número primo : "<<num;
      do {
         tecla = getch();
      } while (tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);
      switch (tecla) {
         case TECLA_ARRIBA:
            opcionSeleccionada--;
            if (opcionSeleccionada < 1) {
               opcionSeleccionada = n;
            }
            break;
         case TECLA_ABAJO:
            opcionSeleccionada++;

            if (opcionSeleccionada > n) {
               opcionSeleccionada = 1;
            }
            break;

         case ENTER:
            repite = false;
            break;
      }
   } while (repite);
   return opcionSeleccionada;
}
DATO *apilar(DATO *u,DATO *nuevo){
	if(u==NULL){
		u= nuevo;
	}else{
		nuevo->sig=u;
		u=nuevo;
	}
	return u;
}
//carga datos del archivo
DATO *cargar_datos(DATO *ve[],int n,char nombre[]){
	DATO *nuevo,*u;
	int dispercion,intentos=0, posicion,tc;
	bool insertado= false;
	FILE *archivo;
	archivo=fopen(nombre,"r");
	while(!feof(archivo)){
		nuevo= new DATO;
        fgets(nuevo->palabra,30,archivo);
        fgets(nuevo->significado,30,archivo);
        strtok(nuevo->palabra, "\n");
        strtok(nuevo->significado, "\n");
		nuevo->sig=NULL;
		tc = strlen(nuevo->palabra);
		posicion= Dispersion1(nuevo->palabra,tc,n);
		if(ve[posicion] == NULL){
			u=ve[posicion];
			ve[posicion]= apilar(u, nuevo);
	        //cout <<"===> EXITO, indice -> "<<posicion<<"\n";
	    } else if(ve[posicion] != NULL && ve[posicion]->palabra != nuevo->palabra){
	    	u=ve[posicion];
	        ve[posicion] = apilar(u,nuevo);
	        //cout<<"===> COLISION, indice ->"<<posicion<<"\n";
	    }
	}
	gotoxy(48,15);cout<<"Archivo Cargado Correctamente";
	fclose(archivo);
}
void imprimir(DATO *ve[], int n){
	setlocale(LC_CTYPE,"ptb");
    DATO *aux[n];
    int u=0;
	gotoxy(54,2);cout<<"PALABRAS";

	gotoxy(11,4);cout<<"|";
	gotoxy(21,4);cout<<"Posición";
	gotoxy(43,4);cout<<"|";
	gotoxy(56,4);cout<<"Español";
	gotoxy(76,4);cout<<"|";
	gotoxy(88,4);cout<<"Portugues";
	gotoxy(109,4);cout<<"|";
	for(int i =1;i<100;i++){
		gotoxy(10+i,3);cout<<"~";
			gotoxy(10+i,5);cout<<"~";
	}
	u=6;
    for(int i=0; i<n; i++){
    	aux[i]=ve[i];
        gotoxy(15,i+u);cout << "   Posicion  "<<i;
        while(aux[i] != NULL){
			gotoxy(53,u+i);cout<<aux[i]->palabra;
			gotoxy(90,u+i);cout<<aux[i]->significado;
            aux[i] = aux[i]->sig;
            gotoxy(11,u+i);cout<<"|";
        	gotoxy(109,u+i);cout<<"|";
        	gotoxy(43,u+i);cout<<"|";
        	gotoxy(76,u+i);cout<<"|";
            u++;
        }
        if(aux[i]==NULL){
        	gotoxy(11,u+i);cout<<"|";
        	gotoxy(109,u+i);cout<<"|";
        	gotoxy(43,u+i);cout<<"|";
        	gotoxy(76,u+i);cout<<"|";
        	for(int j =1;j<100;j++){
			gotoxy(10+j,u+i+1);cout<<"~";
		}
		u++;
		}
        //cout <<"\n";
    }
}
void buscar_palabra(DATO *ve[], int n ){
	char buscar[20];
	DATO *aux;
	int posicion=0,tc,i=0;
	for(int i =1;i<=100;i++){
			gotoxy(10+i,5);cout<<"=";
			gotoxy(10+i,22);cout<<"=";
		}
  		for(int i =1;i<=16;i++){
			gotoxy(11,5+i);cout<<"|";
			gotoxy(110,5+i);cout<<"|";
		}
	gotoxy(30,8);cout << "Que palabra desea buscar: ";
	cin >>buscar;
	posicion=Dispersion1(buscar,strlen(buscar),n);
	aux=ve[posicion];
	if(aux==NULL){
		gotoxy(45,18);cout << "No se encontro la palabra\n";
	}else if (palabraColision(aux,buscar)){
		gotoxy(45,18);cout << "Se encuentra en la posicion "<< posicion <<endl;
	}else{
		gotoxy(45,18);cout << "No se encontro la palabra\n";
	}
}
int ingresar_palabra(DATO *ve[],int m,int n,char nombre[]){
	DATO *nuevo,*u;
    int posicion=0, tc,pri;
    	for(int i =1;i<=100;i++){
			gotoxy(10+i,5);cout<<"=";
			gotoxy(10+i,22);cout<<"=";
		}
  		for(int i =1;i<=16;i++){
			gotoxy(11,5+i);cout<<"|";
			gotoxy(110,5+i);cout<<"|";
		}
    if(m<n){
    	nuevo = new DATO;
		gotoxy(30,8);cout << "Ingrese la  palabra  :";
		cin >> nuevo->palabra;
		gotoxy(30,9);cout << "Ingrese la traduccion :";
		cin >> nuevo->significado;
		nuevo->sig = NULL;
		tc = strlen(nuevo->palabra);
		posicion = Dispersion1(nuevo->palabra, tc,n);
		if(ve[posicion] == NULL){
			u=ve[posicion];
			ve[posicion]= apilar(u, nuevo);
		    gotoxy(45,18);cout <<"===> EXITO, indice -> "<<posicion<<"\n";
			insertar_Archivo(nombre,nuevo);
		} else if(ve[posicion] != NULL && (palabraColision(ve[posicion],nuevo->palabra)==0)){
			u=ve[posicion];
		    ve[posicion] = apilar(u,nuevo);
		    gotoxy(45,18);cout<<"===> COLISION, indice ->"<<posicion<<"\n";
		    insertar_Archivo(nombre,nuevo);
		}else{
			 gotoxy(45,18);cout<< "Error el elemento ya existe--> Vuelva a ingresar\n";
				m--;
				//cout <<"m"<<m;
		}
	}else{
		gotoxy(35,13);cout <<"Error => No se puede ingresar mas palabras. Vector lleno\n";
	}
	return m+1;
}
bool palabraColision(DATO *ve,char buscar[]){
	DATO *aux;
	bool encontrado;
	aux=ve;
	while(aux!= NULL){
		if(strcmp(aux->palabra,buscar)==0){
				for(int i =1;i<=32;i++){
					gotoxy(44+i,11);cout<<"-";
					gotoxy(44+i,13);cout<<"-";
					gotoxy(44+i,15);cout<<"-";
				}
				gotoxy(45,12);cout <<" Palabra\t\tTraduccion";
				gotoxy(44,12);cout <<"|";
				gotoxy(60,12);cout <<"|";
				gotoxy(76,12);cout <<"|";
				gotoxy(44,14);cout <<"|";
				gotoxy(60,14);cout <<"|";
				gotoxy(76,14);cout <<"|";
				gotoxy(45,14);cout <<" "<<aux->palabra <<"\t\t"<<aux->significado;
				encontrado=true;
				break;
		}
		aux=aux->sig;
	}
	return encontrado;
}
void insertar_Archivo(char nombre[],DATO *ve){
	FILE *archivo;
	archivo= fopen(nombre,"a+");
	fprintf(archivo,"\n%s\n",ve->palabra);
	fprintf(archivo,"%s",ve->significado);
	fclose(archivo);
}

