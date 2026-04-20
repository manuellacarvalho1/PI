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

    // Medir o tempo médio (sua função!)
    double tempo = calcular_tempo_medio(produtos, quantidade, ids, 1000);

    // Salvar no CSV de resultados
    FILE* f = fopen("../results/resultados_testes.csv", "a"); // "a" de append (adicionar)
    if(f) {
        fprintf(f, "%s; %d; %.10f\n", nome_arquivo, quantidade, tempo);
        fclose(f);
    }

    printf("Concluido: %s | Tempo: %.10f\n", nome_arquivo, tempo);
    free(produtos);
}

int main() {
    // Limpa o arquivo de resultados antes de começar
    FILE* f = fopen("../results/resultados_testes.csv", "w");
    if(f) {
        fprintf(f, "Arquivo; Total_Registros; Tempo_Medio_Segundos\n");
        fclose(f);
    }

    // Roda para todos os datasets
    executar_experimento("../data/dataset1.csv");
    executar_experimento("../data/dataset2.csv");
    executar_experimento("../data/dataset3.csv");
    executar_experimento("../data/dataset4.csv");

    return 0;
}
