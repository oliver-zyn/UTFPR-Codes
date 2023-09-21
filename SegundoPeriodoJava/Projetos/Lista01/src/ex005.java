import javax.swing.JOptionPane;

public class ex005 {
    public static void main(String[] args) throws Exception {
        float fPeso, fAltura, fIMC;
        String sIMCMessage;

        do {
            fPeso = Float.parseFloat(JOptionPane.showInputDialog("Informe seu peso"));
            fAltura = Float.parseFloat(JOptionPane.showInputDialog("Informe sua altura"));

            if (fPeso <= 0 || fAltura <= 0) {
                JOptionPane.showMessageDialog(null, "Informe um valor válido!");
            }
        }
        while(fPeso <= 0 || fAltura <= 0);

        fIMC = (fPeso / (fAltura * fAltura));

        if (fIMC < 20) {
            sIMCMessage = "Magro";
        } else if (fIMC < 24) {
            sIMCMessage = "Normal";
        } else if (fIMC < 29) {
            sIMCMessage = "Acima do Peso";
        } else if (fIMC < 34) {
            sIMCMessage = "Obeso";
        } else {
            sIMCMessage = "Muito Obeso";
        }

        JOptionPane.showMessageDialog(null, "Peso = " + fPeso + "\nAltura = " + fAltura + "\nIMC = " + String.format("%.2f", fIMC) + "\nConsiderado: " + sIMCMessage);
    }
}
