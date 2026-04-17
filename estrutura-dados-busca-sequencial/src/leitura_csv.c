#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

// Essa função transforma um arquivo textual (nosso dataset) 
// em uma estrutura de dados em memória (vetor de structs)


Produto* ler_produtos(char* arquivo, int* quantidade) 
{
    FILE *dataset = fopen(arquivo,"r");      //abre arquivo no modo leitura

    if (dataset == NULL) 
    {                      
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    //inicializa ponteiro pra retornar quantos registros foram carregados
    *quantidade = 0;

    //cria vetor dinâmico com capacidade inicial de 100 elementos
    int capacidade = 100;
    Produto *vetor = malloc(capacidade * sizeof(Produto));

    if (vetor == NULL) 
    {  
        printf("Erro de alocação de memória.\n");
        fclose(dataset);
        return NULL;
    }

    //buffer armazena temporariamente cada linha do arquivo antes do processamento
    char linha[256]; 

    fgets(linha, sizeof(linha), dataset); //pula o cabeçalho do dataset
    
    while (fgets(linha, sizeof(linha), dataset) != NULL) //fgets() lê uma linha inteira do arquivo
    { 
        linha[strcspn(linha, "\n")] = '\0'; //remove '\n' que vem junto da fgets()

        //separando em campos
        char *campo_id = strtok(linha, ",");   //strtok() modifica a linha, substituindo vírgula por '\0'
        char *campo_nome = strtok(NULL, ",");     
        char *campo_categoria = strtok(NULL, ",");
        char *campo_valor = strtok(NULL, ",");

        // valida se todos os campos foram corretamente extraídos
        if (campo_id == NULL || campo_nome == NULL || campo_categoria == NULL || campo_valor == NULL) {
            continue; //pula linha inválida
        }

        // convertendo tipos
        int id = atoi(campo_id);            //atoi() converte string pra int
        float valor = atof(campo_valor);    //atof() converte string pra float

        //cria objeto do tipo Produto e insere dados nele
        Produto p;
        p.id = id;
        strncpy(p.nome, campo_nome, 50);            //copia no máximo 50 caracteres para evitar overflow
        p.nome[50] = '\0';                          //adiciona o '\0' no final para garantir que a string termine corretamente
        strncpy(p.categoria, campo_categoria, 30);  //mesma lógica pra 'categoria' só que com 30 caracteres
        p.categoria[30] = '\0';
        p.valor = valor;

        if (*quantidade == capacidade) 
        {
            capacidade *= 2;  //dobra capacidade se o vetor encher
            Produto *temp = realloc(vetor, capacidade * sizeof(Produto));  //variável temporária para evitar perder
                                                                           //o ponteiro original se realloc falhar
            if (temp == NULL) 
            {
                printf("Erro ao realocar memória.\n");
                free(vetor);
                fclose(dataset);
                return NULL;
            }
            vetor = temp;
        }
        vetor[*quantidade] = p; //adiciona o produto no vetor e incrementa a quantidade
        (*quantidade)++;
    }
    fclose(dataset); //fecha arquivo
    return vetor;    //retorna nosso vetor de structs preenchido
}
