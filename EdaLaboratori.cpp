#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;
/* listas de listas de listas, */


/* TODO (#2#): crear una funcion para eliminar una fila de las 
               tuplas, eliminar una "fila" es nesesario un 
               indice o usar un identificador para ser mas 
               practico */
               
/* TODO (#1#): crear una funcion de elistado de comandos
 */

/* TODO (#1#): realizar un test con funcion insertar mostrar e 
    liminar */
               

enum _retorno
{ OK, ERROR, NO_IMPLEMENTADA };

 typedef enum _retorno TipoRet;

 typedef enum _retorno TipoRet;

struct columna{
	string dato;
	columna * sig;
};

typedef columna * ptrcolumna;

struct tupla {
	string nombre;
	columna columnas;
	tupla * sig;
};

typedef tupla*  ptrtupla;


struct tablaL {
	string nombre;
	tupla tupla;
	tablaL * sig;
};

typedef tablaL* tabla;



tabla dropTabla(string nombre);
tupla dropTupla(string nomTabla,string nombre);
columna dropcolumn(string nombreTabla, string nombrTupla,string no);
void dropValue(string nombreTabla,string nombTupla,string nomcolumna, string value);

tabla inicio = crearTablavacia();

TipoRet printDataTable (string com2);
TipoRet createTable (string com2);
TipoRet addCol(string com3, string com4);
TipoRet dropTable (string nombreTabla);
TipoRet dropCol ( string nombreTabla, string nombreCol ) ;
TipoRet insertInto (string nombreTabla, string valoresTupla);
TipoRet deleteFrom (string nombreTabla, string condicionEliminar);
TipoRet update (string nombreTabla, string condicionModificar,string columnaModificar, string valorModificar);



int opc(string a);
ptrtupla buscarcol (string elem,ptrtupla l);
void cons(string elem);
void snoc(string elem, tabla l);
void constu(string elem);
void snoctu(string elem ,tupla l );
std::vector<std::string> split(const std::string &text, char sep);
bool IsParenthesesOrDash(char c);
tabla buscartabla (string elem, tabla l);




main()
{

tabla inicio;
inicio = crearTablavacia();

	string ing;
	string com;
	crearTablavacia();
cin>>ing;
	com = SPLIT(ing; " "; 1);
	com2 = SPLIT(ing; " "; 2);	

switch(com){
	string ing;
getline(std::cin, ing);

std::vector<std::string> words;
words = split(ing,' ');
		
int op= opc(ing);

switch(op)
{
		case 1: 
				words[1].erase(std::remove_if(words[1].begin(), words[1].end(), &IsParenthesesOrDash), words[1].end());
				createTable(words[1]);
				words.clear();
				break;
				
		case 2:
				words[1].erase(std::remove_if(words[1].begin(), words[1].end(), &IsParenthesesOrDash), words[1].end());
				dropTable(words[1]);
				words.clear();
				break;
		case 3:
				words[1].erase(std::remove_if(words[1].begin(), words[1].end(), &IsParenthesesOrDash), words[1].end());
    			words = split(words[1],',');
				addCol(words[0],words[1]);
				words.clear();
				break;
		case 4:
				words[1].erase(std::remove_if(words[1].begin(), words[1].end(), &IsParenthesesOrDash), words[1].end());
    			words = split(words[1],',');
				dropCol(words[0],words[1]);
				words.clear();
				break;
		case 5:
				words[1].erase(std::remove_if(words[1].begin(), words[1].end(), &IsParenthesesOrDash), words[1].end());
    			words = split(words[1],',');
				insertInto(words[0],words[1]);
				words.clear();
				break;
		case 6: 
				words[1].erase(std::remove_if(words[1].begin(), words[1].end(), &IsParenthesesOrDash), words[1].end());
    			words = split(words[1],',');
				deleteFrom(words[0],words[1]);
				words.clear();
				break;
		case 7:
				words[1].erase(std::remove_if(words[1].begin(), words[1].end(), &IsParenthesesOrDash), words[1].end());
    			words = split(words[1],',');
				update(words[0],words[1],words[2],words[3]);
				words.clear();
				break;
		case 8:
				words[1].erase(std::remove_if(words[1].begin(), words[1].end(), &IsParenthesesOrDash), words[1].end());
				printDataTable(words[1]);
				words.clear();
				break;
}
}




tabla crearTablavacia(){
	tabla nuevo=new tablaL ;
	nuevo->sig = null;
	return nuevo;
}

tabla dropTable(string nombre)
{
 
	tabla T= //primer elemento
	tabla T= T->sig;
	tabla aux_T = T;
		while((T != NULL) && (T->nombre != nombre))
	{
		anterior = borrar;
		borrar = borrar->sig;
	}
	if(borrar == Null)
	{
	switch(E)
		{
			case Error :
				{
					cout << "Error#02: No existe la Tupla" << endl;
				}
		}
	}
	else if(anterior == NULL)
	{
		delete borrar;
	}
	else
	{
		anterior->sig = borrar->sig;
		delete borrar;
	}
	
}


tupla dropCol(string nomTabla,string nombre)
{
	tabla T=new tumpla; //primer elemento
	tabla T= T->sig;
	tabla aux_T =T;
	tupla Tu=crearTablavacia();
	tupla anterior=Tu;
	tupla borrar=Tu;
	while ((T !=NULL) && (T->nombre != nomTabla))
	{
		T=T->sig;
	}
	if(aux_T==NULL)
	{
		switch(E)
		{
			case Error :
				{
					cout << "Error#01: No existe la tabla" << endl;
				}
		}
	}
	while((Tu != NULL) && (Tu->nombre != nombre))
	{
		anterior = borrar;
		borrar = borrar->sig;
	}
	if(borrar == Null)
	{
	switch(E)
		{
			case Error :
				{
					cout << "Error#02: No existe la Tupla" << endl;
				}
		}
	}
	else if(anterior == NULL)
	{
		delete borrar;
	}
	else
	{
		anterior->sig = borrar->sig;
		delete borrar;
	}
	
	
}
/*
tupla dropCol(string nombreTabla, string nombrTupla,string name)
{
	tabla T= CrearTablaVacia()
	tabla T=T->sig;
	tupla Tu=CrearTuplaVacia();
	columna Col=CrearColVacia();
	columna anterior=Col;
	columna borrar=Col;
	_returno E = Error;
	
	while ((T !=NULL) && (T->nombre != nomTabla))
	{
		T = T->sig;
	}
	if(aux_T==NULL)
	{
		//INTRODUCIR ERROR
		switch(E)
		{
			case Error :
				{
					cout << "Error#01: No existe la tabla" << endl;
				}
		}
		
	}
	while((Tu != NULL) && (Tu->nombre != nombrTupla))
	{
		Tu=Tu->sig;
	}
	if(Tu != Null)
	{
		switch(E)
		{
			case Error :
				{
					cout << "Error#02: No existe la Tupla" << endl;
				}
		}
	}
	
	while((Col != NULL) && (Col->nombre != dato)
	{
		anterior = borrar;
		borrar = borrar->sig;
	}
	if(borrar == Null)
	{
		switch(E)
		{
			case Error :
				{
					cout << "Error#03: No existe la variable" << endl;
				}
		}
	}
	else if(anterior == NULL)
	{
		delete borrar;
	}
	else
	{
		anterior->sig = borrar->sig;
		delete borrar;
	}
	
}
*/
void printDataTable(string nombretabla)
{
		tabla T=new tabla; //primer elemento
	tabla T= T->sig;
	tabla aux_T = T;
	tupla aux_Tu=new tupla;//Primeratabla
	colum col=new Col;
	colum aux_Col =col;
	while((aux_T != NULL) && (aux_T->nombre != nombretabla))
	{
		aux_T = aux_T -> sig;
	}
	while((aux_T != NULL) && (aux_Tu != NULL))
	{
	 cout << aux_Tu -> nombre << " -> ";
	 
	 while ((aux_Col != NULL))
	{
	 cout << aux_Col->dato << " -> "<< endl;
	 aux_Col = aux_Col->siguiente; 
	}
	aux_Col->sig=Col;
	}
	
	if(borrar == Null)
	{
	switch(E)
		{
			case Error :
				{
					cout << "Error#02: No existe la Tupla" << endl;
				}
		}
	}
	else if(anterior == NULL)
	{
		delete borrar;
	}
	else
	{
		anterior->sig = borrar->sig;
		delete borrar;
	}
}



TipoRet printDataTable (string com2){
		tabla l=buscartabla (com2, inicio);
	}


TipoRet addCol(string com3, string com4){ //nombre tabla y col

    tabla l=buscartabla (com3, inicio);
    if(l!=NULL){
        ptrtupla j= buscarcol (com4, (inicio->tupla));
        if(j==NULL){ 
            constu(com4);
            return OK; 
    }
            else    {
        cout<<"El nombre de la tupla ya existe";
        return ERROR;
        }

     }
    else    {
        cout<<"El nombre de la tabla no existe";
        return ERROR;
        }



   }
    else    {
        cout<<"El nombre de la tabla no existe";
        return ERROR;
        }

}



TipoRet createTable (string com2){
    tabla l=inicio;
    tabla p=buscartabla (com2, inicio);
    if(p==NULL){
         cons(com2);
        return OK;
         }
    else    {
        cout<<"El nombre de la tabla ya existe";
        return ERROR;
        }
}


TipoRet addCol(string com3, string com4){ //nombre tabla y col

    tabla l=buscartabla (com3, inicio);
    if(l!=NULL){
        ptrtupla j= buscarcol (com4, (inicio->tupla));
        if(j==NULL){ 
            constu(com4);
            return OK; 
    }
            else    {
        cout<<"El nombre de la tupla ya existe";
        return ERROR;
        }

     }
    else    {
        cout<<"El nombre de la tabla no existe";
        return ERROR;
        }

}

//auxiliares
int opc(string a)
{
	
	if (a.compare("createTable") == 0)
 		return 1;
 	else if (a.compare("dropTable") == 0)
 		return 2;
 	else if (a.compare("addCol") == 0)
 		return 3;
 	else if (a.compare("dropCol") == 0)
 		return 4;	
 	else if (a.compare("insertInto") == 0)
 		return 5;	
 	else if (a.compare("deleteFrom") == 0)
 		return 6;	
 	else if (a.compare("update") == 0)
 		return 7;	
 	else if (a.compare("printDataTable") == 0)
 		return 8;	
 	}
 	
 	tabla buscartabla (string elem ,tabla l) 
	 {
       
    if (l == NULL)
        return NULL;
    if (elem.compare(l->nombre) == 0)
        return l;
    return buscartabla(elem, l->sig);
	}
	
	ptrtupla buscarcol (string elem,ptrtupla l ){  //buscar columnas
    
	if (l == NULL)
        return NULL;
    if (elem.compare(l->nombre) == 0)
        return l;
    return buscarcol(elem, l->sig);
}
//para crear tablas

void cons(string elem){        //agrega al comienzo
    tabla l = inicio;
     tabla nodo = new tablaL;
     nodo->nombre = elem;
     nodo->sig = l;
     l = nodo;
     }
     
void snoc(string elem, tabla l)
	 {        //agrega al final
    tabla l = inicio;
    if (l == NULL)
        cons(elem, l);
    else
        snoc(elem, l->sig);
 	}
 	
 	//para crear tuplas
void constu(string elem){        //agrega al comienzo
    ptrtupla l = inicio;
     ptrtupla nodo = new tupla;
     nodo->nombre = elem;
     nodo->sig = l;
     l = nodo;
}

void snoctu(string elem ,ptrtupla l ){        //agrega al final
    if (l == NULL)
        constu(elem, l);
    else
        snoctu(elem, l->sig);
}

std::vector<std::string> split(const std::string &text, char sep) {
    std::vector<std::string> tokens;
    std::size_t start = 0, end = 0;
    while ((end = text.find(sep, start)) != std::string::npos) {
        if (end != start) {
          tokens.push_back(text.substr(start, end - start));
        }
        start = end + 1;
    }
    if (end != start) {
       tokens.push_back(text.substr(start));
    }
    return tokens;
}

bool IsParenthesesOrDash(char c)
{
    switch(c)
    {
    case '(':
    case ')':
        return true;
    default:
        return false;
    }
}










