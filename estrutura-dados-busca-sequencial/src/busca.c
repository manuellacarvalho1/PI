#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

//essa função busca produtos sequencialmente a partir do ID e retorna a posição

int busca_sequencial(Produto* vetor, int tamanho, int id) //O(n)
{
    for(int i = 0; i < tamanho; i++) 
    {
        if(vetor[i].id == id)  //compara id atual com o buscado
        return i; //achou
    }
    return -1; //não achou
}
