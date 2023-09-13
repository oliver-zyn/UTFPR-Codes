package br.edu.utfpr.Aluno.Classe;

public class pessoa {
    
    private String nome;
    private int idade;

    public pessoa() {
    }

    public pessoa(String nome, int idade) {
        this.nome = nome;
        this.idade = idade;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return this.idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    @Override
    public String toString() {
        return "Nome da pessoa: " + getNome() + "\n" +
            "Idade da pessoa: " + getIdade() + "\n";
    }
}