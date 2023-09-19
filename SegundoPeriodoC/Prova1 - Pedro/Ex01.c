#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct livroCaixa {
    char situacao;
    Data dataLancamento;
    char tipoLancamento;
    char historicoLancamento[35];
    float valorLancamento;
} LivroCaixa;

typedef struct func {
    int cod;
    char nome[75];
    char genero;
    float salario;
    int NumDependentes;
    char considerar;
} Func;

void criaFunc(Func *funcionario) {
    printf("Eh para considerar esse cadastro? (S/N) ");
    scanf("%c", &funcionario->considerar);
    fflush(stdin);

    printf("Qual o codigo do funcionario? ");
    scanf("%d", &funcionario->cod);
    fflush(stdin);

    printf("Qual o nome do funcionario? ");
    gets(funcionario->nome);
    fflush(stdin);

    printf("Qual o genero do funcionario? (M/F) ");
    scanf("%c", &funcionario->genero);
    fflush(stdin);
    
    printf("Qual o salario do funcionario? ");
    scanf("%f", &funcionario->salario);
    fflush(stdin);

    printf("Qual o numero de dependentes do funcionario? ");
    scanf("%d", &funcionario->NumDependentes);
    fflush(stdin);
};

void removerCons(Func *funcionario, int codigo, int t) {
    for(int i = 0; i < t; i++) {
        if(funcionario[i].cod == codigo) {
            funcionario[i].considerar = 'N';
        }
    }
}

void imprimirFunc(Func *funcionario, int t) {
    for(int i = 0; i < t; i++) {
        if(funcionario[i].considerar == 'S') {
            printf("\n=========================================");
            printf("\nCodigo do funcionario: %d\n", funcionario[i].cod);
            printf("Nome do funcionario: %s\n", funcionario[i].nome);
            printf("Genero do funcionario: %c\n", funcionario[i].genero);
            if (funcionario[i].genero == 'F') {
                printf("Salario da funcionaria: %.2f\n", funcionario[i].salario);
                printf("Numero de dependentes: %d", funcionario[i].NumDependentes);
            } else {
                printf("Salario do funcionario: %.2f\n", funcionario[i].salario);
                printf("Numero de dependentes: %d", funcionario[i].NumDependentes);
            }
        }
    }
}

int calculoDependentes(Func *funcionario, char genero, int t) {
    int numDepen = 0;
    for(int i = 0; i < t; i++) {
        if (funcionario[i].considerar == 'S') {
            if(funcionario[i].genero == genero) {
                numDepen += funcionario[i].NumDependentes;
            } 
        }
    }
    return numDepen;
}

float calculoSalario(Func *funcionario, char genero, int t) {
    float salariosT = 0;
    for(int i = 0; i < t; i++) {
        if (funcionario[i].considerar == 'S') {
            if(funcionario[i].genero == genero) {
                salariosT += funcionario[i].salario;
            } 
        }
    }
    return salariosT;
}

float calculoSalarioMedio(Func *funcionario, char genero, int t) {
    float salariosT = 0, salariosM = 0;
    int count = 0;
    for(int i = 0; i < t; i++) {
        if (funcionario[i].considerar == 'S') {
            if(funcionario[i].genero == genero) {
                salariosT += funcionario[i].salario;
                count++;
            } 
        }
    }
    salariosM = salariosT / count;
    return salariosM;
}

void freeFunc(Func *funcionario) {
    free(funcionario);
}

int main(void) {
    char escolha;
    int escolhaOpcao = 0, i = 0, codigo, depM = 0, depF = 0, v = 0, codigoTeste;
    float salarioM = 0, salarioF = 0, salarioMm = 0, salarioTotal = 0;
    Func *funcionario = (Func *)malloc(100 * sizeof(Func));
    Func *funcTeste = (Func *)malloc(5 * sizeof(Func));

    do {
        printf("[1] Cadastrar dados\n[2] Processar Dados\n[3] Relatorio\n[4] Excluir Dados\n[0] Encerrar programa\nQual sera a proxima acao? ");
        scanf("%d", &escolhaOpcao);
        fflush(stdin);
        switch (escolhaOpcao) {
        case 1:
            criaFunc(&funcionario[i]);
            break;
        case 2:
            printf("\nTotal de dependentes -------------\n");
            depM = calculoDependentes(funcionario, 'M', i);
            depF = calculoDependentes(funcionario, 'F', i);
            printf("Funcionarios do sexo masculino = %d\n", depM);
            printf("Funcionarios do sexo feminino =  %d\n\n", depF);

            salarioM = calculoSalario(funcionario, 'M', i);
            salarioF = calculoSalario(funcionario, 'F', i);
            printf("Total Salarios: R$ %.2f\n\n", (salarioF + salarioM));
            printf("Funcionarios do sexo masculino = R$ %.2f\n", salarioM);
            printf("Funcionarios do sexo feminino =  R$ %.2f\n\n", salarioF);

            salarioMm = calculoSalarioMedio(funcionario, 'M', i);
            if (salarioMm == 0) {
                printf("Salario Medio dos funcionarios do sexo masculino = R$ 0.00\n\n");
            } else {
                printf("Salario Medio dos funcionarios do sexo masculino = R$ %.2f\n\n", salarioMm);
            }
            break;
        case 3:
            salarioTotal = 0;
            printf("\nNome ----------------------- Sexo Salario. Dep\n");
            printf("==============================================\n");
            for(int t = 0; t < i; t++) {
                if (funcionario[t].considerar == 'S') {
                    salarioTotal += funcionario[t].salario;
                    printf("                        %s\t%c  %.2f  %d\n", funcionario[t].nome, funcionario[t].genero, funcionario[t].salario, funcionario[t].NumDependentes);
                }
            }
            printf("==============================================\n");
            printf("                          Total =  %.2f\n", salarioTotal);
            break;
        case 4:
            printf("Informe o codigo do funcionario: ");
            scanf("%d", &codigo);
            fflush(stdin);
            removerCons(funcionario, codigo, i);
            break;
        case 0:
            escolha = 'N';
            break;
        default:
            printf("Erro");
            break;
        }

        printf("\nDeseja fazer uma nova acao (S/N)? ");
        scanf(" %c", &escolha);
        fflush(stdin);

        i++;
    } while (escolha == 'S' || escolha == 's');

    // Parte de exemplificar:
    printf("\nInicio da tarefa d)\n");
    for (v = 0; v < 2; v++) {
        criaFunc(&funcTeste[v]);
        printf("\n");
    }
    printf("\nAntes de desconsiderar: \n");
    imprimirFunc(funcTeste, v);
    printf("\n\nInforme o codigo do funcionario a se desconsiderar: ");
    scanf("%d", &codigoTeste);
    removerCons(funcTeste, codigoTeste, v);
    printf("\nApos desconsiderar: \n");
    imprimirFunc(funcTeste, v);

    freeFunc(funcionario);
}



