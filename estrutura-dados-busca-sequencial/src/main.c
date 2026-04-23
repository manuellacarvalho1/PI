#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "leitura_csv.h"
#include "busca.h"
#include "tempo.h"


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

    // repetição dos testes e apresentação da média final
    double soma = 0;
    for(int j = 0; j < 3; j++) {
        double t = calcular_tempo_medio(produtos, quantidade, ids_teste, 1000);
        printf("Rodada %d: %.10f s\n", j+1, t);
        soma += t;
    }

    printf("\nMédia final para este: %.10f s\n", soma / 3); 

    return 0;
}