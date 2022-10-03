/*Ejercicio 1: Hacer un programa para agregar numeros enteros a una pila hasta que el ususario decida, despues mostrar 
los datos introducidos en la pila.*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguente;
};

//prototipos de funciones
void agregarpila(Nodo *&, int);
void sacarpila(Nodo *&, int &);

int main(){
	Nodo *pila=NULL;
	int dato;
	char rpt;
	
	do{
		cout<<"Digite un numero: "; cin>>dato;
		agregarpila(pila,dato);
		cout<<"\nDesea agregar otro elemento a la pila(s/n)?:"; cin>>rpt;
	}while((rpt=='S')||(rpt=='s'));
	
	cout<<"\nSacando todos los elementos de la pila: ";
	
	while(pila!=NULL){ //mientras no sea el final de la pila
		sacarpila(pila, dato);
		if(pila!=NULL){
			cout<<dato<<" , ";
		}
		else{
			cout<<dato<<".";
		}
	}
	
	getch();
	return 0;
}
void agregarpila(Nodo *&pila, int n){
	Nodo *nuevonodo=new Nodo();
	nuevonodo->dato=n;
	nuevonodo->siguente=pila;
	pila=nuevonodo;
	cout<<"\tElemento "<<n<<" ha sido agregado correctamente.";
}
void sacarpila(Nodo *&pila, int &n){
	Nodo *aux=pila;
	n=aux->dato;
	pila=aux->siguente;
	delete aux;
}
