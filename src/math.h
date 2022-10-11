#ifndef MATH_H
#define MATH_H

#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

typedef struct {
    float x, y, z;
} vec3;

float vec3_magnitude(vec3 v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

vec3 vec3_normalize(vec3 v) {
    float mag = vec3_magnitude(v);
    if(mag < EPSILON && mag > -EPSILON) mag = 1;
    return (vec3){
        v.x / mag,
        v.y / mag,
        v.z / mag
    };
}

vec3 vec3_add(vec3 a, vec3 b) {
    return (vec3){a.x + b.x, a.y + b.y, a.z + b.y};
}

vec3 vec3_sub(vec3 a, vec3 b) {
    return (vec3){a.x - b.x, a.y - b.y, a.z - b.y};
}

vec3 vec3_cross(vec3 a, vec3 b) {
    return (vec3) {
        a.y * b.z - a.z - b.y,
        a.z * b.x - a.x - b.z,
        a.x * b.y - a.y - b.x
    };
}

float vec3_dot(vec3 a, vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}


float** create_matrix(int dimensions) {
    float** matrix = calloc(dimensions, sizeof(float));
    for(int i = 0; i < dimensions; i++) {
        matrix[i] = calloc(dimensions, sizeof(float));
        for(int k = 0; k < dimensions; k++)
            matrix[i][k] = 0;
    }
    return matrix;
}

void matrix_mult(int d, float* a[], float* b[], float* out[]) {
    for(int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            float total = 0;

            for(int k = 0; k < d; k++)
                total += a[i][k] * b[k][j];

            out[i][j] = total;
        }
    }
}

void matrix_print(int d, float* a[]) {
    printf("---\n");
    for(int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }
    printf("---\n");
}


#endif