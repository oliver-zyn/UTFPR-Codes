package br.edu.utfpr;

public class Terceiro extends Pessoa {
  private long cpf;

  public Terceiro(String nome, String email, long cpf) {
    super(nome, email);
    this.cpf = cpf;
  }

  public long getCpf() {
    return this.cpf;
  }

  @Override
  public double calculaValorTotalRefeicao(int quantidadeRefeicoes) {
    return 10.5 * quantidadeRefeicoes;
  }

  public void setCpf(long cpf) {
    this.cpf = cpf;
  }

  @Override
  public String toString() {
    return "\nNome = " + getNome() +
      "\nEmail = " + getEmail() +
      "\nCPF = " + getCpf();
  }

}
