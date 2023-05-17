#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
    
    int bem, dor;
    float temp;
    
    printf("Escolha entre as opcoes:\n0 - Não me sinto bem\n1 - Me sinto bem\n");
    scanf("%i", &bem);
    
    if (bem == 1) {
        printf("Paciente Saudavel");
    } else if (bem == 0) {
        printf("Escolha entra as opcoes:\n0 - Paciente nao sente dor\n1 - Paciente sente dor\n");
        scanf("%i", &dor);
        if (dor == 1) {
            printf("Paciente Doente");
        } else if (dor == 0) {
            printf("Informe a temperatura do paciente:\n");
            scanf("%f", &temp);
            if (temp <= 37) {
                printf("Paciente Saudavel");
            } else if (temp > 37) {
                printf("Paciente Doente");
            }
        }
    }
    
    return 0;
}