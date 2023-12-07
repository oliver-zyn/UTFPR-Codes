package br.edu.utfpr.classes;

public class Aluno {
  private int numero;
  private String nome;

  public Aluno() {
  }

  public Aluno(int numero, String nome) {
    this.numero = numero;
    this.nome = nome;
  }

  public int getNumero() {
    return this.numero;
  }

  public void setNumero(int numero) {
    this.numero = numero;
  }

  public String getNome() {
    return this.nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  @Override
  public String toString() {
    return "{" +
      " numero='" + getNumero() + "'" +
      ", nome='" + getNome() + "'" +
      "}";
  }
}
