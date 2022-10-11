#ifndef MATH_H
#define MATH_H

#include <stdio.h>

typedef float matrix3x3[3][3];

void mat3x3_mult(float a[3][3], float b[3][3], float out[3][3]) {
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            float total = 0;

            for(int k = 0; k < 3; k++)
                total += a[i][k] * b[k][j];

            out[i][j] = total;
        }
    }
}

void mat3x3_print(float a[3][3]) {
    printf("---\n");
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }
    printf("---\n");
}


#endif