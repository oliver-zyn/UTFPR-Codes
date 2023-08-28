/*
Faça um programa que leia os dados de 8 alunos (nome, matrícula e média final),
armazenando em um vetor. Uma vez lidos os dados, divida estes dados em 2 novos
vetores, o vetor dos aprovados e o vetor dos reprovados, considerando a média mínima
para a aprovação como sendo 5.0. Exibir na tela os dados do vetor de aprovados, seguido
dos dados do vetor de reprovados.
*/

#include <stdio.h>
#include <string.h>

typedef struct aluno {
    int matricula;
    char nome[75];
    float media;
} Aluno;

Aluno cadastroDeAluno() {
    Aluno aluno;
    fflush(stdin);
    printf("Informe a Matricula: ");
    scanf("%d", &aluno.matricula);
    fflush(stdin);
    printf("Informe o nome do aluno: ");
    gets(aluno.nome);
    fflush(stdin);
    printf("Informe a media final do aluno %s: ", aluno.nome);
    scanf("%f", &aluno.media);
    return aluno;
}

int divideAprovDesaprov(Aluno aluno){
    if (aluno.media > 5) {
        return 1;
    } else {
        return 0;
    }
}

void imprimeAluno(Aluno aluno) {
    printf("\nMatricula: %d\n", aluno.matricula);
    printf("Nome do aluno: %s\n", aluno.nome);
    printf("Media: %.2f\n", aluno.media);
}

void mostraVetorStructAluno(Aluno vet[], int tamanho)
{
    int i;

    for(i=0; i<tamanho; i++)
    {
        imprimeAluno(vet[i]);
    }
}

int main(void) {
    int numC = 2, i, notaA = 0, notaD = 0, verifi;
    Aluno aluno[numC], aprov[numC], desaprov[numC];

    for (i = 0; i < numC; i++) {
        aluno[i] = cadastroDeAluno();
    }
    for (i = 0; i < numC; i++) {
        verifi = 2;
        verifi = divideAprovDesaprov(aluno[i]);
        if (verifi == 1) {
            aprov[notaA] = aluno[i];
            notaA++;
        } else if (verifi == 0) {
            desaprov[notaD] = aluno[i];
            notaD++;
        } else {
            printf("Error");
        }
    }

    printf("============= Aprovados ============\n\n");
    mostraVetorStructAluno(aprov, notaA);
    printf("============= Desaprovados ============\n\n");
    mostraVetorStructAluno(desaprov, notaD);


    return 0;
}