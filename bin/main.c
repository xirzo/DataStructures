#include <stddef.h>
#include <stdlib.h>

#include "graph.h"

// ((type*)vec->data)[i]

int main(int argc, char* argv[]) {
    struct graph* graph = create_graph(6);

    add_edge(graph, 1, 2);
    add_edge(graph, 3, 2);
    add_edge(graph, 4, 2);
    add_edge(graph, 2, 5);
    add_edge(graph, 6, 5);
    add_edge(graph, 4, 6);

    print_graph(graph);

    free_graph(graph);
    return EXIT_SUCCESS;
}
