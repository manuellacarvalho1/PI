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
    if (hash == NULL) {
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

// insere todos os produtos do vetor na tabela hash
void inserir_produtos(TabelaHash *hash, Produto *vetor, int quantidade)
{
    for (int i = 0; i < quantidade; i++)
    {
        int indice = funcao_hash(vetor[i].id, hash->tamanho);
        inserir_lista(&hash->tabela[indice], vetor[i]);
    }
}

// conta colisões: posições com mais de um elemento
int contar_colisoes(TabelaHash *hash)
{
    int colisoes = 0;
    for (int i = 0; i < hash->tamanho; i++)
    {
        if (hash->tabela[i] != NULL && hash->tabela[i]->proximo != NULL)
            colisoes++;
    }
    return colisoes;
}

No* criar_no(Produto produto)
{
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        return NULL;
    }

    novo->produto = produto;
    novo->proximo = NULL;

    return novo;
}

void inserir_lista(No **head, Produto produto) //insere no início = O(1)
{
    No *novo = criar_no(produto);

    if (novo == NULL) {
        return;
    }

    novo->proximo = *head;
    *head = novo;
}

No* buscar_lista(No *head, int id) //aqui a busca é sequencial O(n)
{
    No *atual = head;

    while (atual != NULL)
    {
        if (atual->produto.id == id) {
            return atual;
        }
        atual = atual->proximo;
    }

    return NULL;
}

