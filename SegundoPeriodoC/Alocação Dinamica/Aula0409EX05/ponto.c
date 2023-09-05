#include <stdio.h>
#include <math.h>
#include "ponto.h"

struct ponto {
    float x;
    float y;
};

Ponto *criaPonto(float x, float y) {
    Ponto *p = malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    return p;
}

void imprimePonto(Ponto *p) {
    printf("x: %.2f, y: %.2f\n", p->x, p->y);
}

float calculaDist(Ponto *p1, Ponto *p2) {
    float dx, dy, dt;
    dx = p1->x - p2->x;
    dy = p1->y - p2->y;
    dt = sqrt(pow(dx,2) + pow(dy, 2));
    return dt;
}