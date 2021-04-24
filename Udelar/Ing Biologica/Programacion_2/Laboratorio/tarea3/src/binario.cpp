/* 5017873 */

#include <stdio.h>
#include <assert.h>
#include "../include/binario.h"
#include "../include/cadena.h"
#include "../include/info.h"

struct _rep_binario{
  TInfo dato;
  TBinario izquierdo;
  TBinario derecho;
};


TBinario crearBinario(){
  return NULL;
}

TBinario insertarEnBinario(TInfo i, TBinario b){
  if( esVacioBinario(b) ){
    b = new _rep_binario;
    b->dato = i;
    b->izquierdo = b->derecho = NULL;
  }else if( natInfo(i) < natInfo(b->dato) ){
    b->izquierdo = insertarEnBinario(i , b->izquierdo);
  }else if( natInfo(i) > natInfo(b->dato) ){
    b->derecho = insertarEnBinario(i , b->derecho);
  }

  return b;
}

TInfo mayor(TBinario b){

  if( !esVacioBinario(b->derecho) ){
    return mayor(b->derecho);
  }else return b->dato;
}

TBinario removerMayor(TBinario b){
  return NULL;
}

TBinario removerDeBinario(nat elem, TBinario b){
  return NULL;
}

void liberarBinario(TBinario b){

  // Si el arbol no es vacío llamo a liberar el subarbol izquierdo
  if( !esVacioBinario( b ) ) liberarBinario(b->izquierdo);

  // Si el arbol no es vacío llamo a liberar el subarbol derecho
  if( !esVacioBinario( b ) ) liberarBinario(b->derecho);

  // Si el arbol no es vacío libero la memoria
  if( !esVacioBinario( b ) ){
    liberarInfo(b->dato);
    delete b;
  }

}

bool esVacioBinario(TBinario b){
  return b == NULL;
}

bool esAvl(TBinario b){
  return true;
}

TInfo raiz(TBinario b){
  assert( !esVacioBinario(b) );
  return b->dato;
}

TBinario izquierdo(TBinario b){
  assert( !esVacioBinario(b) );
  return b->izquierdo;
}

TBinario derecho(TBinario b){
  assert( !esVacioBinario(b) );
  return b->derecho;
}

TBinario buscarSubarbol(nat elem, TBinario b){

  if( esVacioBinario(b) ) return NULL;

  // if( natInfo(b->dato) == elem ){
  //   return b;
  // }

  while( !esVacioBinario(b) ){

    if( natInfo(b->dato) == elem ){
      return b;
    }

    if( natInfo(b->dato) < elem ){
      b = b->derecho;
    }else
    if( natInfo(b->dato) > elem ){
      b = b->izquierdo;
    }

  }

  return NULL;
}

int max( nat a, nat b ){

  // return natInfo(a->dato) > natInfo(b->dato) ? a : b;
  // return a > b ? a : b;
  if( a > b ){
    return a;
  }
  if( a < b ){
    return b;
  }
  else return 0;
}
nat alturaBinario(TBinario b){
  if( esVacioBinario(b) ){
    return 0;
  }
  return 1 + max( alturaBinario(b->izquierdo) , alturaBinario(b->izquierdo) );
}

nat cantidadBinario(TBinario b){
  if( esVacioBinario(b) ){
    return 0;
  }
  return 1 + cantidadBinario(b->izquierdo) + cantidadBinario(b->derecho);
}

// TBinario crearArbolUltimosPositivos(TBinario b){
//   crearArbolUltimosPositivos(b->izquierdo);
//   if( esPositivo( realInfo(b->dato) ) ){
//     insertarEnBinario( b->dato , TBinario );
//   }
//   crearArbolUltimosPositivos(b->derecho);
//   return b;
// }

double sumaUltimosPositivos(nat i, TBinario b){
  // los ultimos elementos con la parte real positiva

  // if( esVacioBinario(b->izquierdo) ) sumaUltimosPositivos( b->izquierdo );

  if( (!esVacioBinario( b->derecho ) || !esVacioBinario( b->derecho )) && esPositivo( realInfo(b->dato) ) ){
    return sumaUltimosPositivos( b->izquierdo ) + realInfo(b->dato) + sumaUltimosPositivos( b->derecho ) ;
  }else return 0.0;

  // if( esVacioBinario(b->derecho) ) sumaUltimosPositivos( b->derecho );

}

TCadena linealizacion(TBinario b){
  linealizacion( b->izquierdo );

  linealizacion( b->derecho );



  return NULL;
}

TBinario menores(double cota, TBinario b){
  return NULL;
}

int profundidadBinario(TBinario b){

  return 0;
}

void imprimirBinario(TBinario b){
  // printf("Imprimir Binario\n");

  if( esVacioBinario(b) )
  printf("\n");

  if( !esVacioBinario(b) /*&& !esVacioBinario(b->derecho)*/ ){
    // printf("-");
    imprimirBinario( derecho(b) );
  }

  if( !esVacioBinario(b) ){
    // printf("\n");
    profundidadBinario(b);
    printf("(%d,%.2f)", natInfo(b->dato), realInfo(b->dato) );
  }

  if( !esVacioBinario(b) /*&& !esVacioBinario(b->izquierdo)*/ ){
    // printf("-");
    imprimirBinario( izquierdo(b) );
  }

  /*imprimirBinario( b );
  imprimirBinario( b->derecho );*/
}

/*void imprimirBinario(TBinario b){
  if ( !esVacioBinario(b) ){
    imprimirBinarioNoVacio(b);
  }else printf("\n");
}*/
