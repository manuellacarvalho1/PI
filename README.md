# Projeto: Estrutura de Dados — Busca Sequencial e Tabela Hash 🚀

Este projeto faz parte do **Protocolo Experimental** para medir e comparar o desempenho de algoritmos de busca em grandes conjuntos de dados. O objetivo é analisar o tempo de execução da busca sequencial e da Tabela Hash, realizando múltiplas buscas em um arquivo CSV com aproximadamente 100.003 registros.

---

## 📋 Funcionalidades

- **Leitura de base de dados** em formato `.csv`
- **Implementação de busca sequencial** em vetor dinâmico
- **Implementação de Tabela Hash** com encadeamento exterior para tratamento de colisões
- **Medição de tempo** de execução usando a biblioteca `<time.h>`
- **Comparação experimental** entre as duas estruturas de busca
- **Exportação de resultados** para arquivo `.csv`

---

## 📁 Estrutura do Projeto

- `src/` : Contém os arquivos fonte (`main.c`, `busca.c`, `leitura_csv.c`, `tempo.c`, `hash.c`)
- `data/` : Arquivos de dados (datasets) usados nos testes
- `tests/` : Scripts de teste para busca sequencial (`testes_busca.c`) e hash (`teste_hash.c`)
- `results/` : Arquivo CSV com os resultados dos experimentos (`resultados_testes.csv`)

---

## ⏱️ Protocolo Experimental

O protocolo foi padronizado para garantir uma comparação justa entre as duas estruturas:

- 1.000 buscas consecutivas por execução
- Cada experimento repetido 3 vezes, sendo calculada a média final
- As buscas contemplam:
  - 250 elementos no início da estrutura
  - 250 elementos no meio da estrutura
  - 250 elementos no final da estrutura
  - 250 elementos inexistentes

---

## 🔧 Como Compilar e Rodar

### Programa principal (Fase 1 + Fase 2)

```bash
cd estrutura-dados-busca-sequencial
gcc src/*.c -o programa
./programa
```

### Testes individuais

**Busca Sequencial:**
```bash
cd tests
gcc testes_busca.c ../src/leitura_csv.c ../src/busca.c ../src/tempo.c ../src/hash.c -o testes_busca
./testes_busca
```

**Tabela Hash:**
```bash
cd tests
gcc teste_hash.c ../src/leitura_csv.c ../src/hash.c ../src/tempo.c ../src/busca.c -o teste_hash
./teste_hash
```

Os resultados são salvos automaticamente em `results/resultados_testes.csv`.

---

## 📊 Resultados Obtidos

| Métrica | Busca Sequencial | Tabela Hash |
|---|---|---|
| Tempo total (s) | 0.2292100000 | 0.0000080000 |
| Tempo médio por busca (s) | 0.0002292100 | 0.0000000080 |
| Complexidade teórica | O(n) | O(1) |
| Colisões | - | 0 |

---

## 👩‍💻 Autoras

- Gabriela Gomes Régis
- Manuella Rodrigues de Oliveira Carvalho

IESB — Instituto de Educação Superior de Brasília, 2025
