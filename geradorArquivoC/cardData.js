const cardData = [
    { 
        id: '1',
        title: 'Máximo Divisor', 
        description: 'O maior divisor comum (MDC) é o maior número que divide dois ou mais números sem deixar resto. O MDC é obtido encontrando os fatores comuns aos números e selecionando o maior deles.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Divisores/Maximo%20Divisor.h',
        code: `
int maxDiv(int num, int num2) {

    int i, soma = 0, max1 = 0, max2 = 0, max3 = 0;
    
    for (i = 1; i <= num; i++) {
        if (num%i == 0) {
            if (max1 < i) {
                max1 = i;
            }
        }
    }

    for (i = 1; i <= num2; i++) {
        if (num2%i == 0) {
            if (max2 < i) {
                max2 = i;
            }
        }
        if (max1 == max2 && max3 < max1) {
            max3 = max1;
        }
    }
    return max3;
}
        `
    },
    {
        id: '2',
        title: 'Quais os divisores de um número', 
        description: 'Divisores de um número são os números inteiros que podem ser divididos uniformemente por ele. Incluem o próprio número, 1 e outros fatores desse número.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Divisores/Quais%20Os%20DIVISORES.h',
        code: `
void quaisDiv(int num) {

    int i;
    
    for (i = 1; i <= num; i++) {
        if (num%i == 0) {
            printf("%i  ",i);
        } 
    }
}
        `
    },
    { 
        id: '3',
        title: 'Quantidade de divisores de um número', 
        description: 'A quantidade de divisores de um número é a contagem total de todos os números inteiros pelos quais o número pode ser dividido uniformemente, incluindo o próprio número e o 1.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Divisores/Quantidade%20De%20DIVISORES.h',
        code: `
int qtdDivisores(int num) {

    int i, cont = 0;
    
    for (i = 1; i <= num; i++) {
        if (num%i == 0) {
            cont++;
        }
    }
    return cont;
}
        `
    },
    { 
        id: '4',
        title: 'Soma dos divisores de um número', 
        description: 'A soma dos divisores de um número é o resultado da adição de todos os divisores desse número. Para calcular essa soma, é necessário identificar todos os divisores do número e, em seguida, somá-los.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Divisores/Soma%20Dos%20Divisores.h',
        code: `
int somaDiv(int num) {

    int i, soma = 0;
    
    for (i = 1; i <= num; i++) {
        if (num%i == 0) {
            soma += i;
        }
    }
    
    return soma;
}
        `
    },
    { 
        id: '5',
        title: 'Calcula o divisor comum', 
        description: 'Calcular o divisor comum de dois ou mais números envolve encontrar o maior número que divide uniformemente todos os números dados. Para isso, é necessário listar os divisores de cada número e identificar os divisores que são comuns a todos eles. ',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Divisores/calculaDivisorComum.h',
        code: `
int somaDiv(int num) {

    int i, soma = 0;
    
    for (i = 1; i <= num; i++) {
        if (num%i == 0) {
            soma += i;
        }
    }
    
    return soma;
}
        `
    },
    { 
        id: '6',
        title: 'Criar árvore de natal', 
        description: 'Exibe uma árvore de Natal no console, utilizando como parâmetro um número que representa o tamanho dessa árvore. Ela utiliza caracteres especiais, como asteriscos e espaços, para criar uma representação gráfica da árvore.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Formas%20Geometricas/Fazer%20Arvore%20de%20Natal.h',
        code: `
int montaArvore(int num) {
    int i, j;
    
    for(i = 0; i <= num; i++) {
        for(j = num; i <= j; j--) {
            printf(" ");
        }
        
        for(j = 0; j <= i; j++) {
            printf("*");
        }
    
        for(j = 1; j <= i; j++) {
            printf("*");
        }
        
        printf("\\n");
    }
    
    for(i = 0; i <= 5; i++) {
        for(j = 0; j <= num; j++) {
            printf(" ");
        }

        printf("*\\n");
    }
    
}
        `
    },
    { 
        id: '7',
        title: 'Cria um losango', 
        description: 'Exibe um losango no console, utilizando como parâmetro um número que representa o seu tamanho. Ele utiliza caracteres especiais, como asteriscos e espaços, para criar uma representação gráfica do losango.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Formas%20Geometricas/Fazer%20um%20Losango.h',
        code: `
void dima(int num) {

    if (num % 2 == 0) {
        printf("Numero par, opcao invalida!");
    } else {
        
        int i, y, j;
        
        for (i = 1; i<=(num/2) + 1; i++) {
            for (y = num; i <= y; y--) {
                printf(" ");
            }
            for (y = 1; y <= i; y++) {
                printf("*");
            }
            for (y = 2; y <= i; y++) {
                printf("*");
            }
        printf("\\n");

        }
        for (i = (num/2), j = 1; i>=j; i--) {
            for (y = num; i <= y; y--) {
                printf(" ");
            }
            for (y = 1; y <= i; y++) {
                printf("*");
            }
            for (y = 2; y <= i; y++) {
                printf("*");
            }
        printf("\\n");
        }
    }
}
        `
    },
    { 
        id: '8',
        title: 'Cria um quadrado', 
        description: 'Exibe um quadrado no console, utilizando como parâmetro a sua quantidade de linhas e colunas, além de ser possível passar um caracter específico para que esse quadrado seja montado.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Formas%20Geometricas/FazerQuadrado.h',
        code: `
void quadrado(int numLinhas, int numColunas, int caractere) {

    int i, count;
    
    for (i = 0; i < (numColunas * numLinhas); i++) {
        if (count == numColunas - 1) {
            printf("%c\\n", caractere);
            count = 0;
        } else {
            printf("%c ", caractere);
            count++;
        }
    }
}
        `
    },
    { 
        id: '9',
        title: 'Cria um triângulo vazado / preenchido', 
        description: 'Exibe um triângulo no console, utilizando como parâmetro um número para definir seu tamanho, além de uma opção para definir se o triângulo deve ser ou não preenchido com caracteres.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Formas%20Geometricas/TrianguloVazadoPreenchido.h',
        code: `
void trianguloVazadoOuPreenchido(int num, char opcao) {
    int i, y, j;
    
    if (opcao == 'P' || opcao == 'p') {
        for (i = 1; i<=num + 1; i++) {
            for (y = 1; y < i; y++) {
                printf("*");
            }
        printf("\\n");
        }
    } else if (opcao == 'V' || opcao == 'v'){
        for (i = 0; i < num; i++) {
            if (i == num - 1) {
                for (y = 0; y <= i; y++) {
                    printf("*");
                }
            } else {
                for (y = 0; y <= i; y++) {
                    if (y == 0 || y == i) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
            }
        printf("\\n");
        }
    }

}
        `
    },
    { 
        id: '10',
        title: 'Calcula número retangular e com intervalo', 
        description: 'Números retangulares são números gerados a partir do produto de dois números consecutivos. São chamados assim pois podem ser representados em um formato retangular.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Formas%20Geometricas/RetangularComIntervalo.h',
        code: `
int calcularRetangular(int num) {
    int i = 2, n3 = 0, j, y;
    
    for (i; n3 < num; i += 2) {
        n3 += i;
        j = i;
    }
    if (n3 == num) {
        for (y = 2; y <= num; y += 2) {
            if (y < j) {
                printf("%d + ", y);
            } else if (y == j) {
                printf("%d = %d ==> Eh retangular", y, num);
            }
        }
        return 1;
    } else if (n3 > num){
        printf("%d nao eh retangular", num);
        return 0;
    }
}

void calcularRetangularComIntervalo(int inferior, int superior) {
    int i = 2, n3 = 0, j, y;
    
    for (inferior; inferior <= superior; inferior++) {
        for (i; n3 < inferior; i += 2) {
            n3 += i;
            j = i;
        }
        if (n3 == inferior) {
            for (y = 2; y <= inferior; y += 2) {
                if (y < j) {
                    printf("%d + ", y);
                } else if (y == j) {
                    printf("%d = %d ==> Eh retangular!\\n", y, inferior);
                }
            }
        }
    }
}
        `
    },
    { 
        id: '11',
        title: 'Calcula número triangular e com intervalo', 
        description: 'Um número triangular é um número que pode ser representado na forma de um triângulo equilátero de pontos. A sequência de números triangulares é obtida somando-se os números naturais consecutivos.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Formas%20Geometricas/TriangularComIntervalo.h',
        code: `
int calculaNumeroTriangular(int num) {

    int i = 1, n3 = 0;
    
    for (i = 1; n3 < num; i++) {
        n3 = i * (i + 1) * (i + 2);
    }
    
    if (n3 == num) {
        printf("%d eh triangular ==> %d * %d * %d = %d", num, i - 1, i, i + 1, n3);
        return 1;
    } else {
        printf("%d nao eh triangular.", num);
        return 0;
    }
}

void calculaNumeroTriangularComIntervalo(int inferior, int superior) {
    
    int i = 1, n3 = 0, j;
    
    for (inferior; inferior <= superior; inferior++) {
        for (i; n3 < inferior; i++) {
            n3 = i * (i + 1) * (i + 2);
        }
        if (n3 == inferior) {
            printf("%d eh triangular ==> %d * %d * %d = %d\\n", inferior, i - 1, i, i + 1, n3);
        }
    }
}
        `
    },
    { 
        id: '12',
        title: 'Verifica se o ano é bissexto', 
        description: 'Um ano bissexto é um ano que possui um dia extra, totalizando 366 dias, em vez dos 365 dias dos anos comuns. A função retorna 1 quando o ano passado por parâmetro é bissexto e 0 quando não é bissexto.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Numeros%20Com%20Condições%20Esquisitas/anoBissexto.h',
        code: `
int anoBissexto(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}
        `
    },
    { 
        id: '13',
        title: 'Verifica se um número é feliz', 
        description: 'Um número feliz é um número inteiro positivo que, ao substituir cada dígito pelo quadrado dele e somar repetidamente, resulta em 1. Esses números têm propriedades matemática associados à felicidade e harmonia numérica.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Numeros%20Com%20Condições%20Esquisitas/calcularNumeroFeliz.h',
        code: `
int calcularQuadradoDigitos(int numero) {
    int somaQuadrados = 0, proxDigito = 0;

    while (numero > 0) {
        printf("Soma = %d\\t", somaQuadrados);
        int digito = numero % 10;
        int proxDigito = numero / 10;
        printf("Digito = %d\\t", digito);
        somaQuadrados += digito * digito;
        printf("potencia = %d ^ 2 = %d\\t", digito, (digito * digito));
        printf("Soma acumulada = %d\\t", somaQuadrados);
        printf("Numero final = %d\\n", proxDigito);
        numero /= 10;
    }
    return somaQuadrados;
}

int ehFeliz(int numero) {
    for (int i = 0; i < 20; i++) {
        printf("=== PASSO %d ===\\n", i + 1);
        numero = calcularQuadradoDigitos(numero);
        if (numero == 1) {
            return 1;
        }
    }
    return 0;
}
        `
    },
    { 
        id: '14',
        title: 'Verifica se um número é Armstrong', 
        description: 'Um número Armstrong é um número inteiro positivo no qual a soma dos cubos de seus dígitos é igual ao próprio número. Esses números são raros e têm propriedades matemáticas únicas.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Numeros%20Com%20Condições%20Esquisitas/numeroArmstrong.h',
        code: `
int numeroArmstrong(int num) {
    int originalNum = num;
    int sum = 0;
    int digits = 0;
    
    while (num != 0) {
        digits++;
        num /= 10;
    }
    
    num = originalNum;
    
    while (num != 0) {
        int digit = num % 10;
        sum += pow(digit, digits);
        num /= 10;
    }
    
    return sum == originalNum;
}
        `
    },
    { 
        id: '15',
        title: 'Verifica se um número equivale a soma dos ímpares', 
        description: 'Um número que equivale à soma dos ímpares é um número inteiro em que a sua representação é a soma de vários números ímpares consecutivos.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Numeros%20Com%20Condições%20Esquisitas/numeroEquivaleSomaImpares.h',
        code: `
void numeroEquivaleSomaImpares (int num) {

    int i, soma = 0, resultado = 0;
    
    printf("%d = ", num);
    
    for(i = 1; i <= num; i += 2) {
        
        soma += i;
        printf("%d ", i);
        
        if (soma == num) {
            resultado++;
            break;
        } else if (soma > num) {
            break;
        }
        
    }
    
    if (resultado != 0) {
            printf("=> Soma = %d => Equivale a soma dos impares\\n", soma);
        } else {
            printf("=> Soma = %d => Nao equivale a soma dos impares\\n", soma);
    }
    
}

void numeroEquivaleSomaImparesIntervalo(int inferior, int superior) {
    
    int i;
    
    for (i = inferior; i <= superior; i++) {
        numeroEquivaleSomaImpares(i);
    }
}
        `
    },
    { 
        id: '16',
        title: 'Verifica se um número é perfeito', 
        description: 'Um número perfeito é um número inteiro positivo que é igual à soma de seus divisores próprios (excluindo o próprio número).',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Numeros%20Com%20Condições%20Esquisitas/numeroPerfeito.h',
        code: `
int numeroPerfeito(int num) {
    int sum = 0;
    
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    
    return sum == num;
}
        `
    },
    { 
        id: '17',
        title: 'Verifica se um número é palíndromo', 
        description: 'Um número palíndromo é um número que permanece o mesmo quando lido da esquerda para a direita e vice-versa. Retorna 1 para quando o número é palíndromo.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Numeros%20Com%20Condições%20Esquisitas/palindromo.h',
        code: `
//o parametro deve ser passado como string (ex: "5005")

int isPalindrome(const char *str) {
    int len = strlen(str);
    
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;
        }
    }
    
    return 1;
}
        `
    },
    { 
        id: '18',
        title: 'Calcula fatorial de um número', 
        description: 'O fatorial de um número é o produto de todos os números inteiros positivos menores ou iguais a ele. É representado pelo símbolo "!".',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Pegar%20Caracteristicas%20do%20Número/Calculo%20de%20fatoriais.h',
        code: `
int calculaFat(int num) {
    int i, fat=1;

    for(i=num; i>=2; i--)
    {
        fat = fat * i;
    }
    return(fat);
}

void mostraFat(int num, int fat) {
    int i;

    printf("%d! = ", num);

    for(i=num; i>=2; i--)
    {
        printf("%d * ", i);
    }
    printf("1 = %d\\n", fat);
}
        `
    },
    { 
        id: '19',
        title: 'Verifica se um número é primo', 
        description: 'Um número primo é um número inteiro maior que 1 que possui apenas dois divisores: ele mesmo e 1. Retorna "cont" como 0, caso o número seja primo.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Pegar%20Caracteristicas%20do%20Número/Verifica%20se%20é%20primo.h',
        code: `
int primo(int num) {
    int i = 2, cont = 0, result;
    
    for (i; i<=num / 2; i++) {
        if (num%i == 0) {
            cont++;
            break;
        }
        if (cont > 1) {
            cont++;
        }
    }
    return cont;
}
        `
    },
    { 
        id: '20',
        title: 'Converte um número binário para decimal', 
        description: 'Para realiar a conversão de binário para decimal, deve-se multiplicar cada dígito binário pela potência de 2 correspondente e somar os resultados.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Pegar%20Caracteristicas%20do%20Número/binarioParaDecimal.h',
        code: `
int binarioParaDecimal(long long binaryNum) {
    int decimalNum = 0;
    int base = 1;
    
    while (binaryNum != 0) {
        int digit = binaryNum % 10;
        decimalNum += digit * base;
        binaryNum /= 10;
        base *= 2;
    }
    
    return decimalNum;
}
        `
    },
    { 
        id: '21',
        title: 'Inverte um número inteiro', 
        description: 'Inverter um número inteiro é o processo de reorganizar a ordem dos dígitos, de forma que o último se torne o primeiro e assim por diante.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Pegar%20Caracteristicas%20do%20Número/inverteInteiro.h',
        code: `
int inverteInteiro(int num) {
    int reversed = 0;
    
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    
    return reversed;
}
        `
    },
    { 
        id: '22',
        title: 'Separar dígitos de um número', 
        description: 'A função recebe um número inteiro e separa os seus dígitos, independente do tamanho do número original.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Pegar%20Caracteristicas%20do%20Número/pegarDigitoNumero.h',
        code: `
void pegarDigito(int numero) {
    int digito = 0, numeroSemUltimoDigito = 0;
    while (numero > 0) {
        digito = numero % 10;
        //int numeroSemUltimoDigito = numero / 10;
        printf("Digito: %d\\n", digito);
        numero /= 10;
    }
}
        `
    },
    { 
        id: '23',
        title: 'Gerar vetor de letras maiúsculas', 
        description: 'Gera um vetor de letras maiúsculas aleatórias de A a Z, recebendo como parâmetro um tamanho definido.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Vetores/Gerar%20Vetor%20Char%20Maiusculo.h',
        code: `
void gerarVetorCharMaiscula(char vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        vetor[i] = rand() % 26 + 65;
    }
}
        `
    },
    { 
        id: '24',
        title: 'Gerar vetor de letras minúsculas', 
        description: 'Gera um vetor de letras minúsculas aleatórias de A a Z, recebendo como parâmetro um tamanho definido.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Vetores/Gerar%20Vetor%20Char%20Minusculo.h',
        code: `
void gerarVetorCharMinuscula(char vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        vetor[i] = rand() % 26 + 97;
    }
}
        `
    },
    { 
        id: '25',
        title: 'Mostra os elementos de um vetor char', 
        description: 'Mostra no console todos os elementos de um vetor do tipo char.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Vetores/Mostrar%20Vetor%20CHAR.h',
        code: `
void mostraVetorChar(char vet[], int tamanho, int num) {
    int i, j = 0;

    for(i=0; i<tamanho; i++) {
        if (j < num - 1) {
            printf("%c ", vet[i]);
            j++;
        } else if (j == num - 1) {
            printf("%c\\n", vet[i]);
            j = 0;
        }
    }
}
        `
    },
    { 
        id: '26',
        title: 'Mostra os elementos de um vetor int', 
        description: 'Mostra no console todos os elementos de um vetor do tipo inteiro.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Vetores/Mostrar%20Vetores%20INTEIROS.h',
        code: `
void mostraVetorInteiros(int vet[], int tamanho) {
    int i;

    for(i=0; i<tamanho; i++)
    {
        printf("%d ", vet[i]);
    }
}
        `
    },
    { 
        id: '27',
        title: 'Mostra os elementos de um vetor float', 
        description: 'Mostra no console todos os elementos de um vetor do tipo float.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Vetores/Mostrar%20Vetores%20FLOAT.h',
        code: `
void mostraVetorFloat(float vet[], int tamanho) {
    int i;

    for(i=0; i<tamanho; i++)
    {
        printf("%.1f  ", vet[i]);
    }
}
        `
    },
    { 
        id: '28',
        title: 'Mostra a soma dos elementos de um vetor float', 
        description: 'Mostra no console a soma de todos os elementos de um vetor do tipo float.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Vetores/Mostrar%20Soma%20Vetores%20FLOAT.h',
        code: `
void mostraSomaVetorFloat(float vet[], int tamanho) {
    int i;
    float soma = 0;
    
    for(i=0; i<tamanho; i++){
        soma += vet[i];
    }
    printf("\\nSoma: %.2f", soma);
}
        `
    },
    { 
        id: '29',
        title: 'Ordenar valores de um vetor int', 
        description: 'Faz a ordenação, em ordem crescente, de todos os elementos de um vetor do tipo inteiro.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Vetores/Ordenar%20Valores%20De%20Um%20Vetor.h',
        code: `
void ordenaVetor(int vetor[], int tam) {
    int aux, i, j;
    for (j = tam - 1; j > 0; j--) {
        for (i = 0; i < j; i++) {
            if (vetor[i] > vetor[i + 1]) {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
    }
}
        `
    },
    { 
        id: '30',
        title: 'Gera vetor float de 0 a 1', 
        description: 'Gera um vetor de números do tipo float entre 0 e 1, recebendo como parâmetro um tamanho definido.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Vetores/Vetor%20Float%20de%200%20a%201.h',
        code: `
void geraVetorFloat0a1(float array[], int size) {

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = (float) rand() / RAND_MAX;
    }
}
        `
    },
    { 
        id: '31',
        title: 'Gera vetor float de 0 a 100', 
        description: 'Gera um vetor de números do tipo float entre 0 e 100, recebendo como parâmetro um tamanho definido.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Vetores/Vetor%20Float%20de%200%20a%20100.h',
        code: `
void geraVetorFloat0a100(float array[], int size) {

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = ((float) rand() / RAND_MAX)*100;
    }
}
        `
    },
    { 
        id: '32',
        title: 'Gera vetor int com limites positivos e negativos', 
        description: 'Gera um vetor de números do tipo inteiro entre um intervalo, passado por parâmetro, positivo e negativo.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Vetores/Vetor%20com%20Limites%20Positivos%20e%20Negativos.h',
        code: `
void atualizaVetorComLimitesNegativosEPositivos(int array[], int size, int min, 
int max) {

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % (max + min + 1) - min;
    }
}
        `
    },
    { 
        id: '33',
        title: 'Gera vetor int com limites positivos', 
        description: 'Gera um vetor de números do tipo inteiro entre um intervalo, passado por parâmetro, apenas positivo.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Vetores/Vetor%20com%20Limites%20Positivos.h',
        code: `
void gerarVetorComLimitesPositivos(int array[], int size, int min, int max) {

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % (max - min + 1) + min;
    }
}
        `
    },
    { 
        id: '34',
        title: 'Mostra pares e suas somas de um array sem números repetidos', 
        description: 'Mostra todos os pares e a soma desses pares. Caso o array possua números repetidos, somente um número será considerado.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Vetores/Pares%20De%20Um%20Array%20Sem%20Repetições.h',
        code: `
void paresAteUmNumero(int num) {
    int i;
    
    for (i = 1; i <= num; i++) {
        if (i % 2 == 0) {
            printf("%d  ", i);
        }
    }
}

int somaDePares(int num) {
    int i, cont = 0;
    
    for (i = 1; i <= num; i++) {
        if (i % 2 == 0) {
            cont += i;
        }
    }
    return cont;
}

void paresDeUmArraySemrepetidos(int vetor[], int tamanho) {
    int i;

    for(i=0; i<tamanho; i++) {
        if (i == 0 || vetor[i] != vetor[i-1]) {
            printf("%d => ", vetor[i]);
            paresAteUmNumero(vetor[i]);
            printf("Soma = %d\\n", somaDePares(vetor[i]));
        }
    }
}
        `
    },
    { 
        id: '35',
        title: 'Mostra divisores e quantidade de um array sem números repetidos', 
        description: 'Mostra todos os divisores e a quantidade desses divisores. Caso o array possua números repetidos, somente um número será considerado.',
        githubLink: 'https://github.com/Vttrium/UTFPR-Codes/blob/master/Códigos%20de%20Auxilio/Vetores/DivisoresDosElementosArraySemRepetições.h',
        code: `
int qtdDivisores(int num) {

    int i, cont = 0;
    
    for (i = 1; i <= num; i++) {
        if (num%i == 0) {
            cont++;
        }
    }
    return cont;
}

void quaisDiv(int num) {

    int i;
    
    for (i = 1; i <= num; i++) {
        if (num%i == 0) {
            printf("%i  ",i);
        } 
    }
}

void divisoresDeUmArraySemrepetidos(int vetor[], int tamanho) {
    int i;

    for(i=0; i<tamanho; i++) {
        if (i == 0 || vetor[i] != vetor[i-1]) {
            printf("%d => ", vetor[i]);
            quaisDiv(vetor[i]);
            printf("-  %d Divisores\\n", qtdDivisores(vetor[i]));
        }
    }
}
        `
    },
];

module.exports = cardData