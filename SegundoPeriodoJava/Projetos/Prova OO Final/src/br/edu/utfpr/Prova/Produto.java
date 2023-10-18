package br.edu.utfpr.Prova;

public class Produto {
    private String nome;
    private double precoCusto;
    private double precoVenda;
    private int quantidadeEstoque;
    private String status;

    public Produto() {
    }

    public Produto(String nome, double precoCusto, double precoVenda, int quantidadeEstoque) {
        this.nome = nome;
        this.precoCusto = precoCusto;
        this.precoVenda = precoVenda;
        this.quantidadeEstoque = quantidadeEstoque;
        this.status = "Indefinido";
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getPrecoCusto() {
        return this.precoCusto;
    }

    public void setPrecoCusto(double precoCusto) {
        this.precoCusto = precoCusto;
    }

    public double getPrecoVenda() {
        return this.precoVenda;
    }

    public void setPrecoVenda(double precoVenda) {
        this.precoVenda = precoVenda;
    }

    public int getQuantidadeEstoque() {
        return this.quantidadeEstoque;
    }

    public void setQuantidadeEstoque(int quantidadeEstoque) {
        this.quantidadeEstoque = quantidadeEstoque;
    }

    public String getStatus() {
        return this.status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public void definirStatus() {
        if (getQuantidadeEstoque() >= 100) {
            setStatus("Em excesso");
        } else if (getQuantidadeEstoque() >= 20 && getQuantidadeEstoque() < 100) {
            setStatus("Normal");
        } else {
            setStatus("Mínimo");
        }
    }

    public void apresentarDadosProduto() {
        definirStatus();
        System.out.println("Nome do Produto: " + getNome());
        System.out.println("Preço de Custo: " + getPrecoCusto());
        System.out.println("Preço de Venda: " + getPrecoVenda());
        System.out.println("Quantidade em Estoque: " + getQuantidadeEstoque());
        System.out.println("Status: " + getStatus());
    }
}
