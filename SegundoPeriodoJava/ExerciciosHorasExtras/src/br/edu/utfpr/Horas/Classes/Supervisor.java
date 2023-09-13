package br.edu.utfpr.Horas.Classes;

public class Supervisor extends Empregado{
    private String setor;

    public Supervisor() {
    }

    public Supervisor(String nome, String CPF, double salario, double horasSemanais, double horasTrabalhadas, String setor) {
        super(nome, CPF, salario, horasSemanais, horasTrabalhadas);
        this.setor = setor;
    }

    public String getSetor() {
        return this.setor;
    }

    public void setSetor(String setor) {
        this.setor = setor;
    }

    @Override
    public String toString() {
        return "Nome = " + getNome() + "\n" +
        "CPF = " + getCPF() + "\n" +
        "Salario = " + getSalario() + "\n" +
        "Horas Semanais = " + getHorasSemanais() + "\n" +
        "Horas Trabalhadas = " + getHorasTrabalhadas() + "\n" +
        "Departamento = " + getSetor() + "\n";
    }
}