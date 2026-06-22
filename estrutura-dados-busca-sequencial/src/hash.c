#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

TabelaHash* criar_tabela_hash(int tamanho) //criar com tamanho = 100003
{
    TabelaHash *hash = malloc(sizeof(TabelaHash));

    if (hash == NULL) {
        printf("Erro ao alocar tabela hash.\n");
        return NULL;
    }

    hash->tamanho = tamanho;

    hash->tabela = malloc(tamanho * sizeof(No*));

    if (hash->tabela == NULL) {
        printf("Erro ao alocar vetor da tabela hash.\n");
        free(hash);
        return NULL;
    }

    //inicializando os espaços da tabela com NULL
    for (int i = 0; i < tamanho; i++) {
        hash->tabela[i] = NULL;
    }

    return hash;
}

/* Nosso hash => Resto da Divisão Simples

            h(x) = x % m;

x = id do registro
m = qtde de registros do dataset = 100003 */

int funcao_hash(int id, int tamanho)
{
    return id % tamanho; // tamanho é 100003 !!!!!!
}


void liberar_tabela_hash(TabelaHash *hash)
{
    if (hash == NULL)
    {
        return;
    }

    for (int i = 0; i < hash->tamanho; i++)
    {
        No *atual = hash->tabela[i];

        while (atual != NULL)
        {
            No *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }

    free(hash->tabela);
    free(hash);
}