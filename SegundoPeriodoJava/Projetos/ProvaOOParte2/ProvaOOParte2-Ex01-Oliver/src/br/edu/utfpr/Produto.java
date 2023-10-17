package br.edu.utfpr;

public class Produto {
  private String nome;
  private double precoCusto;
  private double precoVenda;
  private int qtdEstoque;
  private StatusProduto status;

  public Produto() {
  }

  public Produto(String nomeProduto, double precoCusto, double precoVenda, int qtdEstoque) {
    this.nome = nomeProduto;
    this.precoCusto = precoCusto;
    this.precoVenda = precoVenda;
    this.qtdEstoque = qtdEstoque;
    this.status = gerarStatusProduto();
  }

  public String getNome() {
    return this.nome;
  }

  public void setNome(String nomeProduto) {
    this.nome = nomeProduto;
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

  public int getQtdEstoque() {
    return this.qtdEstoque;
  }

  public void setQtdEstoque(int qtdEstoque) {
    this.qtdEstoque = qtdEstoque;
    setStatus(gerarStatusProduto());
  }

  public StatusProduto getStatus() {
    return this.status;
  }

  public void setStatus(StatusProduto status) {
    this.status = status;
  }

  public StatusProduto gerarStatusProduto() {
    int qtdEstoque = getQtdEstoque();
    StatusProduto status;

    if (qtdEstoque >= 100) {
      status = StatusProduto.EXCESSO;
    } else if (qtdEstoque >= 20) {
      status = StatusProduto.NORMAL;
    } else {
      status = StatusProduto.MINIMO;
    }

    return status;
  }

  public void mostrarDadosProduto() {
    System.out.println("========== DADOS PRODUTO ==========");
    System.out.println("Nome do Produto: " + getNome());
    System.out.println("Preco de Custo: R$" + getPrecoCusto());
    System.out.println("Preco de Venda: R$" + getPrecoVenda());
    System.out.println("Quantidade em Estoque: " + getQtdEstoque());
    System.out.println("Status: " + getStatus());
  }
}
