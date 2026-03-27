#include <stdio.h>
#include "../include/produto.h"

Produto* ler_produtos(char* arquivo, int* quantidade) {
    FILE *dataset = fopen("dataset1.csv","r");

    if (dataset == NULL) {
        printf("Erro ao abrir o arquivo.");
    }

    //fgets()

fclose(dataset); 
};
