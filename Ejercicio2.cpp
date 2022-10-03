/*Ejercicio 2: Hacer un programa en C++ utilizando Pilas que contenga el siguiente menu:
1-. Insertar un caracter a la pila.
2-. Mostrar todos los elementos de la pila.
3-. Salir.*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
	char dato;
	Nodo *siguiente;
};

void agregarpila(Nodo *&, char);
void sacarpila(Nodo *&, char &);

int main(){
	Nodo *pila=NULL;
	char dato;
	char rpt1,rpt2;
		
		do{
			cout<<"\nSeleccione la opcion que desea realizar "<<endl;
			cout<<"\t 1. Insertar un elemento a la pila."<<endl;
			cout<<"\t 2. Mostrar todos los elementos de la pila."<<endl;
			cout<<"\t 3. Salir."<<endl;
			cout<<"Opcion: "; cin>>rpt1;
			if(rpt1=='1'){
				do{
					cout<<"Digite un unico caracter: "; cin>>dato;
					agregarpila(pila,dato);
					fflush(stdin);
					cout<<"\nDesea agregar otro elemento a la pila(s/n)?:"; cin>>rpt2;
				}while((rpt2=='S')||(rpt2=='s'));
			}	
			else if(rpt1=='2'){
				cout<<"\nMostrando todos los elementos de la pila: \n";
				while(pila!=NULL){ //mientras no sea el final de la pila
					sacarpila(pila, dato);
					
					if(pila!=NULL){
						cout<<dato<<" , ";
					}
					else{
						cout<<dato<<".";
					}
				}
				cout<<"\nAhora la pila esta vacia, si lo desea puede volver a rellenarla.\n";
				cout<<endl;
				
			}
			else if(rpt1=='3'){
				cout<<"\nSaliendo, presione una tecla para continuar...";
				
				getch();
				return 0;
			}
			else{
				cout<<"Opcion introducida invalido, cerrando el programa. Pulse una tecla para continuar...";
				getch();
				return 0;
			}
		}while(rpt1!='3');

}
void agregarpila(Nodo *&pila, char n){
	Nodo *nuevonodo=new Nodo();
	nuevonodo->dato=n;
	nuevonodo->siguiente=pila;
	pila=nuevonodo;
}
void sacarpila(Nodo *&pila, char &n){
	Nodo *aux=pila;
	n=aux->dato;
	pila=aux->siguiente;
	delete aux;
}
