import java.util.Arrays;
import java.util.Scanner;

public class Vetores2D {
    public static void leArray(int a[][]) {
        Scanner ler = new Scanner(System.in);
        
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                System.out.print("a [" + i + "][" + j + "] = ");
                a[i][j] = ler.nextInt();
            }
        }
    }

    public static void modificarArray(int n, int a[][]) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                a[i][j] = n * a[i][j];
            }
        }
    }

    public static int[][] somarArrays(int a[][], int b[][]) {
        int rows = a.length;
        int cols = a[0].length;
        int soma[][] = new int[rows][cols]; 

        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                soma[i][j] = b[i][j] + a[i][j];
            }
        }
        return soma;
    }

    public static int[][] deepCopy(int[][] original) {
        if (original == null) {
            return null;
        }

        int[][] copy = new int[original.length][];
        for (int i = 0; i < original.length; i++) {
            copy[i] = Arrays.copyOf(original[i], original[i].length);
        }

        return copy;
    }


    public static void imprimeArray(int a[][]) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                System.out.printf("%4d", a[i][j]);
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
        int numL, numC, a[][];
        Scanner ler = new Scanner(System.in);

        System.out.print("Numero de linhas: ");
        numL = ler.nextInt();

        System.out.print("Numero de colunas: ");
        numC = ler.nextInt();

        a = new int[numL][numC];

        leArray(a);
        System.out.println("\nMatriz 1 (Base): ");
        imprimeArray(a);

        int a2[][] = deepCopy(a);

        modificarArray(2, a2);
        System.out.println("\nMatriz 2 (X2): ");
        imprimeArray(a2);

        int a3[][] = somarArrays(a, a2);
        System.out.println("\nMatriz 3 (Soma): ");
        imprimeArray(a3);
    }
}
