#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
  float valor;
  scanf ("%f",&valor);
    if (valor == 7){
      printf("Neutra");
    }
    else if (valor > 7){
      printf("Basica");
    }
    else if (valor < 7){
      printf("Acida");
    }
    
  return 0;
}