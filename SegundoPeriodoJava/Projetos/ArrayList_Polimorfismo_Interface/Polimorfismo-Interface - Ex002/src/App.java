import java.util.ArrayList;

import javax.swing.JOptionPane;

import ClassesPolimorfismo.*;

public class App {
    public static void main(String[] args) throws Exception {
        ArrayList<Pessoa> pessoas = new ArrayList<>();
        Universidade univ = new Universidade(pessoas);
        int opcao = 0;

        do {
            opcao = Integer.parseInt(JOptionPane.showInputDialog("Deseja inserir / ver: \n1- Professor\n2-Coordenador\n3-Reitor\n4-Estagiario\n5-Luz\n6-Valor total de despesas universidade\n7-Sair"));

            switch (opcao) {
                case 1:
                    String nomeProf = JOptionPane.showInputDialog(null, "Nome do professor: ");
                    double salarioProf = Integer.parseInt(JOptionPane.showInputDialog(null, "Salário do professor: "));
                    double adcTitulacaoProf = Integer.parseInt(JOptionPane.showInputDialog(null, "Titulação do professor: "));
                    Professores profe = new Professores(nomeProf, salarioProf, adcTitulacaoProf);
                    profe.calcularGastos();
                    univ.inserirPessoa(profe);
                    JOptionPane.showMessageDialog(null, profe.toString());
                    break;
                    
                case 2:
                    String nomeCoord = JOptionPane.showInputDialog(null, "Nome do coordenador: ");
                    double salarioCoord = Integer.parseInt(JOptionPane.showInputDialog(null, "Salário do coordenador: "));
                    double adcTitulacaoCoord = Integer.parseInt(JOptionPane.showInputDialog(null, "Titulação do coordenador: "));
                    double gratificacaoCoord = Integer.parseInt(JOptionPane.showInputDialog(null, "Gratificação do coordenador: "));
                    Coordenador coorde = new Coordenador(nomeCoord, salarioCoord, adcTitulacaoCoord, gratificacaoCoord);
                    coorde.calcularGastos();
                    univ.inserirPessoa(coorde);
                    JOptionPane.showMessageDialog(null, coorde.toString());
                    break;
                    
                case 3:
                    String nomeReitor = JOptionPane.showInputDialog(null, "Nome do coordenador: ");
                    double salarioReitor = Integer.parseInt(JOptionPane.showInputDialog(null, "Salário do coordenador: "));
                    double gratificacaoReitor = Integer.parseInt(JOptionPane.showInputDialog(null, "Gratificação do coordenador: "));
                    double adcTitulacaoReitor = 0;
                    Reitor Reitor = new Reitor(nomeReitor, salarioReitor, gratificacaoReitor, adcTitulacaoReitor);
                    Reitor.calcularGastos();
                    univ.inserirPessoa(Reitor);
                    JOptionPane.showMessageDialog(null, Reitor.toString());
                    break;
                    
                case 4:
                    String nomeEstag = JOptionPane.showInputDialog(null, "Nome do estagiario: ");
                    double auxilioBolsa = Integer.parseInt(JOptionPane.showInputDialog(null, "Valor do auxilio bolsa: "));
                    double auxilioTransporte = Integer.parseInt(JOptionPane.showInputDialog(null, "Valor do auxilio transporte: "));
                    Estagiario estagiario = new Estagiario(nomeEstag, auxilioBolsa, auxilioTransporte);
                    estagiario.calcularGastos();
                    univ.inserirPessoa(estagiario);
                    JOptionPane.showMessageDialog(null, estagiario.toString());
                    break;

                case 5:
                    double baseCalculo = Double.parseDouble(JOptionPane.showInputDialog(null, "Valor base da luz: "));
                    double valorICMS = Double.parseDouble(JOptionPane.showInputDialog(null, "Valor do ICMS: "));
                    Luz luz = new Luz(baseCalculo, valorICMS);
                    luz.calcularGastos();
                    univ.inserirLuz(luz);
                    JOptionPane.showMessageDialog(null, luz.toString());
                    break;

                case 6:
                    JOptionPane.showMessageDialog(null, "Total de despesas da universidade: " + univ.getTotalGastoUniversidade());
                    break;

                case 7:
                    JOptionPane.showMessageDialog(null, "Saindo...");
                    break;
            
                default:
                    JOptionPane.showMessageDialog(null, "Escolha uma opcao valida!");
                    break;
            }
        } while (opcao != 7);
    }
}
