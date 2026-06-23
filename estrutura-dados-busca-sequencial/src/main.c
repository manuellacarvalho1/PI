#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "leitura_csv.h"
#include "busca.h"
#include "tempo.h"
#include "hash.h"

int main() 
{   
    int quantidade;
    Produto *produtos = ler_produtos("data/dataset1.csv", &quantidade);  

    if (produtos == NULL) {
        printf("Erro ao carregar produtos.\n");
        return 1;
    }

    /* TESTANDO CARREGAMENTO
    for (int i = 0; i < quantidade; i++) {
        printf("%d | %s | %s | %.2f\n",
            produtos[i].id,
            produtos[i].nome,
            produtos[i].categoria,
            produtos[i].valor
        );
    }
    */

    printf("\n--- INICIANDO PROTOCOLO EXPERIMENTAL ---\n");

    int ids_teste[1000];
    for(int i = 0; i < 1000; i++) {
        //elementos no início
        if(i < 250) ids_teste[i] = produtos[0].id;
        //elementos no meio
        else if(i < 500) ids_teste[i] = produtos[quantidade/2].id;
        //elementos no fim
        else if(i < 750) ids_teste[i] = produtos[quantidade-1].id;
        //elementos inexistentes
        else ids_teste[i] = -1;
    }

     // ── FASE 1: busca sequencial ──────────────────────────────────
    printf("\n--- BUSCA SEQUENCIAL ---\n");

    // repetição dos testes e apresentação da média final
    double soma_seq = 0;
    for(int j = 0; j < 3; j++) {
        double t = calcular_tempo_sequencial(produtos, quantidade, ids_teste, 1000);
        printf("Rodada %d: %.10f s\n", j+1, t);
        soma_seq += t;
    }

    double tempo_total_seq = soma_seq / 3;      // média das 3 rodadas
    double tempo_medio_seq = tempo_total_seq / 1000; // média por busca

    printf("\nTempo total médio: %.10f s\n", tempo_total_seq);
    printf("Tempo médio por busca: %.10f s\n", tempo_medio_seq);

     // ── FASE 2: tabela hash ───────────────────────────────────────
    printf("\n--- TABELA HASH ---\n");

    TabelaHash *hash = criar_tabela_hash(100003);
    if (hash == NULL) {
        free(produtos);
        return 1;
    }

    inserir_produtos(hash, produtos, quantidade);

    int colisoes = contar_colisoes(hash);
    printf("Total de colisões: %d\n", colisoes);

    double soma_hash = 0;
    for(int j = 0; j < 3; j++) {
        double t = calcular_tempo_hash(hash, ids_teste, 1000);
        printf("Rodada %d: %.10f s\n", j+1, t);
        soma_hash += t;
    }

    double tempo_total_hash = soma_hash / 3;      // média das 3 rodadas
    double tempo_medio_hash = tempo_total_hash / 1000; // média por busca

    printf("Tempo total médio: %.10f s\n", tempo_total_hash);
    printf("Tempo médio por busca: %.10f s\n", tempo_medio_hash);

    // ── TABELA COMPARATIVA ────────────────────────────────────────
    printf("\n--- TABELA COMPARATIVA ---\n");

    printf("%-25s %-20s %-20s\n", "Métrica", "Busca Sequencial", "Tabela Hash");
    printf("%-25s %-20.10f %-20.10f\n", "Tempo total (s)", tempo_total_seq, tempo_total_hash);
    printf("%-25s %-20.10f %-20.10f\n", "Tempo medio (s)", tempo_medio_seq, tempo_medio_hash);
    printf("%-25s %-20s %-20s\n", "Complexidade teorica", "O(n)", "O(1)");
    printf("%-25s %-20s %-20d\n", "Colisoes", "-", colisoes);

    // libera memória
    liberar_tabela_hash(hash);
    free(produtos);
    return 0;
}