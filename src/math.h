#ifndef MATH_H
#define MATH_H

#include <stdio.h>

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