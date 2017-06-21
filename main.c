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



    listas=cria_vetor_de_listas();


   ler_arquivo(vet,ARQ, &tamanho, listas);
   busca_produto(listas);
    return 0;
}
