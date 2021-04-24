
// EJERCICIO 1 Practico 3

#include <stdio.h>

struct nodo {
  int elem ;
  nodo * sig ;
};

typedef nodo * lista ;

// dada una lista no vacía, retorna su último elemento.
int last(lista l);

// dada una lista no vacía, retorna el promedio de sus elementos.
float average(lista l);

// dados un entero x y una lista l ordenada: inserta x en l ordenadamente.
// Comparar con la
// solución recursiva.
void insOrd(int x, lista &l);

// Inserta x al final de l
void snoc(int x, lista l);

// dados un entero x y una lista l, elimina a x de l.
void removeAll(int x, lista l);

void isIncluded();

int main(){

  return 0;
}

int last(lista l){

  while(l->sig == NULL){
    l = l->sig;
  }

  return l->elem;
}

float average(lista l){

  float promedio = 0.0;
  float count = 0.0;

  while( l != NULL ){
    promedio += l->elem;
    count += 1.0;
    l = l->sig;
  }

  return promedio / count;
}

void insOrd(int x, lista &l){

  lista nuevo = new nodo;
  if( x < l->elem ){
    nodo->elem = x;
    nodo->sig = l;
    l->sig = nodo;
  }else{
    lista aux = l;
    while( aux != NULL ){
      if(x < aux->sig->elem){
        nodo->elem = x;
        nodo->sig = aux->sig;
        aux->sig = nodo;
      }
      aux = aux->sig;
    }
  }

}

void snoc(int x, lista l){
  while( l->sig != NULL ){
    l = l->sig;
  }
  new nodo;
  nodo->elem = x;
  nodo->sig = NULL;
  l->sig = nodo;
}

// Elimina x de l
void removeAll(int x, lista &l){

  lista aux = l;
  while( l->sig != NULL && x == l->elem ){ // Caso de primeros elementos
    aux = l;
    l = l->sig;
    delete aux;
  }

  while( l->sig->sig != NULL ){ // Caso de elementos del medio
    // aux
    if( x == l->sig->elem ){
      aux = l;
      l->sig = l->sig->sig;
      delete aux;
    }
  }

  while( l->sig->sig != NULL && x == l->sig->elem ){ // Caso de ultimos elementos
    // aux
    if( x == l->sig->elem ){
      aux = l->sig;
      if( l->sig->sig != NULL ){
        l->sig = l->sig->sig;
      }else{
        l->sig = NULL;
      }
      delete aux;
    }
  }
}
