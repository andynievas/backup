#include <stdio.h>

float promClase(int a,int b,int c,int d,int e){
    float promedio = a + b + c + d + e;
    return (promedio / 5);
}

int main(){
    int a,b,c,d,e;

    printf("\nIntroduce una nota: ");
    scanf("%i", &a);
    printf("\nIntroduce una nota: ");
    scanf("%i", &b);
    printf("\nIntroduce una nota: ");
    scanf("%i", &c);
    printf("\nIntroduce una nota: ");
    scanf("%i", &d);
    printf("\nIntroduce una nota: ");
    scanf("%i", &e);

    float promedio = promClase(a,b,c,d,e);

    printf("\nPromedio: %.2f\n\n", promedio);

    return 0;
}