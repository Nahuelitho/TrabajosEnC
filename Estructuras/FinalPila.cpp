#include <iostream>
using namespace std;
struct Pila{
	int tope=-1;
	char a[5];
};
void push(Pila &pila, char s);
void pop(Pila &pila);
void peek(Pila &pila);
bool pilaLlena(Pila &pila);
bool pilaVacia(Pila &pila);
void mostrarPila(Pila &pila);
void buscarPila(Pila &pila,char b);
int main(){
	Pila pila;
	char a;
	char b;
int opcion=0;
pilaVacia(pila);
	do{
		do{
		cout<<"1.Agregar(push)"<<endl;
		cout<<"2.Borrar (pop)"<<endl;
		cout<<"3.Mostrar tope(peek)"<<endl;
		cout<<"4.Mostrar pila"<<endl;
		cout<<"5.Buscar pila"<<endl;
		cout<<"6.Salir"<<endl;
		cout<<"Ingrese una opcion: "<<endl;
		cin>>opcion;
		cout<<"-------------------------"<<endl;
		}while(opcion>6||opcion<1);
		switch(opcion){
			case 1:{
				cout<<"ingrese el caracter a guardar"<<endl;
				cin>>a;
				fflush(stdin);
				push(pila,a);
				break;
			}
			case 2:{
				pop(pila);
				break;
			}
			case 3:{
				peek(pila);
				break;
			}
			case 4:{
				mostrarPila(pila);
				break;
			}
			case 5:{
				cout<<"ingrese el caracter a buscar"<<endl;
				cin>>b;
				fflush(stdin);
				cout<<"-------------------------"<<endl;
				buscarPila(pila,b);
				break;
			}			
		}
		system("pause");//pausa para que puedas esperar y ver
		system("cls");	//limpia la pantalla	
	}while(opcion!=6);

	return 0;
}
void  push(Pila &pila,char s){

	if(pilaLlena(pila)){
		cout<<"pila llena"<<endl;//0123 //abc
	}else{
		pila.tope++;
		pila.a[pila.tope]=s;
	//	cout<<"pila cargada"<<endl;
	}	
}
void pop(Pila &pila){
	if(pilaVacia(pila)){
		cout<<"pila vacia"<<endl;
	}else{
	pila.a[pila.tope]='\0';
	pila.tope--;
	//cout<<"eliminado correctamente"<<endl;
	}	
}
void peek(Pila &pila){
	if(pilaVacia(pila)){
		cout<<"pila vacia"<<endl;
	}else{
		int x=pila.tope;
		cout<<pila.a[x]<<endl;
	}	
}
bool pilaLlena(Pila &pila){
	return pila.tope==4;
}
bool pilaVacia(Pila &pila){
	return pila.tope<0;
}
void mostrarPila(Pila &pila){
	Pila pila2;
	
		while(!pilaVacia(pila)){
			push(pila2,pila.a[pila.tope]);
			peek(pila);//3 2c//2 1b//1 0a
			pop(pila);//2//1//0
		}

		while(!pilaVacia(pila2)){
			char z=pila2.a[pila2.tope];
			push(pila,z);
			pop(pila2);
		}
			
}
void buscarPila(Pila &pila,char b){
	Pila pila2;
	int l;
	char x=b;
	char a;
		while(!pilaVacia(pila)){
			push(pila2,pila.a[pila.tope]);
			a=pila.a[pila.tope];
			if(x==a){ 
			cout<<"pila encontrada"<<endl;
			peek(pila);
		}
			pop(pila);//2//1//0
		}

		while(!pilaVacia(pila2)){
			char z=pila2.a[pila2.tope];
			push(pila,z);
			pop(pila2);
		}
/*	
	int contador=0;
	 char x=b;
	 int l;
		if(pilaVacia(pila)){
		cout<<"pila vacia"<<endl;}
		else{
			while(pila.tope>0){
				l=pila.tope-1;
			s[contador]=pila.a[l];
			 char z=pila.a[l];
			if(x==z){ 
			cout<<"pila encontrada"<<endl;
			peek(pila);
		}
			pop(pila);
			contador++;
			}
		}
		while(contador>0){
			int j=contador-1;
			push(pila,s[j]);
			contador--;
		}*/
}
