#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_notas;
    float *notas, soma = 0.0, media, maior_nota = -1.0, menor_nota = 101.0;

    printf("Quantas notas deseja inserir? ");
    scanf("%d", &num_notas);

    if (num_notas <= 0) {
        printf("Número inválido de notas.\n");
        return 1;
    }

    notas = malloc(num_notas * sizeof(float));

    if (notas == NULL) {
        printf("Erro ao alocar memória para notas.\n");
        return 1;
    }

    for (int i = 0; i < num_notas; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &notas[i]);

        soma += notas[i];

        if (notas[i] > maior_nota) {
            maior_nota = notas[i];
        }

        if (notas[i] < menor_nota) {
            menor_nota = notas[i];
        }
    }

    media = soma / num_notas;

    printf("Media: %.1f\n", media);
    printf("Maior nota: %.1f\n", maior_nota);
    printf("Menor nota: %.1f\n", menor_nota);

    free(notas);

    return 0;
}
