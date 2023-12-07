package ClassesPolimorfismo;

public abstract class UniversidadeFuncionarios extends Pessoa {
  private double salario;
  private double adicionalTitulacao;
  protected double salarioTotal;

  public UniversidadeFuncionarios() {
  }

  public UniversidadeFuncionarios(String nome, double salario, double adicionalTitulacao) {
    super(nome);
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
  public abstract String toString();

}