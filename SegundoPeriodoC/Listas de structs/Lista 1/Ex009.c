#include <stdio.h>
#include <string.h>

typedef struct horario {
  int hora;
  int minutos;
  int segundos;
} Horario;

typedef struct data {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct compromisso {
  Data data;
  Horario horario;
  char descricao[100];
} Compromisso;

Compromisso cadastraCompromisso() {
  Compromisso compromisso;

  printf("\nDigite a data do compromisso: \n");
  printf("Dia: ");
  scanf("%d", &compromisso.data.dia);
  printf("Mes: ");
  scanf("%d", &compromisso.data.mes);
  printf("Ano: ");
  scanf("%d", &compromisso.data.ano);

  printf("\nDigite o horario do compromisso: \n");
  printf("Hora: ");
  scanf("%d", &compromisso.horario.hora);
  printf("Minuto: ");
  scanf("%d", &compromisso.horario.minutos);
  printf("Segundo: ");
  scanf("%d", &compromisso.horario.segundos);

  fflush(stdin);

  printf("\nDigite a descricao do compromisso: ");
  gets(compromisso.descricao);

  fflush(stdin);

  return compromisso;
}

void mostraCompromisso(Compromisso compromisso, int mes) {
  if (compromisso.data.mes == mes || mes == 0) {
    printf("\nDescricao: %s", compromisso.descricao);
    printf("\nData: %d/%d/%d", compromisso.data.dia, compromisso.data.mes, compromisso.data.ano);
    printf("\nHorario: %d:%d:%d \n", compromisso.horario.hora, compromisso.horario.minutos, compromisso.horario.segundos);
  }
}

int main(void) {
  int nQtdCompromissos = 0, nOpcao, nMes;

  printf("Quantos compromissos deseja cadastrar? ");
  scanf("%d", &nQtdCompromissos);

  Compromisso compromisso[nQtdCompromissos];

  for(int i = 0; i < nQtdCompromissos; i++) {
    compromisso[i] = cadastraCompromisso();
  }

  do {
    printf("\nO que deseja fazer?\n- Ver todos os compromissos (1) \n- Ver compromissos de um mes especifico (2) \n- Encerrar (3)");
    printf("\nOpcao: ");
    scanf("%d", &nOpcao);

    switch (nOpcao) {
    case 1:
      for(int i = 0; i < nQtdCompromissos; i++) {
        mostraCompromisso(compromisso[i], 0);
      }

      break;
    case 2:
      printf("Qual mes deseja ver? ");
      scanf("%d", &nMes);

      for(int i = 0; i < nQtdCompromissos; i++) {
        mostraCompromisso(compromisso[i], nMes);
      }

      break;
    case 3:
      printf("\nEncerrando...");

      break;
    default:
      printf("\nOpcao invalida!\n");

      break;
    }

  } while (nOpcao != 3);
}