 /* 5017873 */

#include <stdio.h>
#include <assert.h>
#include "../include/usoTads.h"
#include "../include/cadena.h"
#include "../include/info.h"


bool pertenece(nat elem, TCadena cad){

  TLocalizador loc = inicioCadena(cad);

  while( esLocalizador(loc) ){
    if( natInfo( infoCadena(loc, cad) ) == elem ){
      return true;
    }
    loc = siguiente(loc, cad);
  }
  return false;
}

nat longitud(TCadena cad){
  if( esVaciaCadena(cad) ) return 0;
  TLocalizador loc = inicioCadena(cad);
  nat resultado = 0;
  while( esLocalizador(loc) ){
    resultado += 1;
    if( localizadorEnCadena(loc, cad) ) loc = siguiente(loc, cad);
  }
  return resultado;
}

bool estaOrdenadaPorNaturales(TCadena cad){
  if( esVaciaCadena(cad) ) return true;
  TLocalizador loc = inicioCadena(cad);
  nat clave = natInfo(infoCadena(loc, cad));
  while ( localizadorEnCadena(loc, cad) ) {
    if( natInfo(infoCadena(loc, cad)) < clave ){
      // printf("no esta estaOrdenadaPorNaturales.\n");
      return false;
    }else clave = natInfo(infoCadena(loc, cad));
    if( localizadorEnCadena(loc, cad) ) loc = siguiente(loc, cad);
  }
  return true;
}

bool hayNatsRepetidos(TCadena cad){

  if( esVaciaCadena(cad) || ( inicioCadena(cad) == finalCadena(cad) ) ) return false;

  TLocalizador loc = inicioCadena(cad);
  TLocalizador iterador = siguiente( inicioCadena(cad) , cad );

  nat datoNatural = natInfo(infoCadena(loc, cad));

  while( localizadorEnCadena(loc, cad) ){

    datoNatural = natInfo(infoCadena(loc, cad));

    while ( localizadorEnCadena(iterador, cad) ) {
      if( loc != iterador ){
        if( natInfo(infoCadena(iterador, cad)) == datoNatural ){
          return true;
        }
      }
      iterador = siguiente(iterador, cad);
    }

    iterador = inicioCadena(cad);
    loc = siguiente(loc, cad);
  }

  return false;
}

bool sonIgualesCadena(TCadena c1, TCadena c2){
  if ( esVaciaCadena(c1) && esVaciaCadena(c2) ) return true;

  TLocalizador loc1 = inicioCadena(c1);
  TLocalizador loc2 = inicioCadena(c2);

  if( longitud(c1) == longitud(c2) ){

    while ( localizadorEnCadena(loc1, c1) ) {
      if( natInfo( infoCadena(loc1, c1) ) != natInfo( infoCadena(loc2, c2) ) || realInfo( infoCadena(loc1, c1) ) != realInfo( infoCadena(loc2, c2) ) ){
        return false;
      }
      loc1 = siguiente(loc1, c1);
      loc2 = siguiente(loc2, c1);
    }
  }else return false;

  return true;
}

TCadena concatenar(TCadena c1, TCadena c2){
  TCadena c3 = crearCadena();
  TLocalizador loc = inicioCadena(c1);

  while( localizadorEnCadena(loc, c1) ){

    TInfo datoNuevo = crearInfo( natInfo(infoCadena(loc, c1)), realInfo(infoCadena(loc, c1)) );
    c3 = insertarAlFinal( datoNuevo , c3 );

    loc = siguiente(loc, c1);
  }

  loc = inicioCadena(c2);

  while( localizadorEnCadena(loc, c2) ){

    TInfo datoNuevo = crearInfo( natInfo(infoCadena(loc, c2)), realInfo(infoCadena(loc, c2)) );
    c3 = insertarAlFinal( datoNuevo , c3 );

    loc = siguiente(loc, c2);
  }

  return c3;
}

TCadena ordenar(TCadena cad){
  if ( hayNatsRepetidos(cad) || esVaciaCadena(cad) ) return cad;

  TLocalizador loc = inicioCadena(cad);
  TLocalizador primero = inicioCadena(cad);

  TLocalizador menor = NULL;

  while( localizadorEnCadena(loc, cad) ){
    menor = menorEnCadena(loc, cad);
    cad = intercambiar(primero, menor, cad);
    primero = siguiente(primero, cad);

    loc = siguiente(loc, cad);
  }

  return cad;
}

TCadena cambiarTodos(nat original, nat nuevo, TCadena cad){
  TLocalizador loc = inicioCadena(cad);
  while( localizadorEnCadena(loc, cad) ){

    if( natInfo(infoCadena(loc, cad)) == original ){
      // cambiar orininal por nuevo
      TInfo nuevoPar = crearInfo( nuevo , realInfo( infoCadena(loc, cad) ) );
      liberarInfo( infoCadena(loc, cad) );
      cad = cambiarEnCadena( nuevoPar , loc , cad);
    }

    loc = siguiente(loc, cad);
  }

  return cad;
}

TCadena subCadena(nat menor, nat mayor, TCadena cad){
	// Devuelve el segmento de cad conformado por los elementos entre "menor" y "mayor"
  TLocalizador loc = inicioCadena(cad);
	TCadena nuevaCadena = crearCadena();

	while( localizadorEnCadena(loc, cad) ){
		if( menor <= natInfo(infoCadena(loc, cad)) && mayor >= natInfo(infoCadena(loc, cad)) ){
			nuevaCadena = insertarAlFinal( crearInfo( natInfo(infoCadena(loc, cad)) , realInfo(infoCadena(loc, cad)) ) , nuevaCadena);
		}
		loc = siguiente(loc, cad);
	}

  return nuevaCadena;
}
