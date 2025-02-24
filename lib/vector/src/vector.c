#include "vector.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vector* create_vector(size_t element_size) {
    struct vector* vector = malloc(sizeof(struct vector));

    vector->element_size = element_size;
    vector->length = 0;
    vector->size = 1;

    vector->data = malloc(element_size * vector->size);

    if (vector->data == NULL) {
        printf("vector data is null");
    }

    return vector;
}

void free_vector(struct vector* self) {
    free(self->data);
    free(self);
}

void insert_vector(struct vector* self, void* data, size_t index) {
    if (self == NULL || data == NULL) {
        fprintf(stderr, "self or data is null\n");
        return;
    }

    if (index > self->length) {
        fprintf(stderr, "index %zu is bigger that the vector length\n", index);
        return;
    }

    if (self->length == self->size) {
        self->size *= 2;

        void* temp = realloc(self->data, self->size * self->element_size);

        if (!temp) {
            fprintf(stderr, "Memory reallocation failed on index %zu\n", index);
            return;
        }

        self->data = temp;
    }

    self->length++;
    memcpy(self->data + index * self->element_size, data, self->element_size);
}

void push_back_vector(struct vector* self, void* data) {
    insert_vector(self, data, self->length);
}
