#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "hash.h"
char vet[4]={'a','b','c','d'};
const char ARQ[] = "mercadoria.txt";


int main()
{
    lista_enc_t **listas;
     int tamanho=0;
     int x=1;



    listas=cria_vetor_de_listas();


   ler_arquivo(vet,ARQ, &tamanho, listas);
   while(x==1){
        busca_produto(listas);
        printf("\nNova busca tecle 1:\n");
        scanf("%d",&x);
        system("cls");
   }
    libera_listas(listas);
    return 0;
}
