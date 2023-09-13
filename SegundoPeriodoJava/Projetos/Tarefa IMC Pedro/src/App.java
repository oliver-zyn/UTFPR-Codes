import javax.swing.JOptionPane;

import br.edu.utfpr.imc.IMC;

public class App {
    public static void main(String[] args) throws Exception {
        String alturaS = JOptionPane.showInputDialog(null, "Digite a altura (em Metros): ");
        String pesoS = JOptionPane.showInputDialog(null, "Digite o peso (Em Kgs): ");

        double altura = Double.parseDouble(alturaS);
        double peso = Double.parseDouble(pesoS);

        if (altura <= 0 || peso <= 0) {
            JOptionPane.showMessageDialog(null, "Erro, não pode dados negativos ou iguais a 0.");
        } else {
            IMC imc = new IMC(altura, peso);
            double imcI = imc.calcularIMC();
            String caracString = imc.underIMC(imcI);
            System.out.println(imc);
            System.out.printf("IMC: %.2f, Estado: %s", imcI, caracString);
        }

    }
}
