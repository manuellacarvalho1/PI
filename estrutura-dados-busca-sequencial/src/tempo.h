#ifndef TEMPO_H
#define TEMPO_H

#include "produto.h"
#include "busca.h"
#include "hash.h"

double calcular_tempo_sequencial(Produto* vetor, int tamanho, int*ids_busca, int qtd_buscas);
double calcular_tempo_hash(TabelaHash *hash, int *ids_busca, int qtd_buscas);

#endif
