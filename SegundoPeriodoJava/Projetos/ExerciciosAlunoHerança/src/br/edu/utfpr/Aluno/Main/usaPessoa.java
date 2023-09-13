package br.edu.utfpr.Aluno.Main;

import javax.swing.JOptionPane;

import br.edu.utfpr.Aluno.Classe.aluno;
import br.edu.utfpr.Aluno.Classe.servidor;

public class usaPessoa {
    public static void main(String[] args) throws Exception {
        String nome, Alu_Ser;
        char Alu_Ser_C;
        int matricula, idade, SIAPE;

        Alu_Ser = JOptionPane.showInputDialog(null, "Informe se é um aluno ou servidor: (A/S)");
        if (Alu_Ser != null && Alu_Ser.length() == 1) {
            Alu_Ser_C = Alu_Ser.charAt(0);

        if (Alu_Ser_C == 'A' || Alu_Ser_C == 'a') {
            nome = JOptionPane.showInputDialog(null, "Informe o nome do aluno:");

            String idade_S = JOptionPane.showInputDialog(null, "Informe a idade do aluno:");
            idade = Integer.parseInt(idade_S);

            String matricula_S = JOptionPane.showInputDialog(null, "Informe a matricula do aluno:");
            matricula = Integer.parseInt(matricula_S);

            aluno aluno1 = new aluno(nome, idade, matricula);
            System.out.println(aluno1);

        } else if (Alu_Ser_C == 'S' || Alu_Ser_C == 's' ){
            nome = JOptionPane.showInputDialog(null, "Informe o nome do servidor:");

            String idade_S = JOptionPane.showInputDialog(null, "Informe a idade do servidor:");
            idade = Integer.parseInt(idade_S);

            String SIAPE_S = JOptionPane.showInputDialog(null, "Informe o SIAPE do servidor:");
            SIAPE = Integer.parseInt(SIAPE_S);

            servidor servidor1 = new servidor(nome, idade, SIAPE);
            System.out.println(servidor1);
        }
    }        
}
}