#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "leitura_csv.h"


int main() 
{
    int quantidade;
    Produto *produtos = ler_produtos("../data/dataset1.csv", &quantidade);

    for (int i = 0; i < 11; i++) 
    {
        printf("%d | %s | %s | %.2f\n",
            produtos[i].id,
            produtos[i].nome,
            produtos[i].categoria,
            produtos[i].valor
        );
    }

    free(produtos);

    return 0;
}