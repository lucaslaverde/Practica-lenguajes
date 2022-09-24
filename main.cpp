
#include<iostream>
#include<stdlib.h>
#include <fstream>
#include<string.h>

using namespace std;

struct nodo{
	char nombre[30];
	struct nodo *siguiente;
}*inicio=NULL,*aux=NULL,*ultimo=NULL;

void insertar(){
	 ofstream archivo;
    
    

	struct nodo *nuevo=new struct nodo();
	
	cout<<"\nIngrese un usuario con pwd: "<<endl;
	cout<<"\nasi: usuario:pwd: "<<endl;

	cin>>nuevo->nombre;

	
	

	
	if(inicio==NULL){
		inicio=nuevo;
		inicio->siguiente=NULL;
		ultimo=nuevo;
		
	}
	else{
		ultimo->siguiente=nuevo;
		nuevo->siguiente=NULL;
		ultimo=nuevo;
	}
	
	
	
	cout<<"\nElemento insertado correctamente\n";
}

void mostrar(){
	aux=inicio;
	
	while(aux!=NULL){
		cout<<"\n"<<aux->nombre;
		aux=aux->siguiente;
	}

}

void buscar(){
	int contador=0,opcion;
	char nombre[30];
	
	
	cout<<"\nIngrese usuario y pwd a buscar: ";
	cin>>nombre;
	
	
	aux=inicio;
	
	while(aux!=NULL){
		if(strcmp(aux->nombre,nombre)==0){
			contador++;
		}
		aux=aux->siguiente;
	}
	
	if(contador!=0){
		cout<<"\nBienvenido\n";
	}
	else{
		cout<<"\nEl usuario no existe en la lista\n";
	}
}


void eliminar(){
	char nombre[30];
	int contador=0,opcion;
	
	cout<<"\nIngrese usuario a buscar: ";
	cin>>nombre;
	
	aux=inicio;
	
	while(aux!=NULL){
		if(strcmp(aux->nombre,nombre)==0){
			contador++;
		}
		aux=aux->siguiente;
	}
	
	if(contador!=0){
		aux=inicio;
		
		while(aux!=NULL){
			if(strcmp(aux->nombre,nombre)==0){
				if(aux==inicio){
					inicio=inicio->siguiente;
					delete aux;
				}
				else if(aux->siguiente==NULL){
					ultimo=aux->siguiente;
					delete aux;
				}
				else{
					aux=aux->siguiente;
					delete aux;
				}
			}
			aux=aux->siguiente;
		}
		cout<<"\nNombre eliminado \n";
	}
	else{
		cout<<"\nEl nombre "<<nombre<<" no existe en la lista\n";
	}
}

int main(){
	bool salir=false;
	int opcion;
	
	while(!salir){
		cout<<"\n1) Ingresar nombre";
		cout<<"\n2) Buscar nombre";
		cout<<"\n3) Eliminar nombre";
        cout<<"\n4) Ver nombres";
		cout<<"\n5) Salir";
		cout<<"\n\nIngrese una opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: insertar();
				break;
			case 2: buscar();
				break;
			case 3: eliminar();
				break;
            case 4: mostrar();
				break;
			case 5: salir=true;
				break;
			default: cout<<"\nOpcion no valida\n";
				break;
		}
	}
	
}