#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include "lista_enc.h"
#include "no.h"
typedef struct dados produtos_t;

produtos_t *cria_produto(char* nome,int valor);
void cria_listas(int indice, int valor, char *produto);
void ler_arquivo(char *vet,char *ARQ, int *tamanho, lista_enc_t **listas);
lista_enc_t ** cria_vetor_de_listas();
char * obter_nome(produtos_t *p);
int obtem_preco(produtos_t *p);
void busca_produto(lista_enc_t **listas);
#endif // HASH_H_INCLUDED
