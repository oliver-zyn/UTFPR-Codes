void gerarMatrizInteiro(int linha, int coluna, int matriz[linha][coluna], int limite) {

    srand(time(NULL));

    for (int j = 0; j < linha; j++) {
        for (int i = 0; i < coluna; i++) {
            matriz[j][i] = (rand() % limite) + 1;
        }
    }
}