#include <stdio.h>
#include <string.h>

typedef struct filme {
  char titulo[50];
  char diretor[50];
  char genero[50];
  int duracao;
  int nota;
} Filme;

Filme cadastraFilme() {
  Filme filme;

  fflush(stdin);

  printf("\nInforme o titulo: ");
  gets(filme.titulo);

  printf("Informe o nome do diretor: ");
  gets(filme.diretor);

  fflush(stdin);

  printf("Informe o genero: ");
  gets(filme.genero);

  printf("Informe a duracao: ");
  scanf("%d", &filme.duracao);

  printf("Informe a nota (1 - 5): ");
  scanf("%d", &filme.nota);

  return filme;
}

void mostraFilme(Filme filme) {
  printf("\nTitulo: %s\n", filme.titulo);
  printf("Diretor: %s\n", filme.diretor);
  printf("Genero: %s\n", filme.genero);
  printf("Duracao: %i\n", filme.duracao);
  printf("Nota: %i\n\n", filme.nota);
}

Filme retornaFilmeMaisLongo(Filme filme[], int qtdFilmes) {
  Filme filmeMaisLongo;
  int maxDuracao = 0;

  for(int i = 0; i < qtdFilmes; i++) {
    if (filme[i].duracao > maxDuracao) {
      maxDuracao = filme[i].duracao;
      filmeMaisLongo = filme[i];
    }
  }

  return filmeMaisLongo;
}

void mostraFilmeEstrelas(Filme filme[], int qtdFilmes, int estrelas) {
  for(int i = 0; i < qtdFilmes; i++) {
    if (filme[i].nota == estrelas) {
      mostraFilme(filme[i]);
    }
  }
}

void mostraFilmesDiretor(Filme filme[], int qtdFilmes, char diretor[]) {
  for(int i = 0; i < qtdFilmes; i++){
      if (strcmp(diretor, filme[i].diretor) == 0) {
        mostraFilme(filme[i]);
      }
  }
}

void mostraFilmesGenero(Filme filme[], int qtdFilmes, char genero[]) {
  for(int i = 0; i < qtdFilmes; i++){
      if (strcmp(genero, filme[i].genero) == 0) {
        mostraFilme(filme[i]);
      }
  }
}

int main(void) {
  int nQtdFilmes = 0;
  char diretor[50], genero[50];

  printf("Quantos filmes deseja cadastrar? ");
  scanf("%d", &nQtdFilmes);

  Filme filme[nQtdFilmes];

  for(int i = 0; i < nQtdFilmes; i++) {
    filme[i] = cadastraFilme();
  }

  Filme filmeMaisLongo = retornaFilmeMaisLongo(filme, nQtdFilmes);
  printf("\n\nFILME MAIS LONGO:\n");
  mostraFilme(filmeMaisLongo);

  printf("\nFILMES COM 5 ESTRELAS\n");
  mostraFilmeEstrelas(filme, nQtdFilmes, 5);

  printf("\nFILMES COM 1 ESTRELA\n");
  mostraFilmeEstrelas(filme, nQtdFilmes, 1);

  fflush(stdin);  
  printf("\nInforme o diretor: ");
  gets(diretor);
  printf("\nFILMES DO DIRETOR %s\n", diretor);
  mostraFilmesDiretor(filme, nQtdFilmes, diretor);

  fflush(stdin);  
  printf("\nInforme o genero: ");
  gets(genero);
  printf("\nFILMES DO GENERO %s\n", genero);
  mostraFilmesGenero(filme, nQtdFilmes, genero);

}