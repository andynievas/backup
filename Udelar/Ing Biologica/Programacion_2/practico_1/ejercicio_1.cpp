
#include <stdio.h>
#include "ejercicio_1.h"
// #include <string.h>

struct rep_Pila{
    int dato;
    Pila siguiente;
};

Pila crearPila(){
    return NULL;
}

Pila apilar(int x, Pila p){
    Pila nodo = new rep_Pila;
    nodo->dato = x;
    nodo->siguiente = p;
    return nodo;
}

bool esVacia(Pila p){
    if( p == NULL ){
        return true;
    }else{
        return false;
    }
}

int cima(Pila p){
    if( !esVacia(p) ){
        return p->dato;
    }else{
        return 0;
    }
}

Pila desapilar(Pila p){
    if( !esVacia(p) ){
        Pila nodo = p->siguiente;
        printf("\nElemento desapilado: %d.\n", p->dato);
        delete(p);
        return nodo;
    }else{
        return NULL;
    }
}

void destruirPila(Pila p){
  Pila q = NULL;
  while(p != NULL ){
    q = p;
    p = p->siguiente;
    // delete( q->dato );
    delete( q );
  }
  // delete(q);
}

void imprimir(Pila p){

    printf("\nMostrando PILA\n");
    printf("\nDireccion: %d.\n", p);

    while( p != NULL ){
        printf("%d, ", p->dato);
        p = p->siguiente;
    }

    printf("\nFin de la PILA\n");
}

void imprimirInverso(Pila p){
  if( !esVacia(p) ){
    imprimirInverso(p);
    printf("%d, ", p->dato);
  }
}

// int main(){
//     printf("\nHola esto funciona!\n\n");
//
//     char accion[30];
//     int nroComandos = 0;
//     Pila p = crearPila();
//
//     printf("Comandos aceptados:\napilar\ncima\nvacia\ndesapilar\nimprimir\n");
//
//     while( strcmp(accion, "exit") != 0 ){
//         printf("\nWaiting...\n");
//         printf("%i> ",nroComandos);
//         scanf("%s", accion);
//         printf("Introdujiste el comando <%s>.", accion);
//         nroComandos += 1;
//
//         if( strcmp(accion, "apilar") == 0 ){
//
//             int numero;
//
//             printf("\nQue numero quieres apilar: ");
//             scanf("%d", &numero);
//
//             p = apilar(numero, p);
//             printf("Apilado: %d\n", numero);
//
//         }else if( strcmp(accion, "cima") == 0 ){
//             printf("\nEn la cima de la pila se encuentra el dato: %d.\n", cima(p) );
//         }else if( strcmp(accion, "desapilar") == 0 ){
//
//             p = desapilar(p);
//
//         }else if( strcmp(accion, "imprimir") == 0 ){
//
//             printf("\nDireccion: %d.\n", p);
//
//             imprimir(p);
//
//         }else if( strcmp(accion, "vacia") == 0 ){
//             if( esVacia(p) ){
//               printf("\nLa pila esta vacia.\n");
//             }else printf("\nLa pila no esta vacia.\n");
//         }else if( strcmp(accion, "exit") == 0 ){
//             destruirPila(p);
//             printf("\nSaliendo...\n");
//         }else {
//             printf("\nEse comando no existe en el sistema.");
//         }
//     }
//
//     return 0;
// }
