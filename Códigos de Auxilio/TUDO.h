/*VETORES*/
void mostraVetorChar(char vet[], int tamanho, int num)
{
    int i, j = 0;

    for(i=0; i<tamanho; i++) {
        if (j < num - 1) {
            printf("%c ", vet[i]);
            j++;
        } else if (j == num - 1) {
            printf("%c\n", vet[i]);
            j = 0;
        }
    }
}

void gerarVetorCharMaiscula(char vetor[], int tam) {
    
    for (int i = 0; i < tam; i++) {
        vetor[i] = rand() % 26 + 65;
    }
}

void gerarVetorCharMinuscula(char vetor[], int tam) {
    
    for (int i = 0; i < tam; i++) {
        vetor[i] = rand() % 26 + 97;
    }
}

void mostraVetorInteiros(int vet[], int tamanho)
{
    int i;

    for(i=0; i<tamanho; i++)
    {
        printf("%d ", vet[i]);
    }
}

void mostraVetorFloat(float vet[], int tamanho)
{
    int i;

    for(i=0; i<tamanho; i++)
    {
        printf("%.1f  ", vet[i]);
    }
}

void mostraSomaVetorFloat(float vet[], int tamanho)
{
    int i;
    float soma = 0;
    
    for(i=0; i<tamanho; i++){
        soma += vet[i];
    }
    printf("\nSoma: %.2f", soma);
}

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

void divisoresDeUmArraySemrepetidos(int vetor[], int tamanho)
{
    int i;

    for(i=0; i<tamanho; i++) {
        if (i == 0 || vetor[i] != vetor[i-1]) {
            printf("%d => ", vetor[i]);
            quaisDiv(vetor[i]);
            printf("-  %d Divisores\n", qtdDivisores(vetor[i]));
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

void paresAteUmNumero(int num) {
    
    int i;
    
    for (i = 1; i <= num; i++) {
        if (i % 2 == 0) {
            printf("%d  ", i);
        }
    }
}

void paresDeUmArraySemrepetidos(int vetor[], int tamanho)
{
    int i;

    for(i=0; i<tamanho; i++) {
        if (i == 0 || vetor[i] != vetor[i-1]) {
            printf("%d => ", vetor[i]);
            paresAteUmNumero(vetor[i]);
            printf("Soma = %d\n", somaDePares(vetor[i]));
        }
    }
}

void atualizaVetorComLimitesPositivos(int array[], int size, int min, int max) {
    
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % (max - min + 1) + min;
    }
}

void atualizaVetorComLimitesNegativosEPositivos(int array[], int size, int min, int max) {
    
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % (max + min + 1) - min;
    }
}

void geraVetorFloat0a1(float array[], int size) {
    
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = (float) rand() / RAND_MAX;
    }
}

void geraVetorFloat0a100(float array[], int size) {
    
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = ((float) rand() / RAND_MAX)*100;
    }
}

/*DIVISORES*/

int somaDiv(int num) {
    
    int i, soma = 0;
    
    for (i = 1; i <= num; i++) {
        if (num%i == 0) {
            soma += i;
        }
    }
    
    return soma;
}

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

int calculaDivisorComum(int a, int b) {
    if (b == 0) {
        return a;
    }
    
    return calculaDivisorComum(b, a % b);
}

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

/*CARACTERISTICAS*/

int calculaFat(int num) //com par�metros e com retorno
{
    int i, fat=1;

    for(i=num; i>=2; i--)
    {
        fat = fat * i;
    }
    return(fat);
}

void mostraFat(int num, int fat) //com par�metros e sem retorno
{
    int i;

    printf("%d! = ", num);

    for(i=num; i>=2; i--)
    {
        printf("%d * ", i);
    }
    printf("1 = %d\n", fat);
}

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

int inverteInteiro(int num) {
    int reversed = 0;
    
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    
    return reversed;
}

void pegarDigito(int numero) {
    int digito = 0, numeroSemUltimoDigito = 0;
    while (numero > 0) {
        digito = numero % 10;
        //int numeroSemUltimoDigito = numero / 10;
        printf("Digito: %d\n", digito);
        numero /= 10;
    }
}

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

/*FORMAS GEOMETRICAS*/

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
        
        printf("\n");
    }
    
    for(i = 0; i <= 5; i++) {
        for(j = 0; j <= num; j++) {
            printf(" ");
        }
        printf("*\n");
    }
    
}

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
        printf("\n");
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
        printf("\n");
        }
    }
}

void quadrado(int numLinhas, int numColunas, int caractere) {
    
    int i, count;
    
    for (i = 0; i < (numColunas * numLinhas); i++) {
        if (count == numColunas - 1) {
            printf("%c\n", caractere);
            count = 0;
        } else {
            printf("%c ", caractere);
            count++;
        }
    }
}

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
                    printf("%d = %d ==> Eh retangular!\n", y, inferior);
                }
            }
        }
    }
}

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
            printf("%d eh triangular ==> %d * %d * %d = %d\n", inferior, i - 1, i, i + 1, n3);
        }
    }
}

void trianguloVazadoOuPreenchido(int num, char opcao) {
    
    int i, y, j;
    
    if (opcao == 'P' || opcao == 'p') {
        for (i = 1; i<=num + 1; i++) {
            for (y = 1; y < i; y++) {
                printf("*");
            }
        printf("\n");
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
        printf("\n");
        }
    }

}

/*CONDIÇÕES DE NUMEROS ESQUISITOS*/

int anoBissexto(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1; // é bissexto
            } else {
                return 0; // não é bissexto
            }
        } else {
            return 1; // é bissexto
        }
    } else {
        return 0; // não é bissexto
    }
}

int calcularQuadradoDigitos(int numero) {
    int somaQuadrados = 0, proxDigito = 0;
    while (numero > 0) {
        printf("Soma = %d\t", somaQuadrados);
        int digito = numero % 10;
        int proxDigito = numero / 10;
        printf("Digito = %d\t", digito);
        somaQuadrados += digito * digito;
        printf("potencia = %d ^ 2 = %d\t", digito, (digito * digito));
        printf("Soma acumulada = %d\t", somaQuadrados);
        printf("Numero final = %d\n", proxDigito);
        numero /= 10;
    }
    return somaQuadrados;
}

int ehFeliz(int numero) {
    for (int i = 0; i < 20; i++) {
        printf("=== PASSO %d ===\n", i + 1);
        numero = calcularQuadradoDigitos(numero);
        if (numero == 1) {
            return 1;
        }
    }
    return 0;
}

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
            printf("=> Soma = %d => Equivale a soma dos impares\n", soma);
        } else {
            printf("=> Soma = %d => Nao equivale a soma dos impares\n", soma);
    }
    
}

void numeroEquivaleSomaImparesIntervalo(int inferior, int superior) {
    
    int i;
    
    for (i = inferior; i <= superior; i++) {
        numeroEquivaleSomaImpares(i);
    }
}

int numeroPerfeito(int num) {
    int sum = 0;
    
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    
    return sum == num;
}

int isPalindrome(const char *str) {
    int len = strlen(str);
    
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0; // não é palíndromo
        }
    }
    
    return 1; // é palíndromo
}

