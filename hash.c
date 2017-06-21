#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"


#define TAM 50
#define NUM_NACOES 87
#define ALFABETO 3

#define DEBUG


struct dados
{
    char *nome;
    int preco;
};

void ler_arquivo(char *vet,char *ARQ, int *tamanho, lista_enc_t **listas)
{
    char BUFFER[TAM];
    int cont=0,i,ret;
    char produto[40];
    int valor;

    if (listas == NULL)
    {
        perror("Listas==NULL");
        exit(1);
    }

    FILE *fp;
    fp = fopen(ARQ,"r");
    if (fp == NULL)
    {
        perror("leitura");
        exit(1);
    }
#ifdef DEBUG
    printf("Arquivo aberto com sucesso!\n\n");
#endif
    while(!feof(fp))
    {

        fgets(BUFFER,TAM,fp);
        cont++;
    }
    cont -=2;

    *tamanho = cont;

    rewind(fp);
    fgets(BUFFER,TAM,fp);

    for(i=0; i<cont; i++)
    {

        fgets(BUFFER,TAM,fp);
        ret=sscanf(BUFFER,"%80[^,],%d",produto,&valor);

        if (ret != 2)
        {
            fprintf(stderr, "Arquivo de entrada invalido\n");
            exit(EXIT_FAILURE);
        }

#ifdef DEBUG
        //printf("Num de caracteres do nome %2d : %d",i+1,strlen(produto));
        printf("\nProduto : %s",produto);
        printf("\nValor: %d",valor);

        printf("hash index: %d\n", produto[0]-65);

#endif // DEBUG
        int hash_index = produto[0]-65;

        if (hash_index < 0 || hash_index > 26){
            fprintf(stderr, "Hash fora do escopo: %d\n", hash_index);
            fflush(stderr);
            exit(-1);
        }


        add_cabeca(listas[produto[0]-65], cria_no(cria_produto(produto,valor)));

    }
    fclose(fp);
}


produtos_t *cria_produto(char* nome,int valor)
{
#ifdef DEBUG
    printf("\n\nentrou em cria produto");
#endif // DEBU

    produtos_t *p;
    p = malloc(sizeof(produtos_t));
    if (p == NULL)
    {
        perror("malloc cria_produto : p");
        exit(1);
    }

    p->nome = malloc(strlen(nome+1));
    if (p->nome == NULL)
    {
        perror("malloc cria_pessoa : p->nome");
        exit(-1);
    }

    strncpy(p->nome,nome, strlen(nome+1));
    p->preco = valor;


    return p;
}


lista_enc_t ** cria_vetor_de_listas()
{
    int i;
    lista_enc_t ** listas = malloc(sizeof(lista_enc_t*)*26);

    for(i=0; i<26; i++)
    {
        listas[i] = cria_lista_enc();
    }

    return listas;
}


void busca_produto(lista_enc_t **listas)
{
    char produto_digitado[20];
    char *compara;
    int valor_p;
    produtos_t *produto;
    no_t *no;
    printf("Digite o produto desejado:");
    scanf("%s", produto_digitado);

    int hash_index = produto_digitado[0]-65;

    if (hash_index < 0 || hash_index > 26){
        fprintf(stderr, "Erro busca\n");
        exit(-1);
    }


    no=obtem_cabeca(listas[hash_index]);
    while(no)
    {
        produto=obtem_dado(no);
        compara=obter_nome(produto);
        if (strcmp (compara,produto_digitado) == 1 )
        {
            valor_p=obtem_preco(produto);
            printf("%s, %d,00", compara, valor_p);
            break;
        }
        no=obtem_proximo(no);
    }
    printf("Produto não cadastrado");

}



char * obter_nome(produtos_t *p)
{

    if (p == NULL)
    {
        fprintf(stderr, "get_nome: p inv'alido!\n");
        exit(EXIT_FAILURE);
    }

    return p->nome;
}

int obtem_preco(produtos_t *p)
{

    if (p == NULL)
    {
        fprintf(stderr, "get_preco: p inv'alido!\n");
        exit(EXIT_FAILURE);
    }

    return p->preco;
}
