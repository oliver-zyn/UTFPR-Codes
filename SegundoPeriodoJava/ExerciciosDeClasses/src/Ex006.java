import java.text.DecimalFormat;
import java.util.Scanner;

public class Ex006 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DecimalFormat decimalFormat = new DecimalFormat("0.00");

        double sum = 0;
        double product = 1;
        double input;

        do {
            System.out.print("Informe um número real (ou 0 para sair): ");
            input = scanner.nextDouble();

            if (input != 0) {
                sum += input;
                product *= input;
            }
        } while (input != 0);

        System.out.println("Soma: " + decimalFormat.format(sum));
        System.out.println("Produto: " + decimalFormat.format(product));
        scanner.close();
    }
}
