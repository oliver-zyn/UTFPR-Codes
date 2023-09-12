#include "atividadesExt.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct atvs {
    int RA;
    char Descricao[75];
    int CH;
    Data *dataIn;
    Data *datafi;
} Atvs;

Data *dataNova(int d, int m, int a) {
    Data *dt = (Data *)malloc(sizeof(Data));
    dt->dia = d;
    dt->mes = m;
    dt->ano = a;
    return dt;
}

void criaAtvs(Atvs *atividades) {
    int mes, dia, ano;

    printf("Qual o RA do aluno? ");
    scanf("%d", &atividades->RA);
    fflush(stdin);

    printf("Qual a descricao da atividade? ");
    gets(atividades->Descricao);
    fflush(stdin);

    printf("Qual a carga horaria da atividade? ");
    scanf("%d", &atividades->CH);
    fflush(stdin);

    printf("Qual a data inicial da atividade (dd mm aaaa)? ");
    scanf("%d %d %d", &dia, &mes, &ano);
    atividades->dataIn = dataNova(dia, mes, ano);
    fflush(stdin);

    printf("Qual a data final da atividade (dd mm aaaa)? ");
    scanf("%d %d %d", &dia, &mes, &ano);
    atividades->datafi = dataNova(dia, mes, ano);
    fflush(stdin);

};

void imprimirData(Data *dt) {
    printf("%.2d/%.2d/%.4d\n", dt->dia, dt->mes, dt->ano);
}

Data *dataHoje(void) {
    Data *dt = (Data *)malloc(sizeof(Data));
    time_t tempo;
    struct tm *hj;
    tempo = time(NULL); // obtem o tempo corrente
    hj = localtime(&tempo); // obtem a data do sistema operacional
    dt->dia = hj->tm_mday;
    dt->mes = hj->tm_mon + 1;
    dt->ano = hj->tm_year + 1900;
    return(dt);
}

void freeData(Data *data) {
    free(data);
}

int atividadeConcluida(Data *dt) {
    Data *hoje = dataHoje();
    if (dt->ano < hoje->ano || (dt->ano == hoje->ano && dt->mes < hoje->mes) || (dt->ano == hoje->ano && dt->mes == hoje->mes && dt->dia <= hoje->dia)) {
        freeData(hoje);
        return 1;
    } else {
        freeData(hoje);
        return 0;
    }
}

void imprimirAtvs(Atvs *atividade, int t) {
    for(int i = 0; i < t; i++) {
        printf("\n=========================================\n");
        printf("\nRA do aluno: %d\n", atividade[i].RA);
        printf("Descricao da atividade: %s\n", atividade[i].Descricao);
        printf("CH da atividade: %d horas\n", atividade[i].CH);
        printf("Data inicial: ");
        imprimirData(atividade[i].dataIn);
        printf("Data final: ");
        imprimirData(atividade[i].datafi);
        if (atividadeConcluida(atividade[i].datafi) == 1) {
            printf("Atividade Concluida!\n");
        } else {
            printf("Atividade nao concluida.\n");
        }
    }
}

