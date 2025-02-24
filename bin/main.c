#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int main(int argc, char* argv[]) {
    const size_t NUMBER_OF_VERTICIES = 6;

    struct graph* graph = create_graph(NUMBER_OF_VERTICIES);

    add_edge(graph, 1, 2);
    add_edge(graph, 3, 2);
    add_edge(graph, 4, 2);
    add_edge(graph, 2, 5);
    add_edge(graph, 6, 5);
    add_edge(graph, 4, 6);

    print_graph(graph);

    struct dfs_data* data = create_dfs_data(NUMBER_OF_VERTICIES);

    dfs(graph, data, 2);

    free_dfs_data(data);
    free_graph(graph);

    return EXIT_SUCCESS;
}
