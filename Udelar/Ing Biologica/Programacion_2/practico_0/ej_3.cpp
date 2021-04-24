// Ejercicio 3 Ocurrencias

#include <stdio.h>

int Ocurrencias(char* frase, int largo, char letra){

  int totalOcurrencias = 0;

  for(int i=0; i<largo; i++){
    // printf("%c", frase[i]);
    if( letra == frase[i] ){
      totalOcurrencias++;
    }
  }

  return totalOcurrencias;
}

int main(){

  char frase[100];
  char letra;

  // printf("Largo de la frase: %d.\n", strlength(frase) );

  printf("Ingresa una letra a buscar: ");
  scanf("%c", &letra);

  printf("Ingresa una frase: ");
  scanf("%s", frase);
  fflush(stdin);

  printf("\nTotal Ocurrencias de la letra '%c' en la frase '%s': %i.\n", letra, frase, Ocurrencias(frase, 20, letra) );

  return 0;
}
