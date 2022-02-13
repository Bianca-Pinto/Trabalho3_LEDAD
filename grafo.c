// Trabalho Pratico 3 - Heaps e Grafos
// Laboratorio de Estrutura de Dados

#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>

struct grafo {
    int V;          //quantidade de vertices
    int A;          //quantidade de arestas
    int **adj;      //matriz de adjacencia
};

struct grafo_adj {
    int V;
    int A;
    Vertice **adj;      //ponteiro para lista encadeada de vertices
};

struct vertice_adj {
    int v;              //vertice
    Vertice *prox;      //ponteiro para o proximo elemento
};

Grafo* criar_grafo(int v){
    Grafo *g = (Grafo*)malloc(sizeof(Grafo));
    g->V = v;
    g->A = 0;
    alocar_matriz(&(g->adj), v, v, 0);
    return g;
}

// linhas, colunas, valor inicial
void alocar_matriz(int ***m, int l, int c, int val){
    int **maux = malloc(l*sizeof(int *));
    int i, j;
    for(i = 0; i < l; i++)
        maux[i] = malloc(c*sizeof(int));
    for(i = 0; i < l; i++)
        for(j = 0; j < c; j++)
            maux[i][j] = val;
    *m = maux;
}

void inserir_aresta(Grafo *g, int v1, int v2, int peso){
    if(g->adj[v1][v2] == 0){
        g->adj[v1][v2] = peso;      // peso = 1 -> sem peso
        g->A++;
    }
}

void remover_aresta(Grafo *g, int v1, int v2){
    if(g->adj[v1][v2] != 0){
        g->adj[v1][v2] = 0;     // valor = 0, aresta nao existe
        g->A--;
    }
}

Grafo_Adj* criar_grafo_adj(int v){
    Grafo_Adj *g = malloc(sizeof(Grafo_Adj));
    g->V = v;
    g->A = 0;
    g->adj = malloc(v*sizeof(Vertice*));    //n listas encadeadas
    int i;
    for(i = 0; i < v; i++)
        g->adj[i] = NULL;   //inicializa os ponteiros como NULL
    return g;
}

Vertice* novo_vertice(int v, Vertice *prox){
    Vertice *a = malloc(sizeof(Vertice));
    a->v = v;
    a->prox = prox;
    return a;
}

void inserir_aresta_adj(Grafo_Adj *g, int v1, int v2){
    Vertice * aux;
    for(aux = g->adj[v1]; aux != NULL; aux = aux->prox){
        if(aux->v == v2)
            return;
    }
    g->adj[v1] = novo_vertice(v2, g->adj[v1]);
    g->A++;
}

void mostrar_grafo(Grafo *g){
    printf("\nGRAFO DE MATRIZ DE ADJACENCIA:\n");
    int i, j;
    for (i = 0; i < g->V; i++){
        printf("%d: ", i);
        for(j = 0; j < g->V; j++)
            if(g->adj[i][j] != 0)
                printf("%d ", j);
        printf("\n");
    }
    printf("\n");
    for(i = 0; i < g->V; i++){
        for(j = 0; j < g->V; j++)
            printf("%d ",g->adj[i][j]);
        printf("\n");
    }
}

void mostrar_grafo_adj(Grafo_Adj *g){
    printf("\nGRAFO DE LISTA DE ADJACENCIA:\n");
    int i, j=0;
    Vertice *aux;
    for(i = 0; i < g->V; i++){
        printf("%d: ", i);
        for (aux = g->adj[i]; aux != NULL; aux = aux->prox){
            printf(" %d ", aux->v);
            j++;
        }
        printf("\n");
    }
    printf("\n");
}

void arestas_grafo(Grafo *g){
    printf("Quantidade de arestas do grafo: %d ", g->A);
}