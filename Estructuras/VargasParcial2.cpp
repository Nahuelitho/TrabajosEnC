/*Ejercicio 2: (Acevedo - Ceratto - Cola - Coronel - Gomez - Molina  - Munizaga - Paredes - Rodriguez - Saucedo - Sturniolo - Vargas - Villegas- Vissio - Weber)


Escribir un procedimiento Invertir(C) para invertir el contenido de una Fila C ( tipo dato char).  Utilizar Fila/Pila auxiliares si lo necesita.

El programa principal, debe permitir:  insertar, mostrar el tda original y el invertido

 */
 #include "iostream"
 #include<string.h>
 #include <cstdlib>
 
 using namespace std;
 /*YO REALICE LA FILA INVERTIDA RESPALDANDOME CON UNA PILA*/
 struct Pila{
	int tope=-1;
	char datos[5];
};
//////////////////////////////////////////////
 struct Fila{
	char fila[5];
	char primero;
	char ultimo;
	int cantidad;
};
/////////////////METODOS DE LA PILA/////////////////////////////
bool pilaVacia(Pila &pila){
	if(pila.tope<0){
		cout<<"\n";
	}
	return pila.tope<0;
}
bool pilaLlena(Pila &p){
	if(p.tope==5){
		cout<<"\n";
	}
	return p.tope==5;
}

void push(Pila &p,char d){
	if(pilaLlena(p)){
		cout<<"\n";
	}else {
		p.tope++;
		p.datos[p.tope]=d;
		
	}
}
void pop(Pila &p){
	if(pilaVacia(p)){
	cout<<"\n"<<endl;
	}else{
		p.datos[p.tope]='\0';
		p.tope--;
		
		}
	}
	 
void leeTope(Pila &pila){
	if(pilaVacia(pila)){
		cout<<"\n"<<endl;
	} else{
		int x=pila.tope;
		cout<<pila.datos[x]<<endl;
	}
}

///////////////////DE AQUI PARA ABAJO LOS CONTROLES DE FILA//////////////////////////
	void crear(Fila &fila){
	fila.cantidad=0;
	fila.primero=0;
	fila.ultimo=-1;
}
/////////////////////////////////////////////
	bool filaVacia(Fila fila){
		return fila.cantidad==0;
}
/////////////////////////////////////////////
	bool filaLlena(Fila fila){
		return fila.cantidad==5;
}
/////////////////////////////////////////////
	void agregar(Fila &fila,char x){
	if(!filaLlena(fila)){
		fila.ultimo=(fila.ultimo+1)%5;
		fila.fila[fila.ultimo]=x;
		fila.cantidad+=1;
	}else{
		cout<<"no se inserto"<<endl;
	}
}
/////////////////////////////////////////////
	void eliminar(Fila &fila){
		if(!filaVacia(fila)){
			fila.primero=(fila.primero+1)%5;
			fila.cantidad-=1;
	}else{
		cout<<"no se elimino";
	}
}
/////////////////////////////////////////////
	char verPrimero(Fila fila){
	char e;
	if(!filaVacia(fila)){
	e=fila.fila[fila.primero];	
	}
	return e;
}
/////////////////////////////////////////////
	char verUltimo(Fila fila){
	char e;
	if(!filaVacia(fila)){
		e=fila.fila[fila.ultimo];
	}
	return e;
}	
/////////////////////////////////////////////
	void verFila(Fila &fila){
	Fila aux;
	crear(aux);
	while(!filaVacia(fila)){
		agregar(aux,verPrimero(fila));
		cout<<verPrimero(fila)<<"-";
		eliminar(fila);
	}
	while(!filaVacia(aux)){
		agregar(fila,verPrimero(aux));
		eliminar(aux);
	}
	cout<<endl;
}
/////////////////////////////////////////////
	void invertirFila(Fila &fila){
		Pila aux;
		Fila auxF;
		while(!filaVacia(fila)){
			push(aux,verPrimero(fila));
			eliminar(fila);
		}
		
		while(!pilaVacia(aux)){
			agregar(auxF,aux.datos[aux.tope]);
			pop(aux);
			cout<<verUltimo(auxF)<<"-";
		}
		
	}	
 /////////////////////////////////////////////
 int main(){
 	Fila fila;
 	int opcion;
 	char x;
 	crear(fila);
 	do{
	 do{
	 
 		cout<<"1_Agregar elemento a la fila\n";
 			cout<<"2_Borrar elemento de la fila\n";
 			cout<<"3_Ver ultimo elemento de la fila\n";
 			cout<<"4_Ver primer elemento de la fila\n";
 			cout<<"5_Ver fila\n";
 			cout<<"6_Invertir fila\n";
 			cout<<"7_Salir\n";
 			cout<<"Ingrese una opcion: \n";
 			cin>>opcion;
			 }while(opcion>8&&opcion<1);
		 
 		switch(opcion){
 			case 1:{
 				cout<<"Ingrese un elemento caracter para insertar\n";
 				cin>>x;
 				fflush(stdin);
				agregar(fila,x);
				break;}
 			case 2:{
 				eliminar(fila);
 				cout<<"elemento borrado\n";
 				break;}
 			case 3:{
 				cout<<"el ultimo elemento es: "<<verUltimo(fila)<<endl;
 				break;}
 			case 4:{
				
			 
			 	cout<<"el primer elemento es: "<<verPrimero(fila)<<endl;
			 	break;}
 			case 5:{
 			    verFila(fila);
 				break;
				 }
			case 6:{
				cout<<"\nFila original:\n";
				verFila(fila);
				cout<<"\nFila invertida:\n";
				invertirFila(fila);
				cout<<"\n";
				break;
			}
			
			
		 }
		 system("pause");
		 system("cls");
	 }while(opcion!=7);
 	return 0;
 }
 

