void pegarDigito(int numero) {
    int digito = 0, numeroSemUltimoDigito = 0;
    while (numero > 0) {
        digito = numero % 10;
        //int numeroSemUltimoDigito = numero / 10;
        printf("Digito: %d\n", digito);
        numero /= 10;
    }
}