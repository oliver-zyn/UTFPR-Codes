/*
 * Criar um vetor A com 5 elementos inteiros. Implementar um programa que
defina e escreva a média aritmética simples dos elementos ímpares
armazenados neste vetor. Faça métodos para ler os elementos do vetor,
imprimir e calcular a média (utilize Scanner)
 */

import java.util.Scanner;

public class Ex002 {

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
        System.out.println("=================================");
        System.out.println("Imprimindo Vetor:");
        for(int i = 0; i < vetor.length; i++) {
            System.out.println("vetor [" + i + "] = " + vetor[i]);
        }
    }

    public static void calcularMediaDeImpar(int vetor[]) {
        float soma = 0;
        int count = 0;
        for(int i = 0; i < vetor.length; i++) {
            if (vetor[i] % 2 != 0) {
                soma += vetor[i]; count++;
            }
        }
        System.out.println("=================================");
        System.out.println("Calculando a media dos impares no vetor: ");
        System.out.println("Media aritmética: " + soma/count);
    }


    public static void main(String[] args) {
        int vetor[];
        Scanner ler = new Scanner(System.in);
        System.out.print("Informe a quantidade de valores do array: ");
        int tam = ler.nextInt();
        vetor = new int[tam];
        lerArray(vetor);
        imprimeArray(vetor);
        calcularMediaDeImpar(vetor);
        ler.close();
    }
}
