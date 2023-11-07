//QUESTÃO 03

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXTAM 100

typedef struct aluno{
  int numero;
  char nome[50];
} Aluno;

typedef struct nota {
  int numeroAluno;
  float valorNota;
} Nota;

typedef struct pilhaAlunos{
  Aluno aluno[MAXTAM];
  int topo;
} PilhaAlunos;

typedef struct pilhaNotas{
  Nota nota[MAXTAM];
  int topo;
} PilhaNotas;

//FUNCOES GERAIS

PilhaAlunos *criaPilhaVaziaAlunos(){
  PilhaAlunos *p = malloc(sizeof(PilhaAlunos));
  p->topo = -1;
  return p;
}

int pilhaCheiaAlunos(PilhaAlunos *p){
  return p->topo == MAXTAM-1;
}

void liberaPilhaAlunos(PilhaAlunos *p){
  free(p);
}

PilhaNotas *criaPilhaVaziaNotas(){
  PilhaNotas *p = malloc(sizeof(PilhaNotas));
  p->topo = -1;
  return p;
}

int pilhaCheiaNotas(PilhaNotas *p){
  return p->topo == MAXTAM-1;
}

void liberaPilhaNotas(PilhaNotas *p){
  free(p);
}

//FUNCOES ALUNOS

int geraNumeroAluno() {
  srand(time(NULL));
  return rand() % 1000;
}

void insereAluno(PilhaAlunos *p, char nome[]){
  if (pilhaCheiaAlunos(p)){
    printf("Erro: Pilha cheia!\n");
  } else {
    Aluno novoAluno;
    novoAluno.numero = geraNumeroAluno();
    strcpy(novoAluno.nome, nome);
    p->topo++;
    p->aluno[p->topo] = novoAluno;
    printf("Aluno %s cadastrado com sucesso\n", nome);
  }
}

int buscaAluno(PilhaAlunos *p, int numeroAluno) {
  int encontrouAluno = 0;
  
  for(int i = 0; i <= p->topo; i++) {
    if (p->aluno[i].numero == numeroAluno) {
      encontrouAluno = 1;
      break;
    }
  }

  return encontrouAluno;
}

void calcularMedia(PilhaAlunos *pAlunos, PilhaNotas *pNotas, int numeroAluno) {
  float somaNotas = 0;
  int numNotas = 0;

  for(int i = 0; i <= pAlunos->topo; i++) {
    if (pAlunos->aluno[i].numero == numeroAluno) {
      for(int j = 0; j <= pNotas->topo; j++) {
        if (pNotas->nota[j].numeroAluno == numeroAluno) {
          somaNotas += pNotas->nota[j].valorNota;
          numNotas++;
        }
      }
      if (numNotas > 0) {
        float media = somaNotas / numNotas;
        printf("Aluno %d (%s) Media: %.2f\n", pAlunos->aluno[i].numero, pAlunos->aluno[i].nome, media);
      } else {
        printf("Aluno %d (%s) nao possui notas cadastradas\n", pAlunos->aluno[i].numero, pAlunos->aluno[i].nome);
      }
      return;
    }
  }

  printf("Aluno %d nao encontrado\n", numeroAluno);
}

void listarAlunosSemNotas(PilhaAlunos *pAlunos, PilhaNotas *pNotas) {
  int encontrado = 0;

  for(int i = 0; i <= pAlunos->topo; i++) {
    int possuiNotas = 0;

    for(int j = 0; j <= pNotas->topo; j++) {
      if (pNotas->nota[j].numeroAluno == pAlunos->aluno[i].numero) {
        possuiNotas = 1;
        break;
      }
    }

    if (!possuiNotas) {
      printf("\nAluno %d (%s) nao possui notas cadastradas\n", pAlunos->aluno[i].numero, pAlunos->aluno[i].nome);
      encontrado = 1;
    }
  }

  if (!encontrado) {
    printf("\nNenhum aluno sem notas encontrado\n");
  }
}

void excluirAluno(PilhaAlunos *pAlunos, PilhaNotas *pNotas, int numeroAluno) {
  int alunoEncontrado = 0;

  for (int i = 0; i <= pAlunos->topo; i++) {
    if (pAlunos->aluno[i].numero == numeroAluno) {
      int possuiNotas = 0;

      for (int j = 0; j <= pNotas->topo; j++) {
        if (pNotas->nota[j].numeroAluno == numeroAluno) {
          possuiNotas = 1;
          break;
        }
      }

      if (possuiNotas) {
        printf("O aluno possui notas e nao pode ser excluido\n");
      } else {
        for (int k = i; k < pAlunos->topo; k++) {
          pAlunos->aluno[k] = pAlunos->aluno[k + 1];
        }
        pAlunos->topo--;
        printf("Aluno %d excluido com sucesso\n", numeroAluno);
      }

      alunoEncontrado = 1;
      break;
    }
  }

  if (!alunoEncontrado) {
    printf("Aluno com numero %d nao encontrado\n", numeroAluno);
  }
}

void trocaAlunos(Aluno *a, Aluno *b) {
  Aluno temp = *a;
  *a = *b;
  *b = temp;
}

int particiona(Aluno alunos[], int esquerda, int direita) {
  char pivo[50];
  strcpy(pivo, alunos[direita].nome);
  int i = (esquerda - 1);

  for (int j = esquerda; j < direita; j++) {
    if (strcmp(alunos[j].nome, pivo) < 0) {
      i++;
      trocaAlunos(&alunos[i], &alunos[j]);
    }
  }

  trocaAlunos(&alunos[i + 1], &alunos[direita]);
  return (i + 1);
}

void quicksort(Aluno alunos[], int esquerda, int direita) {
  if (esquerda < direita) {
    int indice_pivo = particiona(alunos, esquerda, direita);
    quicksort(alunos, esquerda, indice_pivo - 1);
    quicksort(alunos, indice_pivo + 1, direita);
  }
}

void ordenarAlunos(PilhaAlunos *pAlunos) {
  quicksort(pAlunos->aluno, 0, pAlunos->topo);
}

void exibirAlunosOrdenados(PilhaAlunos *pAlunos, PilhaNotas *pNotas) {
  ordenarAlunos(pAlunos);
  printf("\nLista de alunos em ordem alfabetica: \n");

  for (int i = 0; i <= pAlunos->topo; i++) {
    printf("Aluno %d (%s)\n", pAlunos->aluno[i].numero, pAlunos->aluno[i].nome);
    
    for (int j = 0; j <= pNotas->topo; j++) {
      if (pNotas->nota[j].numeroAluno == pAlunos->aluno[i].numero) {
        printf("  Nota: %.2f\n", pNotas->nota[j].valorNota);
      }
    }
  }
}

//FUNCOES NOTAS

int validaNota(PilhaAlunos *p, int numeroAluno, float valorNota) {
  int notaValida = 1;

  if (buscaAluno(p, numeroAluno) == 0) {
    notaValida = 0;
    printf("Aluno nao encontrado!\n");
  } else if (valorNota <= 10 && valorNota >= 0) {
    notaValida = 0;
    printf("A nota deve estar entre 0 e 10\n");
  }

  return notaValida;
}

void insereNota(PilhaNotas *p, PilhaAlunos *pAlunos, int numeroAluno, float valorNota){
  if (pilhaCheiaNotas(p)){
    printf("Erro: Pilha cheia!\n");
  } else if (validaNota(pAlunos, numeroAluno, valorNota) == 1) {
    Nota novaNota;
    novaNota.numeroAluno = numeroAluno;
    novaNota.valorNota = valorNota;
    p->topo++;
    p->nota[p->topo] = novaNota;
    printf("Nota do aluno %d incluida com sucesso.\n", numeroAluno);
  }
}

void excluirNota(PilhaNotas *pNotas, int numeroAluno, float valorNota) {
  int notaEncontrada = 0;

  for (int i = 0; i <= pNotas->topo; i++) {
    if (pNotas->nota[i].numeroAluno == numeroAluno && pNotas->nota[i].valorNota == valorNota) {
      for (int j = i; j < pNotas->topo; j++) {
          pNotas->nota[j] = pNotas->nota[j + 1];
      }
      pNotas->topo--;
      printf("Nota do aluno %d, valor %.2f excluida com sucesso.\n", numeroAluno, valorNota);
      notaEncontrada = 1;
      break;
    }
  }

  if (!notaEncontrada) {
      printf("Nota do aluno %d e valor %.2f nao foi encontrada\n", numeroAluno, valorNota);
  }
}

int exibeMenu() {
  int opcao = 0;

  printf("\nEscolha uma opcao: \n");
  printf("1- Cadastrar aluno\n");
  printf("2- Cadastrar nota\n");
  printf("3- Calcular a media de um aluno\n");
  printf("4- Listar os nomes dos alunos sem notas\n");
  printf("5- Excluir aluno\n");
  printf("6- Excluir nota\n");
  printf("7- Apresentar a lista de alunos ordenados\n");
  printf("8- Sair\n");
  printf("Opcao: ");
  scanf("%d", &opcao);
  fflush(stdin);

  return opcao;
}

int main(void) {
  PilhaAlunos *pAlunos = criaPilhaVaziaAlunos();
  PilhaNotas *pNotas = criaPilhaVaziaNotas();
  char nome[50];
  int opcao = 0, numeroAluno = 0;
  float nota;

  do { 
    opcao = exibeMenu();

    switch (opcao) {
      case 1:
        printf("\nDigite o nome do aluno: ");
        gets(nome);
        fflush(stdin);
        insereAluno(pAlunos, nome);
        break;

      case 2:
        printf("\nDigite o numero do aluno: ");
        scanf("%d", &numeroAluno);
        printf("Digite a nota: ");
        scanf("%f", &nota);
        insereNota(pNotas, pAlunos, numeroAluno, nota);

        break;

      case 3:
        printf("\nDigite o numero do aluno: ");
        scanf("%d", &numeroAluno);
        calcularMedia(pAlunos, pNotas, numeroAluno);
        break;
      
      case 4:
        listarAlunosSemNotas(pAlunos, pNotas);
        break;

      case 5:
        printf("\nDigite o numero do aluno que deseja excluir: ");
        scanf("%d", &numeroAluno);
        excluirAluno(pAlunos, pNotas, numeroAluno);
        break;

      case 6:
        printf("\nDigite o numero do aluno: ");
        scanf("%d", &numeroAluno);
        printf("Digite o valor da nota que deseja excluir: ");
        scanf("%f", &nota);
        excluirNota(pNotas, numeroAluno, nota);
        break;

      case 7:
        exibirAlunosOrdenados(pAlunos, pNotas);
        break;

      case 8:
        printf("\nSaindo...");
        break;
      
      default:
        printf("\nEscolha uma opcao valida!\n");
        break;
    }
  } while (opcao != 8);
  
  liberaPilhaAlunos(pAlunos);
  liberaPilhaNotas(pNotas);
}
