#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha_vetor.h"

PilhaVetor *criar_pilha(int capacidade)
{
    PilhaVetor *pilha = (PilhaVetor *)malloc(sizeof(PilhaVetor));
    pilha->topo = -1;
    pilha->capacidade = capacidade;
    pilha->elementos = (int *)malloc(capacidade * sizeof(int));
    return pilha;
}

void destruir_pilha(PilhaVetor *pilha)
{
    free(pilha->elementos);
    free(pilha);
}

int pilha_vazia(PilhaVetor *pilha)
{
    return pilha->topo == -1;
}

int pilha_cheia(PilhaVetor *pilha)
{
    return pilha->topo == pilha->capacidade - 1;
}

void empilhar(PilhaVetor *pilha, int elemento)
{
    if (pilha_cheia(pilha))
    {
        printf("Pilha cheia\n");
        return;
    }
    pilha->elementos[++pilha->topo] = elemento;
}

int desempilhar(PilhaVetor *pilha)
{
    if (pilha_vazia(pilha))
    {
        printf("Pilha vazia\n");
        return -1;
    }
    return pilha->elementos[pilha->topo--];
}

int topo(PilhaVetor *pilha)
{
    if (pilha_vazia(pilha))
    {
        printf("Pilha vazia\n");
        return -1;
    }
    return pilha->elementos[pilha->topo];
}

int main()
{
    PilhaVetor *pilha = criar_pilha(5);
    empilhar(pilha, 1);
    empilhar(pilha, 2);
    empilhar(pilha, 3);
    empilhar(pilha, 4);
    empilhar(pilha, 5);
    empilhar(pilha, 6);
    printf("Topo: %d\n", topo(pilha));
    printf("Desempilhando: %d\n", desempilhar(pilha));
    printf("Topo: %d\n", topo(pilha));
    destruir_pilha(pilha);
    return 0;
}






