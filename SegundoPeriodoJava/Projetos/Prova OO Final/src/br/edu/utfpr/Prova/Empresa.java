package br.edu.utfpr.Prova;

public class Empresa extends Grupo{
    private String nome;
    private Grupo[] grupos;
    private int tamanho;

    public Empresa() {
    }

    public Empresa(String nome) {
        this.nome = nome;
        this.grupos = new Grupo[3];
        this.tamanho = 0;
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

    public int getTamanho() {
        return this.tamanho;
    }

    public void setTamanho(int tamanho) {
        this.tamanho = tamanho;
    }

    public void adicionarGrupo(Grupo grupo) {
        if (tamanho < grupos.length) {
            grupos[tamanho] = grupo;
            tamanho++;
        } else {
            System.out.println("Capacidade máxima de grupo atingida.");
        }
    }

    public void estoqueMinimo() {
        for (int i = 0; i < grupos.length; i++) {
            for (int j = 0; j < grupos[i].getProdutos().length; j++) {
                if (grupos[i].getProdutos()[j].getStatus().equals("Mínimo")) {
                    grupos[i].getProdutos()[j].apresentarDadosProduto();
                    System.out.println("------------------------");
                }
            }
        }
    }

    public void apresentarDados() {
        System.out.println("Nome da Empresa: " + getNome());
        System.out.println("Grupos da Empresa:");
        System.out.println("--------------------------");
        for (int i = 0; i < getTamanho(); i++) {
            grupos[i].apresentarDadosGrupo();
            System.out.println("--------------------------");
            System.out.println();
        }
    }
    
}
