package br.edu.utfpr.funcionarios;

import javax.swing.JOptionPane;

public class usaFuncionarios {
    public static void main(String[] args) throws Exception {
        String nome, Ger_Tel, login, senha, salario_S, num_Ramal;
        char Ger_Tel_C;
        double salario;

        Ger_Tel = JOptionPane.showInputDialog(null, "Informe se é um gerente ou telefonista: (G/T)");
        if (Ger_Tel != null && Ger_Tel.length() == 1) {
            Ger_Tel_C = Ger_Tel.charAt(0);

        if (Ger_Tel_C == 'G' || Ger_Tel_C == 'g') {
            nome = JOptionPane.showInputDialog(null, "Informe o nome do gerente:");
            login = JOptionPane.showInputDialog(null, "Informe o login do gerente:");
            senha = JOptionPane.showInputDialog(null, "Informe a senha do gerente:");

            salario_S = JOptionPane.showInputDialog(null, "Informe o salário do gerente:");
            salario = Integer.parseInt(salario_S);

            Gerentes gerente1 = new Gerentes(nome, salario, login, senha);

            System.out.println(gerente1);

        } else if (Ger_Tel_C == 'T' || Ger_Tel_C == 't' ){
            nome = JOptionPane.showInputDialog(null, "Informe o nome do telefonista:");
            num_Ramal = JOptionPane.showInputDialog(null, "Informe o número de ramal do telefonista:");

            salario_S = JOptionPane.showInputDialog(null, "Informe o salário do telefonista:");
            salario = Integer.parseInt(salario_S);

            Telefonistas telefonista1 = new Telefonistas(nome, salario, num_Ramal);

            System.out.println(telefonista1);
        }
    }
}
}