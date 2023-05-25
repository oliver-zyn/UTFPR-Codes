int numeroArmstrong(int num) {
    int originalNum = num;
    int sum = 0;
    int digits = 0;
    
    while (num != 0) {
        digits++;
        num /= 10;
    }
    
    num = originalNum;
    
    while (num != 0) {
        int digit = num % 10;
        sum += pow(digit, digits);
        num /= 10;
    }
    
    return sum == originalNum;
}
