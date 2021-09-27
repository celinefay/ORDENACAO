#include "bolha.h"
#include "countingsort.h"
#include "heapsort.h"
#include "insercao.h"
#include "mergesort.h"
#include "quicksort.h"
#include "selecao.h"
#include "shellsort.h"
#include "geracao.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/resource.h>
struct rusage usage;

//=============================================================================
void teste(int n, char ordem){

   //Delcaracao de variaveis
    //int n = (argc < 2) ? 10000 : atoi(argv[1]);
    int  *array = (int*) malloc(n*sizeof(int));

    if(array == NULL){
      printf("NAO TEM MEMORIA\n");
      exit(0);
    }else{
      printf("TEM MEMORIA\n");
    }
    
    // VARIAVEIS PARA CALCULAR O TEMPO
    clock_t inicio, fim;
    double total;


    //Geracao do conjunto a ser ordenado
    switch(ordem){
      case 'C': crescente(array, n);
      break;
      case 'D': decrescente(array, n);
      break;
      case 'A':  aleatorio(array, n);
      break;
      default: aleatorio(array, n);
    }
	 
    //Mostrar o conjunto a ser ordenado
	 //mostrar(array, n);
		

    //Execucao do algoritmo de ordenacao
	 inicio = clock();
    //bolha(array, n);
    //countingsort(array, n);
    //heapsort(array, n);
    //insercao(array, n);
    //mergesort(array, n);
    //quicksort(array, n);
    //selecao(array, n);
    shellsort(array, n);
	  fim = clock();
    getrusage(RUSAGE_SELF, &usage);
    total = ((fim - inicio) / (double)CLOCKS_PER_SEC);    
  

    //Mostrar o conjunto ordenado, tempo de execucao e status da ordenacao
	 //algoritmo.mostrar(array, n);
	 printf("N: % d T: - %f s - O: %c.\n", n,total, ordem);
	
	 
	 printf("Memory: %d, %f\n",n, usage.ru_maxrss/1024.0);
	 //printf("isOrdenado: %s\n", isOrdenado(array, n) ? "true" : "false");
    //Desalocar o espaco de memoria do array
    free(array);

}





//=============================================================================




int main(int argc, char **argv) {

    for(int i=2000; i<=128000; i=i*2){

   // teste(i, 'C');
  //  teste(i, 'D');
    teste(i, 'A');
    }

    return 0;
}
