#include "BucketSort.h"
#include <stdio.h>

int main(void){

  lista* enc;
  enc = gera_lista();

  arquivamentoLista(enc);
  
  printf("\n%d", enc->begin->dado);
  
  lista* lista_lida;
  lista_lida = lerArquivoArray();

  printf("\n%d", lista_lida->begin->dado);

  lista *organizada;

  int maior, menor;
  maior = maior_numEnc(enc);
  menor = menor_numEnc(enc);
  organizada = bucket_sortenc(enc, enc->num_celulas);
  printf("\n");
  arquivamentoListaOrganizada(organizada);

  return 0;
    

}