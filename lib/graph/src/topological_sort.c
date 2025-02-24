#include "topological_sort.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

void dfs_topological_sort(struct graph* self, bool* visited,
                          struct vector* topological_order, size_t vertice) {
    visited[vertice] = true;

    struct vertice* v = (struct vertice*)((char*)self->vertices->data +
                                          vertice * self->vertices->element_size);

    for (size_t i = 1; i < v->adjacent->length; ++i) {
        size_t* adj = (size_t*)((char*)v->adjacent->data + i * v->adjacent->element_size);

        if (!visited[*adj]) {
            dfs_topological_sort(self, visited, topological_order, *adj);
        }
    }

    push_back_vector(topological_order, &vertice);
}

struct vector* topological_sort(struct graph* self) {
    bool* visited = malloc(sizeof(bool) * (self->vertices->length));
    struct vector* topological_order = create_vector(sizeof(size_t));

    memset(visited, false, self->vertices->length);

    for (size_t i = 1; i < self->vertices->length; ++i) {
        if (!visited[i]) {
            dfs_topological_sort(self, visited, topological_order, i);
        }
    }

    reverse_vector(topological_order);

    free(visited);

    return topological_order;
}
