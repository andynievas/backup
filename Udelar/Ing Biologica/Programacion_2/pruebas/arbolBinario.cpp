// Pruebas con arboles Binarios

#include <stdio.h>

typedef struct rep_binario *TBinario;

struct rep_binario{
  int dato;
  TBinario izquierdo, derecho;
};

TBinario crearBinario(){
  return NULL;
}

TBinario insertarEnBinario(int i, TBinario b){
  if( b == NULL ){
    b = new rep_binario;
    b->dato = i;
    b->izquierdo = b->derecho = NULL;
  }else if( i < b->dato ){
    b->izquierdo = insertarEnBinario(i, b->izquierdo);
  }
  return b;
}

int main(){
  int x = 9;
  printf("%i\n", x);

  TBinario b = crearBinario();

  printf("Binario creado\n");

  b = insertarEnBinario( x , b );
  printf("Insertado %i en binario\n", x);
  x = 5;
  b = insertarEnBinario( x , b );
  printf("Insertado %i en binario\n", x);
  x = 4;
  b = insertarEnBinario( x , b );
  printf("Insertado %i en binario\n", x);

  printf("%i\n", b->dato);
  printf("%i\n", b->izquierdo->dato);
  printf("%i\n", b->izquierdo->izquierdo->dato);

}
