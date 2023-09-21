package br.edu.utfpr;

public class Academico extends Pessoa {
  private long ra;

  public Academico(String nome, String email, long ra) {
    super(nome, email);
    this.ra = ra;
  }

  public long getRa() {
    return this.ra;
  }

  public void setRa(long ra) {
    this.ra = ra;
  }

  @Override
  public double calculaValorTotalRefeicao(int quantidadeRefeicoes) {
    double valorBaseRefeicao = 10.5 * quantidadeRefeicoes;
    double valorComDescontoRefeicao = valorBaseRefeicao - (valorBaseRefeicao * 0.1);

    return valorComDescontoRefeicao;
  }

  @Override
  public String toString() {
    return "\nNome = " + getNome() +
      "\nEmail = " + getEmail() +
      "\nRA = " + getRa();
  }

}
