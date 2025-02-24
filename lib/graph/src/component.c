#include "component.h"

#include <string.h>

static void dfs_component(struct graph* self, size_t* component, size_t vertice,
                          size_t num_flag) {
    component[vertice] = num_flag;

    struct vertice* v = (struct vertice*)((char*)self->vertices->data +
                                          vertice * self->vertices->element_size);

    for (size_t i = 0; i < v->adjacent->length; ++i) {
        size_t* adj = (size_t*)((char*)v->adjacent->data + i * v->adjacent->element_size);

        if (!component[*adj]) {
            dfs_component(self, component, *adj, num_flag);
        }
    }
}

void free_components(struct components* components) {
    free(components->component);
    free(components);
}

struct components* find_components(struct graph* self) {
    size_t num_flag = 0;
    size_t* component = malloc(sizeof(size_t) * (self->vertices->length + 1));

    memset(component, 0, self->vertices->length * sizeof(size_t));

    for (size_t i = 0; i < self->vertices->length; ++i) {
        if (!component[i]) {
            dfs_component(self, component, i, num_flag++);
        }
    }

    struct components* components = malloc(sizeof(struct components));

    components->number_of_components = num_flag - 1;
    components->component = component;

    return components;
}
