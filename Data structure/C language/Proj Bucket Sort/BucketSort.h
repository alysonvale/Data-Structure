
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#define tamanho 5000 // tamanho do do balde

/*
ESTRUTURAS DECLARADAS DO VETOR DOS INTEIROS, E DO BALDE 
QUE SERÁ USADO NO BUCKET SORT
*/

typedef struct bucket{
  int num_elementos;
  int elementos[tamanho];
}bucket;

typedef struct array{
    int  *dado;
    int n_elementos;
}TArray;

/*
*/
typedef struct no{
  int dado;
  struct no* prox;
}no;

typedef struct lista{
  no* begin;
  no* end;
  int num_celulas;
}lista;
/*
*/

TArray * criarArray();

void arquivamentoArray(TArray *  a);
void arquivamentoArrayOrdenado(TArray *  a);

void liberarArray(TArray *a);

void exibirDados(TArray * a);

int maior_elemento(int* vet, int n);

int menor_elemento(int* vet, int n);

void insertionSort(int vetr[], int n);

TArray* bucket_sort(int* vetor, int tam);

bool verifica_organizacao(TArray* vetor);


/*
FUNÇÕES QUE OPERARÃO COM LISTAS ENDADEADAS
*/



bool listar(lista *l, int elemento);

lista* gera_lista();

void arquivamentoLista(lista *  l);

void arquivamentoListaOrganizada(lista *  l);

lista* lerArquivoArray();

int maior_numEnc(lista *l);

int menor_numEnc(lista *l);

int* vetor_de_listaenc(const lista* l);

lista* bucket_sortenc(lista* l, int n);

