package Classes;

public abstract class Pessoa {
    private String nome;
    private String CPF;

    public Pessoa() {
    }

    public Pessoa(String nome, String CPF) {
        this.nome = nome;
        this.CPF = CPF;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCPF() {
        return this.CPF;
    }

    public void setCPF(String CPF) {
        this.CPF = CPF;
    }

    public abstract double calcularGastos();

    @Override
    public String toString() {
        return "{" +
            " nome='" + getNome() + "'" +
            ", CPF='" + getCPF() + "'" +
            "}";
    }

}
