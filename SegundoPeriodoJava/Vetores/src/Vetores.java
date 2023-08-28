import java.util.Scanner;

public class Vetores {
    
    public static void leArray(int a[]) {
        Scanner ler = new Scanner(System.in);
        
        for (int i = 0; i < a.length; i++) {
            System.out.print("a [" + i + "] = ");
            a[i] = ler.nextInt();
        }
        ler.close();
    }

    public static int somaArray(int a[]) {
        int soma = 0;
        for (int i = 0; i < a.length; i++) {
            soma += a[i];
        }
        return soma;
    }

    public static void imprimeArray(int a[]) {
        System.out.print("Array = [");
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i]);
            if (i < a.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }
    public static void main(String[] args) throws Exception {
        int n, a[];
        Scanner tamanho = new Scanner(System.in);
        System.out.print("Informe o tamanho do vetor: ");
        n = tamanho.nextInt();
        a = new int[n];
        tamanho.close();

        leArray(a);
        imprimeArray(a);
        int s = somaArray(a);
        System.out.println(s);
    }
}
