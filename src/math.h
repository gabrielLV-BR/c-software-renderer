#ifndef MATH_H
#define MATH_H

#include <stdio.h>

typedef float matrix3x3[3][3];

float** mat3x3_mult(float a[3][3], float b[3][3]) {
    float** out = (float**) calloc(3, sizeof(float**));
    for(int i = 0; i < 3; i++) {
        out[i] = (float*) calloc(3, sizeof(float*));
        for(int j = 0; j < 3; j++) out[i][j] = 0;
    }

    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            float total = 0;

            for(int k = 0; k < 3; k++)
                total += a[j][k] * b[j][k];

            out[i][j] = 2;
        }
    }
    return out;
}

void mat3x3_print(float** a) {
    printf("---\n");
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2d ", a[i][j]);
        }
        printf("\n");
    }
    printf("---\n");
}


#endif