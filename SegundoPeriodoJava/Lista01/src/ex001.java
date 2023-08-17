import java.util.Scanner;

public class Ex001 {
    public static void main(String[] args) throws Exception {
        Scanner dados = new Scanner(System.in);
        System.out.print("Digite o primeiro número: ");
        int num1 = dados.nextInt();
        System.out.print("Digite o segundo número: ");
        int num2 = dados.nextInt();
        dados.close();
        if (num1 > num2) {
            for(int i = num2; i < num1; i++) {
                if (i % 2 == 0){
                    System.out.print(i + "  ");
                }
            }
        } else if (num1 < num2) {
            for(int i = num1; i < num2; i++) {
                if (i % 2 == 0){
                    System.out.print(i + "  ");
                }
            }
        } else {
            System.out.println("Os números são iguais, não é possível prosseguir.");
        }
    }
}
