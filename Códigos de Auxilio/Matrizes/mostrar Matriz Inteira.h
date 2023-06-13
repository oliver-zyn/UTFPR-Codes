void mostrarMatrizInteiro(int linha, int coluna, int matriz[linha][coluna]) {

    for (int j = 0; j < linha; j++) {
        for (int i = 0; i < coluna; i++) {
            printf("%d ", matriz[j][i]);
        }
        printf("\n");
    }
}