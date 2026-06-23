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

    double media_seq = soma_seq / 3;
    printf("\nMédia final para este: %.10f s\n", media_seq); 

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
    double media_hash = soma_hash / 3;
    printf("Média final: %.10f s\n", media_hash);

    // ── TABELA COMPARATIVA ────────────────────────────────────────
    printf("\n--- TABELA COMPARATIVA ---\n");
    printf("%-25s %-20s %-20s\n", "Métrica", "Busca Sequencial", "Tabela Hash");
    printf("%-25s %-20.10f %-20.10f\n", "Tempo médio (s)", media_seq, media_hash);
    printf("%-25s %-20s %-20s\n", "Complexidade teórica", "O(n)", "O(1)");
    printf("%-25s %-20s %-20d\n", "Colisões", "-", colisoes);

    // libera memória
    liberar_tabela_hash(hash);
    free(produtos);
    return 0;
}