package br.edu.utfpr;

public class Empresa {
  private String nome;
  private Grupo[] grupos;
  private int numGrupos;

  public Empresa() {
  }

  public Empresa(String nome) {
    this.nome = nome;
    this.grupos = new Grupo[50];
    this.numGrupos = 0;
  }

  public String getNome() {
    return this.nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public Grupo[] getGrupos() {
    return this.grupos;
  }

  public void incluirGrupo(Grupo grupo) {
    if (numGrupos < grupos.length) {
      grupos[numGrupos++] = grupo;
    } else {
      System.out.println("Limite máximo de grupos atingido!");
    }
  }

  public String produtosEstoqueMinimo() {
    String produtosMsg = "";
    for (Grupo grupo : this.getGrupos()) {
      if (grupo != null) {
        for (Produto produto : grupo.getProdutos()) {
          if (produto != null && produto.getStatus() == StatusProduto.MINIMO) {
            produtosMsg += " - " + produto.getNome() + "\n";
          }
        }
      }

    }

    return produtosMsg;
  }

  public void mostrarDadosEmpresa() {
    System.out.println("========== DADOS EMPRESA ==========");
    System.out.println("Nome da Empresa: " + getNome());
    System.out.println("Grupos: ");
    for (Grupo grupo : this.getGrupos()) {
      if (grupo != null) {
        System.out.println(" - " + grupo.getNome());
      }
    }
    System.out.println("Produtos com estoque minimo: ");
    System.out.println(produtosEstoqueMinimo());
  }
}
