package br.edu.utfpr;

public class Pessoa {
  private String nome;
  private String endereco;
  private String cidade;
  private String estado;
  private String email;
  private String celular;

  public Pessoa() {
  }

  public Pessoa(String nome, String endereco, String cidade, String estado, String email, String celular) {
    this.nome = nome;
    this.endereco = endereco;
    this.cidade = cidade;
    this.estado = estado;
    this.email = email;
    this.celular = celular;
  }

  public String getNome() {
    return this.nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getEndereco() {
    return this.endereco;
  }

  public void setEndereco(String endereco) {
    this.endereco = endereco;
  }

  public String getCidade() {
    return this.cidade;
  }

  public void setCidade(String cidade) {
    this.cidade = cidade;
  }

  public String getEstado() {
    return this.estado;
  }

  public void setEstado(String estado) {
    this.estado = estado;
  }

  public String getEmail() {
    return this.email;
  }

  public void setEmail(String email) {
    this.email = email;
  }

  public String getCelular() {
    return this.celular;
  }

  public void setCelular(String celular) {
    this.celular = celular;
  }

  @Override
  public String toString() {
    return "\nNome: " + getNome() +
      "\nEndereco: " + getEndereco() +
      "\nCidade: " + getCidade() +
      "\nEstado: " + getEstado() +
      "\nEmail: " + getEmail() +
      "\nCelular: " + getCelular();
  }
  
}
