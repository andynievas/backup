#ifndef COLA_H
#define COLA_H

// Ejercicio 2 Tad Cola de naturales

typedef struct repCola * Cola;

/* Crea y retorna la cola vacia . */
Cola crearCola () ;

/* Inserta el elemento x al final de la cola c . */
Cola encolar ( unsigned int x , Cola c ) ;

/* Retorna TRUE si c es vacia . */
bool esVacia ( Cola c ) ;

/* Retorna el elemento que se encuentra al comienzo de la ←-
cola c . Pre : ! esVacia ( c ) */
unsigned int frente ( Cola c ) ;

/* Retorna la cola resultado de borrar el primer elemento de ←-
c . Pre : ! esVacia ( c ) */
Cola desencolar ( Cola c ) ;

#endif
