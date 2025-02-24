#ifndef GRAPH_H
#define GRAPH_H

#include <stddef.h>
#include <stdlib.h>

#include "vector.h"

struct vertice {
    struct vector* adjacent;
};

struct graph {
    struct vector* vertices;
};

struct graph* create_graph(size_t number_of_vertices);
void free_graph(struct graph* self);

void add_edge(struct graph* self, size_t start, size_t end);
void print_graph(struct graph* self);

#endif  // !GRAPH_H
