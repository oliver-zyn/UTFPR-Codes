package br.edu.utfpr;

public class Servidor extends Pessoa {
  private long siape;

  public Servidor(String nome, String email, long siape) {
    super(nome, email);
    this.siape = siape;
  }

  public long getSiape() {
    return this.siape;
  }

  public void setSiape(long siape) {
    this.siape = siape;
  }

  @Override
  public double calculaValorTotalRefeicao(int quantidadeRefeicoes) {
    double valorBaseRefeicao = 10.5 * quantidadeRefeicoes;
    double valorComDescontoRefeicao = valorBaseRefeicao - (valorBaseRefeicao * 0.08);

    return valorComDescontoRefeicao;
  }

  @Override
  public String toString() {
    return "\nNome = " + getNome() +
      "\nEmail = " + getEmail() +
      "\nSIAPE = " + getSiape();
  }
}
