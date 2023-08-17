import java.util.Scanner;

public class ex003 {
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        int nFuncionarios;
        float fSoma = 0;

        System.out.print("Numero de funcionários: ");
        nFuncionarios = scan.nextInt();

        for(int i = 1; i <= nFuncionarios; i++) {
            System.out.print("Informe o salário do " + i + "º funcionário: ");
            fSoma += scan.nextFloat();
        }

        scan.close();

        System.out.printf("A média salarial dos funcionários é: %.2f", (fSoma / nFuncionarios));
    }
}
