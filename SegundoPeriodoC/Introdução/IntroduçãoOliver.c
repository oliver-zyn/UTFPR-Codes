#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct aluno {
  int RA;
  char nome[50];
  int notas[3];
  float media;
} Aluno;

int mostrarMenu() {
  int opcao;

  printf("\n\nEscolha uma opcao para seguir: \n");
  printf("1 - Cadastrar aluno \n");
  printf("2 - Exibir mural \n");
  printf("3 - Atualizar dados de um aluno \n");
  printf("4 - Encerrar\n");
  printf("Opcao: ");
  scanf("%d", &opcao);

  return opcao;
}

int mostrarMenuAtualizaAluno() {
  int opcao;

  printf("\nEscolha um dado para alterar: \n");
  printf("1 - Nome \n");
  printf("2 - Notas \n");
  printf("Opcao: ");
  scanf("%d", &opcao);

  return opcao;
}

float calculaMedia(int notas[]) {
  float somaMedia = 0;

  for(int j = 0; j < 3; j++) {
    somaMedia += notas[j];
  }

  return (somaMedia / 3);
}

Aluno cadastraAluno() {
  Aluno aluno;

  printf("\nDigite o RA do aluno: ");
  scanf("%d", &aluno.RA);
  fflush(stdin);

  printf("Digite o nome do aluno: ");
  gets(aluno.nome);

  for(int j = 0; j < 3; j++) {
    printf("Digite a nota %d do aluno %s: ", j + 1, aluno.nome);
    scanf("%d", &aluno.notas[j]);
  }

  aluno.media = calculaMedia(aluno.notas);

  printf("\nCADASTRO REALIZADO COM SUCESSO!");

  return aluno;
}

void imprimeAlunoMuralNotas(Aluno aluno) {
  printf("\n\nRA: %d \n", aluno.RA);
  printf("Aluno: %s \n", aluno.nome);
  printf("Notas do aluno: ");

  for(int j = 0; j < 3; j++) {
    printf("%d  ", aluno.notas[j]);
  }

  printf("\nMedia do aluno: %.2f", aluno.media);
}

Aluno atualizarNomeAluno(Aluno aluno, char novoNome[]) {
  strcpy(aluno.nome, novoNome);

  return aluno;
}

int main(void) {
  int numeroAlunos = 0, opcao, ra, mensagemAluno = 0;
  Aluno aluno[100];

  do {
    
  opcao = mostrarMenu();
    
  switch (opcao) {
    case 1:
      printf("\n============ CADASTRO DE ALUNO ============\n");

      fflush(stdin);
      aluno[numeroAlunos] = cadastraAluno();
      numeroAlunos++;
      break;

    case 2:
      printf("\n============ MURAL DE NOTAS ============\n\n");

      printf("Numero de alunos cadastrados: %d", numeroAlunos);

      for(int i = 0; i < numeroAlunos; i++) {
        imprimeAlunoMuralNotas(aluno[i]);
      }
      break;

    case 3:
      printf("\n============ ATUALIZANDO ALUNO ============\n\n");

      printf("Qual o RA do aluno que voce deseja atualizar? ");
      scanf("%d", &ra);

      for(int i = 0; i < numeroAlunos; i++) {
        if (aluno[i].RA == ra) {
          int opcao;
          char novoNome[50];

          opcao = mostrarMenuAtualizaAluno();
          fflush(stdin);

          switch (opcao) {
            case 1:
              printf("\nQual o novo nome para o aluno? ");
              gets(novoNome);
              aluno[i] = atualizarNomeAluno(aluno[i], novoNome);

              mensagemAluno = 1;

              break;
            case 2:
              for(int j = 0; j < 3; j++) {
                printf("Digite a nova nota %d do aluno %s: ", j + 1, aluno[i].nome);
                scanf("%d", &aluno[i].notas[j]);
              }
              
              aluno[i].media = calculaMedia(aluno[i].notas);
              mensagemAluno = 1;

              break;
            default:
              printf("\nOpcao invalida!");
              mensagemAluno = 2;

              break;
          }
        }
      }

      if (mensagemAluno == 1) {
        printf("\nAluno atualizado com sucesso!");
      } else if (mensagemAluno == 2) {
        printf("\nAluno nao atualizado!");
      } else {
        printf("\nAluno nao encontrado!");
      }

      mensagemAluno = 0;
      break;
    
    case 4:
      printf("\nEncerrando o aplicativo...");
      break;

    default:
      printf("\nInsira uma opcao valida!");
      break;
  }

  } while (opcao != 4);
}




