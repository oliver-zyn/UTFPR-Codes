#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAXTAM 100
#define DESLOCAMENTO 3

typedef struct aluno {
  int RA;
  char nome[50];
  char cpf[15];
  int codUsuario;
  int codTurma;
} Aluno;

typedef struct nota {
  int codNota;
  float valorNota;
} Nota;

typedef struct professor {
  int codProfessor;
  char nome[50];
  char cpf[15];
  int codUsuario;
} Professor;

typedef struct usuario {
  int codUsuario;
  char email[50];
  char senha[50];
  int professor;
} Usuario;

typedef struct turma {
  int codTurma;
  char nome[50];
  char disciplina[50];
  int qtdMaxAlunos;
  int codProfessorResp;
} Turma;

typedef struct pilha {
  void* itens[MAXTAM];
  int topo;
} Pilha;

Pilha* criaPilha() {
  Pilha *p = malloc(sizeof(Pilha));
  p->topo = -1;
  return p;
}

int pilhaCheia(Pilha* p) {
  return p->topo == MAXTAM-1;
}

void liberaPilha(Pilha* p) {
  free(p);
}

/* FUNCOES GERAIS */

int geraCod() {
  return rand() % 1000;
}

int exibeMenuInicial() {
  int opcao = 0;

  printf("\nEscolha uma opcao: \n");
  printf("1- Entrar como administrador\n");
  printf("2- Entrar como professor\n");
  printf("3- Entrar como aluno\n");
  printf("4- Sair\n");
  printf("Opcao: ");
  scanf("%d", &opcao);
  fflush(stdin);

  return opcao;
}

void inserePilha(Pilha* p, void* item) {
  if (pilhaCheia(p)) {
    printf("Erro: Pilha cheia!\n");
  } else {
    p->topo++;
    p->itens[p->topo] = item;
  }
}

/* FUNCOES ADM */

void criptografaSenha(char* senha) {
  int i = 0;
  while (senha[i] != '\0') {
    if (isalpha(senha[i])) {
        char base = islower(senha[i]) ? 'a' : 'A';
        senha[i] = (senha[i] - base + DESLOCAMENTO) % 26 + base;
    } else if (isdigit(senha[i])) {
        senha[i] = ((senha[i] - '0' + DESLOCAMENTO) % 10) + '0';
    }
    i++;
  }
}

void descriptografaSenha(char* senha) {
  int i = 0;
  while (senha[i] != '\0') {
    if (isalpha(senha[i])) {
      char base = islower(senha[i]) ? 'a' : 'A';
      senha[i] = (senha[i] - base - DESLOCAMENTO + 26) % 26 + base;
    } else if (isdigit(senha[i])) {
      senha[i] = ((senha[i] - '0' - DESLOCAMENTO + 10) % 10) + '0';
    }
    i++;
  }
}

//FUNÇÕES ADM -> USUARIOS

void cadastraUsuario(Pilha* pUsuarios, int codUsuario, char email[], char senha[], int professor) {
  Usuario* novoUsuario = malloc(sizeof(Usuario));
  criptografaSenha(senha);

  novoUsuario->codUsuario = codUsuario;
  strcpy(novoUsuario->email, email);
  strcpy(novoUsuario->senha, senha);
  novoUsuario->professor = professor;

  inserePilha(pUsuarios, novoUsuario);
}

int listarUsuarios(Pilha* pUsuarios, Pilha *pAlunos, Pilha *pProfessores, int filtro) {
  if (pUsuarios->topo < 1) {
    printf("\nNao existem usuarios cadastrados!\n");
    return 0;
  }

  for (int i = pUsuarios->topo; i >= 0; i--) {
    Usuario *usuario = (Usuario*)pUsuarios->itens[i];

    if ((usuario->professor == 1 && filtro == 0) || (usuario->professor == 0 && filtro == 1)) {
      continue;
    }

    if (filtro != 0) {
      for (int j = pProfessores->topo; j >= 0; j--) {
        Professor *professor = (Professor*)pProfessores->itens[j];
        if (usuario->codUsuario == professor->codUsuario) {
          printf("Codigo do Professor: %d, Nome: %s, Cpf: %s", professor->codProfessor,professor->nome, professor->cpf);
        }
      }
    }

    if (filtro != 1) {
      for (int j = pAlunos->topo; j >= 0; j--) {
        Aluno *aluno = (Aluno*)pAlunos->itens[j];
        if (usuario->codUsuario == aluno->codUsuario) {
          printf("RA do aluno: %d, Nome: %s, Cpf: %s", aluno->RA, aluno->nome, aluno->cpf);
        }
      }
    }

    printf(", Email: %s, Senha (criptografada): %s, Professor: %d\n", usuario->email, usuario->senha, usuario->professor);
  }

  return 1;
}

void atualizaUsuario(Pilha *pUsuarios, int codUsuario, char email[], char senha[]) {
  for (int j = pUsuarios->topo; j >= 0; j--) {
    Usuario* usuarioAtual = (Usuario*)pUsuarios->itens[j];

    if (usuarioAtual->codUsuario == codUsuario) {
      if (strcmp(email, "0") != 0) {
        strcpy(usuarioAtual->email, email);
      }

      if (strcmp(senha, "0") != 0) {
        criptografaSenha(senha);
        strcpy(usuarioAtual->senha, senha);
      }
      break;
    }
  }
}

int buscaCodigoUsuario(Pilha *pAlunoProfessor, int codAlunoProfessor, int professor) {
  int codUsuarioEncontrado = 0;

  for (int j = pAlunoProfessor->topo; j >= 0; j--) {
      if (professor == 1) {
          Professor* prof = (Professor*)pAlunoProfessor->itens[j];
          if (prof->codProfessor == codAlunoProfessor) {
              codUsuarioEncontrado = prof->codUsuario;
              break;
          }
      } else {
          Aluno* aluno = (Aluno*)pAlunoProfessor->itens[j];
          if (aluno->RA == codAlunoProfessor) {
              codUsuarioEncontrado = aluno->codUsuario;
              break;
          }
      }
  }

  return codUsuarioEncontrado;
}


//FUNÇÕES ADM -> ALUNOS

void cadastraAluno(Pilha* pAlunos, char nome[], char cpf[], int codUsuario) {
  Aluno* novoAluno = malloc(sizeof(Aluno));

  novoAluno->RA = geraCod();
  strcpy(novoAluno->nome, nome);
  strcpy(novoAluno->cpf, cpf);
  novoAluno->codUsuario = codUsuario;
  novoAluno->codTurma = 0;

  inserePilha(pAlunos, novoAluno);
  printf("\nAluno cadastrado com sucesso!\n");
}

void atualizaAluno(Pilha* pAlunos, int RA, char nome[], char cpf[]) {
  for (int i = pAlunos->topo; i >= 0; i--) {
    Aluno* alunoAtual = (Aluno*)pAlunos->itens[i];

      if (alunoAtual->RA == RA) {
        if (strcmp(nome, "0") != 0) {
          strcpy(alunoAtual->nome, nome);
        }

        if (strcmp(cpf, "0") != 0) {
          strcpy(alunoAtual->cpf, cpf);
        }

        break;
      }
  }
  printf("\nAluno atualizado com sucesso!\n");
}

int buscaAluno(Pilha *pAlunos, int RA) {
  int encontrouAluno = 0;
  
 for (int i = pAlunos->topo; i >= 0; i--) {
    Aluno *aluno = (Aluno*)pAlunos->itens[i];

    if (aluno->RA == RA) {
      encontrouAluno = 1;
      break;
    }
  }

  return encontrouAluno;
}

void excluirAluno(Pilha *pAlunos, Pilha *pUsuarios, int RA) {
  for (int i = pAlunos->topo; i >= 0; i--) {
    Aluno *alunoAtual = (Aluno*)pAlunos->itens[i];

    if (alunoAtual->RA == RA) {
      for (int j = pUsuarios->topo; j >= 0; j--) {
        Usuario* usuarioAtual = (Usuario*)pUsuarios->itens[j];

        if (usuarioAtual->codUsuario == alunoAtual->codUsuario) {
          for (int k = j; k < pUsuarios->topo; k++) {
            pUsuarios->itens[k] = pUsuarios->itens[k + 1];
          }

          pUsuarios->topo--;
          break;
        }
      }

      for (int k = i; k < pAlunos->topo; k++) {
        pAlunos->itens[k] = pAlunos->itens[k + 1];
      }

      pAlunos->topo--;
      break;
    }
  }

  printf("\nAluno excluido com sucesso!\n");
}

//FUNCOES ADM --> PROFESSORES

void cadastraProfessor(Pilha* pProfessores, char nome[], char cpf[], int codUsuario) {
  Professor* novoProfessor = malloc(sizeof(Professor));

  novoProfessor->codProfessor = geraCod();
  strcpy(novoProfessor->nome, nome);
  strcpy(novoProfessor->cpf, cpf);
  novoProfessor->codUsuario = codUsuario;

  inserePilha(pProfessores, novoProfessor);
  printf("\nProfessor cadastrado com sucesso!\n");
}

void atualizaProfessor(Pilha* pProfessores, int codProfessor, char nome[], char cpf[]) {
  for (int i = pProfessores->topo; i >= 0; i--) {
    Professor* professorAtual = (Professor*)pProfessores->itens[i];

    if (professorAtual->codProfessor == codProfessor) {
      if (strcmp(nome, "0") != 0) {
        strcpy(professorAtual->nome, nome);
      }

      if (strcmp(cpf, "0") != 0) {
        strcpy(professorAtual->cpf, cpf);
      }

      break;
    }
  }
  printf("\nProfessor atualizado com sucesso!\n");
}

int buscaProfessor(Pilha *pProfessores, int codProfessor) {
  int encontrouProfessor = 0;
  
 for (int i = pProfessores->topo; i >= 0; i--) {
    Professor *professor = (Professor*)pProfessores->itens[i];
    if (professor->codProfessor == codProfessor) {
      encontrouProfessor = 1;
      break;
    }
  }

  return encontrouProfessor;
}

void excluirProfessor(Pilha *pProfessores, Pilha *pUsuarios, int codProfessor) {
  for (int i = pProfessores->topo; i >= 0; i--) {
    Professor *professorAtual = (Professor*)pProfessores->itens[i];

    if (professorAtual->codProfessor == codProfessor) {
      for (int j = pUsuarios->topo; j >= 0; j--) {
        Usuario* usuarioAtual = (Usuario*)pUsuarios->itens[j];

        if (usuarioAtual->codUsuario == professorAtual->codUsuario) {
          for (int k = j; k < pUsuarios->topo; k++) {
            pUsuarios->itens[k] = pUsuarios->itens[k + 1];
          }

          pUsuarios->topo--;
          break;
        }
      }

      for (int k = i; k < pProfessores->topo; k++) {
        pProfessores->itens[k] = pProfessores->itens[k + 1];
      }

      pProfessores->topo--;
      break;
    }
  }

  printf("\nProfessor excluido com sucesso!\n");
}

//FUNCOES ADM --> LOGIN

int exibeMenuAdm() {
  int opcao = 0;

  printf("\n===== MENU DE ADMINISTRADOR =====\n");
  printf("\nEscolha uma opcao: \n");
  printf("1- Cadastrar aluno\n");
  printf("2- Cadastrar professor\n");
  printf("3- Editar aluno\n");
  printf("4- Editar professor\n");
  printf("5- Excluir aluno\n");
  printf("6- Excluir professor\n");
  printf("7- Visualizar usuarios do sistema\n");
  printf("8- Sair\n");
  printf("Opcao: ");
  scanf("%d", &opcao);
  fflush(stdin);

  return opcao;
}

void loginAdm(Pilha *pAlunos, Pilha *pProfessores, Pilha *pUsuarios) {
  int opcao = 0, codUsuario = 0, RA = 0, codProfessor = 0;
  char nome[50], email[50], senha[50], cpf[15];

  do {
    opcao = exibeMenuAdm();

    switch (opcao) {
    case 1:
      printf("\nDigite o nome do aluno: ");
      gets(nome);
      printf("Digite o cpf do aluno: ");
      gets(cpf);
      printf("Digite o email do aluno: ");
      gets(email);
      printf("Digite uma senha para o aluno: ");
      gets(senha);
      fflush(stdin);

      codUsuario = geraCod();

      cadastraUsuario(pUsuarios, codUsuario, email, senha, 0);
      cadastraAluno(pAlunos, nome, cpf, codUsuario);

      break;
    case 2:
      printf("\nDigite o nome do professor: ");
      gets(nome);
      printf("Digite o cpf do professor: ");
      gets(cpf);
      printf("Digite o email do professor: ");
      gets(email);
      printf("Digite uma senha para o professor: ");
      gets(senha);
      fflush(stdin);

      codUsuario = geraCod();

      cadastraUsuario(pUsuarios, codUsuario, email, senha, 1);
      cadastraProfessor(pProfessores, nome, cpf, codUsuario);

      break;
    case 3:
      printf("\nAlunos disponiveis para edicao:\n");

      if (listarUsuarios(pUsuarios, pAlunos, pProfessores, 0) == 0) {
        break;
      }

      printf("\nDigite o RA do aluno que deseja editar: ");
      scanf("%d", &RA);
      fflush(stdin);

      if(buscaAluno(pAlunos, RA) == 0) {
        printf("\nNenhum aluno com o RA %d foi encontrado!\n", RA);
        break;
      }

      printf("\nDigite o novo nome do aluno (0 para manter o mesmo): ");
      gets(nome);
      printf("Digite o cpf do aluno (0 para manter o mesmo): ");
      gets(cpf);
      printf("Digite o email do aluno (0 para manter o mesmo): ");
      gets(email);
      printf("Digite uma senha para o aluno (0 para manter a mesma): ");
      gets(senha);
      fflush(stdin);
      atualizaAluno(pAlunos, RA, nome, cpf);
      codUsuario = buscaCodigoUsuario(pAlunos, RA, 1);
      atualizaUsuario(pUsuarios, codUsuario, email, senha);

      break;
    case 4:
      printf("\nProfessores disponiveis para edicao:\n");

      if (listarUsuarios(pUsuarios, pAlunos, pProfessores, 1) == 0) {
        break;
      }

      printf("\nDigite o codigo do professor que deseja editar: ");
      scanf("%d", &codProfessor);
      fflush(stdin);

      if(buscaProfessor(pProfessores, codProfessor) == 0) {
        printf("\nNenhum professor com o codigo %d foi encontrado!\n", codProfessor);
        break;
      }

      printf("\nDigite o nome do professor (0 para manter o mesmo): ");
      gets(nome);
      printf("\nDigite o cpf do professor (0 para manter o mesmo): ");
      gets(cpf);
      printf("\nDigite o email do professor (0 para manter o mesmo): ");
      gets(email);
      printf("\nDigite uma senha para o professor (0 para manter a mesma): ");
      gets(senha);
      fflush(stdin);
      atualizaProfessor(pProfessores, codProfessor, nome, cpf);
      codUsuario = buscaCodigoUsuario(pProfessores, codProfessor, 1);
      atualizaUsuario(pUsuarios, codUsuario, email, senha);

      break;
    case 5:
      printf("\nAlunos disponiveis para exclusao:\n");

      if (listarUsuarios(pUsuarios, pAlunos, pProfessores, 0) == 0) {
        break;
      }

      printf("\nDigite o RA do aluno que deseja excluir: ");
      scanf("%d", &RA);
      fflush(stdin);

      if(buscaAluno(pAlunos, RA) == 0) {
        printf("\nNenhum aluno com o RA %d foi encontrado!\n", RA);
        break;
      }

      excluirAluno(pAlunos, pUsuarios, RA);

      break;
    case 6:
      printf("\nProfessores disponiveis para exclusao:\n");

      if (listarUsuarios(pUsuarios, pAlunos, pProfessores, 1) == 0) {
        break;
      }

      printf("\nDigite o codigo do professor que deseja excluir: ");
      scanf("%d", &codProfessor);
      fflush(stdin);

      if(buscaProfessor(pProfessores, codProfessor) == 0) {
        printf("\nNenhum professor com o codigo %d foi encontrado!\n", RA);
        break;
      }

      excluirProfessor(pProfessores, pUsuarios, codProfessor);

      break;
    case 7:
      printf("\nUsuarios cadastrados:\n");
      listarUsuarios(pUsuarios, pAlunos, pProfessores, 2);

      break;
    case 8:
      printf("\nSaindo...\n");

      break;
    default:
      printf("\nESCOLHA UMA OPCAO VALIDA!\n");

      break;
    }

  } while(opcao != 8);
}

/* FUNCOES PROFESSORES */

//FUNCOES PROFESSORES --> TURMAS

void cadastraTurma(Pilha* pTurmas, char nome[], char disciplina[], int qtdMaxAlunos, int codProfessorResp) {
  Turma* novaTurma = malloc(sizeof(Turma));

  novaTurma->codTurma = geraCod();
  strcpy(novaTurma->nome, nome);
  strcpy(novaTurma->disciplina, disciplina);
  novaTurma->qtdMaxAlunos = qtdMaxAlunos;
  novaTurma->codProfessorResp = codProfessorResp;

  inserePilha(pTurmas, novaTurma);
}

int listarTurmas(Pilha *pTurmas, Pilha *pAlunos, Pilha *pProfessores) {
  if (pTurmas->topo < 1) {
    printf("\nNao existem turmas cadastradas!\n");
    return 0;
  }

  for (int i = pTurmas->topo; i >= 0; i--) {
    Turma *turma = (Turma*)pTurmas->itens[i];

    printf("\nTurma: %s, \n- Codigo da turma: %d \n- Disciplina: %s \n- Quantidade maxima de alunos: %d \n- Alunos:", turma->nome, turma->codTurma, turma->disciplina, turma->qtdMaxAlunos);

    for (int j = pAlunos->topo; j >= 0; j--) {
      Aluno *aluno = (Aluno*)pAlunos->itens[j];
      if (turma->codTurma == aluno->codTurma) {
        printf("Nome: %s, ", aluno->nome);
      }
    }

    for (int j = pProfessores->topo; j >= 0; j--) {
      Professor *professor = (Professor*)pProfessores->itens[j];
      if (turma->codProfessorResp == professor->codProfessor) {
        printf("\n- Professor: %s", professor->nome);
        break;
      }
    }
  }

  return 1;
}

void atualizaTurma(Pilha* pTurmas, int codTurma, char nome[], char disciplina[], int qtdMaxAlunos) {
  for (int i = pTurmas->topo; i >= 0; i--) {
    Turma* turmaAtual = (Turma*)pTurmas->itens[i];

    if (turmaAtual->codTurma == codTurma) {
      if (strcmp(nome, "0") != 0) {
        strcpy(turmaAtual->nome, nome);
      }

      if (strcmp(disciplina, "0") != 0) {
        strcpy(turmaAtual->disciplina, disciplina);
      }

      if (qtdMaxAlunos != 0) {
        turmaAtual->qtdMaxAlunos = qtdMaxAlunos;
      }
      
      break;
    }
  }
  printf("\nTurma atualizada com sucesso!\n");
}

int buscaTurma(Pilha *pTurmas, int codTurma) {
  int encontrouTurma = 0;
  
  for (int i = pTurmas->topo; i >= 0; i--) {
    Turma *turma = (Turma*)pTurmas->itens[i];

    if (turma->codTurma == codTurma) {
      encontrouTurma = 1;
      break;
    }
  }

  return encontrouTurma;
}

int quantidadeAlunosTurma(Pilha *pAlunos, int codTurma) {
  int qtdAlunos = 0;

  for (int i = pAlunos->topo; i >= 0; i--) {
    Aluno *aluno = (Aluno*)pAlunos->itens[i];

    if (aluno->codTurma == codTurma) {
      qtdAlunos++;
    }
  }

  return qtdAlunos;
}

//FUNCOES PROFESSORES --> LOGIN

int buscaCodProfessor(Pilha *pProfessores, int codUsuario) {
  int codProfessor = 0;
  
  for (int i = pProfessores->topo; i >= 0; i--) {
    Professor *professor = (Professor*)pProfessores->itens[i];
      if (professor->codUsuario == codUsuario) {
        codProfessor = professor->codProfessor;
        break;
    }
  }

  return codProfessor;
}

int solicitaLoginProfessor(Pilha *pUsuarios) {
  char email[50], senha[50];
  int codUsuarioProfessor = 0;

  printf("\nDigite seu email: ");
  gets(email);
  printf("Digite sua senha: ");
  gets(senha);

  for (int i = pUsuarios->topo; i >= 0; i--) {
    Usuario *usuarioAtual = (Usuario*)pUsuarios->itens[i];
    char senhaAtual[50];
    strcpy(senhaAtual, usuarioAtual->senha);

    descriptografaSenha(senhaAtual);

    if (strcmp(usuarioAtual->email, email) == 0 && strcmp(senhaAtual, senha) == 0 && usuarioAtual->professor == 1) {
      codUsuarioProfessor = usuarioAtual->codUsuario;
      printf("\nLogin realizado com sucesso!\n");
      break;
    }
  }

  return codUsuarioProfessor;
}

int exibeMenuProfessor() {
  int opcao = 0;

  printf("\n===== MENU DE PROFESSOR =====\n");
  printf("\nEscolha uma opcao: \n");
  printf("1- Cadastrar uma turma\n");
  printf("2- Editar uma turma\n");
  printf("3- Excluir uma turma\n");
  printf("4- Adicionar alunos a uma turma\n");
  printf("5- Visualizar alunos por turma\n");
  printf("6- Visualizar todos os alunos\n");
  printf("7- Lancar notas\n");
  printf("8- Excluir notas\n");
  printf("9- Sair\n");
  printf("Opcao: ");
  scanf("%d", &opcao);
  fflush(stdin);

  return opcao;
}

void loginProfessores(Pilha *pAlunos, Pilha *pProfessores, Pilha *pUsuarios, Pilha *pTurmas) {
  char tentarNovamente, nome[50], disciplina[50];
  int codUsuarioProfessorLogado = 0, codProfessorLogado = 0, logou = 0, opcao = 0, qtdMaxAlunos = 0, codTurma = 0;
  
  do {
    codUsuarioProfessorLogado = solicitaLoginProfessor(pUsuarios);

    if (codUsuarioProfessorLogado == 0) {
      printf("\nUsuario e/ou senha invalidos!");

      printf("\nDeseja tentar logar novamente? (S/N): ");
      scanf("%c", &tentarNovamente);
      fflush(stdin);

      if (tentarNovamente != 'S' && tentarNovamente != 's') {
        return;
      }

    } else {
      logou = 1;
    }
  } while (logou == 0);

  codProfessorLogado = buscaCodProfessor(pProfessores, codUsuarioProfessorLogado);

  do {
    opcao = exibeMenuProfessor();

    switch (opcao) {
      case 1:
        printf("\nDigite o nome da turma: ");
        gets(nome);
        printf("Digite a disciplina da turma: ");
        gets(disciplina);
        printf("Digite a quantidade maxima de alunos permitidos na turma: ");
        scanf("%d", &qtdMaxAlunos);
        fflush(stdin);

        cadastraTurma(pTurmas, nome, disciplina, qtdMaxAlunos, codProfessorLogado);
        break;
      case 2:
        printf("\nTurmas disponiveis para edicao:\n");

        if (listarTurmas(pTurmas, pAlunos, pProfessores) == 0) {
          break;
        }

        printf("\nDigite o codigo da turma que deseja editar: ");
        scanf("%d", &codTurma);
        fflush(stdin);

        if(buscaTurma(pProfessores, codTurma) == 0) {
          printf("\nNenhuma turma com o codigo %d foi encontrada!\n", codTurma);
          break;
        }

        printf("\nDigite o nome da turma (0 para manter o mesmo): ");
        gets(nome);
        printf("\nDigite a disciplina da turma (0 para manter o mesmo): ");
        gets(disciplina);
        int qtdAlunosValida = 0;

        do {
          printf("\nDigite a quantidade maxima de alunos permitidos na turma (0 para manter o mesmo): ");
          scanf("%d", &qtdMaxAlunos);
          fflush(stdin);

          if (qtdMaxAlunos < quantidadeAlunosTurma(pAlunos, codTurma) || qtdMaxAlunos == 0) {
            printf("\nDigite uma quantidade maior que a quantidade de alunos cadastrados na turma!\n");
          } else {
            qtdAlunosValida = 1;
          }

        } while (qtdMaxAlunos != 1);
        
        atualizaTurma(pTurmas, codTurma, nome, disciplina, qtdMaxAlunos);

        break;
      case 9:
        printf("Saindo...");

        break;
      default:
        break;
    }

  } while (opcao != 9); 
  
}

int main(void) {
  Pilha *pAlunos = criaPilha();
  Pilha *pNotas = criaPilha();
  Pilha *pProfessores = criaPilha();
  Pilha *pUsuarios = criaPilha();
  Pilha *pTurmas = criaPilha();
  int opcao = 0;

  srand(time(NULL));

  do {
    opcao = exibeMenuInicial();

    switch (opcao) {
      case 1:
        loginAdm(pAlunos, pProfessores, pUsuarios);

        break;
      case 2:
        loginProfessores(pAlunos, pProfessores, pUsuarios, pTurmas);

        break;
      case 4:
        printf("Encerrando...");

        break;
      default:
        printf("\nESCOLHA UMA OPCAO VALIDA!\n");

        break;
    }
    
  } while (opcao != 4);
  
  liberaPilha(pAlunos);
  liberaPilha(pNotas);
  liberaPilha(pProfessores);
  liberaPilha(pUsuarios);
  liberaPilha(pTurmas);
}
