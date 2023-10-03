package br.edu.utfpr.Escola;

public class Professor extends Pessoa {
  private int identificacao;

  public Professor() {
  }

  public Professor(String nome, String telefone, Endereco endereco, int identificacao) {
    super(nome, telefone, endereco);
    this.identificacao = identificacao;
  }

  public int getIdentificacao() {
    return this.identificacao;
  }

  public void setIdentificacao(int identificacao) {
    this.identificacao = identificacao;
  }

  @Override
  public String toString() {
    return "Nome: " + getNome() +
          "\nTelefone: " + getTelefone() +
          "\nEndereço: " + getEndereco() +
          "\nidentificação: " + getIdentificacao();
  }
}
