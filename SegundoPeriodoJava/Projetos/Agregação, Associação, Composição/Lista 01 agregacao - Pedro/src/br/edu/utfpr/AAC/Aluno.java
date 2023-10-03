package br.edu.utfpr.AAC;

public class Aluno extends Pessoa{
    private String numMatricula;
    private int idade;

    public Aluno() {
    }

    public Aluno(String nome, String telefone, Endereço endereco, String numMatricula, int idade) {
        super(nome, telefone, endereco);
        this.numMatricula = numMatricula;
        this.idade = idade;
    }

    public String getNumMatricula() {
        return this.numMatricula;
    }

    public void setNumMatricula(String numMatricula) {
        this.numMatricula = numMatricula;
    }
    
    public int getIdade() {
        return this.idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    @Override
    public String toString() {
        return 
        "Número Matrícula = " + getNumMatricula() +
        "\nNome = " + getNome() +
        "\nTelefone = " + getTelefone() +
        "\nEndereço = " + getEndereco() +
        "\nIdade = " + getIdade();
    }
}
