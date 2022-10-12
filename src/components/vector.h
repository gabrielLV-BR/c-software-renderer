#ifndef VECTOR_H
#define VECTOR_H

#include <stdint.h>

typedef struct {
    uint32_t count;
    uint32_t capacity;
    void** values;
} vector;

vector vector_new(uint32_t capacity);
void vector_free(vector* vec);
void vector_resize(vector* vec, uint32_t new_size);
void vector_push(vector* vec, void* val);

#endif