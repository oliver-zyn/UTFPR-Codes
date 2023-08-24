/*
Ler um vetor A com 10 elementos inteiros correspondentes as idades de
um grupo de pessoas. Escreva um programa que determine e escreva a
quantidade de pessoas que possuem idade superior a 35 anos. (Utilize
JOptionPane).
 */

import javax.swing.JOptionPane;

public class Ex003 {

    public static void lerArray(int vetor[]) {
        String valor;
        System.out.println("=================================");
        for(int i = 0; i < vetor.length; i++) {
            valor = JOptionPane.showInputDialog("Elemento " + i + " = ");
            vetor[i] = Integer.parseInt(valor);
        }
    }

    public static void pessoasAcimade35(int vetor[]) {
        int vetorAcima[], count = 0, y = 0;
        for(int i = 0; i < vetor.length; i++) {
            if (vetor[i] > 35) {
                count++;
                vetorAcima = new int[count];
                vetorAcima[y] = vetor[i];
                y++;
            }
        }
        JOptionPane.showMessageDialog(null, "Número de pessoas acima de 35 anos: " + count);
    }
    public static void main(String[] args) {
        int vetor[];
        String valor = JOptionPane.showInputDialog("Informe a quantidade de valores do array: ");
        int valores = Integer.parseInt(valor);
        vetor = new int[valores];
        lerArray(vetor);
        pessoasAcimade35(vetor);
    }
}
