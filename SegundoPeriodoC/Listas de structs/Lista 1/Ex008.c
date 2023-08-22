/*
8. Faça um programa que leia um vetor com dados de 5 livros: título, autor e ano. Permita ao
usuário:
• Cadastrar um livro;
• Buscar livros pelo título (mostrar todos os livros com o título igual ao buscado);
• Buscar livros pelo ano (mostrar todos os livros com o ano igual ao buscado);
*/

#include <stdio.h>
#include <string.h>

typedef struct livro {
    char titulo[50];
    char autor[75];
    int ano;
} Livro;

Livro cadastroDeLivro() {
    Livro livro;
    fflush(stdin);
    printf("Informe o titulo: ");
    gets(livro.titulo);
    printf("Informe o nome do autor: ");
    gets(livro.autor);
    fflush(stdin);
    printf("Informe o ano em que o livro foi lancado: ");
    scanf("%i", &livro.ano);
    printf("\n");
    return livro;
}

void imprimeLivro(Livro livro) {
    printf("\nTitulo: %s\n", livro.titulo);
    printf("Nome do autor: %s\n", livro.autor);
    printf("Ano: %i\n", livro.ano);
}

void mostraVetorStructLivro(Livro vet[], int tamanho)
{
    int i;

    for(i=0; i<tamanho; i++)
    {
        imprimeLivro(vet[i]);
    }
}

int main(void) {
    int numL = 2, pesquisar = 0;
    Livro livro[numL], livroPorAno[numL], livroPorTitulo[numL];

    for(int i = 0; i < numL; i++){
        livro[i] = cadastroDeLivro();
    }
    do {
        char titulo[50];
        int ano, numLA = 0, numLT = 0;
        int escolha = 0;
        printf("Informe se voce quer pesquisar por ano ou titulo o seu livro: (1-ano / 2-titulo): ");
        scanf("%d", &escolha);
        fflush(stdin);
        switch (escolha) {
            case 1:
                printf("Informe um ano: ");
                scanf("%d", &ano);
                fflush(stdin);
                for(int i = 0; i < numL; i++){
                    if (ano == livro[i].ano) {
                        livroPorAno[numLA] = livro[i];
                        numLA++;
                    }
                }
                printf("\n====== Livros pelo ano %d ======\n", ano);
                mostraVetorStructLivro(livroPorAno, numLA);
                break;
            case 2:
                fflush(stdin);  
                printf("Informe um titulo: ");
                gets(titulo);
                for(int i = 0; i < numL; i++){
                    if (strcmp(titulo, livro[i].titulo) == 0) {
                        livroPorTitulo[numLT] = livro[i];
                        numLT++;
                    }
                }
                printf("\n====== Livros pelo titulo '%s' ======\n", titulo);
                mostraVetorStructLivro(livroPorTitulo, numLT);
                break;
            default:
                printf("Escolha invalida!");
                break;
        }
        printf("Fazer nova pesquisa? (1-Sim/0-Nao): ");
        scanf("%d", &pesquisar);

    } while (pesquisar != 0);
}