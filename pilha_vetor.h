struct pilha_vetor
{
    int topo;
    int capacidade;
    int *elementos;
};

typedef struct pilha_vetor PilhaVetor;

PilhaVetor *criar_pilha(int capacidade);
void destruir_pilha(PilhaVetor *pilha);
int pilha_vazia(PilhaVetor *pilha);
int pilha_cheia(PilhaVetor *pilha);

void empilhar(PilhaVetor *pilha, int elemento);
int desempilhar(PilhaVetor *pilha);
int topo(PilhaVetor *pilha);



