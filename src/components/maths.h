#ifndef MATH_H
#define MATH_H

typedef struct {
    float x, y, z;
} vec3;

vec3 vec3_add(vec3 a, vec3 b);
vec3 vec3_sub(vec3 a, vec3 b);

vec3 vec3_normalize(vec3 v);
float vec3_magnitude(vec3 v);

vec3 vec3_cross(vec3 a, vec3 b);
float vec3_dot(vec3 a, vec3 b);

float** create_matrix(int dimensions);

void matrix_mult(int d, float* a[], float* b[], float* out[]);

#ifndef NDEBUG
void matrix_print(int d, float* a[]);
#else
inline void matrix_print(int d, float* a[]);
#endif

#endif