#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    int RA;
    char nome[50];
    char telefone[15];
    char email[50];
};

int main() {
    int num_alunos;

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &num_alunos);

    if (num_alunos <= 0) {
        printf("Número inválido de alunos.\n");
        return 1;
    }

    struct Aluno *alunos = malloc(num_alunos * sizeof(struct Aluno));

    if (alunos == NULL) {
        printf("Erro ao alocar memória para alunos.\n");
        return 1;
    }

    for (int i = 0; i < num_alunos; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("RA: ");
        scanf("%d", &alunos[i].RA);

        printf("Nome: ");
        scanf("%s", alunos[i].nome);

        printf("Telefone: ");
        scanf("%s", alunos[i].telefone);

        printf("Email: ");
        scanf("%s", alunos[i].email);
    }

    printf("\nDados dos alunos cadastrados:\n\n");
    for (int i = 0; i < num_alunos; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("RA: %d\n", alunos[i].RA);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Telefone: %s\n", alunos[i].telefone);
        printf("Email: %s\n", alunos[i].email);
        printf("\n");
    }

    free(alunos);

    return 0;
}
