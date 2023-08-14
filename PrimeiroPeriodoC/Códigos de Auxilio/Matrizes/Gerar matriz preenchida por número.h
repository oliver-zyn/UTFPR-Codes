void gerarMatrizInteiroPreenchida(int linha, int coluna, int matriz[linha][coluna], int num) {

    for (int j = 0; j < linha; j++) {
        for (int i = 0; i < coluna; i++) {
            matriz[j][i] = num;
        }
    }
}