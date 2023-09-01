package br.edu.utfpr.aula3108;

public class Filme {
    private int id;
    private String nome;
    private String genero;
    private int duracao;
    private String atores;
    private double valorIngresso;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getGenero() {
        return genero;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public int getDuracao() {
        return duracao;
    }

    public void setDuracao(int duracao) {
        this.duracao = duracao;
    }

    public String getAtores() {
        return atores;
    }

    public void setAtores(String atores) {
        this.atores = atores;
    }

    public double getValorIngresso() {
        return valorIngresso;
    }

    public void setValorIngresso(double valorIngresso) {
        this.valorIngresso = valorIngresso;
    }

    public Filme() {
        this.id = 1;
        this.nome = "Era do gay";
        this.genero = "18+";
        this.duracao = 130;
        this.atores = "Leonardo de Caprio" + "Da Vinci";
        this.valorIngresso = 0.00;
    }

    public Filme(int id, String nome, String genero, int duracao, String atores, double valorIngresso) {
        setId(id); setNome(nome); setGenero(genero);
        setDuracao(duracao); setAtores(atores); setValorIngresso(valorIngresso);
    }

    @Override
    public String toString() {
        return "{" +
            " id='" + getId() + "'" +
            ", nome='" + getNome() + "'" +
            ", genero='" + getGenero() + "'" +
            ", duracao='" + getDuracao() + "'" +
            ", atores='" + getAtores() + "'" +
            ", valorIngresso='" + getValorIngresso() + "'" +
            "}";
    }

}