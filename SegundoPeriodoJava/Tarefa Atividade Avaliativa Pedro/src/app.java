import javax.swing.JOptionPane;

import br.edu.utfpr.conta.EncapsulamentoConta;

public class app {
    public static void main(String[] args) {
        String opcaoSai;
        int opcaoSaiI = 0;

        String numeroS = JOptionPane.showInputDialog(null, "Digite o número da conta: ");
        String saldoS = JOptionPane.showInputDialog(null, "Digite o valor do saldo inicial: ");

        long numero = Integer.parseInt(numeroS);
        double saldo = Integer.parseInt(saldoS);

        EncapsulamentoConta conta = new EncapsulamentoConta(numero, saldo);

        do {
            String opcaoS = JOptionPane.showInputDialog(null, "Digite a opção: \n[1] - Desposito\n[2] - Saque\n[3] - Sair");
            int opcao = Integer.parseInt(opcaoS);

            switch (opcao) {

            case 1:
                String depositoS = JOptionPane.showInputDialog(null, "Digite a quantidade a depositar: ");
                double depositoI = Integer.parseInt(depositoS);
                conta.deposito(depositoI);

                System.out.println("Valores após deposito: ");
                System.out.println(conta);

                opcaoSai = JOptionPane.showInputDialog(null, "Realizar nova transação? (1- Sim/ 0- Não):");
                opcaoSaiI = Integer.parseInt(opcaoSai);

                break;
            case 2:
                String saqueS = JOptionPane.showInputDialog(null, "Digite a quantidade a sacar: ");
                double saqueI = Integer.parseInt(saqueS);
                conta.saque(saqueI);

                System.out.println("Valores após saque: ");
                System.out.println(conta);

                opcaoSai = JOptionPane.showInputDialog(null, "Realizar nova transação? (1- Sim/ 0- Não):");
                opcaoSaiI = Integer.parseInt(opcaoSai);

                break;
            case 3:
                opcaoSaiI = 0;
                break;
            default:
                System.out.println("Opção inválida.");
                break;
            }
            
        } while (opcaoSaiI != 0);
    }
}
