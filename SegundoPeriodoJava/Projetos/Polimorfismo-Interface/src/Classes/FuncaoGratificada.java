package Classes;

public abstract class FuncaoGratificada extends Servidor {
    private double gratificacao;

    public FuncaoGratificada() {
    }

    public FuncaoGratificada(String nome, String CPF, double salario, double adicionalTitulacao, double gratificacao) {
        super(nome, CPF, salario, adicionalTitulacao);
        this.gratificacao = gratificacao;
    }

    public double getGratificacao() {
      return this.gratificacao;
    }

    public void setGratificacao(double gratificacao) {
      this.gratificacao = gratificacao;
    }

    @Override
    public String toString() {
      return "{" +
        " gratificacao='" + getGratificacao() + "'" +
        "}";
    }

}
