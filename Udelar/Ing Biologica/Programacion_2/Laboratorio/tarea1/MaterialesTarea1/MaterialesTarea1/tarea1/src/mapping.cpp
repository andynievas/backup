/* 5017873 */

/*
  Se incluyen los archivos en donde se declaran las operaciones y tipos que se
  deben implentar.
 */
#include "../include/lista.h"
#include "../include/mapping.h"


// Biblioteca estándar
#include <assert.h>
#include <stdio.h>


struct _rep_mapping{
  TLista infoM;
};

/*
  Devuelve un elemento de tipo 'TMapping' vacío (sin elementos).
 */
TMapping crearMapping(){
  TMapping map = new _rep_mapping;
  map->infoM = crearLista();
  return map;
}

/*
  Si en 'map' hay menos de MAX (definido en utils.h) asociaciones y 'clave'
  no tiene un valor asociado en 'map' agrega en 'map' la asociación
  (clave,valor). En otro caso la operación no tiene efecto.
  Devuelve 'map'.
 */
TMapping asociar(nat clave, double valor, TMapping map){
  if( (longitud(map->infoM) < MAX) && !esClave(clave , map) ){
    info_t nuevo;
    nuevo.natural = clave;
    nuevo.real = valor;
    map->infoM = insertar( longitud(map->infoM)+1 , nuevo, map->infoM );
  }

  return map;
}

/*
  Devuelve 'true' si y solo si 'clave' tiene un valor asociado en 'map'.
 */
bool esClave(nat clave, TMapping map){
  return posNat(clave, map->infoM ) != 0 ;
}

/*
  Devuelve el valor que en 'map' está asociado a 'clave'.
  Precondición: esClave(clave, map)
 */
double valor(nat clave, TMapping map){
  assert(esClave(clave, map));
  return infoLista( posNat(clave, map->infoM) , map->infoM ).real ;
}

/*
  Si 'clave' tiene un valor asociado en 'map' remueve de `map' la asociación de
  'clave'. En otro caso la operación no tiene efecto.
  Devuelve 'map'.
 */
TMapping desasociar(nat clave, TMapping map){
  if( esClave(clave, map) ){
    map->infoM = remover( posNat(clave, map->infoM ) , map->infoM);
  }
  return map;
}
