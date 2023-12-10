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
  int raAluno;
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
  if (pAlunos->topo == -1 && filtro == 0) {
    printf("\nNao existem alunos cadastrados!\n");
    return 0;
  } else if (pProfessores->topo == -1 && filtro == 1) {
    printf("\nNao existem professores cadastrados!\n");
    return 0;
  } else if (pUsuarios->topo == -1 && filtro == 2) {
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
          printf("- Codigo do Professor: %d, Nome: %s, Cpf: %s", professor->codProfessor,professor->nome, professor->cpf);
        }
      }
    }

    if (filtro != 1) {
      for (int j = pAlunos->topo; j >= 0; j--) {
        Aluno *aluno = (Aluno*)pAlunos->itens[j];
        if (usuario->codUsuario == aluno->codUsuario) {
          printf("- RA do aluno: %d, Nome: %s, Cpf: %s", aluno->RA, aluno->nome, aluno->cpf);
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
      printf("Digite o cpf do professor (0 para manter o mesmo): ");
      gets(cpf);
      printf("Digite o email do professor (0 para manter o mesmo): ");
      gets(email);
      printf("Digite uma senha para o professor (0 para manter a mesma): ");
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

//FUNCOES PROFESSORES --> ALUNOS

int listarAlunosSemTurma(Pilha *pAlunos) {
  int encontrouAlunoSemTurma = 0;

  if (pAlunos->topo == -1) {
    printf("\nNao existem alunos cadastrados!\n");
    return 0;
  }

  for (int i = pAlunos->topo; i >= 0; i--) {
    Aluno *aluno = (Aluno*)pAlunos->itens[i];

    if (aluno->codTurma == 0) {
      encontrouAlunoSemTurma = 1;
      printf("\n- RA: %d, Nome: %s", aluno->RA, aluno->nome);
    }
  }

  if (encontrouAlunoSemTurma == 0) {
    printf("\nNenhum aluno sem turma foi encontrado!\n");
    return 0;
  }

  return 1;
}

int listarAlunosComTurma(Pilha *pAlunos, Pilha *pTurmas) {
  int encontrouAlunoComTurma = 0;

  if (pAlunos->topo == -1) {
    printf("\nNao existem alunos cadastrados!\n");
    return 0;
  }

  for (int i = pAlunos->topo; i >= 0; i--) {
    Aluno *aluno = (Aluno*)pAlunos->itens[i];

    if (aluno->codTurma != 0) {
      encontrouAlunoComTurma = 1;
      printf("\n- RA: %d, Nome: %s, ", aluno->RA, aluno->nome);

      for (int i = pTurmas->topo; i >= 0; i--) {
        Turma *turma = (Turma*)pTurmas->itens[i];

        if (turma->codTurma == aluno->codTurma) {
          printf("Turma vinculada: %s\n", turma->nome);
        }
      }
    }
  }

  if (encontrouAlunoComTurma == 0) {
    printf("\nNenhum aluno com turma foi encontrado!\n");
    return 0;
  }

  return 1;
}

int listarAlunosNotas(Pilha *pAlunos, Pilha *pNotas) {
  if (pAlunos->topo == -1) {
    printf("\nNao existem alunos cadastrados!\n");
    return 0;
  }

  for (int i = pAlunos->topo; i >= 0; i--) {
    Aluno *aluno = (Aluno*)pAlunos->itens[i];

    printf("\n- RA: %d, Nome: %s\n", aluno->RA, aluno->nome);

    for (int j = pNotas->topo; j >= 0; j--) {
      Nota *nota = (Nota*)pNotas->itens[j];

      if (nota->raAluno == aluno->RA) {
        printf("  - Nota: %.2f\n", nota->valorNota);
      }
    }
  }

  return 1;
}

//FUNCOES PROFESSORES --> NOTAS

void cadastraNota(Pilha* pNotas, int raAluno, float valorNota) {
  Nota* novaNota = malloc(sizeof(Turma));

  novaNota->codNota = geraCod();
  novaNota->raAluno = raAluno;
  novaNota->valorNota = valorNota;

  inserePilha(pNotas, novaNota);

  printf("\nNota lancada com sucesso!\n");
}

int validaNota(float valorNota) {
  int notaValida = 1;

  if (valorNota < 0 || valorNota > 10) {
    notaValida = 0;
    printf("\nA nota deve estar entre 0 e 10!\n");
  }

  return notaValida;
}

void excluirNotas(Pilha *pNotas, int RA) {
  int notaEncontrada = 0;

  for (int i = pNotas->topo; i >= 0; i--) {
    Nota *nota = (Nota*)pNotas->itens[i];

    if (nota->raAluno == RA) {
      for (int k = i; k < pNotas->topo; k++) {
        pNotas->itens[k] = pNotas->itens[k + 1];
      }

      pNotas->topo--;
      notaEncontrada = 1;
    }
  }

  if (!notaEncontrada) {
    printf("\nNenhuma nota para o aluno %d foi encontrada!\n", RA);
    return;
  }

  printf("\nNotas excluidas com sucesso!\n");
}

//FUNCOES PROFESSORES --> TURMAS

void cadastraTurma(Pilha* pTurmas, char nome[], char disciplina[], int qtdMaxAlunos, int codProfessorResp) {
  Turma* novaTurma = malloc(sizeof(Turma));

  novaTurma->codTurma = geraCod();
  strcpy(novaTurma->nome, nome);
  strcpy(novaTurma->disciplina, disciplina);
  novaTurma->qtdMaxAlunos = qtdMaxAlunos;
  novaTurma->codProfessorResp = codProfessorResp;

  inserePilha(pTurmas, novaTurma);

  printf("\nTurma cadastrada com sucesso!\n");
}

int listarTurmas(Pilha *pTurmas, Pilha *pAlunos, Pilha *pProfessores, Pilha *pNotas) {
  int turmaTemAluno = 0;

  if (pTurmas->topo == -1) {
    printf("\nNao existem turmas cadastradas!\n");
    return 0;
  }

  for (int i = pTurmas->topo; i >= 0; i--) {
    Turma *turma = (Turma*)pTurmas->itens[i];

    printf("\nTurma: %s: \n- Codigo da turma: %d \n- Disciplina: %s \n- Quantidade maxima de alunos: %d \n- Alunos: ", turma->nome, turma->codTurma, turma->disciplina, turma->qtdMaxAlunos);

    for (int j = pAlunos->topo; j >= 0; j--) {
      Aluno *aluno = (Aluno*)pAlunos->itens[j];
      int alunoTemNota = 0;
      if (turma->codTurma == aluno->codTurma) {
        printf("%s (", aluno->nome);

        for (int k = pNotas->topo; k >= 0; k--) {
          Nota *nota = (Nota*)pNotas->itens[k];

          if (nota->raAluno == aluno->RA) {
            printf("%.2f  ", nota->valorNota);
            alunoTemNota = 1;
          }
        }

        if (!alunoTemNota) {
          printf("sem notas");
        }

        printf("), ");

        turmaTemAluno = 1;
      }
    }

    if (!turmaTemAluno) {
      printf("Nenhum aluno");
    }

    for (int j = pProfessores->topo; j >= 0; j--) {
      Professor *professor = (Professor*)pProfessores->itens[j];
      if (turma->codProfessorResp == professor->codProfessor) {
        printf("\n- Professor: %s\n", professor->nome);
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

void excluirTurma(Pilha *pTurmas, int codTurma) {
  for (int i = pTurmas->topo; i >= 0; i--) {
    Turma* turmaAtual = (Turma*)pTurmas->itens[i];

    if (turmaAtual->codTurma == codTurma) {
      for (int k = i; k < pTurmas->topo; k++) {
        pTurmas->itens[k] = pTurmas->itens[k + 1];
      }

      pTurmas->topo--;
      break;
    }
  }

  printf("\nTurma excluida com sucesso!\n");
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

int verificaDisponibilidadeTurma(Pilha *pTurmas, Pilha *pAlunos, int codTurma) {
  int turmaDisponivel = 0;

  for (int i = pTurmas->topo; i >= 0; i--) {
    Turma *turma = (Turma*)pTurmas->itens[i];

    if (turma->codTurma == codTurma && quantidadeAlunosTurma(pAlunos, codTurma) < turma->qtdMaxAlunos) {
      turmaDisponivel = 1;
      break;
    }
  }

  return turmaDisponivel;
}

void incluirAlunoEmTurma(Pilha *pAlunos, int RA, int codTurma) {
  for (int i = pAlunos->topo; i >= 0; i--) {
    Aluno *aluno = (Aluno*)pAlunos->itens[i];

    if (aluno->RA == RA) {
      aluno->codTurma = codTurma;
    }
  }

  printf("\nAluno incluido com sucesso!\n");
}

void removerAlunoTurma(Pilha *pAlunos, int RA) {
  for (int i = pAlunos->topo; i >= 0; i--) {
    Aluno *aluno = (Aluno*)pAlunos->itens[i];

    if (aluno->RA == RA) {
      aluno->codTurma = 0;
    }
  }

  printf("\nAluno removido com sucesso!\n");
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

int solicitaLogin(Pilha *pUsuarios, int professor) {
  char email[50], senha[50];
  int codUsuario = 0;

  printf("\nDigite seu email: ");
  gets(email);
  printf("Digite sua senha: ");
  gets(senha);

  for (int i = pUsuarios->topo; i >= 0; i--) {
    Usuario *usuarioAtual = (Usuario*)pUsuarios->itens[i];
    char senhaAtual[50];
    strcpy(senhaAtual, usuarioAtual->senha);

    descriptografaSenha(senhaAtual);

    if (strcmp(usuarioAtual->email, email) == 0 && strcmp(senhaAtual, senha) == 0 && usuarioAtual->professor == professor) {
      codUsuario = usuarioAtual->codUsuario;
      printf("\nLogin realizado com sucesso!\n");
      break;
    }
  }

  return codUsuario;
}

int exibeMenuProfessor() {
  int opcao = 0;

  printf("\n===== MENU DE PROFESSOR =====\n");
  printf("\nEscolha uma opcao: \n");
  printf("1- Cadastrar uma turma\n");
  printf("2- Editar uma turma\n");
  printf("3- Excluir uma turma\n");
  printf("4- Adicionar aluno a uma turma\n");
  printf("5- Remover aluno de uma turma\n");
  printf("6- Visualizar alunos e turmas\n");
  printf("7- Lancar notas\n");
  printf("8- Excluir notas\n");
  printf("9- Sair\n");
  printf("Opcao: ");
  scanf("%d", &opcao);
  fflush(stdin);

  return opcao;
}

void loginProfessor(Pilha *pAlunos, Pilha *pProfessores, Pilha *pUsuarios, Pilha *pTurmas, Pilha *pNotas) {
  char tentarNovamente, nome[50], disciplina[50];
  int codUsuarioProfessorLogado = 0, codProfessorLogado = 0, logou = 0, opcao = 0, qtdMaxAlunos = 0, codTurma = 0, RA = 0;
  float nota = 0;
  
  do {
    codUsuarioProfessorLogado = solicitaLogin(pUsuarios, 1);

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
        printf("\n==== Turmas disponiveis para edicao ====\n");

        if (listarTurmas(pTurmas, pAlunos, pProfessores, pNotas) == 0) {
          break;
        }

        printf("\nDigite o codigo da turma que deseja editar: ");
        scanf("%d", &codTurma);
        fflush(stdin);

        if(buscaTurma(pTurmas, codTurma) == 0) {
          printf("\nNenhuma turma com o codigo %d foi encontrada!\n", codTurma);
          break;
        }

        printf("\nDigite o nome da turma (0 para manter o mesmo): ");
        gets(nome);
        printf("Digite a disciplina da turma (0 para manter o mesmo): ");
        gets(disciplina);
        int qtdAlunosValida = 0;

        do {
          printf("Digite a quantidade maxima de alunos permitidos na turma (0 para manter o mesmo): ");
          scanf("%d", &qtdMaxAlunos);
          fflush(stdin);

          if (qtdMaxAlunos < quantidadeAlunosTurma(pAlunos, codTurma) && qtdMaxAlunos != 0) {
            printf("\nDigite uma quantidade maior ou igual a quantidade de alunos cadastrados na turma!\n\n");
          } else {
            qtdAlunosValida = 1;
          }

        } while (qtdAlunosValida != 1);
        
        atualizaTurma(pTurmas, codTurma, nome, disciplina, qtdMaxAlunos);

        break;
      case 3:
        printf("\n==== Turmas disponiveis para exclusao ====\n");

        if (listarTurmas(pTurmas, pAlunos, pProfessores, pNotas) == 0) {
          break;
        }

        printf("\nDigite o codigo da turma que deseja excluir: ");
        scanf("%d", &codTurma);
        fflush(stdin);

        if(buscaTurma(pTurmas, codTurma) == 0) {
          printf("\nNenhuma turma com o codigo %d foi encontrada!\n", codTurma);
          break;
        }

        if(quantidadeAlunosTurma(pAlunos, codTurma) > 0) {
          printf("\nAinda existem alunos vinculados a essa turma!\n");
          break;
        }

        excluirTurma(pTurmas, codTurma);

        break;
      case 4:
        printf("\n==== Alunos sem turma disponiveis ====\n");

        if (listarAlunosSemTurma(pAlunos) == 0) {
          break;
        }

        printf("\n\nDigite o RA do aluno que deseja incluir em uma turma: ");
        scanf("%d", &RA);
        fflush(stdin);

        if(buscaAluno(pAlunos, RA) == 0) {
          printf("\nNenhum aluno com o RA %d foi encontrado!\n", RA);
          break;
        }

        printf("\n==== Turmas disponiveis ====\n");

        if (listarTurmas(pTurmas, pAlunos, pProfessores, pNotas) == 0) {
          break;
        }

        printf("\nDigite o codigo da turma que deseja incluir o aluno %d: ", RA);
        scanf("%d", &codTurma);
        fflush(stdin);

        if(buscaTurma(pTurmas, codTurma) == 0) {
          printf("\nNenhuma turma com o codigo %d foi encontrada!\n", codTurma);
          break;
        }

        if(verificaDisponibilidadeTurma(pTurmas, pAlunos, codTurma) == 0) {
          printf("\nA turma escolhida ja esta cheia!\n");
          break;
        }

        incluirAlunoEmTurma(pAlunos, RA, codTurma);
      
        break;
      case 5:
        printf("\n==== Alunos com turma ====\n");

        if (listarAlunosComTurma(pAlunos, pTurmas) == 0) {
          break;
        }

        printf("\nDigite o RA do aluno que deseja remover da turma: ");
        scanf("%d", &RA);
        fflush(stdin);

        if(buscaAluno(pAlunos, RA) == 0) {
          printf("\nNenhum aluno com o RA %d foi encontrado!\n", RA);
          break;
        }

        removerAlunoTurma(pAlunos, RA);

        break;
      case 6:
        printf("\n==== Alunos sem turma ====\n");
        if (listarAlunosSemTurma(pAlunos) == 0) {
          break;
        }

        printf("\n==== Turmas ====\n");
        if (listarTurmas(pTurmas, pAlunos, pProfessores, pNotas) == 0) {
          break;
        }

        break;

      case 7:
        printf("\n==== Alunos disponiveis no sistema ====\n");

        if (listarAlunosNotas(pAlunos, pNotas) == 0) {
          break;
        }

        printf("\nDigite o RA do aluno que deseja lancar uma nota: ");
        scanf("%d", &RA);
        fflush(stdin);

        if(buscaAluno(pAlunos, RA) == 0) {
          printf("\nNenhum aluno com o RA %d foi encontrado!\n", RA);
          break;
        }

        printf("\nDigite a nota para o aluno: ");
        scanf("%f", &nota);

        if(validaNota(nota) == 0) {
          break;
        }

        cadastraNota(pNotas, RA, nota);

        break;
      
      case 8:
        printf("\n==== Alunos disponiveis no sistema ====\n");

        if (listarAlunosNotas(pAlunos, pNotas) == 0) {
          break;
        }

        printf("\nDigite o RA do aluno que deseja excluir as notas: ");
        scanf("%d", &RA);
        fflush(stdin);

        if(buscaAluno(pAlunos, RA) == 0) {
          printf("\nNenhum aluno com o RA %d foi encontrado!\n", RA);
          break;
        }

        excluirNotas(pNotas, RA);

        break;
      case 9:
        printf("\nSaindo...\n");

        break;
      default:
        printf("\nESCOLHA UMA OPCAO VALIDA!\n");

        break;
    }

  } while (opcao != 9); 
}

/* FUNCOES ALUNOS */

float calcularMedia(Pilha *pAlunos, Pilha *pNotas, int RA) {
  float somaNotas = 0;
  int numNotas = 0;

  for (int i = pAlunos->topo; i >= 0; i--) {
    Aluno *aluno = (Aluno*)pAlunos->itens[i];

    if (aluno->RA == RA) {

      for (int j = pNotas->topo; j >= 0; j--) {
        Nota *nota = (Nota*)pNotas->itens[j];

        if (nota->raAluno == aluno->RA) {
          somaNotas += nota->valorNota;
          numNotas++;
        }
      }

      if (numNotas > 0) {
        float media = somaNotas / numNotas;
        return media;
      }

    break;
    }
  }

  return 0;
}

void visualizarBoletimAluno(Pilha *pAlunos, Pilha *pNotas, Pilha *pTurmas, int RA) {
  int encontrouTurma = 0, encontrouNota = 0;
  float media = 0;

  for (int i = pAlunos->topo; i >= 0; i--) {
    Aluno *aluno = (Aluno*)pAlunos->itens[i];

    if (aluno->RA == RA) {
      printf("\n==== BOLETIM ALUNO: %s - %d ====\n", aluno->nome, aluno->RA);
      printf("\nTurma: ");

      for (int j = pTurmas->topo; j >= 0; j--) {
        Turma *turma = (Turma*)pTurmas->itens[j];

        if (turma->codTurma == aluno->codTurma) {
          printf("%s", turma->nome);
          encontrouTurma = 1;
          break;
        }
      }

      if (!encontrouTurma) {
        printf("Nenhuma turma");
      }

      printf("\nNotas:");

      for (int j = pNotas->topo; j >= 0; j--) {
        Nota *nota = (Nota*)pNotas->itens[j];

        if (nota->raAluno == aluno->RA) {
          printf(" %.2f", nota->valorNota);
          encontrouNota = 1;
        }
      }

      if (!encontrouNota) {
        printf(" Nenhuma nota");
      }

      media = calcularMedia(pAlunos, pNotas, RA);

      printf("\nMedia: %.2f\n", media);
      printf("Situacao: ");

      if (media >= 7) {
        printf("Aprovado\n");
      } else {
        printf("Reprovado\n");
      }
    }
  }
}

void listaColegasTurma(Pilha *pAlunos, Pilha *pTurmas, int RA) {
  int codTurma = 0;
  char nomeTurma[50], disciplinaTurma[50];

  for (int i = pAlunos->topo; i >= 0; i--) {
    Aluno *aluno = (Aluno*)pAlunos->itens[i];

    if (aluno->RA == RA) {

      if (aluno->codTurma == 0) {
        printf("\nVoce nao esta cadastrado em nenhuma turma!\n");
        return;
      }

      codTurma = aluno->codTurma;
      break;
    }
  }

  for (int i = pTurmas->topo; i >= 0; i--) {
    Turma *turma = (Turma*)pTurmas->itens[i];

    if (turma->codTurma == codTurma) {
      strcpy(nomeTurma, turma->nome);
      strcpy(disciplinaTurma, turma->disciplina);
      break;
    }
  }

  printf("\n==== COLEGAS DE TURMA ====\n\n");
  for (int i = pAlunos->topo; i >= 0; i--) {
    Aluno *aluno = (Aluno*)pAlunos->itens[i];

    if (aluno->codTurma == codTurma && aluno->RA != RA) {
      printf("- Colega: %s\n", aluno->nome);
    }
  }

  printf("\nTurma: %s\n", nomeTurma);
  printf("Disciplina: %s\n", disciplinaTurma);
}

//FUNCOES ALUNOS --> LOGIN

int buscaRaAluno(Pilha *pAlunos, int codUsuario) {
  int RA = 0;
  
  for (int i = pAlunos->topo; i >= 0; i--) {
    Aluno *aluno = (Aluno*)pAlunos->itens[i];

    if (aluno->codUsuario == codUsuario) {
      RA = aluno->RA;
      break;
    }
  }

  return RA;
}

int exibeMenuAluno() {
  int opcao = 0;

  printf("\n===== MENU DE ALUNO =====\n");
  printf("\nEscolha uma opcao: \n");
  printf("1- Visualizar boletim\n");
  printf("2- Visualizar colegas de turma\n");
  printf("3- Sair\n");
  printf("Opcao: ");
  scanf("%d", &opcao);
  fflush(stdin);

  return opcao;
}

void loginAluno(Pilha *pAlunos, Pilha *pUsuarios, Pilha *pTurmas, Pilha *pNotas) {
  int codUsuarioAlunoLogado = 0, logou = 0, opcao = 0, RaAlunoLogado = 0;
  char tentarNovamente;

  do {
    codUsuarioAlunoLogado = solicitaLogin(pUsuarios, 0);

    if (codUsuarioAlunoLogado == 0) {
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

  RaAlunoLogado = buscaRaAluno(pAlunos, codUsuarioAlunoLogado);

  do {
    opcao = exibeMenuAluno();

    switch (opcao) {
      case 1:
        visualizarBoletimAluno(pAlunos, pNotas, pTurmas, RaAlunoLogado);

        break;
      case 2:
        listaColegasTurma(pAlunos, pTurmas, RaAlunoLogado);

        break;
      case 3:
        printf("\nSaindo...\n");

        break;
      default:
        printf("\nESCOLHA UMA OPCAO VALIDA!\n");

        break;
      }
  } while (opcao != 3); 

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
        loginProfessor(pAlunos, pProfessores, pUsuarios, pTurmas, pNotas);

        break;
      case 3:
        loginAluno(pAlunos, pUsuarios, pTurmas, pNotas);

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
