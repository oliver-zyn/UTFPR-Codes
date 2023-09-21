/*
Criar um vetor A. A quantidade de elementos inteiros deve ser definida
pelo usuário. Implementar um programa que defina e escreva a soma de
todos os elementos armazenados neste vetor. (Utilize Scanner)
 */

import java.util.Scanner;

public class Ex001 {

    public static void lerArray(int vetor[]) {
        System.out.println("=================================");
        System.out.println("Tamanho do vetor = " + vetor.length);
        Scanner ler = new Scanner(System.in);
        for(int i = 0; i < vetor.length; i++) {
            System.out.print("Elemento " + i + " = ");
            vetor[i] = ler.nextInt();
        }
        ler.close();
    }

    public static void imprimeArray(int vetor[]) {
        int soma = 0;
        System.out.println("=================================");
        System.out.println("Imprimindo Vetor:");
        for(int i = 0; i < vetor.length; i++) {
            System.out.println("vetor [" + i + "] = " + vetor[i]);
            soma += vetor[i];
        }
        System.out.println("=================================");
        System.out.println("Soma do array: " + soma);
    }
    public static void main(String[] args) throws Exception {
        int vetor[];
        Scanner ler = new Scanner(System.in);
        System.out.print("Informe a quantidade de valores do array: ");
        int tam = ler.nextInt();
        vetor = new int[tam];
        lerArray(vetor);
        imprimeArray(vetor);
        ler.close();
    }
}
