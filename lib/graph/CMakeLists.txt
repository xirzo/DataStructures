add_library(graph 
    ./src/component.c
    ./src/dfs.c
    ./src/graph.c
    ./src/topological_sort.c
)

target_include_directories(graph
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(graph PUBLIC vector)
