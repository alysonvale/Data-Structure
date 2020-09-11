#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int a, b, c, pedro;
  int oponente;
  int luta;
  int porcentagem;
  char tipo[3];
  scanf("%d %d %d %d",&a,&b,&c,&pedro);
  scanf("%s",tipo);
  
  porcentagem = pedro - (pedro * 0.70);
  
  oponente = (a + b + c);

  if ((strcmp(tipo,"C") == 0) || (strcmp(tipo,"c") == 0)){
  
    
    
      while ((pedro != 0) && (oponente != 0)){
        pedro = pedro - 45;
        oponente = oponente - 120;
         
        if (pedro <= 0){
          break;
        }
        if (oponente <= 0){
          break;
        }
        if ((oponente <= 0 ) && (pedro > 0)){
          break;
        }
        if ((oponente > 0 ) && (pedro <= 0)){
          break;
        }


      }

     
    }

  else if ((strcmp(tipo,"V") == 0) || (strcmp(tipo,"v") == 0)){
    
      
      while ((pedro != 0) && (oponente != 0)){
        pedro = pedro - 60;
      oponente = oponente - 120 ;
         
        if (pedro <= 0){
          break;
        }
        if (oponente <= 0){
          break;
        }
        if ((oponente <= 0 ) && (pedro > 0)){
          break;
        }
        if ((oponente > 0 ) && (pedro <= 0)){
          break;
        }


      }

  
  }
  
  
  if (pedro > porcentagem){
    printf("Eba! Pedro sobreviveu");
  }
  else if (pedro <= porcentagem){
    printf("Que pena... Era um jovem tao promissor");
  }
  

  return 0;
}