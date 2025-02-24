#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int main(int argc, char* argv[]) {
    const size_t NUMBER_OF_VERTICES = 6;

    struct graph* graph = create_graph(NUMBER_OF_VERTICES);

    add_edge(graph, 1, 2);
    add_edge(graph, 2, 1);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 3);
    add_edge(graph, 5, 6);
    add_edge(graph, 6, 5);

    print_graph(graph);

    struct components* components = find_components(graph);

    printf("Number of components: %zu\n", components->number_of_components);

    for (size_t i = 1; i <= NUMBER_OF_VERTICES; ++i) {
        printf("Vertice #%zu is in %zu component\n", i, components->component[i]);
    }

    free_components(components);
    free_graph(graph);

    return EXIT_SUCCESS;
}
