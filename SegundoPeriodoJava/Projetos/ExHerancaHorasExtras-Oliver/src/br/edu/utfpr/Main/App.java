package br.edu.utfpr.Main;

import javax.swing.JOptionPane;

import br.edu.utfpr.HorasExtras.Gerente;
import br.edu.utfpr.HorasExtras.Supervisor;

public class App {
    public static void main(String[] args) throws Exception {
        int tipoEmpregado;
        String sTipoEmpregado, nome, cpf, departamento, setor, sSalario, sHorasSemanais, sHorasTrabalhadas;
        double salario, horasSemanais, horasTrabalhadas;

        sTipoEmpregado = JOptionPane.showInputDialog(null, "Escolha entre: \n1 - gerente \n2 - supervisor ");
        tipoEmpregado = Integer.parseInt(sTipoEmpregado);

        if (tipoEmpregado == 1) {
            nome = JOptionPane.showInputDialog(null, "Informe o nome do gerente:");
            cpf = JOptionPane.showInputDialog(null, "Informe o CPF do gerente:");
            departamento = JOptionPane.showInputDialog(null, "Informe o departamento do gerente:");

            sSalario = JOptionPane.showInputDialog(null, "Informe o salário do gerente:");
            salario = Double.parseDouble(sSalario);

            sHorasSemanais = JOptionPane.showInputDialog(null, "Informe a quantidade esperada de horas semanais:");
            horasSemanais = Double.parseDouble(sHorasSemanais);

            sHorasTrabalhadas = JOptionPane.showInputDialog(null, "Informe a quantidade trabalhada de horas:");
            horasTrabalhadas = Double.parseDouble(sHorasTrabalhadas);

            Gerente gerente = new Gerente(nome, cpf, salario, horasSemanais, horasTrabalhadas, departamento);

            System.out.println(gerente.toString());

            System.out.println("Valor hora extra = " + gerente.calculaValorHoraExtra());
            System.out.println("Quantidade de horas extras = " + gerente.calculaQuantidadeHorasExtras());
            System.out.println("Valor de horas extras = " + gerente.calculaValorHorasExtras());

        } else if (tipoEmpregado == 2) {
            nome = JOptionPane.showInputDialog(null, "Informe o nome do supervisor:");
            cpf = JOptionPane.showInputDialog(null, "Informe o CPF do supervisor:");
            setor = JOptionPane.showInputDialog(null, "Informe o setor do supervisor:");

            sSalario = JOptionPane.showInputDialog(null, "Informe o salário do supervisor:");
            salario = Double.parseDouble(sSalario);

            sHorasSemanais = JOptionPane.showInputDialog(null, "Informe a quantidade esperada de horas semanais:");
            horasSemanais = Double.parseDouble(sHorasSemanais);

            sHorasTrabalhadas = JOptionPane.showInputDialog(null, "Informe a quantidade trabalhada de horas:");
            horasTrabalhadas = Double.parseDouble(sHorasTrabalhadas);

            Supervisor supervisor = new Supervisor(nome, cpf, salario, horasSemanais, horasTrabalhadas, setor);

            System.out.println(supervisor.toString());

            System.out.println("Valor hora extra = " + supervisor.calculaValorHoraExtra());
            System.out.println("Quantidade de horas extras = " + supervisor.calculaQuantidadeHorasExtras());
            System.out.println("Valor de horas extras = " + supervisor.calculaValorHorasExtras());

        } else {
            System.out.println("Opcao invalida!");
        }
    }
}
