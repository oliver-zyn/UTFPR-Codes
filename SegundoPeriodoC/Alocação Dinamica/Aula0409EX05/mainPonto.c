#include <stdio.h>
#include <math.h>
#include "ponto.h"

int main(void) {
    Ponto *p1 = criaPonto(3, 4);
    Ponto *p2 = criaPonto(6, 7);

    imprimePonto(p1);
    imprimePonto(p2);

    float dist = calculaDist(p1, p2);
    printf("\nDistancia entre os pontos: %.2f", dist);
}