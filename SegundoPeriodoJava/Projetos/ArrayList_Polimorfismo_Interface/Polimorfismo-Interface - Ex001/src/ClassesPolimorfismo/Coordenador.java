package ClassesPolimorfismo;

public class Coordenador extends FuncaoGratificada {

    public Coordenador() {
    }
    
    public Coordenador(String nome, String CPF, double salario, double adicionalTitulacao, double gratificacao) {
        super(nome, CPF, salario, adicionalTitulacao, gratificacao);
    }

    @Override
    public double calcularGastos() {
        return getAdicionalTitulacao() + getGratificacao() + getSalario();
    }

    @Override
    public String toString() {
      return "Coordenador: " + 
      "\n Nome: " + getNome() +
      "\n CPF: " + getCPF() +
      "\n Salario: " + getSalario() +
      "\n Adicional por titulacao: " + getAdicionalTitulacao() +
      "\n Gratificacao: " + getGratificacao() +
      "\n Salario total: " + calcularGastos();
  }

}
