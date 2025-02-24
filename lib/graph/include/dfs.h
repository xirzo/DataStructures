#ifndef DFS_H
#define DFS_H

#include <stddef.h>

#include "graph.h"

struct dfs_data {
    bool* visited;
};

struct dfs_data* create_dfs_data(const size_t number_of_vertices);
void free_dfs_data(struct dfs_data* data);
void dfs(struct graph* self, struct dfs_data* data, size_t vertice);

#endif  // !DFS_H
