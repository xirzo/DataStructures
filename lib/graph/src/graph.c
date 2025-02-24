#include "graph.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

struct graph* create_graph(const size_t number_of_vertices) {
    struct graph* graph = malloc(sizeof(struct graph));

    graph->vertices = create_vector(sizeof(struct vertice));

    for (size_t i = 0; i < number_of_vertices + 1; ++i) {
        struct vertice v;

        v.adjacent = create_vector(sizeof(size_t));

        push_back_vector(graph->vertices, &v);
    }

    return graph;
}

void free_graph(struct graph* self) {
    for (size_t i = 0; i < self->vertices->length; ++i) {
        struct vertice* v =
            (struct vertice*)(self->vertices->data + i * self->vertices->element_size);
        free_vector(v->adjacent);
    }

    free_vector(self->vertices);
    free(self);
}

void print_graph(struct graph* self) {
    for (size_t i = 1; i < self->vertices->length; ++i) {
        struct vertice* v = (struct vertice*)((char*)self->vertices->data +
                                              i * self->vertices->element_size);

        printf("Vertice #%zu: \n", i);

        for (size_t j = 0; j < v->adjacent->length; ++j) {
            printf("%zu ", ((size_t*)v->adjacent->data)[j]);
        }

        printf("\n");
    }
}

void add_oriented_edge(struct graph* self, size_t start, size_t end) {
    struct vertice* v1 = (struct vertice*)((char*)self->vertices->data +
                                           start * self->vertices->element_size);

    push_back_vector(v1->adjacent, &end);
}

void add_non_oriented_edge(struct graph* self, size_t start, size_t end) {
    struct vertice* v1 = (struct vertice*)((char*)self->vertices->data +
                                           start * self->vertices->element_size);

    struct vertice* v2 = (struct vertice*)((char*)self->vertices->data +
                                           end * self->vertices->element_size);
    push_back_vector(v1->adjacent, &end);
    push_back_vector(v2->adjacent, &start);
}
