package ClassesPolimorfismo;

public class Coordenador extends CargosComissionados {

    public Coordenador() {
    }
    
    public Coordenador(String nome, double salario, double adicionalTitulacao, double gratificacao) {
        super(nome, salario, adicionalTitulacao, gratificacao);
    }

    @Override
    public void calcularGastos() {
        this.salarioTotal = getAdicionalTitulacao() + getGratificacao() + getSalario();
    }

    @Override
    public double getGastos() {
        return this.salarioTotal;
    }

    @Override
    public String toString() {
      return "Coordenador: " + 
      "\n Nome: " + getNome() +
      "\n Salario: " + getSalario() +
      "\n Adicional por titulacao: " + getAdicionalTitulacao() +
      "\n Gratificacao: " + getGratificacao() +
      "\n Salario total: " + getGastos();
  }

}
