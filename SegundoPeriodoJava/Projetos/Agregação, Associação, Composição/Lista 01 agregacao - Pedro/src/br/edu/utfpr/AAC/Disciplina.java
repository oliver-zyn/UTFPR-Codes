package br.edu.utfpr.AAC;

public class Disciplina {
    private int codigo;
    private Professor prof; // Agregação
    private String nome;

    public Disciplina() {
    }

    public Disciplina(int codigo, Professor prof, String nome) {
        this.codigo = codigo;
        this.prof = prof;
        this.nome = nome;
    }

    public int getCodigo() {
        return this.codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public Professor getProf() {
        return this.prof;
    }

    public void setProf(Professor prof) {
        this.prof = prof;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String listaProfessor() {
        return this.prof.getNome();
    }

    @Override
    public String toString() {
        return "{" +
            " codigo='" + getCodigo() + "'" +
            "\nprof='" + getProf() + "'" +
            "\nnome='" + getNome() + "'" +
            "}";
    }
}
