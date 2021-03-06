#ifndef LISTA_ENC_H_INCLUDED
#define LISTA_ENC_H_INCLUDED

#include "no.h"

typedef struct listas_enc lista_enc_t;

lista_enc_t *cria_lista_enc(void);
void add_cauda(lista_enc_t *lista, no_t* elemento);
void add_cabeca(lista_enc_t *lista, no_t* elemento);
void *rmv_cabeca(lista_enc_t *lista);

void imprimir_lista(lista_enc_t *lista);
no_t *obtem_cabeca(lista_enc_t *lista);

void *contem_dado(lista_enc_t *lista, void *dado);

no_t * remove_elem(lista_enc_t *lista, int index);

#endif // LISTA_ENC_H_INCLUDED
