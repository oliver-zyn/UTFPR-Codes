import javax.swing.JOptionPane;

import br.edu.utfpr.Academico;
import br.edu.utfpr.Servidor;
import br.edu.utfpr.Terceiro;

public class App {
    public static void main(String[] args) throws Exception {
        int opcao = 0, quantidadeRefeicoes;
        String nome, email, valorTotalRefeicoes = "";

        do {
           opcao = Integer.parseInt(JOptionPane.showInputDialog(null, "Escolha entre: \n1 - Acadêmico \n2 - Servidor \n3 - Terceiro"));

           if (opcao <= 0 || opcao > 3) JOptionPane.showMessageDialog(null, "Opção inválida! Selecione entre 1-3");
        } while (opcao <= 0 || opcao > 3);

        nome = JOptionPane.showInputDialog(null, "Informe seu nome");
        email = JOptionPane.showInputDialog(null, "Informe seu email");
        quantidadeRefeicoes = Integer.parseInt(JOptionPane.showInputDialog(null, "Quantas refeições serão realizadas?"));

        switch (opcao) {
            case 1:
                long ra = Long.parseLong(JOptionPane.showInputDialog(null, "Qual seu RA?"));
                Academico academico = new Academico(nome, email, ra);
                valorTotalRefeicoes = String.format("%.2f", academico.calculaValorTotalRefeicao(quantidadeRefeicoes));

                System.out.println(academico.toString());
                System.out.println("Valor total das refeições (10% de desconto) = " + valorTotalRefeicoes);

                break;
            case 2:
                long siape = Long.parseLong(JOptionPane.showInputDialog(null, "Qual seu SIAPE?"));
                Servidor servidor = new Servidor(nome, email, siape);
                valorTotalRefeicoes = String.format("%.2f", servidor.calculaValorTotalRefeicao(quantidadeRefeicoes));

                System.out.println(servidor.toString());
                System.out.println("Valor total das refeições (8% de desconto) = " + valorTotalRefeicoes);

                break;
            case 3:
                long cpf = Long.parseLong(JOptionPane.showInputDialog(null, "Qual seu CPF?"));
                Terceiro terceiro = new Terceiro(nome, email, cpf);
                valorTotalRefeicoes = String.format("%.2f", terceiro.calculaValorTotalRefeicao(quantidadeRefeicoes));

                System.out.println(terceiro.toString()); 
                System.out.println("Valor total das refeições (sem desconto) = " + valorTotalRefeicoes);

                break;
            default:
                System.out.println("Opção inválida!");
                break;
        }
    }
}
