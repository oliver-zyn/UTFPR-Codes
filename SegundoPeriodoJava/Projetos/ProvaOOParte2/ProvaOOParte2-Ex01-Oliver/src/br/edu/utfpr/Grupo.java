package br.edu.utfpr;

public class Grupo {
  private String nome;
  private String tipo;
  private Produto[] produtos;
  private int numProdutos; 

  public Grupo() {
  }

  public Grupo(String nome, String tipo) {
    this.nome = nome;
    this.tipo = tipo;
    this.produtos = new Produto[50];
    this.numProdutos = 0;
  }

  public String getNome() {
    return this.nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getTipo() {
    return this.tipo;
  }

  public void setTipo(String tipo) {
    this.tipo = tipo;
  }

  public Produto[] getProdutos() {
    return this.produtos;
  }

  public void incluirProduto(Produto produto) {
    if (numProdutos < produtos.length) {
        produtos[numProdutos++] = produto;
    } else {
        System.out.println("Limite máximo de produtos atingido!");
    }
  }

  public double totalPrecosCusto() {
    double total = 0;
    for (Produto produto : this.getProdutos()) {
      if (produto != null) {
        total += produto.getPrecoCusto() * produto.getQtdEstoque();
      }
    }

    return total;
  }

  public void mostrarDadosGrupo() {
    System.out.println("========== DADOS GRUPO ==========");
    System.out.println("Nome do Grupo: " + getNome());
    System.out.println("Tipo do Grupo: " + getTipo());
    System.out.println("Produtos: ");
    for (Produto produto : this.getProdutos()) {
      if (produto != null) {
        System.out.println("  - " + produto.getNome());
      }
    }
    System.out.println("Preco total de custo: R$" + totalPrecosCusto());
  }
}
