#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED

typedef struct ponto Ponto;
Ponto *criaPonto(float x, float y);
void imprimePonto(Ponto *p);
float calculaDist(Ponto *p1, Ponto *p2);

#endif // PONTO_H_INCLUDED