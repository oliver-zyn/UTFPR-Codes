int existeNoVetor(int vetor[], int size, int num) {
    
    int i,count = 0;
    
    for (i = 0; i < size; i++) {
        if (vetor[i] == num) {
            count++;
        }
    }
    return count;
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

void mostraVetorInteiros(int vet[], int tamanho) {
    int i;

    for(i=0; i<tamanho; i++)
    {
        printf("%d ", vet[i]);
    }
}

int verificaAMaiorOcorrenciaNoVetor(int vetor[], int size) {
    
    int soma, count, k, x, y, i;
    
    soma = 1;
    count = 1;
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
        printf("\nMaior quantidade de ocorrencias: %i por que teve %i ocorrencias.", vetor[i], soma);
    } else {
        printf("\nMaior quantidade de ocorrencias: %i por que teve %i ocorrencias.", k, soma);
    }
    
}

void gerarTabuada(int num) {
    
    int result;
    
    for (int i = 0; i <= 10; i++) {
        result = num * i;
        printf("%d * %d = %d\n", num, i, result);
    }
    
}