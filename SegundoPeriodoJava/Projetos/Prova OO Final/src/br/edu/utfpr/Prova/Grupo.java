package br.edu.utfpr.Prova;

public class Grupo extends Produto{
    private String nome;
    private String tipo;
    private Produto[] produtos;
    private int tamanho;

    public Grupo() {
    }

    public Grupo(String nome, String tipo) {
        this.nome = nome;
        this.tipo = tipo;
        this.produtos = new Produto[3];
        this.tamanho = 0;
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

    public int getTamanho() {
        return this.tamanho;
    }

    public void adicionarProduto(Produto produto) {
        if (tamanho < produtos.length) {
            produtos[tamanho] = produto;
            tamanho++;
        } else {
            System.out.println("Capacidade máxima de produtos atingida.");
        }
    }

    public double calcularCusto() {
        double CustoTotal = 0;
        for (int i = 0; i < tamanho; i++) {
            CustoTotal += produtos[i].getPrecoCusto();
        }
        return CustoTotal;
    }

    public void apresentarDadosGrupo() {
        System.out.println("Nome do Grupo: " + getNome());
        System.out.println("Tipo: " + getTipo());
        System.out.println("Produtos no Grupo:");
        System.out.println("--------------------------");
        for (int i = 0; i < getTamanho(); i++) {
            produtos[i].apresentarDadosProduto();
            System.out.println("--------------------------");
        }
        System.out.println("Valor Total de Custo: " + calcularCusto());
    }
}
