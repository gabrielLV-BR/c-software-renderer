#ifndef OBJECT_H
#define OBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

typedef struct {
    float x, y, z;
} vertex;

typedef struct {
    vertex a, b, c;
} polygon;

vector load_model(char* path) {
    FILE* file = fopen(path, "r");
    char* line = NULL;
    size_t line_size = 0;

    int i = 0;
    size_t size = 0;

    vector vertices = vec_new(507u);
    vector faces    = vec_new(100u);

    if(file == NULL) goto END;

    while((size = getline(&line, &line_size, file)) != -1) {

        char* token = strtok(line, " ");

        int32_t i = 0;
        if(strcmp(token, "v") == 0) {
            // Vértice
            float values[3];
            for(int32_t i = 0; i < 3; i++) {
                token = strtok(NULL, " ");
                values[i] = strtof(token, NULL); 
            }
            vertex* v = (vertex*) malloc(sizeof(vertex));
            v->x = values[0] * 100.0 + 100.0;
            v->y = values[1] * 100.0 + 100.0;
            v->z = values[2] * 100.0 + 100.0;
            vec_push(&vertices, (void*)v);
        } else if (strcmp(token, "f") == 0) {
            // Face
            int32_t values[3];
            for(int i = 0; i < 3; i++) {
                token = strtok(NULL, " ");
                values[i] = strtol(token, NULL, 10) - 1; 
            }
            polygon* poly = (polygon*) malloc(sizeof(polygon));
            poly->a = *(vertex*)vertices.values[values[0]];
            poly->b = *(vertex*)vertices.values[values[1]];
            poly->c = *(vertex*)vertices.values[values[2]];
            vec_push(&faces, (void*)poly);
        }

    }

    printf("Number of vertices: %d\n", vertices.count);
    printf("Number of faces: %d\n", faces.count);

END:
    free(line);
    fclose(file);
    vec_free(&vertices);
    return faces;
}

#endif
