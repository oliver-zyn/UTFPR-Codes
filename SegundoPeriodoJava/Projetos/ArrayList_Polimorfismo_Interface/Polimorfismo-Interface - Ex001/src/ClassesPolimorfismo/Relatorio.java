package ClassesPolimorfismo;

public class Relatorio {
  private double totalGastos;

  public Relatorio() {
  }

  public double getTotalGastos() {
    return this.totalGastos;
  }

  public void setTotalGastos(double totalGastos) {
    this.totalGastos = totalGastos;
  }

  void somar(Pessoa pessoa) {
    setTotalGastos(getTotalGastos() + pessoa.calcularGastos()); 
  }
  
}
