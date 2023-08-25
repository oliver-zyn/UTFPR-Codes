package br.edu.utfpr.operacoes;

import java.util.Scanner;

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

    @Override
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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite o valor do número 1: ");
        double numero1 = scanner.nextDouble();

        System.out.print("Digite o valor do número 2: ");
        double numero2 = scanner.nextDouble();

        Operacoes operacao = new Operacoes(numero1, numero2);

        System.out.println("\nEscolha a operação:");
        System.out.println("1. Soma");
        System.out.println("2. Subtração");
        System.out.println("3. Multiplicação");
        System.out.println("4. Divisão");
        System.out.print("Opção: ");
        int opcao = scanner.nextInt();

        double resultado = 0.0;
        String operacaoNome = "";

        switch (opcao) {
            case 1:
                resultado = operacao.soma();
                operacaoNome = "Soma";
                break;
            case 2:
                resultado = operacao.subtrair();
                operacaoNome = "Subtração";
                break;
            case 3:
                resultado = operacao.multiplicar();
                operacaoNome = "Multiplicação";
                break;
            case 4:
                resultado = operacao.dividir();
                operacaoNome = "Divisão";
                break;
            default:
                System.out.println("Opção inválida.");
                scanner.close();
                return;
        }

        System.out.println("\nResultado da " + operacaoNome + ": " + resultado);
        System.out.println("Dados do objeto Operacoes:");
        System.out.println(operacao); // Isso chamará automaticamente o método toString()

        scanner.close();
    }
}
