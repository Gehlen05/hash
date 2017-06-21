#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"
#include "no.h"

#define DEBUG

struct listas_enc {
    no_t *cabeca;
    no_t *cauda;
    int tamanho;
};

//cria uma lista vazia
lista_enc_t *cria_lista_enc (void) {
    lista_enc_t *p = malloc(sizeof(lista_enc_t));

    if (p == NULL){
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}

void add_cauda(lista_enc_t *lista, no_t* elemento)
{
    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

   //lista vazia
   if (lista->tamanho == 0)
   {
        #ifdef DEBUG
        printf("add_cauda: add primeiro elemento: %p\n", elemento);
        #endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desliga_no(elemento);
   }
   else {
        // Remove qualquer ligacao antiga
        desliga_no(elemento);
        // Liga cauda da lista com novo elemento
        liga_nos(lista->cauda, elemento);

        lista->cauda = elemento;
        lista->tamanho++;
   }
   #ifdef DEBUG
   printf("Adicionado %p --- tamanho da lista: %d\n", elemento, lista->tamanho);
   #endif // DEBUG
}

void add_cabeca(lista_enc_t *lista, no_t* elemento)
{
    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cabeca: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

   //lista vazia
   if (lista->tamanho == 0)
   {
        #ifdef DEBUG
        printf("add_cabeca: add primeiro elemento: %p\n", elemento);
        #endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desliga_no(elemento);
   }
   else {
        // Remove qualquer ligacao antiga
        desliga_no(elemento);
        // Liga cabeca da lista com novo elemento
        liga_nos(elemento, lista->cabeca);

        lista->cabeca = elemento;
        lista->tamanho++;
   }
    #ifdef DEBUG
   printf("Adicionado %p --- tamanho da lista: %d\n", elemento, lista->tamanho);
   #endif // DEBUG
}

void *rmv_cabeca(lista_enc_t *lista)
{
    void *dado;
    no_t *elemento;
    if (lista == NULL){
        fprintf(stderr,"rmv_cabeca: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }
   //lista vazia
   if (lista->tamanho == 0)
   {
        #ifdef DEBUG
        printf("rmv_cabeca: lista vazia, impossivel remover elemento\n");
        #endif // DEBUG
   }
   else {
        // Remove qualquer ligacao antiga
        elemento = lista->cabeca;
        lista->cabeca = obtem_proximo(elemento);
        lista->tamanho--;
   }
   dado = obtem_dado(lista);
   free(elemento);
    #ifdef DEBUG
   printf("Removido %p --- tamanho: %d\n", lista->cabeca, lista->tamanho);
   #endif // DEBUG
   return dado;
}

void imprimir_lista(lista_enc_t *lista){

    int j = 1;

    no_t *e = lista->cabeca;

    while(e != NULL){


        void *dado = obtem_dado(e);


        printf("Dado do elemento %d : %p\n ", j, dado);
        j++;
        e = obtem_proximo(e);

    }
}

void *contem_dado(lista_enc_t *lista, void *dado_search){

    no_t *dado_lista = lista->cabeca;

    void *dado_found;

    while(dado_lista!=NULL){

        dado_found = obtem_dado(dado_lista);
        if(dado_found == dado_search){

            printf("Dado procurado = %p --- Dado encontrado = %p\n", dado_search, dado_found);
            break;

        }

        else

            dado_lista = obtem_proximo(dado_lista);
    }

    if(dado_lista==NULL)
        return NULL;
}

no_t *obtem_cabeca(lista_enc_t *lista){

    if (lista == NULL){
        fprintf(stderr,"obtem_cabeca: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return lista->cabeca;
}
