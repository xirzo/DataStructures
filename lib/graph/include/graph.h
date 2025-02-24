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

struct dfs_data {
    bool* visited;
};

struct graph* create_graph(const size_t number_of_vertices);
void free_graph(struct graph* self);

void add_edge(struct graph* self, size_t start, size_t end);
void print_graph(struct graph* self);

struct dfs_data* create_dfs_data(const size_t number_of_vertices);
void free_dfs_data(struct dfs_data* data);

void dfs(struct graph* self, struct dfs_data* data, size_t vertice);

#endif  // !GRAPH_H
