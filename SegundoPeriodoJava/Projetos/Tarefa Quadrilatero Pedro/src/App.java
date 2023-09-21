import javax.swing.JOptionPane;

import br.edu.utfpr.quadrilatero.Quadrilatero;

public class App {
    public static void main(String[] args) {

        String lado1S = JOptionPane.showInputDialog(null, "Digite o valor do lado 1: ");
        String lado2S = JOptionPane.showInputDialog(null, "Digite o valor do lado 2: ");

        double lado1 = Integer.parseInt(lado1S);
        double lado2 = Integer.parseInt(lado2S);
        if (lado1 < 0 || lado2 < 0) {
            JOptionPane.showMessageDialog(null, "Erro, não pode lado negativo.");
        } else {
            Quadrilatero quadrilatero = new Quadrilatero(lado1, lado2);
            System.out.println(quadrilatero);
        }
    }
}
