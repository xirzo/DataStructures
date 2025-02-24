#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

struct vector {
    void* data;
    size_t element_size;
    size_t length;
    size_t size;
};

struct vector* create_vector(size_t element_size);
void free_vector(struct vector* self);

void insert_vector(struct vector* self, void* data, size_t index);
void push_back_vector(struct vector* self, void* data);

#endif  // !VECTOR_
