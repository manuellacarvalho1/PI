#include <time.h>
#include "tempo.h"
#include "busca.h"
#include "hash.h"

//essa função calcula o tempo total de uma busca sequencial
double calcular_tempo_sequencial(Produto* vetor, int tamanho, int*ids_busca, int qtd_buscas) 
{
    clock_t inicio, fim;

    //momento em que o teste começa (conta em ticks de CPU)
    inicio = clock();
    for(int i = 0; i < qtd_buscas; i++) {
        busca_sequencial(vetor, tamanho, ids_busca[i]);
    }
    //momento em que o teste termina
    fim = clock();

    //calcula a diferença entre fim e início, CLOCKS_PER_SEC converte os ticks de CPU em segundos
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

//essa função calcula o tempo total de uma busca na tabela hash
double calcular_tempo_hash(TabelaHash *hash, int *ids_busca, int qtd_buscas)
{
    clock_t inicio, fim;
    inicio = clock();

    for (int i = 0; i < qtd_buscas; i++) {  //executa a busca mesmo quando o ID não existe
        buscar_hash(hash, ids_busca[i]);    //retorna NULL para ID < 0 
    }

    fim = clock();
    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}
