#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct coordenadaCartesiana {
  int x;
  int y;
} CoordenadaCartesiana;

typedef struct coordenadaPolar {
  int r;
  int a;
} CoordenadaPolar;

int main(void) {
    CoordenadaPolar coordenadaPolar;
    CoordenadaCartesiana coordenadaCartesiana;

    printf("Digite o valor do raio: ");
    scanf("%d", &coordenadaPolar.r);

    printf("Digite o valor do argumento em graus: ");
    scanf("%d", &coordenadaPolar.a);

    coordenadaPolar.a = (coordenadaPolar.a * (3.14 / 180.0));

    coordenadaCartesiana.x = coordenadaPolar.r * cos(coordenadaPolar.a);
    coordenadaCartesiana.y = coordenadaPolar.r * sin(coordenadaPolar.a);

    printf("\nPonto cartesiano: (%d, %d)\n", coordenadaCartesiana.x, coordenadaCartesiana.y);
    printf("x = %d\n", coordenadaCartesiana.x);
    printf("y = %d\n", coordenadaCartesiana.y);
}