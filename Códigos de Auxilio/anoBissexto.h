int anoBissexto(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1; // é bissexto
            } else {
                return 0; // não é bissexto
            }
        } else {
            return 1; // é bissexto
        }
    } else {
        return 0; // não é bissexto
    }
}
