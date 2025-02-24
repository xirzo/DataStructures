add_library(vector ${CMAKE_CURRENT_SOURCE_DIR}/src/vector.c)

target_include_directories(vector
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
