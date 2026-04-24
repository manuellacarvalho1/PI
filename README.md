# Projeto: Estrutura de Dados — Busca Sequencial 🚀

Este projeto faz parte do **Protocolo Experimental** para medir o desempenho de algoritmos de busca em grandes conjuntos de dados. O objetivo é analisar o tempo total de execução ao realizar múltiplas buscas em um arquivo CSV.

## 📋 Funcionalidades
* **Leitura de base de dados** em formato `.csv`.
* **Implementação de algoritmo** de Busca Sequencial.
* **Medição de tempo** de execução com precisão de milissegundos usando a biblioteca `<time.h>`.

## 📂 Estrutura do Projeto
* `src/`: Contém os arquivos fonte (`main.c`, `busca.c`, `leitura_csv.c`, `tempo.c`).
* `data/`: Arquivos de dados (datasets) usados nos testes.
* `tests/`: Scripts e arquivos auxiliares para validação.

## ⏱️ Protocolo Experimental
O código foi configurado para realizar um loop de 1000 buscas para garantir uma média estável de tempo, contornando a alta velocidade de processamento do computador.

## 🛠️ Como Compilar e Rodar
Para compilar o projeto unificando todos os módulos, utilize o GCC na raiz do projeto:

```bash
gcc src/*.c -o programa

Para executar o protocolo de testes:

./programa

