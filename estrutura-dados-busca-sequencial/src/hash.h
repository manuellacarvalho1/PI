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

//funções

TabelaHash* criar_tabela_hash(int tamanho); //tamanho deve ser igual à quantidade de registros do dataset 1
void liberar_tabela_hash(TabelaHash *hash);
int funcao_hash(int id, int tamanho);

#endif