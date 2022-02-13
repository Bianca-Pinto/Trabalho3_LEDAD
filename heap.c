// Trabalho Pratico 3 - Heaps e Grafos
// Laboratorio de Estrutura de Dados

#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

#define N 100
#define FLAG_ERRO -1
#define VERDADEIRO 1
#define FALSO 0

int p_v;

struct heap {
    unsigned int qtde;
    unsigned int dados[N];
};

Heap *criar_heap() {
    Heap *h = (Heap*) malloc(sizeof(Heap));
    if(h == NULL)
        return NULL;
    h->qtde = 0;
    return h;
};

int esvaziar_heap(Heap* h){
    if(h == NULL)
        return FALSO;
    h->qtde = 0;
    return VERDADEIRO;
}

void liberar_heap(Heap **h){
    free(*h);
    *h = NULL;
}

int tamanho_heap(Heap* h){
    if(h == NULL)
        return FLAG_ERRO;
    return h->qtde;
}

int heap_cheia(Heap *h){
    if(h == NULL)
        return FALSO;
    return h->qtde == N;
}

int heap_vazia(Heap *h){
    if(h == NULL)
        return FALSO;
    return h->qtde == 0;
}

int inserir_fim_heap(Heap* h, unsigned int v){
    if (h == NULL || heap_cheia(h))
        return FALSO;
    h->dados[h->qtde] = v;
    h->qtde++;
    return VERDADEIRO;
}

int remover_fim(Heap *h){
    if(h == NULL || heap_vazia(h))
        return FALSO;
    h->qtde--;
    return VERDADEIRO;
}

int pai(Heap *h, int f){
    if (f <= 0)     //caso seja raiz
        return -1;
    else
        return (f-1)/2;
}

int filho1(Heap *h, int p){
    int f1 = 2*p+1;
    if (f1 >= h->qtde)  //verifica a quantidade de elementos do heap
        return -1;      //acesso a um elemento que nao existe no heap
    else return f1;
}

int filho2(Heap *h, int p){
    int f2 = 2*p+2;
    if (f2 >= h->qtde)     //verifica a quantidade de elementos do heap
        return -1;         //acesso a um elemento que nao existe no heap
    else return f2;
}

int inserir_heap(Heap *h, int v){
    if (!inserir_fim_heap(h,v))     //insercao no heap sempre no final
        return 0;
    p_v = h->qtde-1;    //posicao do elemento recem-inserido
    //verifica se o elemento novo respeita a regra colocada no heap
    while(h->dados[p_v] > h->dados[pai(h, p_v)] && pai(h, p_v) >= 0){
        troca(h, p_v, pai(h,p_v));
        p_v = pai(h, p_v);
    }
    return VERDADEIRO;
}

void troca(Heap *h, int p1, int p2){
    int aux = h->dados[p1];
    h->dados[p1] = h->dados[p2];
    h->dados[p2] = aux;
}

void exibir_heap(Heap *h){
    int i;
    int nvl = 1;        //exibe o heap por niveis da arvore
    for (i = 1; i <= h->qtde; i++){
        if(i == nvl){
            printf("\n");
            nvl = 2*(i);
        }
        printf("%d ", h->dados[i-1]);
    }
}

void constroi_heap_de_vetor(Heap *h, int* vetor, int n){
    int i;
    for (i = 0; i< n; i++)
        inserir_heap(h, vetor[i]);
}

int remover_max(Heap *h){
    h->dados[0] = h->dados[h->qtde-1];
    remover_fim(h);
    h->qtde--;
    max_heapify(h, 0);
}

void max_heapify(Heap *h, int p){
    while (h->dados[p] < h->dados[filho1(h,p)] || h->dados[p] < h->dados[filho2(h,p)]){
        if (h-> dados[filho1(h, p)] < h->dados[filho2(h,p)] && filho2(h,p) != -1){
            troca(h, p, filho2(h,p));
            p = filho2(h,p);
        }
        else if (h->dados[filho1(h,p)] >= h->dados[filho2(h,p)] && filho1(h,p) != -1){
            troca(h,p,filho1(h,p));
            p = filho1(h,p);
        }
        else {
            break;
        }
    }
}

// funcao que recebe um heap e retorna o valor do menor elemento
int elemento_minimo(Heap *h){
    int i;
    int menor, nvl = 1;        //exibe o heap por niveis da arvore
    menor = h->dados[0];
    for (i = 1; i <= h->qtde; i++){
        if(i == nvl){
            nvl = 2*(i);
        }
        if(h->dados[i-1] < menor){
            menor = h->dados[i-1];
        }
    }
    return menor;
}

void imprimir_elemento_minimo(Heap *h){
    printf("\nO menor elemento do heap e %d \n", elemento_minimo(h));
}

void max_heap_elemento_minimo (Heap *h, int* vetor, int n){
    constroi_heap_de_vetor(h,vetor,n);
    imprimir_elemento_minimo(h);
}

int verifica_heap(Heap *h, int p){
    int i, teste;
    for (i = 1; i <= h->qtde; i++) {
        if (h->dados[p] >= (h->dados[filho1(h, p)] && h->dados[filho2(h, p)]))
            teste = 1;
        else
            teste = 0;
    }
    if (teste == 1){
        printf("\nA arvore e um max-heap\n");
        return 1;
    }
    else {
        printf("\nA arvore nao e um max-heap\n");
        return 0;
    }
}