import javax.swing.JOptionPane;

public class ex005Pedro {
    public static void main(String[] args) throws Exception {
        String altura = JOptionPane.showInputDialog(null, "Informe a altura: (em M) ");
        String peso = JOptionPane.showInputDialog(null, "Informe o peso: (em KG) ");
        float alturaN = Float.parseFloat(altura);
        float pesoN = Float.parseFloat(peso);
        float IMC = pesoN / (alturaN * alturaN);
        String cond;
        if (IMC < 20) {
            cond = "Magro";
        } else if (IMC < 24) {
            cond = "Normal";
        } else if (IMC < 29) {
            cond = "Acima do peso";
        } else if (IMC < 34) {
            cond = "Obeso";
        } else {
            cond = "Muito Obeso";
        }

        if (pesoN == 0 || alturaN == 0) {
            System.out.println("Error");
        } else {
            JOptionPane.showMessageDialog(null, "Peso: " + pesoN + "\nAltura: " + alturaN + "\nIMC: " + IMC + "\nCondição: " + cond);
        }
    }
}
