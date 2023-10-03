package br.edu.utfpr.AAC;

public abstract class Pessoa {
    private String nome;
    private String telefone;
    private Endereço endereco;

    public Pessoa() {
    }

    public Pessoa(String nome, String telefone, Endereço endereco) {
        this.nome = nome;
        this.telefone = telefone;
        this.endereco = endereco;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getTelefone() {
        return this.telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public Endereço getEndereco() {
        return this.endereco;
    }

    public void setEndereco(Endereço endereco) {
        this.endereco = endereco;
    }

    public String listEndereco() {
        return this.endereco.getRua() + 
        ", " + this.endereco.getNumero() +
        ", " + this.endereco.getBairro() +
        ", " + this.endereco.getCidade();
    }

}
