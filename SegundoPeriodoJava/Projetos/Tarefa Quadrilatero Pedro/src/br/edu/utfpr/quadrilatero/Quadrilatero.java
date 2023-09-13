package br.edu.utfpr.quadrilatero;

public class Quadrilatero {
    private double lado1;
    private double lado2;

    public Quadrilatero() {
        this.lado1 = 10;
        this.lado2 = 5;
    }

    public Quadrilatero(double lado1, double lado2) {
        this.lado1 = lado1;
        this.lado2 = lado2;
    }

    public double getLado1() {
        return lado1;
    }

    public void setLado1(double lado1) {
        this.lado1 = lado1;
    }

    public double getLado2() {
        return lado2;
    }

    public void setLado2(double lado2) {
        this.lado2 = lado2;
    }

    public double area() {
        return (lado1 * lado2);
    }

    public double perimetro() {
        return (2 * lado1 + 2 * lado2);
    }

    public boolean quadrado() {
        return lado1 == lado2;
    }

    public boolean retangulo() {
        return lado1 != lado2;
    }

    public String toString() {
        if (quadrado() == true) {
            return "Lado 1: " + lado1 + ", Lado 2: " + lado2 + ", Perimetro: " + perimetro() + ", Área: " + area() + "\nÉ um quadrado";
        } else {
            return "Lado 1: " + lado1 + ", Lado 2: " + lado2 + ", Perimetro: " + perimetro() + ", Área: " + area() + "\nÉ um retângulo";
        }
    }
}