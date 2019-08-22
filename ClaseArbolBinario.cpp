#include <iostream>
#include <windows.h>
using namespace std;

typedef class ArbolBinarioBusqueda *ABB ;

class ArbolBinarioBusqueda 
{
	private :
		int nro ;
		class ArbolBinarioBusqueda  *izq, *der;


public :
ABB crearNodo (int x)
{
	ABB nuevoNodo = new (class ArbolBinarioBusqueda);
	nuevoNodo->nro = x;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	return nuevoNodo ;
}

void insertar (ABB &arbol, int x)
{
	if (arbol==NULL)
	{
		arbol=crearNodo (x);
	}
	else if (x<arbol->nro)
	{
		insertar (arbol->izq,x);
	}
		else if (x>arbol->nro)
	{
		insertar (arbol->der,x);
	}		
}
void preOrden (ABB arbol)
{
	if (arbol != NULL)
	{
		cout << arbol->nro << " " ;
		preOrden (arbol->izq);
		preOrden (arbol->der);
	
	}
}
void inOrden (ABB arbol)
{
	if (arbol != NULL)
	{
		
		
		inOrden (arbol->izq);
  		cout << arbol->nro << " " ;
		inOrden (arbol->der);
	
	}
}
void posOrden (ABB arbol)
{
	if (arbol != NULL)
	{
	
		posOrden (arbol->izq);
		posOrden (arbol->der);
		cout << arbol->nro << " " ;
	}
} 

void verArbol (ABB arbol, int n)
{
	if (arbol == NULL)
	{
		return ;
	}
	verArbol (arbol->der,n+1);
	for (int i=0 ; i<n ; i++)
	{
		cout << " " ;
	}
	cout << arbol -> nro << endl ;
	verArbol (arbol->izq,n+1);
}
void suma (ABB arbol, int &su)
{
	
	if (arbol != NULL)
	{     
		suma(arbol->izq,su);
		su=su + arbol-> nro;
		suma(arbol->der,su);
		
	}
}

};


int main ()
{   
	 
	 ArbolBinarioBusqueda *arb = new ArbolBinarioBusqueda  () ;
	 ABB arbol=NULL;
	int n=0;
	int x=0;  
    int su=0 ;  
	
	int opc ;
	char resp ;         //opcion de repetir
	do 
	{
		//
		cout <<"1- Ingresar arbol" << endl ;
		cout <<"2- Mostrar el arbol" << endl ;
		cout <<"3- Recorridos" << endl ;
		cout <<"4- Calcular altura o profundidad y niveles" << endl ;
		cout <<"5- Mostrar el peso del arbol" << endl ;
		cout <<"6- Salir" << endl ; 
		cout <<"EL NUMERO DE NODOS ES" << ": " << n << endl ;  
		cout <<"Ingrese opcion: " ;
		cin >>opc ;
		switch (opc)
		{
			case 1:
			cout << "ingrese el numero de arbol: " ;
			cin >> n;
			
			for(int i=0; i<n; i++)
			{
			cout<<"Ingrese el valor del nodo: ";
			cin>>x;
			arb->insertar(arbol, x);
			}
			system ("cls") ;
			break ;
			
			case 2 :	
			cout<<"Mostrando arbolito..."<<endl;
			arb->verArbol(arbol, 0);
			cout << endl << "La altura del arbol es" << ": " << n ;
			cout << endl << "La nivel del arbol es" << ": " << n-1 ;
			
			arb->suma(arbol, su) ;
			cout << endl << "La suma de los valores de los nodos es" << ": " << su << endl ; 
		 	
			 
			system ("pause") ;
			system ("cls") ;
			break ;
			////////////////////////////////////////////////////////////////////
			case 3 :
			int reco ;
			system ("cls") ;
			cout << "Que recorrido desea ver?\n1-Pre-Orden\n2-In-Orden\n3-Pos-Orden\n4-Regresar al menu" << endl ;
			cout << "Inregese opcion " << endl ;
			cin >> reco ;
			switch(reco)
			{
				case 1 :
				cout << "Mostrar arbol en pre-orden: " << endl ;
				arb->preOrden(arbol);
				system ("pause") ;
				system ("cls") ;
				break ;
				case 2 :
				cout << endl << "Mostrar arbol en pos-orden: " << endl ;
				arb->posOrden (arbol)  ;
				system ("pause") ;
				system ("cls") ;
				break;
				case 3:
				cout << endl <<  "Mostrar arbol en in-orden: " << endl;
				arb->inOrden (arbol);
				system ("pause") ;
				system ("cls") ;
				break ;
			}
			break ; 
			
			case 4 :
			break ;

		}
	}   while (opc !=5) ;
	system ("pause") ;
	return 0 ;
		
}

