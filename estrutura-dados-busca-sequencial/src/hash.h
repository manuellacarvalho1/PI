#ifndef HASH_H
#define HASH_H

#include "produto.h"

typedef struct No {  //lista encadeada 
    Produto produto;
    struct No *proximo;
} No;


typedef struct {    //struct pra tabela hash
    int tamanho;
    No **tabela;
} TabelaHash;


TabelaHash* criar_tabela_hash(int tamanho); //tamanho deve ser igual à quantidade de registros do dataset 1
void liberar_tabela_hash(TabelaHash *hash);
int funcao_hash(int id, int tamanho);
void inserir_produtos(TabelaHash *hash, Produto *vetor, int quantidade);
int contar_colisoes(TabelaHash *hash);

//head = ponteiro pro primeiro elemento da lista
No* criar_no(Produto produto);
void inserir_lista(No **head, Produto produto);
No* buscar_lista(No *head, int id);
No* buscar_hash(TabelaHash *hash, int id);

#endif