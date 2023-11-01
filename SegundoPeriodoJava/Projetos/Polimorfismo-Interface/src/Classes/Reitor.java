package Classes;

public class Reitor extends FuncaoGratificada {

  public Reitor() {
  }

  public Reitor(String nome, String CPF, double salario, double adicionalTitulacao, double gratificacao) {
      super(nome, CPF, salario, adicionalTitulacao, gratificacao);
  }  

  public double calcularGastos() {
    return getGratificacao() + getSalario() + getAdicionalTitulacao();
  }
  
}