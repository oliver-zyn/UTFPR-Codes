package br.edu.utfpr.Escola;

public class Disciplina {
  private int codigo;
  private String nome;
  private Professor professor; //Agregação

  public Disciplina() {
  }

  public Disciplina(int codigo, String nome, Professor professor) {
    this.codigo = codigo;
    this.nome = nome;
    this.professor = professor;
  }

  public int getCodigo() {
    return this.codigo;
  }

  public void setCodigo(int codigo) {
    this.codigo = codigo;
  }

  public String getNome() {
    return this.nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public Professor getProfessor() {
    return this.professor;
  }

  public void setProfessor(Professor professor) {
    this.professor = professor;
  }

  public String getNomeProfessor() {
    return this.professor.getNome();
  }

  @Override
  public String toString() {
    return "Codigo: " + getCodigo() +
          "\nNome: " + getNome() +
          "\nProfessor: " + getProfessor();
  }
}
