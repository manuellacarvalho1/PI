#include <stdio.h>
#include <stdlib.h>
#include "../src/produto.h"
#include "../src/leitura_csv.h"
#include "../src/tempo.h"

void executar_experimento(char* nome_arquivo) {
    int quantidade;
    Produto* produtos = ler_produtos(nome_arquivo, &quantidade);
    
    if(!produtos) return;

    // Criar array de 1000 IDs para testar (Início, Meio, Fim, Inexistente)
    int ids[1000];
    for(int i=0; i<1000; i++) {
        if(i < 250) ids[i] = produtos[0].id;
        else if(i < 500) ids[i] = produtos[quantidade/2].id;
        else if(i < 750) ids[i] = produtos[quantidade-1].id;
        else ids[i] = -1;
    }

    // Medir o tempo
    double tempo_medio = calcular_tempo_sequencial(produtos, quantidade, ids, 1000);
    double tempo_total = tempo_medio;           // tempo total das 1000 buscas
    double tempo_medio_por_busca = tempo_medio / 1000; // tempo médio por busca

    // Salvar no CSV de resultados
    FILE* f = fopen("../results/resultados_testes.csv", "a");
    if(f) {
    fprintf(f, "sequencial -> %-18s | %-15d | %-20.10f | %-20.10f | %-10s\n",
        nome_arquivo, quantidade, tempo_total, tempo_medio_por_busca, "-");      
    fclose(f);
    }

    printf("Concluido: %s | Total: %.6f | Medio: %.10f\n", nome_arquivo, tempo_total, tempo_medio);    
    free(produtos);
}

int main() {
    // Limpa o arquivo de resultados antes de começar
    FILE* f = fopen("../results/resultados_testes.csv", "w");
    if(f) {
        fprintf(f, "%-35s | %-15s | %-20s | %-20s | %-10s\n",
        "Arquivo", "Total_Registros", "Tempo_total", "Tempo_Medio_Segundos", "Colisões");
        fclose(f);
    }

    // Rodando o teste
    executar_experimento("../data/dataset1.csv");


    return 0;
}
