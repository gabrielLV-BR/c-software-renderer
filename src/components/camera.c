#include "camera.h"

float** get_camera_look_at(camera* cam, vec3 target) {
    // direction
    cam->direction = vec3_normalize(vec3_sub(target, cam->position));

    // para pegar o eixo direito, primeiro criamos um cima "falso"
    vec3 up = { 0, 1, 0 };
    vec3 right = vec3_normalize(vec3_cross(cam->direction, up));

    // agora usamos o right para calcular o up verdadeiro
    up = vec3_normalize(vec3_cross(cam->direction, right));

    // criamos as matrizes necessárias
    float** a = create_matrix(4);
    float** b = create_matrix(4);

    float** look_at = create_matrix(4);

    return look_at;
}