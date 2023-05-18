#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    float dist, capmax, consumo, litros_restantes;
    
    printf("Informe a distancia (em Km) percorrida entre cidades: ");
    scanf("%f", &dist);
    
    printf("Informe a capacidade maxima do tanque de combustivel do veiculo: ");
    scanf("%f", &capmax);
    
    printf("Informe o consumo medio (em Km por litro) do veiculo: ");
    scanf("%f", &consumo);

    litros_restantes = capmax - (fmod((dist/consumo), capmax));
    
    printf("Foram necessarios %.1f litros para percorrer o trajeto\n", dist/consumo);
    
    printf("Foi necessario abastecer %.0f vezes.\n", ceil(dist/(consumo*capmax)));
    
    printf("Restou no tanque %.1f litros.", litros_restantes);
    return 0;
}