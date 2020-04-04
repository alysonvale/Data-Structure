#include "BucketSort.h"
#include <stdio.h>

int main(void){
	


  TArray * a = criarArray();
  arquivamentoArray(a);
  
  

  TArray* array_lido;
  array_lido = lerArquivoArray();
  
  
  
  int tamanho_vetor = array_lido->n_elementos;
  printf("\n%d", maior_elemento(array_lido->dado, tamanho_vetor));
  printf("\n%d", menor_elemento(array_lido->dado, tamanho_vetor));
  printf("\n%d", (maior_elemento(array_lido->dado, tamanho_vetor) -menor_elemento(array_lido->dado, tamanho_vetor))/tamanho);
  printf("\n%d", ((array_lido->dado[87457] - (menor_elemento(array_lido->dado, tamanho_vetor))) / tamanho));
  printf("\n%d" , array_lido->dado[87457]);

  TArray* b;
  b = bucket_sort(array_lido->dado, tamanho_vetor);
  printf("\n");
  arquivamentoArrayOrdenado(b);



  //exibirDados(b);
  return 0;
    

}