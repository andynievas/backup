/* 5017873 */

/*
  Se incluyen los archivos en donde se declaran las operaciones y tipos que se
  deben implentar.
 */
#include "../include/lista.h"
#include "../include/cola.h"


// Biblioteca estándar
#include <assert.h>
#include <stdio.h>


struct _rep_cola{
  TLista data;
};

/*
  Devuelve un elemento de tipo 'TCola' vacío (sin elementos).
 */
TCola crearCola(){
  TCola cola = new _rep_cola;
  cola->data = crearLista();
  return cola;
}

/*
  Devuelve 'true' si y solo si 'cola' no tiene elementos.
 */
bool esVaciaCola(TCola cola){
  return longitud(cola->data) == 0;
}

/*
  Si en 'cola' hay menos de MAX (definido en utils.h) elementos, encola
  'nuevo' en 'cola'. En otro caso la operación no tiene efecto.
  Devuelve 'cola'.
 */
TCola encolar(info_t nuevo, TCola cola){
  if( longitud(cola->data) < MAX ){
    cola->data = insertar(1, nuevo, cola->data);
  }
  return cola;
}

/*
  Devuelve el frente de 'cola'.
  Precondición: 'cola' tiene elementos.
 */
info_t frente(TCola cola){
  return infoLista( longitud(cola->data) , cola->data );
}

/*
  Si 'cola' tiene elementos desapila el frente de 'cola'.
  En otro caso la operación no tiene efecto.
  Devuelve 'cola'.
 */
TCola desencolar(TCola c){
  if( longitud(c->data) > 0 ){
    c->data = remover( longitud(c->data) , c->data );
  }
  return c;
}
