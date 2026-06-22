#include <time.h>
#include "tempo_hash.h"

double calcular_tempo_hash(TabelaHash *hash, int *ids_busca, int qtd_buscas)
{
    clock_t inicio, fim;
    inicio = clock();
    for (int i = 0; i < qtd_buscas; i++)
    {
        if (ids_busca[i] < 0) continue;
        int indice = funcao_hash(ids_busca[i], hash->tamanho);
        buscar_lista(hash->tabela[indice], ids_busca[i]);
    }
    fim = clock();
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}