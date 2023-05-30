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