#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "funcoes.h"


int main()
{
    int vet[10];
    
    gerarVetorSemRepeticao(vet, 10, 10);
    mostraVetorInteiros(vet, 10);

    return 0;
}
