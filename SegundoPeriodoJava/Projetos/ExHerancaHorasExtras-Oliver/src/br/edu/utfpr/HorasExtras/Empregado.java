package br.edu.utfpr.HorasExtras;

public class Empregado {
  private String nome;
  private String cpf;
  private double salario;
  private double horasSemanais;
  private double horasTrabalhadas;

  public Empregado() {
    this.nome = "";
    this.cpf = "000.000.000-00";
    this.salario = 0;
    this.horasSemanais = 0;
    this.horasTrabalhadas = 0;
  }

  public Empregado(String nome, String cpf, double salario, double horasSemanais, double horasTrabalhadas) {
    this.nome = nome;
    this.cpf = cpf;
    this.salario = salario;
    this.horasSemanais = horasSemanais;
    this.horasTrabalhadas = horasTrabalhadas;
  }

  public String getNome() {
    return this.nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getCpf() {
    return this.cpf;
  }

  public void setCpf(String cpf) {
    this.cpf = cpf;
  }

  public double getSalario() {
    return this.salario;
  }

  public void setSalario(double salario) {
    this.salario = salario;
  }

  public double getHorasSemanais() {
    return this.horasSemanais;
  }

  public void setHorasSemanais(double horasSemanais) {
    this.horasSemanais = horasSemanais;
  }

  public double getHorasTrabalhadas() {
    return this.horasTrabalhadas;
  }

  public void setHorasTrabalhadas(double horasTrabalhadas) {
    this.horasTrabalhadas = horasTrabalhadas;
  }

  public double calculaValorHoraExtra() {
    return (getSalario() / getHorasSemanais()) * 1.5;
  }

  public double calculaQuantidadeHorasExtras() {
    double horasExtras = getHorasTrabalhadas() - getHorasSemanais();

    if (horasExtras <= 0) horasExtras = 0;

    return horasExtras;
  }

  public double calculaValorHorasExtras() {
    return (calculaValorHoraExtra() * calculaQuantidadeHorasExtras());
  }

  @Override
    public String toString() {
        return "Nome = " + getNome() + "\n" +
            "CPF = " + getCpf() + "\n" +
            "Salario = " + getSalario() + "\n" +
            "Horas Semanais = " + getHorasSemanais() + "\n" +
            "Horas Trabalhadas = " + getHorasTrabalhadas() + "\n";
    }

}