// Trabalho Pratico 3 - Heaps e Grafos
// Laboratorio de Estrutura de Dados

#ifndef TRABALHOPRATICO3_HEAPS_GRAFOS_MIN_HEAP_H
#define TRABALHOPRATICO3_HEAPS_GRAFOS_MIN_HEAP_H

#include "heap.h"

typedef struct min_heap Min_heap;

Min_heap *criar_min_heap();
int min_heap_cheia(Min_heap *h);
int min_heap_vazia(Min_heap *h);
int pai_min_heap(Min_heap *h, int f);
int filho1_min_heap(Min_heap *h, int p);
int filho2_min_heap(Min_heap *h, int p);
void troca_min_heap(Min_heap *h, int p1, int p2);
int inserir_fim_min_heap(Min_heap* h, unsigned int v);
int inserir_min_heap(Min_heap *h, int v);
void constroi_min_heap_de_vetor(Min_heap *h, int* vetor, int n);
void min_heapify(Min_heap *h, int p);
void exibir_min_heap(Min_heap *h);

#endif //TRABALHOPRATICO3_HEAPS_GRAFOS_MIN_HEAP_H
