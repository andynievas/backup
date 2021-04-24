#ifndef HEADERFILE_H
#define HEADERFILE_H

typedef struct rep_Pila *Pila;

/* Crea la Pila vacia */
Pila crearPila();

/* Inserta el elemento x en la cima de la pila p. x queda como el último elemento apilado. */
Pila apilar(int x, Pila p);

/* Verifica si la Pila p está vacía */
bool esVacia(Pila p);

/*  Retorna el elemento de la cima de la Pila p (último elemento apilado).
    Pre : !esVacia(p) */
int cima(Pila p);

/*  Retorna la Pila p sin el elemento de la cima (ultimo elemento apilado).
    Pre : !esVacia(p) */
Pila desapilar(Pila p);

#endif
