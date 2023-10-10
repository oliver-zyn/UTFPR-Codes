import javax.swing.JOptionPane;

import br.edu.utfpr.Aniversario;
import br.edu.utfpr.DiaDosNamorados;
import br.edu.utfpr.Natal;
import br.edu.utfpr.Pessoa;

public class App {
    public static void main(String[] args) throws Exception {
        String nomeDestinatario, nomeRemetente, endereco, cidade, estado, email, celular, dataComemorativa;
        int dataComemorativaInt;

        nomeDestinatario = JOptionPane.showInputDialog(null, "Qual o nome do destinatário? ");
        endereco = JOptionPane.showInputDialog(null, "Qual o endereço do destinatário? ");
        cidade = JOptionPane.showInputDialog(null, "Qual a cidade do destinatário? ");
        estado = JOptionPane.showInputDialog(null, "Qual o estado do destinatário? ");
        email = JOptionPane.showInputDialog(null, "Qual o email do destinatário? ");
        celular = JOptionPane.showInputDialog(null, "Qual o celular do destinatário? ");

        nomeRemetente = JOptionPane.showInputDialog(null, "Qual o nome do remetente? ");

        dataComemorativa = JOptionPane.showInputDialog(null, "Qual a data comemorativa?\n1- Dia dos namorados\n2- Natal\n3- Aniversário");
        dataComemorativaInt = Integer.parseInt(dataComemorativa);

        Pessoa destinatario = new Pessoa(nomeDestinatario, endereco, cidade, estado, email, celular);

        switch (dataComemorativaInt) {
            case 1:
                DiaDosNamorados diaDosNamorados = new DiaDosNamorados(destinatario, nomeRemetente);
                diaDosNamorados.mostraMensagem();
                break;
            case 2:
                Natal natal = new Natal(destinatario, nomeRemetente);
                natal.mostraMensagem();
                break;

            case 3:
                Aniversario aniversario = new Aniversario(destinatario, nomeRemetente);
                aniversario.mostraMensagem();
                break;
            default:
                System.out.println("Opcao invalida!");
                break;
        }
    }
}
