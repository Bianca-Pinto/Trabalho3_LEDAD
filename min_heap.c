// Trabalho Pratico 3 - Heaps e Grafos
// Laboratorio de Estrutura de Dados

#include "min_heap.h"
#include <stdio.h>
#include <stdlib.h>

#define N 100
#define FLAG_ERRO -1
#define VERDADEIRO 1
#define FALSO 0

struct min_heap {
    unsigned int qtde;
    unsigned int dados[N];
};

Min_heap *criar_min_heap() {
    Min_heap *h = (Min_heap*) malloc(sizeof(Min_heap));
    if(h == NULL)
        return NULL;
    h->qtde = 0;
    return h;
};

int min_heap_cheia(Min_heap *h){
    if(h == NULL)
        return FALSO;
    return h->qtde == N;
}

int min_heap_vazia(Min_heap *h){
    if(h == NULL)
        return FALSO;
    return h->qtde == 0;
}

int pai_min_heap(Min_heap *h, int f){
    if (f <= 0)
        return -1;
    else
        return (f-1)/2;
}

int filho1_min_heap(Min_heap *h, int p){
    int f1 = 2*p+1;
    if (f1 >= h->qtde)
        return -1;
    else return f1;
}

int filho2_min_heap(Min_heap *h, int p){
    int f2 = 2*p+2;
    if (f2 >= h->qtde)
        return -1;
    else return f2;
}

void troca_min_heap(Min_heap *h, int p1, int p2){
    int aux = h->dados[p1];
    h->dados[p1] = h->dados[p2];
    h->dados[p2] = aux;
}

int inserir_fim_min_heap(Min_heap* h, unsigned int v){
    if (h == NULL || min_heap_cheia(h))
        return FALSO;
    h->dados[h->qtde] = v;
    h->qtde++;
    return VERDADEIRO;
}

int inserir_min_heap(Min_heap *h, int v){
    if (!inserir_fim_min_heap(h,v))
        return 0;
    int min = h->qtde-1;
    while(h->dados[min] < h->dados[pai_min_heap(h, min)] && pai_min_heap(h, min) >= 0){
        troca_min_heap(h, pai_min_heap(h,min),min);
        min = pai_min_heap(h, min);
    }
    return 1;
}

void constroi_min_heap_de_vetor(Min_heap *h, int* vetor, int n){
    int i;
    for (i = 0; i< n; i++)
        inserir_min_heap(h, vetor[i]);
}

void min_heapify(Min_heap *h, int p){
    while (h->dados[p] > h->dados[filho1_min_heap(h,p)] || h->dados[p] > h->dados[filho2_min_heap(h,p)]){
        if (h-> dados[filho1_min_heap(h, p)] < h->dados[filho2_min_heap(h,p)] && filho2_min_heap(h,p) != -1){
            troca_min_heap(h, filho1_min_heap(h,p), p);
            p = filho1_min_heap(h,p);
        }
        else if (h->dados[filho1_min_heap(h,p)] >= h->dados[filho2_min_heap(h,p)] && filho1_min_heap(h,p) != -1){
            troca_min_heap(h,filho2_min_heap(h,p),p);
            p = filho2_min_heap(h,p);
        }
        else {
            break;
        }
    }
}

void exibir_min_heap(Min_heap *h){
    int i;
    int nvl = 1;
    for (i = 1; i <= h->qtde; i++){
        if(i == nvl){
            printf("\n");
            nvl = 2*(i);
        }
        printf("%d ", h->dados[i-1]);
    }
}
