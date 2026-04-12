#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "leitura_csv.h"
#include "busca.h"


int main() 
{   
    //testando ler_produtos() ->  ok
    
    int quantidade;
    Produto *produtos = ler_produtos("../data/dataset1.csv", &quantidade);  

    if (produtos == NULL) {
        printf("Erro ao carregar produtos.\n");
        return 1;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("%d | %s | %s | %.2f\n",
            produtos[i].id,
            produtos[i].nome,
            produtos[i].categoria,
            produtos[i].valor
        );
    }

    //testando busca_sequencial() com alguns casos

    int ids_teste[10] = {
        produtos[0].id,                  // início
        produtos[quantidade/4].id,       // 25%
        produtos[quantidade/2].id,       // meio
        produtos[(3*quantidade)/4].id,   // 75%
        produtos[quantidade-1].id,       // final
        999999,                          // inexistente
        -1,                              // inexistente
        12345,                           // talvez exista
        55555,                           // talvez exista
        888888                           // inexistente
    };

    // loop de teste
    for (int i = 0; i < 10; i++) 
    {
        int id_busca = ids_teste[i];
        int pos = busca_sequencial(produtos, quantidade, id_busca);

        if (pos != -1) {
            printf("ID %d encontrado na posição %d (%s)\n", id_busca, pos, produtos[pos].nome);
        } else {
            printf("ID %d não encontrado\n", id_busca);
        }
    }

    return 0;
}