#ifndef TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H

#include <stddef.h>

#include "graph.h"

struct vector* topological_sort(struct graph* self);

#endif
