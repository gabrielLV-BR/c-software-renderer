#ifndef CAMERA_H
#define CAMERA_H

#include "maths.h"

typedef struct {
    float fob;
    float aspect;
    float near;
    float far;

    vec3 position;
    vec3 direction;
} camera;

float** get_camera_look_at(camera* cam, vec3 target);

#endif