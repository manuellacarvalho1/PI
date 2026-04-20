#include <time.h>
#include "tempo.h"
#include "busca.h"

//essa função calcula quanto tempo leva uma busca em média
double calcular_tempo_medio(Produto* vetor, int tamanho, int*ids_busca, int qtd_buscas) {
    clock_t inicio, fim;

    //momento em que o teste começa (conta em ticks de CPU)
    inicio = clock();
    for(int i = 0; i < qtd_buscas; i++) {
        busca_sequencial(vetor, tamanho, ids_busca[i]);
    }
    //momento em que o teste termina
    fim = clock();

    //calcula a diferença entre fim e início, CLOCKS_PER_SEC converte os ticks de CPU em segundos
    return ((double)(fim - inicio) / CLOCKS_PER_SEC) / qtd_buscas;
}
