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