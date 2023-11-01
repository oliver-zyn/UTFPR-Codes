package Classes;

public abstract class Servidor extends Pessoa {
  private double salario;
  private double adicionalTitulacao;


  public Servidor() {
  }

  public Servidor(String nome, String CPF, double salario, double adicionalTitulacao) {
    super(nome, CPF);
    this.salario = salario;
    this.adicionalTitulacao = adicionalTitulacao;
  }

  public double getSalario() {
    return this.salario;
  }

  public void setSalario(double salario) {
    this.salario = salario;
  }

  public double getAdicionalTitulacao() {
    return this.adicionalTitulacao;
  }

  public void setAdicionalTitulacao(double adicionalTitulacao) {
    this.adicionalTitulacao = adicionalTitulacao;
  }

  @Override
  public String toString() {
    return "{" +
      " salario='" + getSalario() + "'" +
      ", adicionalTitulacao='" + getAdicionalTitulacao() + "'" +
      "}";
  }

}