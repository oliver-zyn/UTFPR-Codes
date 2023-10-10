package br.edu.utfpr.Escola;

public abstract class Pessoa {
  private String nome;
  private String telefone;
  private Endereco endereco; //Associação

  public Pessoa() {
  }

  public Pessoa(String nome, String telefone, Endereco endereco) {
    this.nome = nome;
    this.telefone = telefone;
    this.endereco = endereco;
  }

  public String getNome() {
    return this.nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getTelefone() {
    return this.telefone;
  }

  public void setTelefone(String telefone) {
    this.telefone = telefone;
  }

  public Endereco getEndereco() {
    return this.endereco;
  }

  public void setEndereco(Endereco endereco) {
    this.endereco = endereco;
  }

  public String listarEndereco() {
    return this.endereco.getRua() + 
          ", " + this.endereco.getNumero() +
          ", " + this.endereco.getBairro() +
          ", " + this.endereco.getCidade();
  }

  @Override
  public abstract String toString();
}
