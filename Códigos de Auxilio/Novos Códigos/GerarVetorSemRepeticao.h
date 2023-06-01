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