// Ejercicio 4 Es Palíndrome

#include <stdio.h>
#include <string.h>

bool EsPalindrome(char *frase){
  // char fraseAlReves = ;

  printf("%c.\n", frase);

  // while(*frase != "\0"){
  //   printf("No es el ultimo caracter.\n");
  //   frase++;
  // }

  // if( Es Palindrome? ){
  //   return true;
  // }else{
  //   return false;
  // }
  return true;
}

int main(){

  char * frase = new char;

  printf("Ingrese una frase: ");
  scanf("%s", frase);

  EsPalindrome(frase);

  return 0;
}
