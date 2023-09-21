#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario {
    int codigo;
    char nome[50];
    char sexo;
    float salario;
    int numDependentes;
    char registroValido;
} Funcionario;

void cadastrarFuncionario(Funcionario *funcionario, int *qtdFuncionarios) {
    printf("\nDigite o codigo do funcionario: ");
    scanf("%d", &funcionario[*qtdFuncionarios].codigo);
    fflush(stdin);

    printf("Digite o nome do funcionario: ");
    scanf("%s", funcionario[*qtdFuncionarios].nome);

    printf("Digite o sexo do funcionario (M/F): ");
    scanf(" %c", &funcionario[*qtdFuncionarios].sexo);

    printf("Digite o valor do salario: ");
    scanf("%f", &funcionario[*qtdFuncionarios].salario);

    printf("Digite o numero de dependentes: ");
    scanf("%d", &funcionario[*qtdFuncionarios].numDependentes);

    printf("Digite se o registro deve ser considerado (S/N): ");
    scanf(" %c", &funcionario[*qtdFuncionarios].registroValido);

    printf("\nCADASTRO REALIZADO COM SUCESSO!\n");
}

int removerFuncionario(Funcionario *funcionarios, int qtdFuncionarios, int codigo) {
    for (int i = 0; i < qtdFuncionarios; i++) {
        if (funcionarios[i].codigo == codigo) {
            funcionarios[i].registroValido = 'N';
            return 1;
        }
    }
    return 0;
}

int qtdFuncionariosPorSexo(Funcionario *funcionarios, int qtdFuncionarios, char sexo) {
    int qtdFuncionariosSexo = 0;
    for (int i = 0; i < qtdFuncionarios; i++) {
        if (funcionarios[i].registroValido == 'S' && funcionarios[i].sexo == sexo) {
            qtdFuncionariosSexo++;
        }
    }
    return qtdFuncionariosSexo;
}

float calculaTotalSalarioFuncionarios(Funcionario *funcionarios, int qtdFuncionarios) {
    float totalSalarioFuncionarios = 0;
    for (int i = 0; i < qtdFuncionarios; i++) {
        if (funcionarios[i].registroValido == 'S') {
            totalSalarioFuncionarios += funcionarios[i].salario;
        }
    }
    return totalSalarioFuncionarios;
}

float calculaTotalSalarioPorSexo(Funcionario *funcionarios, int qtdFuncionarios, char sexo) {
    float totalSalarioPorSexo = 0;
    for (int i = 0; i < qtdFuncionarios; i++) {
        if (funcionarios[i].registroValido == 'S' && funcionarios[i].sexo == sexo) {
            totalSalarioPorSexo += funcionarios[i].salario;
        }
    }
    return totalSalarioPorSexo;
}

void processarDados(Funcionario *funcionarios, int qtdFuncionarios) {
    int qtdFuncionariosMasculinos = qtdFuncionariosPorSexo(funcionarios, qtdFuncionarios, 'M');
    int qtdFuncionariosFemininos = qtdFuncionariosPorSexo(funcionarios, qtdFuncionarios, 'F');

    float totalSalarioFuncionarios = calculaTotalSalarioFuncionarios(funcionarios, qtdFuncionarios);
    float totalSalarioMasculino = calculaTotalSalarioPorSexo(funcionarios, qtdFuncionarios, 'M');
    float totalSalarioFeminino = calculaTotalSalarioPorSexo(funcionarios, qtdFuncionarios, 'F');

    printf("\nTotal de Dependentes...........\n");
    printf("Funcionarios Sexo Masculino = %d\n", qtdFuncionariosMasculinos);
    printf("Funcionarios Sexo Feminino = %d\n", qtdFuncionariosFemininos);

    printf("\nTotal Salarios = R$ %.2f\n", totalSalarioFuncionarios);

    printf("\nTotal Salarios........................\n");
    printf("Funcionarios Sexo Masculino = R$ %.2f\n", totalSalarioMasculino);
    printf("Funcionarios Sexo Feminino = R$ %.2f\n", totalSalarioFeminino);

    if (qtdFuncionariosMasculinos > 0) {
        printf("\nSalario Medio dos Funcionarios do Sexo Masculino = R$ %.2f\n", (totalSalarioMasculino / qtdFuncionariosMasculinos));
    }
}

void imprimirRelatorio(Funcionario *funcionarios, int qtdFuncionarios) {
    printf("\nNome............................ Sexo Salario Dep\n");
    printf("=================================================\n");

    for (int i = 0; i < qtdFuncionarios; i++) {
        if (funcionarios[i].registroValido == 'S') {
            printf("%s\t\t\t\t %c    %.2f   %d\n", funcionarios[i].nome, funcionarios[i].sexo, funcionarios[i].salario, funcionarios[i].numDependentes);
        }
    }

    printf("=================================================\n");

    printf("\t\t\t\t Total: %.2f\n", calculaTotalSalarioFuncionarios(funcionarios, qtdFuncionarios));
}

int exibeMenu() {
    int opcaoMenu = 0;

    printf("\nESCOLHA UMA OPCAO: \n");

    printf("\n[1] Cadastrar Dados\n");
    printf("[2] Processar Dados\n");
    printf("[3] Relatorio\n");
    printf("[4] Excluir dados\n");
    printf("[0] Encerrar o Programa\n");
    printf("\nOpcao: ");
    scanf("%d", &opcaoMenu);

    return opcaoMenu;
}

int main(void) {
    int opcaoMenu = 0, qtdFuncionarios = 0;
    Funcionario *funcionarios = malloc(50 * sizeof(Funcionario));

    do {
        char cadastrarNovamente;

        opcaoMenu = exibeMenu();

        switch (opcaoMenu) {
            case 1:
                do {
                    cadastrarFuncionario(funcionarios, &qtdFuncionarios);
                    qtdFuncionarios++;
                    printf("\nDeseja cadastrar um novo funcionario? (S/N): ");
                    scanf(" %c", &cadastrarNovamente);
                } while (cadastrarNovamente == 'S' || cadastrarNovamente == 's');
                break;

            case 2:
                if (qtdFuncionarios == 0) {
                    printf("\nNENHUM FUNCIONARIO FOI CADASTRADO!\n");
                } else {
                    processarDados(funcionarios, qtdFuncionarios);
                }
                break;

            case 3:
                if (qtdFuncionarios == 0) {
                    printf("\nNENHUM FUNCIONARIO FOI CADASTRADO!\n");
                } else {
                    imprimirRelatorio(funcionarios, qtdFuncionarios);
                }
                break;

            case 4:
                if (qtdFuncionarios == 0) {
                    printf("\nNENHUM FUNCIONARIO FOI CADASTRADO!\n");
                } else {
                    int codigo = 0;
                    printf("\nInforme o codigo do funcionario que sera removido: ");
                    scanf("%d", &codigo);

                    if (removerFuncionario(funcionarios, qtdFuncionarios, codigo) == 1) {
                        printf("\nFUNCIONARIO %d REMOVIDO COM SUCESSO!\n", codigo);
                    } else {
                        printf("\nNENHUM FUNCIONARIO FOI ENCONTRADO!\n");
                    }
                }
                break;

            case 0:
                printf("\nENCERRANDO O PROGRAMA...\n");
                break;

            default:
                printf("\nOPCAO INVALIDA!\n");
                break;
        }
    } while (opcaoMenu != 0);

    free(funcionarios);
    return 0;
}
