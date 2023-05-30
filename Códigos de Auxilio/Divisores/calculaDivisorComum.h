int calculaDivisorComum(int a, int b) {
    if (b == 0) {
        return a;
    }
    
    return calculaDivisorComum(b, a % b);
}
