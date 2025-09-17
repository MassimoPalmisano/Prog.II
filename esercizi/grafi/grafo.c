#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

graph* create_graph(int n) {
    graph* G = (graph*)malloc(sizeof(graph));
    if (G == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    if (n < 0) {
        fprintf(stderr, "Graph cannot have negative numbers of nodes\n");
        exit(EXIT_FAILURE);
    }
    G->dim = n;
    if (n > 0){
        G->nodes = (adj_list*)malloc(n * sizeof(adj_list));
        if (G->nodes == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < n; i++) {
            G->nodes[i] = NULL;
        }
    } else {
        G->nodes = NULL;
    }
    return G;
}

void free_graph(graph* G) {
    if (!G) return;
    for (int i = 0; i < G->dim; ++i) {
        adj_node* curr = G->nodes[i];
        while (curr) {
            adj_node* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(G->nodes);
    free(G);
}

int graph_get_dim(graph* g) {
    return g->dim;
}

/* Funzione che aggiunge l'arco orientato (u,v) alla lista di adiacenza del
 * nodo u (aggiunge in testa alla lista). L'arco ha peso w. */
void graph_add_arc_w(graph* G, int u, int v, float w) {
    adj_node* t = (adj_node*)malloc(sizeof(adj_node));
    if (t == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    t->node = v - 1;
    t->weight = w;
    t->next = G->nodes[u - 1];
    G->nodes[u - 1] = t;
}

/* Funzione che aggiunge l'arco orientato (u,v) alla lista di adiacenza del
 * nodo u (aggiunge in testa alla lista). */
void graph_add_arc(graph* G, int u, int v) {
    adj_node* t = (adj_node*)malloc(sizeof(adj_node));
    if (t == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    t->node = v - 1;
    t->weight = 0;
    t->next = G->nodes[u - 1];
    G->nodes[u - 1] = t;
}

/* Funzione che aggiunge un edge pesato (u,v) alla lista di adiacenza del
 * nodo u (aggiunge in testa alla lista). */
void graph_add_edge_w(graph* g, int u, int v, float w) {
    graph_add_arc_w(g, u, v, w);
    graph_add_arc_w(g, v, u, w);
}

/* Funzione che aggiunge un edge non pesato (u,v) alla lista di adiacenza del
 * nodo u (aggiunge in testa alla lista). */
void graph_add_edge(graph* g, int u, int v) {
    graph_add_arc(g, u, v);
    graph_add_arc(g, v, u);
}

adj_list graph_get_adjlist(graph* g, int u) {
    return g->nodes[u - 1];
}

int get_adjnode(adj_node* l) {
    return (l->node + 1);
}

adj_list get_nextadj(adj_list l) {
    return l->next;
}

float get_adjweight(adj_node* l) {
    return (l->weight);
}
