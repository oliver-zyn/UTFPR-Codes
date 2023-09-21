package br.edu.utfpr.imc;

public class IMC {
    private double altura;
    private double peso;

    public IMC() {
        this.altura = 10;
        this.peso = 5;
    }

    public IMC(double altura, double peso) {
        this.altura = altura;
        this.peso = peso;
    }

    public double getAltura() {
        return altura;
    }

    public double getPeso() {
        return peso;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }

    public double calcularIMC() {
        return peso / (altura * altura);
    }

    public String underIMC(double IMC) {
        if (IMC < 20) {
            return "Magro";
        } else if (IMC < 24) {
            return "Normal";
        } else if (IMC < 29) {
            return "Acima do peso";
        } else if (IMC < 34) {
            return "Obeso";
        } else {
            return "Muito Obeso";
        }
    }
    
    public String toString() {
        return "Altura: " + altura + ", Peso: " + peso;
    }
}
