#include <iostream>
#include <s#include <string.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>

using namespace std;
/* listas de listas de listas, */

enum _retorno
{ OK, ERROR, NO_IMPLEMENTADA };

typedef enum _retorno TipoRet;

struct columna{
	int num;
	string dato;
	columna * sig;
};

typedef columna * ptrcolumna;

struct tupla {
	string nombre;
	bool pk;
	ptrcolumna columna;
	tupla * sig;
};

typedef tupla*  ptrtupla;


struct tablaL {
	int cantcol;
	string nombre;
	ptrtupla tupla;
	tablaL * sig;
};

typedef tablaL* tabla;



tabla crearTablavacia(){
	tabla nuevo=new tablaL ;
	nuevo->cantcol=0;
	nuevo->sig=NULL;
	nuevo->tupla=NULL; 
	return nuevo;
}

tabla inicio = crearTablavacia();

TipoRet printDataTable (string com2);
TipoRet createTable (string com2);
TipoRet addCol(string com3, string com4);
TipoRet dropTable (string a);
TipoRet dropCol ( string a, string b ) ;
TipoRet insertInto (string nombre, string valTu);
TipoRet deleteFrom (string a, string b);
TipoRet update (string nombreTabla, string condicionModificar,string columnaModificar, string valorModificar);


int opc(string a);
ptrtupla buscarcol (string elem,ptrtupla l);
void cons(string elem);
void constu(string elem,ptrtupla l);
std::vector<std::string> split(const std::string &text, char sep);
bool IsParenthesesOrDash(char c);
tabla buscartabla (string elem, tabla l);
ptrtupla buscarpk (ptrtupla l );
ptrcolumna expk (string elem,ptrcolumna l );
void addatos(string elem,ptrcolumna l);
void tuplaimprimir(ptrtupla raiz);
int ulticol(ptrcolumna l);
void info(ptrtupla t,int i);



main(){
string ing;
while (true){

getline(std::cin, ing);

std::vector<std::string> words;
words = split(ing,' ');
		
int op= opc(words[0]);

switch(op){
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
}
TipoRet dropTable(string a){
	return NO_IMPLEMENTADA;
}
TipoRet dropCol(string a,string b){
	return NO_IMPLEMENTADA;
}

TipoRet deleteFrom(string a,string b){
	return NO_IMPLEMENTADA;
}

TipoRet update (string nombreTabla, string condicionModificar,string columnaModificar, string valorModificar){
	return NO_IMPLEMENTADA;
}


TipoRet insertInto (string nombre, string valTu){
	tabla l=buscartabla(nombre, inicio);
		if(l!=NULL){
        	std::vector<std::string> val;
			val = split(valTu,':');
        	int cont = val.size();
        	if(cont==l->cantcol){
        		ptrtupla tupk=buscarpk (l->tupla->sig);
        		ptrcolumna pk = expk (val[0],tupk->columna);
	
           	 	if(pk==NULL){
           	 		ptrtupla intu=l->tupla->sig;
           	 		for (int i=cont-1;i>=0;i--){
						ptrcolumna nodo = new columna;
						nodo->dato = val[i];
						nodo->sig = intu->columna;
						if(nodo->sig==NULL)
							nodo->num=1;
						else{
						int nn=nodo->sig->num;
						nn=nn+1;
						nodo->num=nn;	
							
						}
						
						intu->columna = nodo;		
           	 	 		intu=intu->sig;	 			
           	 		}	
           	 			return OK; 
           	 		
           	 		
					}
           	 	else{
					cout<<"El primer parametro (PK) ya exsite";
            		return ERROR;
				}
  			}
            else    {
        		cout<<"el numero de columnas no coinside con los parametros";
        		return ERROR;
        }

     }
    	else    {
       	 	cout<<"El nombre de la tabla no existe";
        	return ERROR;
        }



}








TipoRet printDataTable (string com2){
		tabla l=buscartabla (com2, inicio);
		if(l!=NULL){
        	if(l->cantcol!=0){
				ptrtupla t=l->tupla->sig; 
				cout<<com2<<"\n";
				tuplaimprimir(t);
				cout<<"\n";
				ptrtupla init=l->tupla->sig;
				int con = ulticol(l->tupla->sig->columna);
        		for(int i=con;i>0;i--){
        			t=init;
					info(t,i);
					cout<<"\n";	
			    	}	
				return OK;
			}
  		
            else {
        		cout<<"no hay tuplas en "<<com2;
        		return ERROR;
            }

        }
    	else    {
       	 	cout<<"El nombre de la tabla no existe";
        	return ERROR;
        }


	}
		

TipoRet createTable (string com2){
    tabla l=inicio->sig;
    tabla p=buscartabla (com2, l);
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
 	tabla p=inicio->sig;
    tabla l=buscartabla (com3,p);
    if(l!=NULL){
    	
    	ptrtupla j= buscarcol (com4, (p->tupla));
        if(j==NULL){
        	
        	if (l->tupla==NULL){
    			ptrtupla nodo = new tupla;
    			nodo->sig = NULL;
    			l->tupla = nodo;
    		}
    		
            constu(com4,l->tupla);
            l->cantcol=l->cantcol+1;
            
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






//AUXILIARES

int opc(string a)
{
	
	if (a.compare("createTable") == 0)
 		return 1;
 	if (a.compare("dropTable") == 0)
 		return 2;
 	if (a.compare("addCol") == 0)
 		return 3;
 	if (a.compare("dropCol") == 0)
 		return 4;	
 	if (a.compare("insertInto") == 0)
 		return 5;	
 	if (a.compare("deleteFrom") == 0)
 		return 6;	
 	if (a.compare("update") == 0)
 		return 7;	
 	if (a.compare("printDataTable") == 0)
 		return 8;	
 	}
 	
int ulticol(ptrcolumna l){
	if(l==NULL){
	   return 0;
		}
    		
    return l->num;
    }
 	
 	
void tuplaimprimir(ptrtupla raiz) {
	if(raiz!=NULL){
	    tuplaimprimir(raiz->sig);
        cout<<raiz->nombre<<':';
	}	
 }
ptrtupla buscarpk (ptrtupla l ){  //buscar columnas
  while(l->sig!=NULL){
		 l=l->sig;
	}
	return l;

}
ptrcolumna expk (string elem,ptrcolumna l){  //buscar columnas

	if (l==NULL){
        return NULL;
	}
    if (elem.compare(l->dato) == 0){
        return l;    
	}
    return expk(elem, l->sig);

}

tabla buscartabla (string elem ,tabla l){
       
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

void addatos(string elem,ptrcolumna l){        //agrega al comienzo
     ptrcolumna nodo = new columna;
     nodo->dato = elem;
     nodo->sig = l->sig;
     l = nodo;
     if(nodo->sig==NULL)
     	nodo->num=1;
     else
	 	nodo->num=nodo->num+1;
     }


//para crear tablas
void cons(string elem){        //agrega al comienzo
     tabla l = inicio;
     tabla nodo = new tablaL;
     nodo->nombre = elem;
     nodo->sig = l->sig;
     nodo->cantcol=0;
     nodo->tupla=NULL;
     l->sig = nodo;
     
     }



//para crear tuplas
void constu(string elem,ptrtupla l){        //agrega al comienzo
     ptrtupla nodo = new tupla;
     nodo->sig = l->sig;
     nodo->nombre = elem; 
     nodo->columna = NULL;		
     if (nodo->sig==NULL)
     	nodo->pk = true;
     else
        nodo->pk=false;
     l->sig = nodo;	
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

void info(ptrtupla t,int i) {
	ptrcolumna c;
	if (t!=NULL){
	    info(t->sig,i);
		c=t->columna;
		while (c!=NULL){
			  	if(c->num==i){
					cout<<c->dato<<':';
			    			}
			    c=c->sig;
		}	
			    	}	
 }



tdio.h>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>

using namespace std;
/* listas de listas de listas, */

enum _retorno
{ OK, ERROR, NO_IMPLEMENTADA };

typedef enum _retorno TipoRet;

struct columna{
	int num;
	string dato;
	columna * sig;
};

typedef columna * ptrcolumna;

struct tupla {
	string nombre;
	bool pk;
	ptrcolumna columna;
	tupla * sig;
};

typedef tupla*  ptrtupla;


struct tablaL {
	int cantcol;
	string nombre;
	ptrtupla tupla;
	tablaL * sig;
};

typedef tablaL* tabla;



tabla crearTablavacia(){
	tabla nuevo=new tablaL ;
	nuevo->cantcol=0;
	nuevo->sig=NULL;
	nuevo->tupla=NULL; 
	return nuevo;
}

tabla inicio = crearTablavacia();

TipoRet printDataTable (string com2);
TipoRet createTable (string com2);
TipoRet addCol(string com3, string com4);
TipoRet dropTable (string a);
TipoRet dropCol ( string a, string b ) ;
TipoRet insertInto (string nombre, string valTu);
TipoRet deleteFrom (string a, string b);
TipoRet update (string nombreTabla, string condicionModificar,string columnaModificar, string valorModificar);


int opc(string a);
ptrtupla buscarcol (string elem,ptrtupla l);
void cons(string elem);
void constu(string elem,ptrtupla l);
std::vector<std::string> split(const std::string &text, char sep);
bool IsParenthesesOrDash(char c);
tabla buscartabla (string elem, tabla l);
ptrtupla buscarpk (ptrtupla l );
ptrcolumna expk (string elem,ptrcolumna l );
void addatos(string elem,ptrcolumna l);
void tuplaimprimir(ptrtupla raiz);
int ulticol(ptrcolumna l);



main(){
string ing;
while (true){

getline(std::cin, ing);

std::vector<std::string> words;
words = split(ing,' ');
		
int op= opc(words[0]);

switch(op){
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
}
TipoRet dropTable(string a){
	return NO_IMPLEMENTADA;
}
TipoRet dropCol(string a,string b){
	return NO_IMPLEMENTADA;
}

TipoRet deleteFrom(string a,string b){
	return NO_IMPLEMENTADA;
}

TipoRet update (string nombreTabla, string condicionModificar,string columnaModificar, string valorModificar){
	return NO_IMPLEMENTADA;
}


TipoRet insertInto (string nombre, string valTu){
	tabla l=buscartabla(nombre, inicio);
		if(l!=NULL){
        	std::vector<std::string> val;
			val = split(valTu,':');
        	int cont = val.size();
        	if(cont=l->cantcol){ 
        		ptrtupla tupk=buscarpk (l->tupla);
        		ptrcolumna pk = expk (val[0],tupk->columna);		
           	 	if(pk==NULL){ 	 		
           	 		ptrtupla intu=l->tupla;	 		
           	 		for (int i=(cont-1);i<=0;i--){   	 							
           	 			intu=intu->sig;	 			
           	 		}	
           	 			return OK; 
           	 		
           	 		
					}
           	 	else{
					cout<<"El primer parametro (PK) ya exsite";
            		return ERROR;
				}
  			}
            else    {
        		cout<<"el numero de columnas no coinside con los parametros";
        		return ERROR;
        }

     }
    	else    {
       	 	cout<<"El nombre de la tabla no existe";
        	return ERROR;
        }



}








TipoRet printDataTable (string com2){
		tabla l=buscartabla (com2, inicio);
		if(l!=NULL){
        	if(l->cantcol!=0){
				ptrtupla t=l->tupla; 
				cout<<com2<<"\n";
				tuplaimprimir(t);
				ptrcolumna c;
				ptrtupla init=t;
				int con = ulticol(t->columna);
        		for(int i=con;i<0;i--){
        			t=init;
        			while (t!=NULL){
						c=t->columna->sig;
			    		while (c!=NULL){
			    			if(c->num==i){
								cout<<c->dato<<':';
								break;
			    			}
			    			c=c->sig;
						}
					t=t->sig;	
			    	}	
				}
				return OK;
			}
  		
            else {
        		cout<<"no hay tuplas en "<<com2;
        		return ERROR;
            }

        }
    	else    {
       	 	cout<<"El nombre de la tabla no existe";
        	return ERROR;
        }


	}
		

TipoRet createTable (string com2){
    tabla l=inicio->sig;
    tabla p=buscartabla (com2, l);
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
 	tabla p=inicio->sig;
    tabla l=buscartabla (com3,p);
    if(l!=NULL){
    	
    	ptrtupla j= buscarcol (com4, (p->tupla));
        if(j==NULL){
        	
        	if (l->tupla==NULL){
    			ptrtupla nodo = new tupla;
    			nodo->sig = NULL;
    			l->tupla = nodo;
    		}
    		
            constu(com4,l->tupla);
            l->cantcol=l->cantcol+1;
            
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






//AUXILIARES

int opc(string a)
{
	
	if (a.compare("createTable") == 0)
 		return 1;
 	if (a.compare("dropTable") == 0)
 		return 2;
 	if (a.compare("addCol") == 0)
 		return 3;
 	if (a.compare("dropCol") == 0)
 		return 4;	
 	if (a.compare("insertInto") == 0)
 		return 5;	
 	if (a.compare("deleteFrom") == 0)
 		return 6;	
 	if (a.compare("update") == 0)
 		return 7;	
 	if (a.compare("printDataTable") == 0)
 		return 8;	
 	}
 	
int ulticol(ptrcolumna l){
	while(l->sig!=NULL){
		l=l->sig;
    }
    return l->num;
} 	
 	
void tuplaimprimir(ptrtupla raiz) {
	if(raiz!=NULL){
	    tuplaimprimir(raiz->sig);
        cout<<raiz->nombre<<':';
	}	
 }
ptrtupla buscarpk (ptrtupla l ){  //buscar columnas
    
	if (l == NULL)
        return NULL;
    if (l->pk=true)
        return l;
    return buscarpk(l->sig);
}
ptrcolumna expk (string elem,ptrcolumna l){  //buscar columnas

	if (l==NULL){
        return NULL;
	}
    if (elem.compare(l->sig->dato) == 0){
        return l;    
	}
    return expk(elem, l->sig);

}

tabla buscartabla (string elem ,tabla l){
       
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

void addatos(string elem,ptrcolumna l){        //agrega al comienzo
     ptrcolumna nodo = new columna;
     nodo->dato = elem;
     nodo->sig = l->sig;
     l = nodo;
     if(nodo->sig==NULL)
     	nodo->num=1;
     else
	 	nodo->num=nodo->num+1;
     }


//para crear tablas
void cons(string elem){        //agrega al comienzo
     tabla l = inicio;
     tabla nodo = new tablaL;
     nodo->nombre = elem;
     nodo->sig = l->sig;
     nodo->cantcol=0;
     nodo->tupla=NULL;
     l->sig = nodo;
     
     }



//para crear tuplas
void constu(string elem,ptrtupla l){        //agrega al comienzo
     ptrtupla nodo = new tupla;
     nodo->sig = l->sig;
     nodo->nombre = elem; 
     nodo->columna = NULL;		
     if (nodo->sig==NULL)
     	nodo->pk = true;
     else
        nodo->pk=false;
     l->sig = nodo;	
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


tabla dropTable(string nombre)
{
 
	ptrtabla T =  //primer elemento
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
