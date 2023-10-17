package br.edu.utfpr;

public enum StatusProduto {
    MINIMO("mínimo"),
    NORMAL("normal"),
    EXCESSO("excesso");

    private String descricao;

    StatusProduto(String descricao) {
        this.descricao = descricao;
    }

    public String getDescricao() {
        return descricao;
    }
}