// Ejercicio 2 Tad Cola de naturales

#include <stdio.h>
#include "ejercicio_2.h"

struct repCola{
  unsigned int dato;
  Cola siguiente;
};

Cola frenteCola = NULL;

Cola crearCola (){
  return NULL;
}

Cola encolar ( unsigned int x , Cola c ){
  Cola new_nodo = new repCola;
  if(c == NULL){
    new_nodo->dato = x;
    new_nodo->siguiente = c;
  }
  new_nodo->dato = x;
  new_nodo->siguiente = c;
  return new_nodo;
}

bool esVacia ( Cola c ){
  return c==NULL ;
}

unsigned int frente ( Cola c ){
  return frenteCola->dato;
}

Cola desencolar ( Cola c ){

  return frenteCola;
}
