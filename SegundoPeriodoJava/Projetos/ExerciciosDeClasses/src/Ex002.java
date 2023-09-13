import java.util.Scanner;

public class Ex002 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);

        System.out.print("Informe a quantidade de valores: ");
        int tam = ler.nextInt();

        System.out.print("Informe a potência desejada: ");
        int potencia = ler.nextInt();

        for (int i = 0; i < tam; i++) {
            System.out.print("\nInforme o valor " + (i + 1) + ": ");
            double valor = ler.nextDouble();
            double resultado = Math.pow(valor, potencia);
            System.out.println(valor + " elevado a " + potencia + " é igual a " + resultado);
        }
        ler.close();
    }
}
