#ifndef MATH_H
#define MATH_H

#include <stdio.h>

typedef float matrix3x3[3][3];

void mat3x3_mult(matrix3x3 a, matrix3x3 b, matrix3x3 out) {
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            float total = 0;

            for(int k = 0; k < 3; k++)
                total += a[i][k] * b[j][k];

            out[i][j] = total;
        }
    }
}

void mat3x3_print(matrix3x3 a) {
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