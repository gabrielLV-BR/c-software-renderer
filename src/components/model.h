#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "maths.h"
#include "vector.h"

typedef struct {
    vec3 a, b, c;
} polygon;

vector load_obj_model(char* path);

#endif
