package br.edu.utfpr.Escola;

public class Aluno extends Pessoa {
  private int matricula;
  private int idade;

  public Aluno() {
  }

  public Aluno(String nome, String telefone, Endereco endereco, int matricula, int idade) {
    super(nome, telefone, endereco);
    this.matricula = matricula;
    this.idade = idade;
  }

  public int getMatricula() {
    return this.matricula;
  }

  public void setIdentificacao(int matricula) {
    this.matricula = matricula;
  }

  public int getIdade() {
    return this.idade;
  }

  public void setIdade(int idade) {
    this.idade = idade;
  }

  @Override
  public String toString() {
    return "Nome: " + getNome() +
          "\nTelefone: " + getTelefone() +
          "\nEndereço: " + getEndereco() +
          "\nIdade: " + getIdade() +
          "\nMatrícula: " + getMatricula();
  }
}
