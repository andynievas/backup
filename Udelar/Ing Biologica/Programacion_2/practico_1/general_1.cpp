#include <stdio.h>
#include "ejercicio_1.h"
#include <string.h>

void imprimir(Pila p);
void destruirPila(Pila p);

int main(){
    printf("\nHola esto funciona!\n\n");

    char accion[30];
    int nroComandos = 0;
    Pila p = crearPila();

    printf("Comandos aceptados:\napilar\ncima\nvacia\ndesapilar\nimprimir\n");

    while( strcmp(accion, "exit") != 0 ){
        printf("\nWaiting...\n");
        printf("%i> ",nroComandos);
        scanf("%s", accion);
        printf("Introdujiste el comando <%s>.", accion);
        nroComandos += 1;

        if( strcmp(accion, "apilar") == 0 ){

            int numero;

            printf("\nQue numero quieres apilar: ");
            scanf("%d", &numero);

            p = apilar(numero, p);
            printf("Apilado: %d\n", numero);

        }else if( strcmp(accion, "cima") == 0 ){
            printf("\nEn la cima de la pila se encuentra el dato: %d.\n", cima(p) );
        }else if( strcmp(accion, "desapilar") == 0 ){

            p = desapilar(p);

        }else if( strcmp(accion, "imprimir") == 0 ){

            printf("\nDireccion: %d.\n", p);

            imprimir(p);

        }else if( strcmp(accion, "vacia") == 0 ){
            if( esVacia(p) ){
              printf("\nLa pila esta vacia.\n");
            }else printf("\nLa pila no esta vacia.\n");
        }else if( strcmp(accion, "exit") == 0 ){
            destruirPila(p);
            printf("\nSaliendo...\n");
        }else {
            printf("\nEse comando no existe en el sistema.");
        }
    }

    return 0;
}
