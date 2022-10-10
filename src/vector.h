#ifndef VECTOR_H
#define VECTOR_H

#include <stdint.h>
#include <stdlib.h>
#include <memory.h>

typedef struct {
    uint32_t count;
    uint32_t capacity;
    void** values;
} vector;

vector vec_new(uint32_t capacity) {
    vector vec;
    vec.capacity = capacity;
    vec.count = 0;
    vec.values = (void**) calloc(capacity, sizeof(void*)); 
    return vec;
}

void vec_free(vector* vec) {
    for(uint32_t i = 0; i < vec->capacity; i++)
        free(vec->values[i]);
    free(vec->values);
    vec->capacity = 0;
    vec->count = 0;
}

void vec_resize(vector* vec, uint32_t new_size) {
    vec->values = (void**) realloc(vec->values, new_size * sizeof(void*));
    vec->capacity = new_size;
    if(vec->count > new_size) vec->count = new_size;
}

void vec_push(vector* vec, void* val) {
    if(vec->count + 1 > vec->capacity) {
        vec_resize(vec, vec->capacity * 2);
    }
    vec->values[vec->count++] = val;
}

#endif