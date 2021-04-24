/* 5017873 */

/*
  Se incluyen los archivos en donde se declaran las operaciones y tipos que se
  deben implentar.
 */
#include "../include/lista.h"
#include "../include/pila.h"


// Biblioteca estándar
#include <assert.h>
#include <stdio.h>


struct _rep_pila{
  TLista info;
};

/*
  Devuelve un elemento de tipo 'TPila' vacío (sin elementos).
 */
TPila crearPila(){
  TPila pila = new _rep_pila;
  pila->info = crearLista();
  return pila;
}

/*
  Devuelve 'true' si y solo si 'pila' no tiene elementos.
 */
bool esVaciaPila(TPila pila){
  return longitud(pila->info) == 0;
}

/*
  Si en 'pila' hay menos de MAX (definido en utils.h) elementos apila
  'nuevo' en 'pila'. En otro caso la operación no tiene efecto.
  Devuelve 'pila'.
 */
TPila apilar(info_t nuevo, TPila pila){
  if( longitud(pila->info) < MAX ){
    pila->info = insertar(1, nuevo, pila->info);
  }
  return pila;
}

/*
  Devuelve el tope de 'pila'.
  Precondición: 'pila' tiene elementos.
 */
info_t cima(TPila pila){
  assert( !esVaciaPila(pila) );
  return infoLista(1, pila->info);
}

/*
  Si 'pila' tiene elementos desapila el tope de 'pila'.
  En otro caso la operación no tiene efecto.
  Devuelve 'pila'.
 */
TPila desapilar(TPila pila){
  if( longitud(pila->info) > 0 ){
    pila->info = remover(1 , pila->info);
  }
  return pila;
}
