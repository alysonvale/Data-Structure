#include <stdio.h>
#include <stdlib.h>

int main(void) {
  float salario;
  float salario_futuro;
  int percentual;
  float aumento;

  scanf("%f",&salario);

  if (salario <= 280) {
    percentual = 20;
    salario_futuro = (salario * 1.2);
    aumento  = (salario_futuro - salario);
    printf("%.2f\n%d\n%.2f\n%.2f\n",salario,percentual,aumento,salario_futuro);
  }

  else if ((salario > 280)  && (salario <= 700)){
    percentual = 15;
    salario_futuro = (salario * 1.15);
    aumento  = (salario_futuro - salario);
    printf("%.2f\n%d\n%.2f\n%.2f\n",salario,percentual,aumento,salario_futuro);
  }

  else if ((salario > 700) && (salario < 1500)){
    percentual = 10;
    salario_futuro = (salario * 1.1);
    aumento  = (salario_futuro - salario);
    printf("%.2f\n%d\n%.2f\n%.2f\n",salario,percentual,aumento,salario_futuro);
  }

  else if (salario >= 1500){
    percentual = 5;
    salario_futuro = (salario * 1.05);
    aumento  = (salario_futuro - salario);
    printf("%.2f\n%d\n%.2f\n%.2f\n",salario,percentual,aumento,salario_futuro);
  }


  return 0;
}