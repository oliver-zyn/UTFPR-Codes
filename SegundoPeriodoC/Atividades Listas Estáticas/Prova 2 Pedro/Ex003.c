#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAM 100
typedef struct aluno Aluno;
typedef struct nota Nota;
typedef struct fila Fila;
typedef struct pilha Pilha;

int menu() {
    int opcao;
    char texto[] = "1 - Cadastrar Aluno\n2 - Cadastrar Nota\n3 - Calcular Media do Aluno\n4 - Listar nomes dos alunos sem notas\n5 - Excluir Aluno\n6 - Excluir nota\n7 - Apresentar lista de alunos ordenados\n8 - Sair\n";
    printf(texto);
    scanf("%d", &opcao);
    return opcao;
}

struct aluno{
    int numero;
    char nome[100];
};

struct nota{
    int numeroAluno;
    double nota;
};

struct pilha{
    Aluno aluno[MAXTAM];
    int topo;
};

struct fila{
    Nota nota[MAXTAM];
    int primeiro;
    int ultimo;
    int tamanho;
};

// FILA: 

Fila *criaFilaVazia(){
    Fila *f = malloc(sizeof(Fila));
    f->primeiro = 0;
    f->ultimo = 0;
    f->tamanho = 0;
    return f;
}

int filaCheia(Fila *f){
    return f->tamanho == MAXTAM;
}

int filaVazia(Fila *f){
    return f->tamanho == 0;
}

void enfileira(Fila *f, int numeroAluno, double nota){
    if (filaCheia(f)){
        printf("Erro: Fila cheia!");
    }else{
        Nota novanota;
        novanota.numeroAluno = numeroAluno;
        novanota.nota = nota;
        f->nota[f->ultimo] = novanota;
        f->ultimo = (f->ultimo+1) % MAXTAM;
        f->tamanho++;
    }
}

void imprimeFila(Fila *f){
    int t, i;
    i = f->primeiro;
    for(t = 0; t < f->tamanho; t++){
        printf("Numero do aluno: %d\n",f->nota[i].numeroAluno);
        printf("Nota: %lf\n",f->nota[i].nota);
        i = (i+1) % MAXTAM;
    }
}

void desinfileira(Fila *f){
    if (filaVazia(f)){
        printf("Erro: Fila vazia!");
    }else{
        f->primeiro = (f->primeiro + 1) % MAXTAM;
        f->tamanho--;
    }
}

void liberaFila(Fila *f){
    free(f);
}

// PILHA:

Pilha *criaPilhaVazia(){
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

int pilhaCheia(Pilha *p){
    return p->topo == MAXTAM-1;
}

int pilhaVazia(Pilha *p){
    return p->topo == -1;
}

void empilha(Pilha *p, char nome[]){
    if (pilhaCheia(p)){
        printf("Erro: Pilha cheia...!\n");
    }else{
        Aluno novoAluno;
        p->topo++;
        novoAluno.numero = p->topo + 1;
        strcpy(novoAluno.nome, nome);
        p->aluno[p->topo] = novoAluno;
    }
}

void imprimePilha(Pilha *p){
    int tam = p->topo;
    int i;
    for(i = tam; i >= 0; i--){
        printf("Numero: %d\n",p->aluno[i].numero);
        printf("Nome: %s\n",p->aluno[i].nome);
    }
}

void desempilha(Pilha *p){
    if(pilhaVazia(p)){
        printf("Erro: Pilha vaiza");
    }else{
        p->topo--;
    }
}

void liberaPilha(Pilha *p){
    free(p);
}

// ================================================================ //

void cadastrarAluno(Pilha *pilhaAlunos) {
    char nome[100];
    printf("Digite o nome do aluno: ");
    scanf("%s", nome);
    empilha(pilhaAlunos, nome);
    printf("Aluno cadastrado com sucesso!\n");
}

void cadastrarNota(Pilha *pilhaAlunos, Fila *filaNotas) {
    int numeroAluno;
    double nota;

    printf("Digite o numero do aluno: ");
    scanf("%d", &numeroAluno);

    if (numeroAluno < 1 || numeroAluno > pilhaAlunos->topo + 1) {
        printf("Aluno nao cadastrado.\n");
        return;
    }

    printf("Digite a nota do aluno (entre 0 e 10): ");
    scanf("%lf", &nota);

    if (nota < 0 || nota > 10) {
        printf("Nota invalida.\n");
        return;
    }

    enfileira(filaNotas, numeroAluno, nota);
    printf("Nota cadastrada com sucesso!\n");
}

void calcularMedia(Pilha *pilhaAlunos, Fila *filaNotas) {
    int numeroAluno;
    printf("Digite o numero do aluno: ");
    scanf("%d", &numeroAluno);

    if (numeroAluno < 1 || numeroAluno > pilhaAlunos->topo + 1) {
        printf("Aluno nao cadastrado.\n");
        return;
    }

    double somaNotas = 0;
    int contNotas = 0;
    for (int i = 0; i < filaNotas->tamanho; i++) {
        if (filaNotas->nota[i].numeroAluno == numeroAluno) {
            somaNotas += filaNotas->nota[i].nota;
            contNotas++;
        }
    }

    if (contNotas == 0) {
        printf("Nao ha notas cadastradas para este aluno.\n");
    } else {
        double media = somaNotas / contNotas;
        printf("Nome do aluno: %s\n", pilhaAlunos->aluno[numeroAluno - 1].nome);
        printf("Media do aluno: %.2lf\n", media);
    }
}

void listarAlunosSemNotas(Pilha *pilhaAlunos, Fila *filaNotas) {
    printf("Alunos sem notas cadastradas:\n");
    for (int i = 0; i <= pilhaAlunos->topo; i++) {
        int alunoTemNotas = 0;
        for (int j = 0; j < filaNotas->tamanho; j++) {
            if (filaNotas->nota[j].numeroAluno == i + 1) {
                alunoTemNotas = 1;
                break;
            }
        }
        if (alunoTemNotas == 0) {
            printf("Numero: %d, Nome: %s\n", i + 1, pilhaAlunos->aluno[i].nome);
        }
    }
}

void excluirAluno(Pilha *pilhaAlunos, Fila *filaNotas) {
    if (pilhaVazia(pilhaAlunos)) {
        printf("Nao ha alunos cadastrados para excluir.\n");
        return;
    }

    if (filaVazia(filaNotas)) {
        desempilha(pilhaAlunos);
        printf("Aluno excluido com sucesso!\n");
    } else {
        printf("Nao eh possivel excluir um aluno que possui notas cadastradas.\n");
    }
}

void excluirNota(Fila *filaNotas) {
    if (filaVazia(filaNotas)) {
        printf("Nao ha notas cadastradas para excluir.\n");
        return;
    }

    desinfileira(filaNotas);
    printf("Nota excluida com sucesso!\n");
}

void apresentarAlunosOrdenados(Pilha *pilhaAlunos) {
    Pilha *copiaPilha = criaPilhaVazia();
    Pilha *tempPilha = criaPilhaVazia();

    while (!pilhaVazia(pilhaAlunos)) {
        char nome[MAXTAM];
        strcpy(nome, pilhaAlunos->aluno[pilhaAlunos->topo].nome);
        empilha(tempPilha, nome);
        empilha(copiaPilha, nome);
        desempilha(pilhaAlunos);
    }

    while (!pilhaVazia(tempPilha)) {
        char nome[MAXTAM];
        strcpy(nome, tempPilha->aluno[tempPilha->topo].nome);
        empilha(pilhaAlunos, nome);
        desempilha(tempPilha);
    }

    int n = copiaPilha->topo + 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(copiaPilha->aluno[j].nome, copiaPilha->aluno[j + 1].nome) < 0) { // < em vez de >
                char temp[MAXTAM];
                strcpy(temp, copiaPilha->aluno[j].nome);
                strcpy(copiaPilha->aluno[j].nome, copiaPilha->aluno[j + 1].nome);
                strcpy(copiaPilha->aluno[j + 1].nome, temp);
            }
        }
    }

    printf("Alunos ordenados em ordem decrescente:\n");
    while (!pilhaVazia(copiaPilha)) {
        printf("Nome: %s\n", copiaPilha->aluno[copiaPilha->topo].nome);
        desempilha(copiaPilha);
    }

    liberaPilha(copiaPilha);
    liberaPilha(tempPilha);
}

int main() {
    Pilha *pilhaAlunos = criaPilhaVazia();
    Fila *filaNotas = criaFilaVazia();

    int opcao;
    do {
        opcao = menu();
        switch (opcao) {
            case 1:
                cadastrarAluno(pilhaAlunos);
                break;
            case 2:
                cadastrarNota(pilhaAlunos, filaNotas);
                break;
            case 3:
                calcularMedia(pilhaAlunos, filaNotas);
                break;
            case 4:
                listarAlunosSemNotas(pilhaAlunos, filaNotas);
                break;
            case 5:
                excluirAluno(pilhaAlunos, filaNotas);
                break;
            case 6:
                excluirNota(filaNotas);
                break;
            case 7:
                apresentarAlunosOrdenados(pilhaAlunos);
                break;
            case 8:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 8);

    liberaPilha(pilhaAlunos);
    liberaFila(filaNotas);

    return 0;
}
