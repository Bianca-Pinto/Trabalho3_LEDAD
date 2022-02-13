// Trabalho Pratico 3 - Heaps e Grafos
// Laboratorio de Estrutura de Dados

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "min_heap.h"
#include "grafo.h"

int main() {
    printf("------ HEAPS ------\n");
    int i;
    int vetor[] = {50,29,33,21,11,78,66,99};
    Heap* h = criar_heap();
    if (h == NULL)
        return 0;

    printf("\n===== Max-Heap ====== \n");
    // funcao constroi max-heap de vetor e imprime o elemento minimo
    max_heap_elemento_minimo(h,vetor,8);
    exibir_heap(h);
    exibir_heap(h);
    printf("\n");

    // funcao verifica se o heap e um max-heap
    verifica_heap(h,0);

    printf("\n===== Min-Heap ====== \n");
    // funcao que cria um min-heap [biblioteca min-heap somente]
    Min_heap* min_h = criar_min_heap();
    constroi_min_heap_de_vetor(min_h,vetor,8);
    exibir_min_heap(min_h);
    printf("\n\n");

    printf("\n\n------ GRAFOS ------\n");
    Grafo *t;
    t = criar_grafo(5);
    inserir_aresta(t,0,1,1);
    inserir_aresta(t,1,0,1);
    inserir_aresta(t,1,2,1);
    inserir_aresta(t,4,3,1);
    inserir_aresta(t,2,4,1);
    inserir_aresta(t,1,4,1);
    mostrar_grafo(t);
    //arestas_grafo(t);
    //orientacao_grafo(t);

    //remover_aresta(t,0,1);
    //remover_aresta(t,0,2);
    //mostrar_grafo(t);

    Grafo *g;
    int **m;
    g = criar_grafo(6);
    alocar_matriz(&m,6,6,0);
    inserir_aresta(g,0,1,1);
    inserir_aresta(g,1,4,1);
    inserir_aresta(g,2,0,1);
    inserir_aresta(g,2,5,1);
    inserir_aresta(g,4,3,1);
    inserir_aresta(g,4,5,1);
    mostrar_grafo(g);

    return 0;
}
