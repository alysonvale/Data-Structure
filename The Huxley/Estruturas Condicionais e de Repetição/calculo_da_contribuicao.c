#include <stdio.h>
#include <stdlib.h>

int main(void) {
  float salario_base;
  float desconto;

  scanf("%f",&salario_base);

  
  if (salario_base <= 1751.81){
    desconto = salario_base - (salario_base * 0.92);
    printf("Desconto do INSS: R$ %f",desconto);
  }

  else if ((salario_base >= 1751.82 ) && (salario_base <= 2919.72)){
    desconto = salario_base - (salario_base * 0.91);
    printf("Desconto do INSS: R$ %f",desconto);
  }
  else if ((salario_base >= 2919.73) && (salario_base <= 5839.45)){
    desconto = salario_base - (salario_base * 0.89);
    printf("Desconto do INSS: R$ %f",desconto);
  }
  else if (salario_base >= 5839.46){
    desconto = 5839.45 - 5197.1105;
    printf("Desconto do INSS: R$ %f",desconto);
  }

  return 0;
}