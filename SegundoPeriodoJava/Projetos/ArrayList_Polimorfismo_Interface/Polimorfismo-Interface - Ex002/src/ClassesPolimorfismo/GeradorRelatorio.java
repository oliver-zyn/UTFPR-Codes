package ClassesPolimorfismo;

public class GeradorRelatorio {
  private double totalGastos;

  public GeradorRelatorio() {
  }

  public double getTotalGastos() {
    return this.totalGastos;
  }

  public void setTotalGastos(double totalGastos) {
    this.totalGastos = totalGastos;
  }

  void somarPessoa(Pessoa pessoa) {
    setTotalGastos(getTotalGastos() + pessoa.getGastos()); 
  }

  void somarLuz(Luz luz) {
    setTotalGastos(getTotalGastos() + luz.getGastos()); 
  }
  
}
