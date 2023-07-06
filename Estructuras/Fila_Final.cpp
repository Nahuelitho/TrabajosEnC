#include <iostream>
using namespace std;
struct Fila{
	int fila[5];
	int primero;
	int ultimo;
	int cantidad;
};
void inicializar(Fila &fila){
	fila.cantidad=0;
	fila.primero=0;
	fila.ultimo=-1;
}
bool filaVacia(Fila fila){
	return fila.cantidad==0;
}
bool filaLlena(Fila fila){
	return fila.cantidad==5;
}
void insertar(Fila &fila,int x){
	if(!filaLlena(fila)){
		fila.ultimo= (fila.ultimo+1)%5;
		fila.fila[fila.ultimo]=x;
		fila.cantidad+=1;
	}else{
		cout<<"no se pudo insertar"<<endl;
	}
}
void suprimir(Fila &fila){
	if(!filaVacia(fila)){
		fila.primero= (fila.primero+1)%5;
		fila.cantidad-=1;
	}else{
		cout<<"no se puede eliminar"<<endl;
	}
}
int verPrimero(Fila fila){
	int c;
	if(!filaVacia(fila)){
		c= fila.fila[fila.primero];		
	}
	return c;
}
int verUltimo(Fila fila){
	int c;
	if(!filaVacia(fila)){
		c= fila.fila[fila.ultimo];
		
	}
	return c;
}
void mostrarFila(Fila &fila){
	Fila aux;
	inicializar(aux);
	while(!filaVacia(fila)){
		insertar(aux,verPrimero(fila));
		cout<<verPrimero(fila)<<"-";
		suprimir(fila);
	}
	while(!filaVacia(aux)){
		insertar(fila,verPrimero(aux));
		suprimir(aux);
	}
	cout<<endl;
}
void buscarFila(Fila &fila,int x){
	Fila aux;
	int contador=1;
	int encuentra=0;
	inicializar(aux);
	while(!filaVacia(fila)){
		insertar(aux,verPrimero(fila));
		if(verPrimero(fila)==x){
			cout<<"Se encontro el numero: "<<verPrimero(fila)<<endl;
			cout<<"En la posicion: "<<contador<<endl;
			encuentra++;
		}
		contador++;
		suprimir(fila);
	}
	while(!filaVacia(aux)){
		insertar(fila,verPrimero(aux));
		suprimir(aux);
	}
	if(encuentra==0){
		cout<<"el numero ingresado no se encuentra en la fila"<<endl;
	}
	cout<<endl;
}
int verPrinero(Fila fila){
	int c;
	if(!filaVacia(fila)){
	c=fila.fila[fila.primero];	
	}
	return c;
}
int main(){
	int opcion=0;
	int x;
	Fila fila;
	inicializar(fila);
	do{do{
		cout<<"1.Insertar"<<endl;
		cout<<"2.Suprimir"<<endl;
		cout<<"3.Ver primero"<<endl;
		cout<<"4.Ver ultimo"<<endl;
		cout<<"5.Mostrar fila"<<endl;
		cout<<"6.Buscar fila"<<endl;
		cout<<"7.Salir"<<endl;

		cout<<"Ingrese una opcion: "<<endl;

		cin>>opcion;
		}while(opcion>7||opcion<1);
		switch(opcion){
			case 1:{
				cout<<"ingrese el numero para insertar: "<<endl;
				cin>>x;
				fflush(stdin);
				insertar(fila,x);
				break;
			}
			case 2:{
				suprimir(fila);
				cout<<"Elemento borrado"<<endl;
				break;
			}
			case 3:{
				cout<<"el primero es: "<<verPrimero(fila)<<endl;
				break;
			}
			case 4:{
				cout<<"el ultimo es: "<<verUltimo(fila)<<endl;
				break;
			}			
			case 5:{ mostrarFila(fila);
				break;
			}
			case 6:{
				cout<<"ingrese el numero a buscar: "<<endl;
				cin>>x;
				fflush(stdin);
				buscarFila(fila,x);
				break;
			}
		}
		system("pause");//pausa para que puedas esperar y ver
		system("cls");	//limpia la pantalla
	}while(opcion!=7);
	
	return 0;
}
