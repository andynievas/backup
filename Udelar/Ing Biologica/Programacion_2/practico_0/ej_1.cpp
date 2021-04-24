// Ejercicio 1 Promedio clase

#include <stdio.h>

float PromClase(int a, int b, int c, int d, int e ){

  int minimo = a;

  if( b <= minimo){
    minimo = b;
  }if( c <= minimo){
    minimo = c;
  }if( d <= minimo){
    minimo = d;
  }if( e <= minimo ){
    minimo = e;
  }

  printf("Minimo es: %i.\n", minimo);
  int total = a+b+c+d+e - minimo;
  printf("Total es: %i.\n", total);

  float promedio = total / 4.0;

  return promedio;
}

int main(){

  int a,b,c,d,e;
  // int calificaciones[5];

  printf("Ingrese una calificacion: ");
  scanf("%i", &a);

  printf("Ingrese una calificacion: ");
  scanf("%i", &b);

  printf("Ingrese una calificacion: ");
  scanf("%i", &c);

  printf("Ingrese una calificacion: ");
  scanf("%i", &d);

  printf("Ingrese una calificacion: ");
  scanf("%i", &e);

  // for(int i=0; i<5; i++){
  //   printf("Ingrese una calificacion: ");
  //   scanf("%i", calificaciones[i]); No funciona
  // }

  float promedio = PromClase(a, b, c, d, e);
  // float promedio = PromClase( calificaciones[0], calificaciones[1], calificaciones[2], calificaciones[3], calificaciones[4] );

  printf("El promedio es: %.2f.\n", promedio);

  return 0;
}
