#include <stdio.h>
#include <stdlib.h>
#include "../src/produto.h"
#include "../src/leitura_csv.h"
#include "../src/hash.h"
#include "../src/tempo.h"

void executar_experimento_hash(char* nome_arquivo) {
    int quantidade;
    Produto* produtos = ler_produtos(nome_arquivo, &quantidade);

    if (!produtos) return;

    // Criar array de 1000 IDs para testar (Inicio, Meio, Fim, Inexistente)
    int ids[1000];
    for(int i=0; i<1000; i++) {
        if(i < 250) ids[i] = produtos[0].id;
        else if(i < 500) ids[i] = produtos[quantidade/2].id;
        else if(i < 750) ids[i] = produtos[quantidade-1].id;
        else ids[i] = -1;
    }

    // Criar e popular tabela hash
    TabelaHash *hash = criar_tabela_hash(100003);
    if (hash == NULL) {
        free(produtos);
        return;
    }
    inserir_produtos(hash, produtos, quantidade);

    int colisoes = contar_colisoes(hash);

    // Medir o tempo
    double tempo_medio = calcular_tempo_hash(hash, ids, 1000);
    double tempo_total = tempo_medio * 1000;

    // Salvar no CSV de resultados
    FILE* f = fopen("../results/resultados_testes.csv", "a");
    if(f) {
        fseek(f, 0, SEEK_END);
        long tamanho = ftell(f);
        if (tamanho == 0) {
            fprintf(f, "Arquivo; Total_Registros; Tempo_total; Tempo_Medio_Segundos\n");
        }
        fprintf(f, "hash -> %-27s | %-15d | %-20.10f | %-20.10f | %-10d\n", 
        nome_arquivo, quantidade, tempo_total, tempo_medio, colisoes);
        fclose(f);
    }

    printf("Concluido: %s | Total: %.6f | Medio: %.10f | Colisoes: %d\n", 
           nome_arquivo, tempo_total, tempo_medio, colisoes);

    liberar_tabela_hash(hash);
    free(produtos);
}

int main() {
    executar_experimento_hash("../data/dataset1.csv");
    return 0;
}