void gerarTabuada(int num) {
    
    int result;
    
    for (int i = 0; i <= 10; i++) {
        result = num * i;
        printf("%d * %d = %d\n", num, i, result);
    }
    
}