package br.edu.utfpr.HorasExtras;

public class Gerente extends Empregado{
  private String departamento;

  public Gerente() {
    this.departamento = "";
  }

  public Gerente(String nome, String cpf, double salario, double horasSemanais, double horasTrabalhadas, String departamento) {
    super(nome, cpf, salario, horasSemanais, horasTrabalhadas);
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
    "CPF = " + getCpf() + "\n" +
    "Salario = " + getSalario() + "\n" +
    "Horas Semanais = " + getHorasSemanais() + "\n" +
    "Horas Trabalhadas = " + getHorasTrabalhadas() + "\n" +
    "Departamento = " + getDepartamento() + "\n";
}

}