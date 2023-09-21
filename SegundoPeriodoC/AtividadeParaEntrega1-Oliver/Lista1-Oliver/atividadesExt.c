#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "atividadesExt.h"

struct data {
    int dia;
    int mes;
    int ano;
};

struct atividade {
    int RA;
    char descricao[75];
    int cargaHoraria;
    Data *dataInicial;
    Data *dataFinal;
};

Data *dataNova(int d, int m, int a) {
    Data *dt = malloc(sizeof(Data));
    dt->dia = d;
    dt->mes = m;
    dt->ano = a;
    return dt;
}

void cadastrarAtividade(Atividade *atividade) {
    int dia, mes, ano;

    printf("Qual o RA do aluno? ");
    scanf("%d", &atividade->RA);
    fflush(stdin);

    printf("Qual a descricao da atividade? ");
    gets(atividade->descricao);

    printf("Qual a carga horaria da atividade? ");
    scanf("%d", &atividade->cargaHoraria);

    printf("Qual a data inicial (DD MM YYYY)? ");
    scanf("%d %d %d", &dia, &mes, &ano);
    atividade->dataInicial = dataNova(dia, mes, ano);

    printf("Qual a data final (DD MM YYYY)? ");
    scanf("%d %d %d", &dia, &mes, &ano);
    atividade->dataFinal = dataNova(dia, mes, ano);

    printf("\nCADASTRO REALIZADO COM SUCESSO!");
}

void imprimirData(Data *dt) {
    printf("%.2d/%.2d/%.4d", dt->dia, dt->mes, dt->ano);
}

Data *dataHoje(void) {
    Data *dt = malloc(sizeof(Data));
    time_t tempo;
    struct tm *hj;
    tempo = time(NULL); // obtem o tempo corrente
    hj = localtime(&tempo); // obtem a data do sistema operacional
    dt->dia = hj->tm_mday;
    dt->mes = hj->tm_mon + 1;
    dt->ano = hj->tm_year + 1900;
    return dt;
}

void liberarData(Data *dt) {
    free(dt);
}

int atividadeConcluida(Data *dt) {
    Data *hoje = dataHoje();
    if (dt->ano < hoje->ano || (dt->ano == hoje->ano && dt->mes < hoje->mes) || (dt->ano == hoje->ano && dt->mes == hoje->mes && dt->dia <= hoje->dia)) {
        liberarData(hoje);
        return 1;
    } else {
        liberarData(hoje);
        return 0;
    }
}

void imprimirAtividades(Atividade *atividades, int t) {
    for (int i = 0; i < t; i++) {
        printf("============================");
        printf("\nRA: %d\n", atividades[i].RA);
        printf("Descricao: %s\n", atividades[i].descricao);
        printf("Carga horaria: %d\n", atividades[i].cargaHoraria);
        printf("Data inicial: ");
        imprimirData(atividades[i].dataInicial);
        printf("\nData final: ");
        imprimirData(atividades[i].dataFinal);
        printf("\nAtividade concluida: %d\n", atividadeConcluida(atividades[i].dataFinal));
    }
}


