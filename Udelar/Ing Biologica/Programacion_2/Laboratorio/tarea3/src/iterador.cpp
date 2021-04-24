/* 5017873 */

#include <stdio.h>
#include <assert.h>
#include "../include/iterador.h"
#include "../include/cadena.h"
#include "../include/info.h"

struct nodoIterador{
  nat dato;
  TIterador siguiente;
};
typedef struct nodoIterador *nodoIter;

struct _rep_iterador{
  bool definida;
  nodoIter iterador;
};

TIterador crearIterador(){
  TIterador nuevo = new _rep_iterador;
  nuevo->definida = false;
  nuevo->iterador = NULL;
  return nuevo;
}

TIterador agregarAIterador(nat elem, TIterador iter){

  if( iter->iterador == NULL ){
    iter->iterador = new nodoIterador;
    iter->iterador->dato = elem;
    iter->iterador->siguiente = NULL;
  }else{// Caso en el que si tiene elementos
    
  }

  return iter;
}

TIterador reiniciarIterador(TIterador iter){
  if( iter tiene elementos ){
    liberarIterador(iter);
    iter->definida = false;
  }
  return iter;
}

TIterador avanzarIterador(TIterador iter){
  if( estaDefinidaActual(iter) ){
    iter = iter->siguiente;
  }
  return iter;
}

nat actualEnIterador(TIterador iter){
  return 1;
}

bool estaDefinidaActual(TIterador iter){
  return iter->definida;
}

void liberarIterador(TIterador iter){
  // printf("Liberar Iterador\n");
}
