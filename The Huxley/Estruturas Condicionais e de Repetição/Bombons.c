#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int avela;
    int caramelo;
    int passas;
    float total;
    int qnt1;
    int qnt2;
    int qnt3;
    int produto;

    scanf("%d",&avela);
    scanf("%d",&caramelo);
    scanf("%d",&passas);
    scanf("%d",&qnt1);
    scanf("%d",&qnt2);
    scanf("%d",&qnt3);
    total = ((avela * qnt1) + (caramelo * qnt2) + (passas * qnt3));

    printf("Valor: R$%.2f",total);

  return 0;

}