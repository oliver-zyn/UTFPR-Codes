package br.edu.utfpr.classes;

public class Nota {
    private int numeroAluno;
    private double nota;

    public Nota() {
    }

    public Nota(int numeroAluno, double nota) {
        this.numeroAluno = numeroAluno;
        this.nota = nota;
    }

    public int getNumeroAluno() {
        return this.numeroAluno;
    }

    public void setNumeroAluno(int ID_Aluno) {
        this.numeroAluno = ID_Aluno;
    }

    public double getNota() {
        return this.nota;
    }

    public void setNota(double nota) {
        this.nota = nota;
    }

    @Override
    public String toString() {
        return "{" +
            " numeroAluno='" + getNumeroAluno() + "'" +
            ", nota='" + getNota() + "'" +
            "}";
    }

}