package ClassesPolimorfismo;

public class Reitor extends FuncaoGratificada {

  public Reitor() {
  }

  public Reitor(String nome, String CPF, double salario, double adicionalTitulacao, double gratificacao) {
      super(nome, CPF, salario, adicionalTitulacao, gratificacao);
  }  

  public double calcularGastos() {
    return getGratificacao() + getSalario() + getAdicionalTitulacao();
  }

  @Override
  public String toString() {
      return "Reitor: " + 
      "\n Nome: " + getNome() +
      "\n CPF: " + getCPF() +
      "\n Salario: " + getSalario() +
      "\n Adicional por titulacao: " + getAdicionalTitulacao() +
      "\n Gratificacao: " + getGratificacao() +
      "\n Salario total: " + calcularGastos();
  }
  
}