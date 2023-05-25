int binarioParaDecimal(long long binaryNum) {
    int decimalNum = 0;
    int base = 1;
    
    while (binaryNum != 0) {
        int digit = binaryNum % 10;
        decimalNum += digit * base;
        binaryNum /= 10;
        base *= 2;
    }
    
    return decimalNum;
}
