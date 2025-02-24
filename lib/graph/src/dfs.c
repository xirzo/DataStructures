#include "dfs.h"

#include <stdio.h>
#include <string.h>

struct dfs_data* create_dfs_data(const size_t number_of_vertices) {
    struct dfs_data* data = malloc(sizeof(struct dfs_data));

    data->visited = malloc(sizeof(bool) * (number_of_vertices + 1));

    memset(data->visited, 0, sizeof(bool) * (number_of_vertices + 1));

    return data;
}

void free_dfs_data(struct dfs_data* data) {
    free(data->visited);
    free(data);
}

void dfs(struct graph* self, struct dfs_data* data, size_t vertice) {
    data->visited[vertice] = true;

    printf("Current vertice: %zu\n", vertice);

    struct vertice* v = (struct vertice*)((char*)self->vertices->data +
                                          vertice * self->vertices->element_size);

    for (size_t i = 1; i < v->adjacent->length; ++i) {
        size_t* adjacent =
            (size_t*)((char*)v->adjacent->data + i * v->adjacent->element_size);

        if (!data->visited[*adjacent]) {
            dfs(self, data, *adjacent);
        }
    }
}
