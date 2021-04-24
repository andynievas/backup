/* 5017873 */

#include <stdio.h>
#include <assert.h>
// #include <string.h>
#include "../include/cadena.h"
#include "../include/info.h"

struct nodoCadena {
  TInfo dato;
  TLocalizador anterior;
  TLocalizador siguiente;
};

struct _rep_cadena {
  TLocalizador inicio;
  TLocalizador final;
};


bool esLocalizador(TLocalizador loc){
  return loc != NULL;
}

TCadena crearCadena(){
  TCadena cad = new _rep_cadena;
  cad->inicio = cad->final = NULL;
  return cad;
}

void liberarCadena(TCadena cad){

  TLocalizador loc = cad->inicio;

  if( esVaciaCadena(cad) ){
    delete cad->inicio;
    delete cad->final;
  }else while( esLocalizador(loc) ){
    TLocalizador aux;
    liberarInfo(loc->dato);
    if( localizadorEnCadena(loc, cad) ){
      aux = loc;
      loc = siguiente(loc, cad);
      delete aux;
    }
  }
  delete cad;
}

bool esVaciaCadena(TCadena cad){
  return cad->inicio == NULL && cad->final == NULL;
}


TLocalizador inicioCadena(TCadena cad){
  return cad->inicio;
}

TLocalizador finalCadena(TCadena cad){
  return cad->final;
}

TInfo infoCadena(TLocalizador loc, TCadena cad){
  assert( localizadorEnCadena(loc, cad) );
  return loc->dato;
}

TLocalizador siguiente(TLocalizador loc, TCadena cad){
  assert(localizadorEnCadena(loc, cad));
  if( !esFinalCadena(loc, cad) ){
    return loc->siguiente;
  }else{
    return NULL;
  }
}

TLocalizador anterior(TLocalizador loc, TCadena cad){
  assert(localizadorEnCadena(loc, cad));
  // if( esInicioCadena(loc, cad) ){
  //   return NULL;
  // }else{
  //   return loc->anterior;
  // }
  return esInicioCadena(loc, cad) ? NULL : loc->anterior;
}

bool esFinalCadena(TLocalizador loc, TCadena cad){
  if( !esVaciaCadena(cad) && localizadorEnCadena(loc, cad) ){
    // printf("esFinalCadena dentro de la funcion mia");
    return loc->siguiente == NULL;
  }else{
    return false;
  }
}

bool esInicioCadena(TLocalizador loc, TCadena cad){
  if( esVaciaCadena(cad) || !esLocalizador(loc) ){
    return false;
  }else{
    return loc->anterior == NULL;
  }
}

TCadena insertarAlFinal(TInfo i, TCadena cad){
  TLocalizador nuevo = new nodoCadena;
  nuevo->dato = i;

  if( esVaciaCadena(cad) ){
    nuevo->siguiente = nuevo->anterior = NULL;
    cad->inicio = cad->final = nuevo;
  }else {
    nuevo->anterior = cad->final;
    nuevo->siguiente = NULL;

    cad->final->siguiente = nuevo;
    cad->final = nuevo;
  }

  return cad;
}

TCadena insertarAntes(TInfo i, TLocalizador loc, TCadena cad){
  assert( localizadorEnCadena(loc, cad) );

  TLocalizador nuevo = new nodoCadena;

  nuevo->dato = i;
  nuevo->siguiente = loc;
  if( esInicioCadena(loc, cad) ){
    nuevo->anterior = NULL;
    cad->inicio = nuevo;
  }else{ // Insertar al medio
    nuevo->anterior = loc->anterior;
    loc->anterior->siguiente = nuevo;
  }
  loc->anterior = nuevo;

  return cad;
}

TCadena removerDeCadena(TLocalizador loc, TCadena cad){
  assert( localizadorEnCadena(loc, cad) );
  TLocalizador aBorrar = loc;
  if( esInicioCadena(loc, cad) && esFinalCadena(loc, cad) ){ // Caso de unico elemento
    liberarInfo(aBorrar->dato);
    cad->inicio = cad->final = NULL;
  }else if( esInicioCadena(loc, cad) ){ // Caso del inicio
    loc = loc->siguiente;
    liberarInfo(aBorrar->dato);
    loc->anterior = NULL;
    cad->inicio = loc;
  }else if( esFinalCadena(loc, cad) ){ // Caso del final
    loc = loc->anterior;
    liberarInfo(aBorrar->dato);
    loc->siguiente = NULL;
    cad->final = loc;
  }else{ // Caso del medio
    TLocalizador locAux = siguiente(loc, cad);
    loc = anterior(loc, cad);
    liberarInfo(aBorrar->dato);
    loc->siguiente = locAux;
    locAux->anterior = loc;
  }
  delete aBorrar;
  return cad;
}

void imprimirCadena(TCadena cad){
  TLocalizador loc = inicioCadena(cad);
  while( esLocalizador(loc) ){
    printf("(%i,%.2f)", natInfo(infoCadena(loc, cad)), realInfo(infoCadena(loc, cad)));
    if( localizadorEnCadena(loc, cad) ) loc = siguiente(loc, cad);
  }
  printf("\n");
}

TLocalizador kesimo(nat k, TCadena cad){
  if( k == 0 ) return NULL;
  TLocalizador loc = inicioCadena(cad);
  for(nat i = 1; i < k; i++){
    if ( esFinalCadena(loc, cad) ){
      return NULL;
    }
    if( localizadorEnCadena(loc, cad) ) loc = siguiente(loc, cad);
  }
  return loc;
}

bool localizadorEnCadena(TLocalizador loc, TCadena cad){
  if( esVaciaCadena(cad) ){
    return false;
  }else{
    // printf("esLocalizador en cadena. dentro de la funcion locEnCadena\n");
    while( loc != NULL ){
      if( loc->dato != NULL ){
        // printf("esLocalizador dentro del while");
        return true;
      }
      loc = loc->siguiente;
    }
  }
  return false;
}

bool precedeEnCadena(TLocalizador loc1, TLocalizador loc2, TCadena cad){
  if ( esVaciaCadena(cad) ){
    return false;
  }else if( loc1 == loc2 ){return true;}

  TLocalizador iterador = inicioCadena(cad);

  while( !esFinalCadena(iterador, cad) ){
    if ( iterador == loc1 || iterador == loc2 ){
      return iterador == loc1;
    }
    iterador = iterador->siguiente;
  }
  return false;
}

TCadena insertarSegmentoDespues(TCadena sgm, TLocalizador loc, TCadena cad){
  assert( esVaciaCadena(cad) || localizadorEnCadena(loc, cad) );
  if( esVaciaCadena(sgm) ) {delete sgm; return cad;}

  if ( esVaciaCadena(cad) ){
    cad->inicio = inicioCadena(sgm);
    cad->final = finalCadena(sgm);
    delete sgm;
  }/*else if( esInicioCadena(loc, cad) && esFinalCadena(loc, cad) ){
    caso de unico elemento
  }*/else if( esInicioCadena(loc, cad) || esFinalCadena(loc, cad) ){
    if( esFinalCadena(loc, cad) ){
      TLocalizador inicioSgm = inicioCadena(sgm);
      inicioSgm->anterior = loc;
      loc->siguiente = inicioSgm;
      cad->final = finalCadena(sgm);
      delete sgm;
    }else{ // Caso de loc inicioCadena
      // esInicioCadena();
      TLocalizador continuacion = loc->siguiente;
      TLocalizador finalSgm = finalCadena(sgm);
      finalSgm->siguiente = continuacion;
      loc->siguiente = inicioCadena(sgm);
      delete sgm;
    }
  }else{
    TLocalizador continuacion = loc->siguiente;
    loc->siguiente = inicioCadena(sgm);
    sgm->final->siguiente = continuacion;
    delete sgm;
  }
  // delete sgm;
  return cad;
}

TCadena copiarSegmento(TLocalizador desde, TLocalizador hasta, TCadena cad){
  assert( esVaciaCadena(cad) || precedeEnCadena(desde, hasta, cad) );

  TCadena segmento = crearCadena();

  if( esVaciaCadena(cad) ){
    return segmento;
  }

  TLocalizador cursor = desde;

  while( cursor != hasta && localizadorEnCadena(cursor, cad) ){
    TInfo dato = crearInfo( natInfo(infoCadena( cursor , cad )) , realInfo(infoCadena( cursor , cad )) );
    segmento = insertarAlFinal( dato , segmento);
    cursor = siguiente(cursor, cad);
  }
  TInfo dato = crearInfo( natInfo(infoCadena( cursor , cad )) , realInfo(infoCadena( cursor , cad )) );
  segmento = insertarAlFinal( dato , segmento);
  cursor = siguiente(cursor, cad);

  return segmento;
}

// Precedimiento auxiliar
// Borra un nodo accedido por loc, de cad
// loc queda indeterminado
void borrarNodoCadena(TLocalizador loc, TCadena cad){
  TLocalizador anteriorLoc = anterior(loc, cad);
  TLocalizador siguienteLoc = siguiente(loc, cad);
  // TLocalizador inicioSgm = desde;
  if( esInicioCadena(loc, cad) && esFinalCadena(loc, cad) ){
    liberarInfo( infoCadena(loc, cad) );
    delete loc;
    cad->inicio = cad->final = NULL;
  }else if( esInicioCadena(loc, cad) ){
    liberarInfo( infoCadena(loc, cad) );
    delete loc;
    siguienteLoc->anterior = NULL;
    cad->inicio = siguienteLoc;
  }else if( esFinalCadena(loc, cad) ){ // Caso del ultimo nodo
    liberarInfo( infoCadena(loc, cad) );
    delete loc;
    anteriorLoc->siguiente = NULL;
    cad->final = anteriorLoc;
  }else{ // Caso de un nodo del medio
    liberarInfo( infoCadena(loc, cad) );
    delete loc;
    anteriorLoc->siguiente = siguienteLoc;
    siguienteLoc->anterior = anteriorLoc;
  }
}

// insertarSegmentoDespues 5 (1,1) (2,2) (3,3) (4,4) (5,5)

TCadena borrarSegmento(TLocalizador desde, TLocalizador hasta, TCadena cad){
  if( esVaciaCadena(cad) ) return cad;

  TLocalizador cursor = siguiente(desde, cad);

  if( desde == hasta ){
    borrarNodoCadena(desde, cad);
  }else/*if( esInicioCadena(desde, cad) )*/{
    while ( desde != hasta ) {
      borrarNodoCadena(desde, cad);
      desde = cursor;
      cursor = siguiente(cursor, cad);
    }
    borrarNodoCadena(desde, cad);
    desde = cursor;
    if ( localizadorEnCadena(cursor, cad) ) cursor = siguiente(cursor, cad);
  }

  return cad;
}

TCadena cambiarEnCadena(TInfo i, TLocalizador loc, TCadena cad){
  loc->dato = i;
  return cad;
}

TCadena intercambiar(TLocalizador loc1, TLocalizador loc2, TCadena cad){

  if ( loc1 == loc2 ) return cad;

  TInfo aux = infoCadena(loc1, cad);
  loc1->dato = infoCadena(loc2, cad);
  loc2->dato = aux;

  return cad;
}

TLocalizador siguienteClave(nat clave, TLocalizador loc, TCadena cad){
  if( esVaciaCadena(cad) ) return NULL;

  while( localizadorEnCadena(loc, cad) ){
    if( natInfo( infoCadena(loc, cad) ) == clave ){
      return loc;
    }

    loc = siguiente(loc, cad);
  }

  return NULL;
}

TLocalizador anteriorClave(nat clave, TLocalizador loc, TCadena cad){

  if( esVaciaCadena(cad) ) return NULL;

  while( localizadorEnCadena(loc, cad) ){
    if( natInfo( infoCadena(loc, cad) ) == clave ){
      return loc;
    }

    loc = anterior(loc, cad);
  }

  return NULL;
}

TLocalizador menorEnCadena(TLocalizador loc, TCadena cad){
  assert(localizadorEnCadena(loc, cad));
  TLocalizador resultado = loc;
  nat menor = natInfo(loc->dato);
  nat nuevoMenor;
  while( !esFinalCadena(loc, cad) ){/* !esFinalCadena(loc, cad) */
    nuevoMenor = natInfo(loc->dato);
    if( nuevoMenor < menor ){
      menor = natInfo(loc->dato);
      resultado = loc;
    }
    loc = siguiente(loc, cad);
  }
  nuevoMenor = natInfo(loc->dato);
  if( nuevoMenor < menor ){
    menor = natInfo(loc->dato);
    resultado = loc;
  }
  loc = siguiente(loc, cad);
  return resultado;
}
