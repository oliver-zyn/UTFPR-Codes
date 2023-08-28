/* Escreva um programa que calcule o valor do produto de acordo com a taxa de aumento
(%). Solicite ao usuário que informe o valor do produto e a taxa de aumento. O programa
retornar o novo valor do produto. Exemplo: valor do produto = R$ 2.000,00, Taxa de
aumento = 10%. O novo valor do produto é R$ 2.200,00. (Utilize a classe JOptionPane) */

import javax.swing.JOptionPane;

public class ex004 {
    public static void main(String[] args) throws Exception{
        String salario = JOptionPane.showInputDialog(null, "Informe o valor do salário: ");
        String taxa = JOptionPane.showInputDialog(null, "Informe o valor da taxa: ");
        float salarioN = Float.parseFloat(salario);
        float taxaN = Float.parseFloat(taxa);
        float newSalary = salarioN + salarioN*(taxaN/100);
        System.out.println("Novo salário: R$" + newSalary);
    }
}
