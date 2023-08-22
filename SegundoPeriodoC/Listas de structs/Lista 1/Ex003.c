#include <stdio.h>

typedef struct dosesVacina {
  char nome[50];
  char cidade[50];
  int idade;
} DosesVacina;

void mostraDadosPacientes(DosesVacina paciente) {
  printf("\nNome do paciente: %s", paciente.nome);
  printf("\nCidade do paciente: %s", paciente.cidade);
  printf("\nIdade do paciente: %d\n", paciente.idade);
}

int main(void) {
  int nPacientes = 5;
  DosesVacina paciente[100];

  printf("\nCADASTRANDO %d PACIENTES\n", nPacientes);

  for (int i = 0; i < nPacientes; i++) {
    printf("\nDigite o nome do paciente: ");
    gets(paciente[i].nome);

    printf("Digite a cidade do paciente: ");
    gets(paciente[i].cidade);

    printf("Digite a idade do paciente: ");
    scanf("%d", &paciente[i].idade);

    fflush(stdin);
  }

  printf("\nLISTAGEM DE PACIENTES\n");

  for(int i = 0; i < nPacientes; i++) {
    mostraDadosPacientes(paciente[i]);
  }
  
}