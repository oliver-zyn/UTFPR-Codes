package br.edu.utfpr.Aluno.Classe;

public class aluno extends pessoa {
    
    private int matricula;

    public aluno() {
    }

    public aluno(String nome, int idade, int matricula) {
        super(nome, idade);
        this.matricula = matricula;
    }

    public int getMatricula() {
        return this.matricula;
    }

    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    @Override
    public String toString() {
        return "\nNome do Aluno: " + getNome() + "\n" +
            "Idade do Aluno: " + getIdade() + "\n" +
            "Matricula: " + getMatricula() + "\n";
    }

}
