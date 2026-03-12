# Projeto Estrutura de Dados — Fase 1

## Objetivo

Analisar o desempenho da busca sequencial em um vetor de produtos carregado a partir de um dataset CSV.

## Estrutura do Produto

typedef struct {
    int id;
    char nome[51];
    char categoria[31];
    float valor;
} Produto;

## Funcionalidades

- Leitura de arquivo CSV
- Armazenamento em vetor dinâmico
- Busca sequencial por ID
- Medição de tempo de execução
- Protocolo experimental com 1000 execuções

## Execução

make
./programa

## Resultados

Os resultados experimentais estão disponíveis na pasta `results`.

## Integrantes

- Manuella Rodrigues de Oliveira Carvalho
- Gabriela Gomes Régis
