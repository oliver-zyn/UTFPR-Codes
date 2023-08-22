#include <stdio.h>
#include <string.h>

typedef struct dataNasc {
  int dia;
  int mes;
  int ano;
} DataNasc;

typedef struct atleta {
  char nome[50];
  char cpf[15];
  DataNasc dataNasc;
  char modalidade[50];
  float salario;
} Atleta;

Atleta cadastrarAtleta() {
  Atleta atleta;

  printf("\nDigite o nome do atleta: ");
  gets(atleta.nome);

  printf("Digite o cpf do atleta: ");
  gets(atleta.cpf);

  printf("Digite a data de nascimento do atleta (DD MM AAAA): \n");
  printf("Dia: ");
  scanf("%d", &atleta.dataNasc.dia);
  printf("Mes: ");
  scanf("%d", &atleta.dataNasc.mes);
  printf("Ano: ");
  scanf("%d", &atleta.dataNasc.ano);

  fflush(stdin);

  printf("Digite a modalidade do atleta: ");
  gets(atleta.modalidade);

  printf("Digite o salario do atleta: ");
  scanf("%f", &atleta.salario);

  fflush(stdin);

  return atleta;
}

void mostraDadosAtleta(Atleta atleta) {
  printf("\nNome: %s", atleta.nome);
  printf("\nCPF: %s", atleta.cpf);
  printf("\nData de nascimento: %d/%d/%d", atleta.dataNasc.dia, atleta.dataNasc.mes, atleta.dataNasc.ano);
  printf("\nModalidade: %s", atleta.modalidade);
  printf("\nSalario: %.2f", atleta.salario);
}

int main(void) {
  Atleta atleta;

  atleta = cadastrarAtleta();

  printf("\nDADOS DO ATLETA: %s\n", atleta.nome);

  mostraDadosAtleta(atleta);
}

