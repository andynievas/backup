// EJERCICIO 1 Practico 2

#include <stdio.h>

// a) Implemente de forma recursiva la función ordenar:

/*  Ordena A[1..n] de  manera  creciente. */
void ordenar(float * A, uint n);


/*  
Inserta e en A[1..n+1] de  manera  ordenada.
Precondición: n>=0. Si n>=1 => A[1..n] está ordenado de manera creciente.
A[n+1] es  indeterminado.
Postcondición: A[1..n+1]  queda  ordenado  de  manera  creciente. */
void  insertarOrdenado(float * A, uint n, float e);

int main(){

  return 0;
}

void ordenar(float * A, uint n){
	if( n > 0 ){
		ordernar(A , n-1);
		insertarOrdenado(A, n-1, A[n]);
	}
}

void  insertarOrdenado(float * A, uint n, float e){
	
}





