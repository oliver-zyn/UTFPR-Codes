package br.edu.utfpr.operacoes;

public class Operacoes {
    private double num1;
    private double num2;

    public Operacoes() {
        this.num1 = 10;
        this.num2 = 5;
    }

    public Operacoes(double num1, double num2) {
        this.num1 = num1;
        this.num2 = num2;
    }

    public double getNum1() {
        return num1;
    }

    public double getNum2() {
        return num2;
    }

    public void setNum1(double num1) {
        this.num1 = num1;
    }

    public void setNum2(double num2) {
        this.num2 = num2;
    }
    
    public String toString() {
        return "Número 1: " + num1 + ", Número 2: " + num2;
    }

    public double soma() {
        return (num1 + num2);
    }

    public double subtrair() {
        return (num1 - num2);
    }

    public double dividir() {
        if (num2 == 0) {
            System.out.println("Divisão por zero não é possível.");
            return Double.NaN;
        }
        return (num1 / num2);
    }

    public double multiplicar() {
        return (num1 * num2);
    }
}
