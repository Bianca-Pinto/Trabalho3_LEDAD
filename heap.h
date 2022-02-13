// Trabalho Pratico 3 - Heaps e Grafos
// Laboratorio de Estrutura de Dados

#ifndef TRABALHOPRATICO3_HEAPS_GRAFOS_HEAP_H
#define TRABALHOPRATICO3_HEAPS_GRAFOS_HEAP_H

#include "min_heap.h"
typedef struct heap Heap;

Heap* criar_heap();
int heap_cheia(Heap *h);
int heap_vazia(Heap *h);
int esvaziar_heap(Heap* l);
int inserir_fim_heap(Heap* h, unsigned int v);
void liberar_heap(Heap** l);
int tamanho_heap(Heap *l);
int inserir_heap(Heap *l, int p);
void max_heapify(Heap *h, int p);
int remover_max(Heap *h);
int pai(Heap *h, int f);
int filho1(Heap *h, int p);
int filho2(Heap *h, int p);
int inserir(Heap *h, int v);
void exibir_heap(Heap *h);
void troca(Heap *h, int p1, int p2);
void constroi_heap_de_vetor(Heap *h, int* vetor, int n);
int elemento_minimo(Heap *h);
void imprimir_elemento_minimo(Heap *h);
void max_heap_elemento_minimo (Heap *h, int* vetor, int n);
int verifica_heap(Heap *h, int p);

#endif //TRABALHOPRATICO3_HEAPS_GRAFOS_HEAP_H
