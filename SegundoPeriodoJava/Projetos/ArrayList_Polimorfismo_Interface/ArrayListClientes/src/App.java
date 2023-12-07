import javax.swing.JOptionPane;
import java.util.ArrayList;

import Classes.ClienteFuncionario;
import Classes.ClientePessoaFisica;
import Classes.ClientePessoaJuridica;
import Classes.Empresa;
import Classes.Pessoa;

public class App {
    public static void main(String[] args) throws Exception {
        ArrayList<Pessoa> clientes = new ArrayList<>();
        Empresa empresa = new Empresa(clientes);
        int opcao = 0;

        while (opcao != 7) {
            opcao = Integer.parseInt(JOptionPane.showInputDialog("Menu Principal:\n1. Adicionar Cliente Funcionário\n2. Adicionar Cliente Pessoa Física\n3. Adicionar Cliente Pessoa Jurídica\n4. Excluir Cliente pelo Índice\n5. Imprimir Lista de Clientes\n6. Ordenar Clientes por Nome\n7. Sair"));        

            switch (opcao) {
                case 1:
                    String nomecf = JOptionPane.showInputDialog("Nome do Cliente Funcionário: ");
                    String CTPS = JOptionPane.showInputDialog("CTPS: ");
                    empresa.inserir(new ClienteFuncionario(nomecf, CTPS));
                    break;
                case 2:
                    String nomepf = JOptionPane.showInputDialog("Nome da Pessoa Física: ");
                    String CPF = JOptionPane.showInputDialog("CPF: ");
                    empresa.inserir(new ClientePessoaFisica(nomepf, CPF));
                    break;
                case 3:
                    String nomepj = JOptionPane.showInputDialog("Nome da Pessoa Jurídica: ");
                    String CNPJ = JOptionPane.showInputDialog("CNPJ: ");
                    empresa.inserir(new ClientePessoaJuridica(nomepj, CNPJ));
                    break;
                case 4:
                    String nomeEx = JOptionPane.showInputDialog("Nome do cliente que será excluido: ");

                    if (empresa.excluir(nomeEx)) {
                        JOptionPane.showMessageDialog(null, "Cliente excluido com sucesso!");
                    } else {
                        JOptionPane.showMessageDialog(null, "Nao foi possivel excluir o cliente!");
                    }

                    break;
                case 5:
                    empresa.imprimir();
                    break;
                case 6:
                    empresa.ordenarAlfabetica();
                    JOptionPane.showMessageDialog(null, "Clientes ordenados por nome!");
                    break;
                case 7:
                    JOptionPane.showMessageDialog(null, "Encerrando programa...");
                    break;
                default:
                    JOptionPane.showMessageDialog(null, "Opção inválida. Tente novamente!");
            }
        }
    }
}
