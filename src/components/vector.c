#include "vector.h"

#include <stdlib.h>

vector vector_new(uint32_t capacity) {
    vector vec;
    vec.capacity = capacity;
    vec.count = 0;
    vec.values = (void**) calloc(capacity, sizeof(void*)); 
    return vec;
}

void vector_free(vector* vec) {
    for(uint32_t i = 0; i < vec->capacity; i++)
        free(vec->values[i]);
    free(vec->values);
    vec->capacity = 0;
    vec->count = 0;
}

void vector_resize(vector* vec, uint32_t new_size) {
    vec->values = (void**) realloc(vec->values, new_size * sizeof(void*));
    vec->capacity = new_size;
    if(vec->count > new_size) vec->count = new_size;
}

void vector_push(vector* vec, void* val) {
    if(vec->count + 1 > vec->capacity) {
        vector_resize(vec, vec->capacity * 2);
    }
    vec->values[++vec->count] = val;
}