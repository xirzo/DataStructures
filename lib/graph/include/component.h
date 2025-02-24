#ifndef COMPONENT_H
#define COMPONENT_H

#include <stddef.h>

#include "graph.h"

struct components {
    size_t number_of_components;
    size_t* component;
};

struct components* find_components(struct graph* self);
void free_components(struct components* components);

#endif
