/*
Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve
conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota
da terceira prova.
• Permita ao usuário entrar com os dados de 5 alunos;
• Encontre o aluno com maior nota da primeira prova;
• Encontre o aluno com maior média geral;
• Encontre o aluno com menor média geral; ́
• Percorra o vetor de alunos e para cada aluno diga se ele foi aprovado ou reprovado,
considerando o valor 6 para aprovação.
*/

#include <stdio.h>
#include <string.h>

typedef struct aluno {
    int matricula;
    char nome[75];
    float notas[3];
    float media;
} Aluno;

Aluno cadastroDeAluno() {
    Aluno aluno;
    float media = 0;
    fflush(stdin);
    printf("Informe a Matricula: ");
    scanf("%d", &aluno.matricula);
    fflush(stdin);
    printf("Informe o nome do aluno: ");
    gets(aluno.nome);
    fflush(stdin);
    for(int i = 0; i < 3; i++) {
        printf("Informe a nota %d: ", i+1);
        scanf("%f", &aluno.notas[i]);
        media += aluno.notas[i];
    }
    aluno.media = media / 3;
    return aluno;
}

void imprimeAluno(int numCadastro, Aluno aluno) {
    printf("\n============ Aluno %i ============\n\n", numCadastro);
    printf("Matricula: %d\n", aluno.matricula);
    printf("Nome do aluno: %s\n\n", aluno.nome);
    printf("============== NOTAS =============\n\n");
    for(int i = 0; i < 3; i++) {
        printf("Nota %d: %.2f\n", i+1, aluno.notas[i]);
    }
    printf("Media: %.2f\n", aluno.media);
}

int main(void) {
    int numC = 5, max1 = 0, i;
    int alunoNota1, alunoMedia1, alunoMedia0;
    float maiorMedia = 0, menorMedia = 10;
    Aluno aluno[numC];

    for (i = 0; i < numC; i++) {
        aluno[i] = cadastroDeAluno();
    }
    for(i = 0; i < numC; i++) {
        if (aluno[i].notas[0] > max1) {
            max1 = aluno[i].notas[0];
            alunoNota1 = i;
        }
    }
    for (i = 0; i < numC; i++) {
        imprimeAluno(i, aluno[i]);
    }
    printf("\n");
    printf("Aluno com maior nota na prova 1 eh: %s\n", aluno[alunoNota1].nome);
    for(i = 0; i < numC; i++) {
        if (aluno[i].media > maiorMedia) {
            maiorMedia = aluno[i].media;
            alunoMedia1 = i;
        }
    }
    printf("Aluno com maior media eh: %s\n", aluno[alunoMedia1].nome);
    for(i = 0; i < numC; i++) {
        if (aluno[i].media < menorMedia) {
            menorMedia = aluno[i].media;
            alunoMedia0 = i;
        }
    }
    printf("Aluno com menor media eh: %s\n", aluno[alunoMedia0].nome);
    for(i = 0; i < numC; i++) {
        if (aluno[i].media < 6) {
            printf("Aluno %s, Reprovado.\n", aluno[i].nome);
        } else {
            printf("Aluno %s, Aprovado.\n", aluno[i].nome);
        }
    }
    return 0;
}