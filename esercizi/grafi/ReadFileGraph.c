#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"
#include "grafo.c"

int main(){
    FILE *fp;
    int u, v;

    graph* G = create_graph(7);

    fp = fopen("graph1", "r");
    if (fp == NULL) {
        perror("Errore nell'aprire il file");
        return 1;
    }

    while (fscanf(fp, "%d %d", &u, &v) == 2) {
        graph_add_arc(G, u, v);
    }

    printf("\n\nLettura grafo dopo l'inserimento degli archi attraverso graph1\n");
    for (int i = 0; i < G->dim; i++) {
        printf("Nodo %d:", i + 1);
        adj_node *curr = G->nodes[i];
        if (curr == NULL) {
            printf(" (nessun arco)");
        }
        while (curr != NULL) {
            printf(" -> %d", curr->node + 1);
            curr = curr->next;
        }
        printf("\n");
    }

    fclose(fp);

    fp = fopen("graph2", "r");

    if (fp == NULL) {
        perror("Errore nell'aprire il file");
        return 1;
    }

    while (fscanf(fp, "%d %d", &u, &v) == 2) {
        graph_add_arc(G, u, v);
    }

    printf("\n\nLettura grafo dopo l'inserimento degli archi attraverso graph2\n");
    for (int i = 0; i < G->dim; i++) {
        printf("Nodo %d:", i + 1);
        adj_node *curr = G->nodes[i];
        if (curr == NULL) {
            printf(" (nessun arco)");
        }
        while (curr != NULL) {
            printf(" -> %d", curr->node + 1);
            curr = curr->next;
        }
        printf("\n");
    }

}