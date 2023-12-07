package ClassesPolimorfismo;

public class Reitor extends CargosComissionados {

  public Reitor() {
  }

  public Reitor(String nome, double salario, double gratificacao, double adicionalTitulacao) {
      super(nome, salario, gratificacao, adicionalTitulacao);
  }  

  public void calcularGastos() {
    this.salarioTotal = getGratificacao() + getSalario();
  }
  
  public double getGastos() {
    return this.salarioTotal;
  }

  @Override
  public String toString() {
      return "Reitor: " + 
      "\n Nome: " + getNome() +
      "\n Salario: " + getSalario() +
      "\n Gratificacao: " + getGratificacao() +
      "\n Salario total: " + getGastos();
  }
}