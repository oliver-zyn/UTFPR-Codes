import java.util.Scanner;

import br.edu.utfpr.operacoes.Operacoes;

public class App {
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
