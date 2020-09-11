#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  char nascionalidade, ocupacao;
  int qnt_armas, calibre, cont = 0;



 
  while (cont != 1){
    scanf(" %c",&nascionalidade);
    

    

    if ( (nascionalidade == 'B') || (nascionalidade == 'E')){
      scanf(" %c",&ocupacao);
      scanf("%d",&qnt_armas);
      scanf("%d",&calibre);
    

      if (nascionalidade == 'B'){
        
        if (ocupacao == 'M'){
          printf("Liberado\n");
          
        }
        else if ( (ocupacao == 'T') || (ocupacao == 'O') ){
          if ( (qnt_armas == 1) && (calibre <= 22)){
            printf("Liberado\n");
          }
          
        
          else{
            printf("Barrado\n");
          }
        }
        else if (ocupacao == 'C')  {

          if (((qnt_armas == 1) && (calibre <= 38)) || ((qnt_armas == 2) && (calibre <= 38)) ){
            printf("Liberado\n");
          }
          
          else{
            printf("Barrado\n");
          }
          
        }
        
        
      
      }
      else if  (nascionalidade == 'E') {

        
        if ( ((ocupacao == 'M')) || ((ocupacao == 'T')) || ((ocupacao == 'C')) || ((ocupacao == 'O'))){
          if ((qnt_armas > 0) && (calibre > 0) ){
            printf("Barrado\n");
          }
          else{
            printf("Liberado\n");
          }
        }
      
        
      
      }
    }
    else if ((nascionalidade =='A') || (nascionalidade == 'L') || (nascionalidade == 's')){
      cont = 1;
      
    }



  }
  printf("Fim\n");
  

  return 0;
}