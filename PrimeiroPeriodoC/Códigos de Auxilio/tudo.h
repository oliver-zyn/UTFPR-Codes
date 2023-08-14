#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

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
        
void quaisDiv(int num) {

    int i;
    
    for (i = 1; i <= num; i++) {
        if (num%i == 0) {
            printf("%i  ",i);
        } 
    }
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
        
int somaDiv(int num) {

    int i, soma = 0;
    
    for (i = 1; i <= num; i++) {
        if (num%i == 0) {
            soma += i;
        }
    }
    
    return soma;
}
        
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
    printf("1 = %d\n", fat);
}
        
int ehprimoOuN(int numero) {
    int i, cont = 0;
    for (i = 2; i<=numero / 2; i++) {
        if (numero%i == 0) {
            cont++;
            break;
        }
        if (cont > 1) {
            cont++;
        }
    }
    return cont;
}

int getprimos(char vetor[], char vetorPrimo[]) {

    int size = 0;
    size = sizeString(vetor);

    int j = 0;
    printf("String de caracteres primos: ");
    for(int i = 0; i <= size; i++) {
        if(ehprimoOuN(vetor[i]) == 0 && vetor[i] != ' ') {
            vetorPrimo[j] = vetor[i];
            printf("%c", vetor[i]);
            fflush(stdin);
            j++;
        }
    }
    return j;
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
    int invertido = 0;
    
    while (num != 0) {
        int digit = num % 10;
        invertido = invertido * 10 + digit;
        num /= 10;
    }
    
    return invertido;
}
        
void pegarDigito(int numero) {
    int digito = 0, numeroSemUltimoDigito = 0;
    while (numero > 0) {
        digito = numero % 10;
        printf("Digito: %d\n", digito);
        numero /= 10;
    }
}
        
void gerarVetorCharMaiscula(char vetor[], int Size) {
    for (int i = 0; i < Size; i++) {
        vetor[i] = rand() % 26 + 65;
    }
}
        
void gerarVetorCharMinuscula(char vetor[], int Size) {
    for (int i = 0; i < Size; i++) {
        vetor[i] = rand() % 26 + 97;
    }
}
        
void mostraVetorChar(char vet[], int Size, int num) {
    int j = 0;

    for(int i = 0; i < Size; i++) {
        if (j < num - 1) {
            printf("%c ", vet[i]);
            j++;
        } else if (j == num - 1) {
            printf("%c\n", vet[i]);
            j = 0;
        }
    }
}
        
void mostraVetorInt(int vetorint[], int Size)
{
    for(int i = 0; i<Size; i++) {
        printf("%d ", vetorint[i]);
    }
}
        
void mostraVetorFloat(float vet[], int Size) {

    for(int i = 0; i < Size; i++)
    {
        printf("%.1f  ", vet[i]);
    }
}
        
void mostraSomaVetorFloat(float vet[], int Size) {
    float soma = 0;
    
    for(int i = 0; i < Size; i++){
        soma += vet[i];
    }
    printf("\nSoma: %.2f", soma);
}
        
void ordenarVetoresInteiros(int vetorint[], int Size) {

    int j, auxiliar, i;

    for (j = Size - 1; j > 0; j--) {
        for (i = 0; i < j; i++) {
            if (vetorint[i] > vetorint[i + 1]) {
                auxiliar = vetorint[i];
                vetorint[i] = vetorint[i + 1];
                vetorint[i + 1] = auxiliar;
            }
        }
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
        
void FazVetorComLimitesNegativosEPositivos(int array[], int size, int min, int max) {

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % (max + min + 1) - min;
    }
}
        
void FazVetorComLimitesPositivos(int array[], int max, int min, int size) {

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % (max - min + 1) + min;
    }
}
        
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
            printf("Soma = %d\n", somaDePares(vetor[i]));
        }
    }
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

void divisoresDeUmArraySemrepetidos(int vetor[], int tamanho) {
    int i;

    for(i=0; i<tamanho; i++) {
        if (i == 0 || vetor[i] != vetor[i-1]) {
            printf("%d => ", vetor[i]);
            quaisDiv(vetor[i]);
            printf("-  %d Divisores\n", qtdDivisores(vetor[i]));
        }
    }
}
        
void gerarTabuada(int num) {

    int result;
    
    for (int i = 0; i <= 10; i++) {
        result = num * i;
        printf("%d * %d = %d\n", num, i, result);
    }
    
}
        
void gerarVetorSemRepeticao(int vetor[], int tamanho, int limite) {

    int i, num, j;
    
    srand(time(NULL));

    for(i = 0; i < tamanho; i++) {
        do {
            
            num = rand() % limite + 1;
            
            for (j = 0; j < i; j++) {
                if (vetor[j] == num) {
                    num = 0;
                    break;
                }
            }
            
        } while (num == 0);
        
        vetor[i] = num;
    }
    
}
        
int existeNoVetor(int vetor[], int size, int num) {

    int count = 0, i;
    
    for (i = 0; i < size; i++) {
        if (vetor[i] == num) {
            count++;
        }
    }
    return count;
}
        
int verificaAMaiorOcorrenciaNoVetor(int vetor[], int size) {

    int soma = 1, k, x, y, count = 1, i;
    
    for (i = 0; i < size; i++) {
        if (vetor[i] == y) {
            count += 1;
        } else {
            count = 1;
        }
        if (soma < count) {
            k = vetor[i];
            soma = count;
        }
        y = vetor[i];
    }
    if (k == 0) {
        printf("\nMaior quantidade de ocorrencias: %i por que %i ocorrencias.", vetor[i], soma);
    } else {
        printf("\nMaior quantidade de ocorrencias: %i por que %i ocorrencias.", k, soma);
    }
    
}
        
int comparaString(char str1[], char str2[]) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1;
    }

    return 0;
}
        
void contaAlfaDecimal(char string[]) {
    int i, countAlfa = 0, countDecimal = 0;
    
    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] >= 'a' && string[i] <= 'z' || string[i] >= 'A' && string[i] <= 'Z') {
            countAlfa++;
        } else if (string[i] >= '0' && string[i] <= '9') {
            countDecimal++;
        }
    }
    
    printf("Existem %d caracteres alfabeticos no texto.\n", countAlfa);
    printf("Existem %d caracteres numericos no texto.", countDecimal);
}
        
void contaVogais(int vetVogais[], char string[]) {

    int i;
    
    for(i=0; string[i]!='\0'; i++) {
        if (string[i] == 'a' || string[i] == 'A') {
            vetVogais[0]++;
        } else if (string[i] == 'e' || string[i] == 'E') {
            vetVogais[1]++;
        } else if (string[i] == 'i' || string[i] == 'I') {
            vetVogais[2]++;
        } else if (string[i] == 'o' || string[i] == 'O') {
            vetVogais[3]++;
        } else if (string[i] == 'u' || string[i] == 'U') {
            vetVogais[4]++;
        }
    }
    
    printf("\nVOGAL\t QUANTIDADE\n");
    printf("====================\n");
    printf("a/A\t\t%d\n", vetVogais[0]);
    printf("e/E\t\t%d\n", vetVogais[1]);
    printf("i/I\t\t%d\n", vetVogais[2]);
    printf("o/O\t\t%d\n", vetVogais[3]);
    printf("u/U\t\t%d\n", vetVogais[4]);
}
        
void copiaPrimeiraPalavra(char string[]) {
    int i, j = 0, y = 0, primeiroEspaco = 0;
    char stringPalavra[50];
    
    for (i = 0; string[i] != '\0'; i++) {
        
        if (primeiroEspaco == 0) {
            while (string[i] == ' ') {
                i++;
            }
        }
        
        primeiroEspaco = 1;
        
        if (string[i] != ' ' && string[i] != '\n') {
            stringPalavra[j] = string[i];
            j++;
        } else {
            break;
        }
        
    }
    
    stringPalavra[j] = '\0';
    printf("%s\n", stringPalavra);
}
        
void quebraLinha(char string[]) {
    int i, j = 0, primeiroEspaco = 0;
    char palavra[50];

    printf("\n==== TEXTO NA VERTICAL ====\n");

    for (i = 0; string[i] != '\0'; i++) {
        if (primeiroEspaco == 0) {
            while (string[i] == ' ') {
                i++;
            }
        }

        primeiroEspaco = 1;

        if (string[i] != ' ' && string[i] != '\n') {
            palavra[j] = string[i];
            j++;
        } else {
            palavra[j] = '\0';
            printf("%s\n", palavra);
            j = 0;
        }
    }

    palavra[j] = '\0';
    printf("%s", palavra);
}
        
void concatenaStrings(char string1[], char string2[]) {
    int size1 = 0, size2 = 0, i, j;

    size1 = tamanhoString(string1);
    size2 = tamanhoString(string2);

    for (i = size1, j = 0; i < (size1 + size2); i++, j++) {
        string1[i] = string2[j];
    }

    string1[size1 + size2] = '\0';

    printf("%s", string1);
}
        
void contadorDeEspacos(char Vetor[]) {
    int size = 0;
    while(Vetor[size] != '\0') {
        size++;
    }

    int vetorEspacos[size], i, j = 0,count = 0;

    for (i = 0; i < size; i++) {
        if (Vetor[i] == ' ' && Vetor[i+1] == ' ') {
            count++;
        } else if (Vetor[i] == ' ' && Vetor[i+1] != ' ') {
            count++;
            vetorEspacos[j] = count;
            j++;
            count = 0;
        }
    }
    printf("==== VETOR ESPACOS ====\n");
    for (i = 0; i < j; i++) {
        printf("%d\t", vetorEspacos[i]);
    }
}
        
int Includes(char string[], char substring[]) {
    int resultado = 0, i = 0, j;

    while(string[i] != '\0') {
        if (string[i] == substring[0]) {
            j = 0;
            while (substring[j] != '\0' && string[i] != '\0') {
                if (string[i] != substring[j]) {
                    break;
                }
                i++;
                j++;
            }
            if (substring[j] == '\0') {
                resultado = 1;
            }
        }
        i++;
    }
    return resultado;
}
        
int sizeString(char str[]) {

    int size = 0;
    while (str[size] != '\0') {
        size++;
    }
    return size - 1;
}
        
int contaPalavras(char string[]) {
    int size = 0, i = 0, novaPalavra = 1, countPalavras = 0;

    size = sizeString(string);

    for(i = 0; i < size; i++) {
        if (string[i] == ' ') {
        novaPalavra = 1;
        } else if (novaPalavra == 1) {
            novaPalavra = 0;
            countPalavras++;
        }
    }

    return countPalavras;
}
        
int sizeString(char str[]) {

    int size = 0;
    while (str[size] != '\0') {
        size++;
    }
    return size - 1;
}

void primeirasLetras(char vetor[], char string[]) {
  int i = 0, size = 0, j = 0;

  size = sizeString(string);

  for (i = 0; i <= size; i++) {
    if ((i == 0 && string[i] != ' ') || (string[i] != ' ' && string[i-1] == ' ')) {
      vetor[j] = string[i];
      j++;
    }
  }
  
  for (i = 0; i < j; i++) {
    printf("%c  ", vetor[i]);
  }
  
  printf("\n");
}

int sizeString(char str[]) {

    int size = 0;
    while (str[size] != '\0') {
        size++;
    }
    return size - 1;
}

void ultimasLetras(char vetor[], char string[]) {
    int i = 0, size = 0, j = 0;

    size = sizeString(string);

    for(i = 0; i <= size; i++) {
        if ((string[i] != ' ' && string[i+1] == ' ') || (string[i] != ' ' && string[i + 1] == '\0')) {
        vetor[j] = string[i];
        j++;
        }
    }

    for (i = 0; i < j; i++) {
        printf("%c  ", vetor[i]);
    }

    printf("\n");
}
        
void gerarMatrizInteiro(int SizeL, int SizeC, int matriz[SizeL][SizeC], int limite) {

  srand(time(NULL));

  for (int i = 0; i < SizeL; i++) {
      for (int j = 0; j < SizeC; j++) {
          matriz[i][j] = (rand() % limite) + 1;
      }
  }
}
        
void gerarMatrizInteiroPreenchida(int SizeL, int SizeC, int matriz[SizeL][SizeC], int numero) {

  for (int i = 0; i < SizeL; i++) {
      for (int j = 0; j < SizeC; j++) {
          matriz[i][j] = numero;
      }
  }
}
        
void mostrarMatrizInteiro(int SizeL, int SizeC, int matriz[SizeL][SizeC]) {

    for (int j = 0; j < SizeL; j++) {
        for (int i = 0; i < SizeC; i++) {
            printf("%d ", matriz[j][i]);
        }
        printf("\n");
    }
}
        
int calcularPotencia(int base, int expoente) {

  int resultado = 1;

  for (int i = 0; i < expoente; i++) {
      resultado *= base;
  }
  return resultado;
}

void calculaPotenciaPorVetores(int vetorbase[], int vetorexpoente[], int vetorResultado[], int tamanho) {

  printf("BASE\tEXPOENTE\tRESULTADO\n");
  for (int i = 0; i < tamanho; i++) {
      int base = vetorbase[i];
      int expoente = vetorexpoente[i];
      vetorResultado[i] = calcularPotencia(base, expoente);
      printf("%d\t%d\t\t%d\n", base, expoente, vetorResultado[i]);
  }
}
        
int contadorDePalavras(char Vetor[], int vetorpalavras[]) {

    int size = 0;
    int vetorPalavras[size], i, j = 0,count = 0;

    while(Vetor[size] != '\0') {
        size++;
    }

    for (i = 0; i < size; i++) {
        if (Vetor[i] != ' ') {
            count++;
            if (Vetor[i + 1] == ' ' || Vetor[i + 1] == '\0') {
                vetorPalavras[j] = count;
                j++;
                count = 0;
            }
        }
    }

    printf("==== VETOR PALAVRAS ====\n");
    for (i = 0; i < j; i++) {
        printf("%d\t", vetorPalavras[i]);
        vetorpalavras[i] = vetorPalavras[i];
    }
    return j;
    printf("\n");
}
        
int contadorDeEspacos(char Vetor[], int vetorespacos[]) {

    int size = 0;
    int vetorEspacos[size], i, j = 0,count = 0;

    while(Vetor[size] != '\0') {
        size++;
    }

    for (i = 0; i < size; i++) {
        if (Vetor[i] == ' ' && Vetor[i+1] == ' ') {
            count++;
        } else if (Vetor[i] == ' ' && Vetor[i+1] != ' ') {
            count++;
            vetorEspacos[j] = count;
            j++;
            count = 0;
        }
    }

    printf("==== VETOR ESPACOS ====\n");
    for (i = 0; i < j; i++) {
        printf("%d\t", vetorEspacos[i]);
        vetorespacos[i] = vetorEspacos[i];
    }
    return j;
    printf("\n");
}
        
void semRepeticao(int vetor[], int result[], int tamanho) {

  int j = 0;
  for(int i=0; i<tamanho; i++) {
        if (i == 0 || vetor[i] != vetor[i-1]) {
            result[j] = vetor[i];
            j++;
        }
    }
}

void contagemDeNumeros(int vetor[], int result[], int size) {
  
  int j = 0, count = 0;

  for(int i = 0; i < size; i++) {
      if (vetor[i] == vetor[i+1]) {
        count++;
      } else {
        result[j] = count;
        count = 0;
        j++;
      }
    }
  int resultado[size];
  semRepeticao(vetor, resultado, size);
  printf("\n==== MATRIZ ====\n");
  for (int i = 0; i < j; i++) {
    printf("%d\t%d\n", resultado[i], result[i]+1);
  }  
}
        
void divisoresDeUmArraySemrepetidos(int vetor[], int tamanho) {
    int i, qtde = 0;
    printf("\nVALOR\tQTDE DIVIDORES PRIMO\n");
    for(i=0; i<tamanho; i++) {
        if (i == 0 || vetor[i] != vetor[i-1]) {
            qtde = qtdDivisores(vetor[i]);
            if (primo(vetor[i]) == 0 && vetor[i] != 1) {
              printf("%d\t%d\t\tSIM\n",vetor[i], qtde);
            } else if (primo(vetor[i]) == 1 || vetor[i] == 1) {
              printf("%d\t%d\t\tNAO\n",vetor[i], qtde);
            }
        }
    }
}
        
int sizeString(char str[]) {

    int size = 0;
    while (str[size] != '\0') {
        size++;
    }
    return size - 1;
}

void gaguejarString(char string[], char stringGaguejada[]) {

    int tamanho, i = 0, j = 0, count = 1;
    
    tamanho = sizeString(string);

    for(i = 0; i <= tamanho; i++) {
        if (verificaVogal(string[i]) != 0) {
        stringGaguejada[j] = string[i];
        for (int k = 1; k <= count; k++) {
            stringGaguejada[j + k] = string[i];
        }
        j += (count + 1);
        count++;
        } else {
        stringGaguejada[j] = string[i];
        j++;
        }
    }

    stringGaguejada[j] = '\0';

    printf("%s", stringGaguejada);
}
        
int charehInt(char texto[], int textoInt[], int size) {

    int i, charct, j = 0;
    
    for(i = 0; i < size; i++) {
        if (texto[i] != ' ') {
            charct = texto[i];
            textoInt[j] = charct;
            j++;
        }
    }

    return size;
}
        
void copy(int vetor0[], int vetor1[], int size1) {
    for(int i = 0; i < size1; i++) {
        vetor0[i] = vetor1[i];
    }
}
        
void vetorParImpar(int vetor[], int size) {

    int size2, vetorPar[size], vetorImpar[size], j = 0, y = 0;

    size2 = SemRepeticaoNoVetor(vetor, size);

    for (int i = 0; i < size2; i++) {
        if (vetor[i] % 2 == 0) {
            vetorPar[j] = vetor[i];
            j++;
        } else {
            vetorImpar[y] = vetor[i];
            y++;
        }
    }
    printf("\n\nNumero de pares (sem repeticao): %d\n",j);
    printf("\nNumero de impares (sem repeticao): %d\n",y);

    printf("\n==== Vetor de PARES ====\n");
    for (int i = 0; i < j; i++) {
        printf("%d  ", vetorPar[i]);
    }
    printf("\n==== Vetor de IMPARES ====\n");
    for (int i = 0; i < y; i++) {
        printf("%d  ", vetorImpar[i]);
    }
}

void matrizParImpar(int vetor[], int size) {

  int size2 = 0, count = 0, j = 0, y = 0;
  int vetorPar[size], vetorImpar[size];
  
  for(int i = 0; i < size; i++) {
      if (vetor[i] == vetor[i+1]) {
          count++;
      } else {
          if (vetor[i] % 2 == 0) {
              vetorPar[j] = count;
              j++;
          } else {
              vetorImpar[y] = count;
              y++;
          }
          count = 0;
      }
  }
  size2 = SemRepeticaoNoVetor(vetor, size);
  printf("\n\n==== MATRIZ PAR ====\n");
  for (int i = 0, j = 0; i < size2; i++) {
      if (vetor[i] % 2 == 0) {
          printf("%d\t%d\n", vetor[i], vetorPar[j]+1);
          j++;
      }
  }
  printf("\n==== MATRIZ IMPAR ====\n");
  for (int i = 0, y = 0; i < size2; i++) {
      if (vetor[i] % 2 != 0) {
          printf("%d\t%d\n", vetor[i], vetorImpar[y]+1);
          y++;
      }
  }
}
        
int SemRepeticaoNoVetor(int vetors[], int size) {

    int vetorR[50];
    int i = 0, j = 0;

    for (i = 0; i < size; i++) {
        if (i == 0 || vetors[i] != vetors[i-1]) {
            j++;
            vetorR[j] = vetors[i];
        }
    }
    for(i = 0; i < size; i++) {
        if (vetorR[i] != '\0') {
            vetors[i] = vetorR[i];
        } else {
            vetors[i] = '\0';
        }
    }
    return j;
}
        
int verificaVogal(char letra) {
    int resultado = 0;
    
    if (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') {
        resultado++;
    }
    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
        resultado++;
    }
    return resultado;
}
        