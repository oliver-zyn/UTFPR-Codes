package ClassesPolimorfismo;

public abstract class CargosComissionados extends UniversidadeFuncionarios {
    private double gratificacao;
    
    public CargosComissionados() {
    }

    public CargosComissionados(String nome, double salario, double gratificacao, double adicionalTitulacao) {
        super(nome, salario, adicionalTitulacao);
        this.gratificacao = gratificacao;
    }

    public double getGratificacao() {
      return this.gratificacao;
    }

    public void setGratificacao(double gratificacao) {
      this.gratificacao = gratificacao;
    }
    
    public abstract String toString();

}
