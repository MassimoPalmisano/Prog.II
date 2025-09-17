#ifndef __GRAFO_H__
#define __GRAFO_H__

typedef struct adj_node {
    int node;
    float weight;
    struct adj_node* next;
} adj_node;

typedef adj_node* adj_list;

typedef struct {
    adj_list* nodes;
    int dim;
} graph;

graph* create_graph(int n);
void free_graph(graph* G);

int graph_get_dim(graph* g);
adj_list graph_get_adjlist(graph* g, int u);

void graph_add_arc(graph* G, int u, int v);
void graph_add_edge(graph* g, int u, int v);
void graph_add_arc_w(graph* G, int u, int v, float w);
void graph_add_edge_w(graph* g, int u, int v, float w);

int get_adjnode(adj_node* l);
float get_adjweight(adj_node* l);
adj_list get_nextadj(adj_list l);

#endif /* __GRAFO_H__ */