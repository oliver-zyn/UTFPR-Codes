package br.edu.utfpr.Horas.Main;

import javax.swing.JOptionPane;

import br.edu.utfpr.Horas.Classes.Supervisor;
import br.edu.utfpr.Horas.Classes.Gerente;

public class usaHoras {
    public static void main(String[] args) throws Exception {
        String nome, Ger_Sup, CPF, setor, departamento;
        String salario_S, HorasSemanais_S, HorasTrabalhadas_S;
        char Ger_Sup_C;
        double salario, HorasSemanais, HorasTrabalhadas;

        Ger_Sup = JOptionPane.showInputDialog(null, "Informe se é um gerente ou supervisor: (G/S)");
        if (Ger_Sup != null && Ger_Sup.length() == 1) {
            Ger_Sup_C = Ger_Sup.charAt(0);

        if (Ger_Sup_C == 'G' || Ger_Sup_C == 'g') {
            double HorasEx, ValorPorHoraEx, ValorTotalHoraEx;

            Gerente gerente1 = new Gerente();

            nome = JOptionPane.showInputDialog(null, "Informe o nome do gerente:");
            gerente1.setNome(nome);
            CPF = JOptionPane.showInputDialog(null, "Informe o CPF do gerente:");
            gerente1.setCPF(CPF);
            departamento = JOptionPane.showInputDialog(null, "Informe o departamento do gerente:");
            gerente1.setDepartamento(departamento);

            salario_S = JOptionPane.showInputDialog(null, "Informe o salário do gerente:");
            salario = Integer.parseInt(salario_S);
            gerente1.setSalario(salario);

            HorasSemanais_S = JOptionPane.showInputDialog(null, "Informe a quantidade esperada de horas semanais:");
            HorasSemanais = Integer.parseInt(HorasSemanais_S);
            gerente1.setHorasSemanais(HorasSemanais);

            HorasTrabalhadas_S = JOptionPane.showInputDialog(null, "Informe a quantidade trabalhada de horas:");
            HorasTrabalhadas = Integer.parseInt(HorasTrabalhadas_S);
            gerente1.setHorasTrabalhadas(HorasTrabalhadas);

            HorasEx = gerente1.calcularHorasEx(HorasSemanais, HorasTrabalhadas);
            ValorPorHoraEx = gerente1.calcularValorPorHorasEx(salario, HorasSemanais);
            ValorTotalHoraEx = gerente1.calcularValorHorasEx(ValorPorHoraEx, HorasEx);

            System.out.println(gerente1);
            System.out.println("Horas extras trabalhadas: " + HorasEx);
            System.out.printf("Valor por hora extra: %.2f\n", ValorPorHoraEx);
            System.out.printf("Valor total pelas horas extras trabalhadas: %.2f\n", ValorTotalHoraEx);

        } else if (Ger_Sup_C == 'S' || Ger_Sup_C == 's' ){
            double HorasEx, ValorPorHoraEx, ValorTotalHoraEx;
            nome = JOptionPane.showInputDialog(null, "Informe o nome do supervisor:");
            CPF = JOptionPane.showInputDialog(null, "Informe o CPF do supervisor:");
            setor = JOptionPane.showInputDialog(null, "Informe o setor do supervisor:");
            
            salario_S = JOptionPane.showInputDialog(null, "Informe o salário do supervisor:");
            salario = Integer.parseInt(salario_S);

            HorasSemanais_S = JOptionPane.showInputDialog(null, "Informe a quantidade esperada de horas semanais:");
            HorasSemanais = Integer.parseInt(HorasSemanais_S);

            HorasTrabalhadas_S = JOptionPane.showInputDialog(null, "Informe a quantidade trabalhada de horas:");
            HorasTrabalhadas = Integer.parseInt(HorasTrabalhadas_S);

            Supervisor supervisor1 = new Supervisor(nome, CPF, salario, HorasSemanais, HorasTrabalhadas, setor);

            HorasEx = supervisor1.calcularHorasEx(HorasSemanais, HorasTrabalhadas);
            ValorPorHoraEx = supervisor1.calcularValorPorHorasEx(salario, HorasSemanais);
            ValorTotalHoraEx = supervisor1.calcularValorHorasEx(ValorPorHoraEx, HorasEx);

            System.out.println(supervisor1);
            System.out.println("Horas extras trabalhadas: " + HorasEx);
            System.out.printf("Valor por hora extra: %.2f\n", ValorPorHoraEx);
            System.out.printf("Valor total pelas horas extras trabalhadas: %.2f\n", ValorTotalHoraEx);
        }
    }
    }
}
