import java.util.Scanner;

public class Ex003 {
    public static void main(String[] args) throws Exception {
        Scanner dados = new Scanner(System.in);
        System.out.print("Digite o comprimento: ");
        int comprimento = dados.nextInt();
        System.out.print("Digite a altura: ");
        int altura = dados.nextInt();
        System.out.print("Digite a largura: ");
        int largura = dados.nextInt();
        dados.close();
        int volume = comprimento*altura*largura;
        System.out.println("O volume é de: " + volume + "m");
    }
}
