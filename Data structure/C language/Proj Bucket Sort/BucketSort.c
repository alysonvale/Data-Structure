#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BucketSort.h"


TArray * criarArray(){
    int i =0, n=3000000 ,max=10000000;
    TArray * p = NULL;
    
    srand(time(NULL));
    int *v = (int*) malloc(n * sizeof(int));
    if ((p = (TArray *)malloc(sizeof(TArray))) == NULL)return NULL;
    while (i<n){
        int valor = (rand() % max);
        v[i] = valor;
        
        i++;
        p->n_elementos ++;
    }
    p->dado = v;
    return p;    
}

void arquivamentoArray(TArray *  a){
  FILE * pont_arq;
  int i = 0, n=3000000, cont = 0;
  pont_arq = fopen("Array.txt", "w");
  for (i = 0; i<n; i++){
    fprintf(pont_arq, "%d ", a->dado[i]);
    cont ++;
    if (cont == 20){
      fprintf(pont_arq, "\n%d ", a->dado[i]);
      cont = 0;
    }
  }
  fclose(pont_arq);
  printf("O arquivo foi criado com sucesso!");
  return;
  
}

void arquivamentoArrayOrdenado(TArray *  a){
  FILE * pont_arq;
  int i = 0, n=3000000, cont = 0;
  pont_arq = fopen("Array Ordenado.txt", "w");
  for (i = 0; i<n; i++){
    fprintf(pont_arq, "%d ", a->dado[i]);
    cont ++;
    if (cont == 20){
      fprintf(pont_arq, "\n%d ", a->dado[i]);
      cont = 0;
    }
  }
  fclose(pont_arq);
  printf("O arquivo foi criado com sucesso!");
  return;
  
}


void liberarArray(TArray *a)
{
    if (a != NULL)
        free(a);
}

void exibirDados(TArray * a){
    int i = 0,n=3000000;
    while (i<n){
        printf("%d\n", a->dado[i]);
        i++;
    }
    
}

int maior_elemento(int* vet, int n){
  int maior;
  maior = vet[0];
  for(int i = 1; i<n; i++){
    if(vet[i] >= maior){
      maior = vet[i];
    }
  }
  return maior;
}

int menor_elemento(int* vet, int n){
  int menor;
  menor = vet[0];
  for(int i = 1; i<n; i++){
    if(vet[i] <= menor){
      menor = vet[i];
    }
  }
  return menor;
}

/*função para ordenar cada balde individualment*/
void insertion_sort(int vet[], int n){ 
    int i, pivo, j; 
    for (i = 1; i < n; i++) { 
        pivo = vet[i]; 
        j = i - 1; 
  
        /* Move os elementos do vetor que sao maiores
        que o pivo, uma posicao afrente que suas atuais posicoes*/
        while (j >= 0 && vet[j] > pivo) { 
            vet[j + 1] = vet[j]; 
            j = j - 1; 
        } 
        vet[j + 1] = pivo; 
    } 
} 

TArray* bucket_sort(int* vetor, int tam){
  int maior, menor;
  maior = maior_elemento(vetor, tam);
  menor = menor_elemento(vetor, tam);
  int quantidade_baldes = ((maior - menor) / tamanho) +1;
  bucket* vet_baldes;
  if((vet_baldes = (bucket*) malloc(quantidade_baldes * sizeof(bucket))) == NULL){return 0;}
  int i, j;
  for(i = 0; i<quantidade_baldes; i++){
    vet_baldes[i].num_elementos = 0;
  }
  int posicao;
  int cont;
  for(i = 0; i<tam; i++){
    posicao = (vetor[i] - menor) / tamanho;
    vet_baldes[posicao].elementos[vet_baldes[posicao].num_elementos] = vetor[i];
    (vet_baldes[posicao].num_elementos)++;    
  }
  /*alocando um novo array pra ser retornado organizado*/
  TArray* sorted_vet;
  sorted_vet = (TArray*) malloc(sizeof(TArray));
  sorted_vet->dado = (int*) malloc(tam * sizeof(int));

  /*loop de implementação do algoritmo de insertion sort nos baldes, 
  e qe pega cada elemento dos baldes já prganizados, para o vetor novo*/
   posicao = 0;
  for(i = 0; i<quantidade_baldes; i++){
    insertion_sort(vet_baldes[i].elementos, vet_baldes[i].num_elementos);
    for(j = 0; j<vet_baldes[i].num_elementos; j++){
      sorted_vet->dado[posicao] = vet_baldes[i].elementos[j];
      posicao++;    
      }
  }
  free(vet_baldes);
  return sorted_vet;
}

bool verifica_organizacao(TArray* vetor){
  int i = 0;
  bool eh_organizado = true;
  while(i < (vetor->n_elementos) - 1){
    if(vetor->dado[i] < vetor->dado[i+1]){
      return !(eh_organizado);
    }
    i++;
  }
  return eh_organizado;
}

/*
FUNÇÕES PARA LISTA ENCADEADA
*/
/*CODIGOS QUE PRECISAM SER TERMIANDOS*/
bool listar(lista* l, int valor){
  no* aux;
  aux = l->end;

  if (aux == NULL){
    no* novo;
    if(( novo = (no*) malloc(sizeof(no))) == NULL) return false;
    novo->dado = valor;
    novo->prox = NULL;
    l->begin = novo;
    l->end = novo;
    l->num_celulas++;
    return true;
  }else{
    no* novo;
    if((novo = (no*) malloc(sizeof(no))) == NULL) return false;
    novo->dado = valor;
    novo->prox = NULL;
    ((l->end)->prox) = novo;
    l->end = novo;
    l->num_celulas++;
    return true;
  }
  return false;
}

lista* gera_lista(){
  lista* lista_criada;
  lista_criada = (lista*) malloc(sizeof(lista));
  int i = 0;
  lista_criada->begin = NULL;
  lista_criada->end = NULL;
  lista_criada->num_celulas = 0;
  srand(time(NULL));
  while(i<3000000){
    int valor = (rand() % 10000000);
    if((listar(lista_criada, valor)) == false)return lista_criada;
    i++;
  }
  return lista_criada;
}

void arquivamentoLista(lista *  l){
  FILE * pont_arq;
  int i = 0, n=3000000, cont = 0;
  pont_arq = fopen("Lista.txt", "w");
  no* aux;
  for (aux = l->begin; aux!= NULL; aux = aux->prox){
    fprintf(pont_arq, "%d ", aux->dado);
    cont ++;
    if (cont == 20){
      fprintf(pont_arq, "\n%d ", aux->dado);
      cont = 0;
    }
  }
  fclose(pont_arq);
  printf("O arquivo foi criado com sucesso!");
  return;
  
}


void arquivamentoListaOrganizada(lista *  l){
  FILE * pont_arq;
  int i = 0, n=3000000, cont = 0;
  pont_arq = fopen("Lista Organizada.txt", "w");
  no* aux;
  for (aux = l->begin->prox; aux!= NULL; aux = aux->prox){
    fprintf(pont_arq, "%d ", aux->dado);
    cont ++;
    if (cont == 20){
      fprintf(pont_arq, "\n%d ", aux->dado);
      cont = 0;
    }
  }
  fclose(pont_arq);
  printf("O arquivo foi criado com sucesso!");
  return;
  
}

lista* lerArquivoArray()
{

    FILE *pont_arq;
    char recebe[15];
    int i = 0, n = 3000000, cont = 0;
    int *vetor;
    vetor = (int *)malloc(n * sizeof(int));
    pont_arq = fopen("Lista.txt", "rt");
    for (i = 0; i < n; i++)
    {
        fscanf(pont_arq, "%s ", recebe);
        int valor = atoi(recebe);
        vetor[i] = valor;
        //printf("%d ",vetor[i]);
        cont++;
        if (cont == 20)
        {
            fscanf(pont_arq, "%s\n", recebe);
            int valor = atoi(recebe);
            vetor[i] = valor;

            cont = 0;
        }
    }
    lista* nova;
    nova = (lista*) malloc(sizeof(lista));
    for(i = 0; i<n; i++){
        listar(nova, vetor[i]);
    }
    fclose(pont_arq);
    printf("\nO arquivo foi lido com sucesso!");
    free(vetor);
    return nova;
}



int* vetor_de_listaenc(const lista* l){
  int *vetor = NULL;
  if((vetor = (int*) malloc((l->num_celulas) * sizeof(int))) == NULL) {return NULL;}
  int pos = 0;
  no* aux = l->begin;
  while(aux != NULL){
    vetor[pos] = aux->dado;
    pos++;
    aux = aux->prox;
  }
  return vetor;
}

int maior_numEnc(lista *l){
  int maior;
  no* aux;
  aux = l->begin;
  maior = aux->dado;
  for(aux = l->begin; aux != NULL; aux = aux->prox){
    if(aux->dado > maior){
      maior = aux->dado;
    }
  }
  return maior;
}

int menor_numEnc(lista *l){
  int menor;
  no* aux;
  aux = l->begin;
  menor = aux->dado;
  for(aux = l->begin; aux != NULL; aux = aux->prox){
    if((aux->dado) < menor){
      menor = aux->dado;
    }
  }
  return menor;
}

lista* bucket_sortenc(lista* l, int n){  
//passando como parametro:: a lista desorganizada e o numero de nós (tamanho da lista)
  
  
  int maior, menor;
  maior = maior_numEnc(l);
  menor = menor_numEnc(l);

  int num_baldes;
  num_baldes = ((maior - menor) / tamanho) + 1;

  bucket* vet_baldes;
  if((vet_baldes = (bucket*) malloc(num_baldes * sizeof(bucket))) == NULL) {return NULL;}
  
  
  no* aux;
  aux = l->begin;
  int i, j;
  int posicao;

  for(i = 0; i< num_baldes; i++){
    vet_baldes[i].num_elementos = 0;
  }

  for(aux = l->begin; aux != NULL; aux = aux->prox){
    posicao = ((aux->dado) - menor) / tamanho;
    
    if(posicao < num_baldes){vet_baldes[posicao].elementos[vet_baldes[posicao].num_elementos] = (aux->dado);
    (vet_baldes[posicao].num_elementos)++;
    }
    else{
      printf("\n%d %d %d", posicao , aux->dado, menor);
    }
  }

  lista* nova;
  if((nova = (lista*) malloc(sizeof(lista))) == NULL) return NULL;
  posicao = 0;
  aux = l->begin;
  for(i = 0; i< num_baldes; i++){
    insertion_sort(vet_baldes[i].elementos, vet_baldes[i].num_elementos);
    for(j = 0; j<vet_baldes[i].num_elementos; j++){
      listar(nova,vet_baldes[i].elementos[j]);
      }
  }
  
return nova;
}
  
