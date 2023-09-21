package br.edu.utfpr;

public abstract class Pessoa {
  private String nome;
  private String email;

  public Pessoa(String nome, String email) {
    this.nome = nome;
    this.email = email;
  }

  public String getNome() {
    return this.nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getEmail() {
    return this.email;
  }

  public void setEmail(String email) {
    this.email = email;
  }

  public abstract double calculaValorTotalRefeicao(int quantidadeRefeicoes);

  @Override
  public abstract String toString();
}
