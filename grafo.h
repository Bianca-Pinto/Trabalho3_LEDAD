// Trabalho Pratico 3 - Heaps e Grafos
// Laboratorio de Estrutura de Dados

#ifndef TRABALHOPRATICO3_HEAPS_GRAFOS_GRAFO_H
#define TRABALHOPRATICO3_HEAPS_GRAFOS_GRAFO_H

typedef struct grafo Grafo;
typedef struct vertice_adj Vertice;     //lista de adjacencia
typedef struct grafo_adj Grafo_Adj;     //lista de adjecencia

Grafo* criar_grafo(int v);
void alocar_matriz(int ***m, int l, int c, int val);
void inserir_aresta(Grafo *g, int v1, int v2, int peso);
void remover_aresta(Grafo *g, int v1, int v2);

Grafo_Adj* criar_grafo_adj(int v);
Vertice* novo_vertice(int v, Vertice * prox);
void inserir_aresta_adj(Grafo_Adj *g, int v1, int v2);
void mostrar_grafo(Grafo *g);
void mostrar_grafo_adj(Grafo_Adj *g);
void arestas_grafo(Grafo *g);

#endif //TRABALHOPRATICO3_HEAPS_GRAFOS_GRAFO_H
