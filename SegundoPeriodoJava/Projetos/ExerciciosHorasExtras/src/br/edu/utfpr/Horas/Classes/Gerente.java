package br.edu.utfpr.Horas.Classes;

public class Gerente extends Empregado{
    private String departamento;

    public Gerente() {
    }

    public Gerente(String nome, String CPF, double salario, double horasSemanais, double horasTrabalhadas, String departamento) {
        super(nome, CPF, salario, horasSemanais, horasTrabalhadas);
        this.departamento = departamento;
    }

    public String getDepartamento() {
        return this.departamento;
    }

    public void setDepartamento(String departamento) {
        this.departamento = departamento;
    }

    @Override
    public String toString() {
        return "Nome = " + getNome() + "\n" +
        "CPF = " + getCPF() + "\n" +
        "Salario = " + getSalario() + "\n" +
        "Horas Semanais = " + getHorasSemanais() + "\n" +
        "Horas Trabalhadas = " + getHorasTrabalhadas() + "\n" +
        "Departamento = " + getDepartamento() + "\n";
    }
}
