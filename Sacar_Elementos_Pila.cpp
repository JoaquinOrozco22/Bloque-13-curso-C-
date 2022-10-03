#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;	
};

void agregarpila(Nodo *&, int); //prototipo
void sacarpila(Nodo *&, int&);

int main(){
	
	Nodo *pila = NULL;
	int dato;
	
	cout<<"\nDigite un numero: "; cin>>dato;
	agregarpila(pila, dato);
	cout<<"\nDigite un numero: "; cin>>dato;
	agregarpila(pila, dato);
	
	cout<<"\nSacando los elementos de la pila: ";
	while(pila != NULL){  //mientras no sea el final de la pila
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

void agregarpila (Nodo *&pila, int n){
	Nodo *nuevo_nodo=new Nodo();
	nuevo_nodo->dato=n;
	nuevo_nodo->siguiente=pila;
	pila=nuevo_nodo;
	
	cout<<"\nEl elemento '"<<n<<"' se ha Agregado a la pila correctamente."<<endl;
}
void sacarpila(Nodo *&pila, int &n){
	Nodo *aux=pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}
