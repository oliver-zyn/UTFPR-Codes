package Classes;

public class ClientePessoaFisica extends Pessoa {
    private String CPF;

    public ClientePessoaFisica() {
    }

    public ClientePessoaFisica(String nome, String CPF) {
        super(nome);
        this.CPF = CPF;
    }

    public String getCPF() {
        return this.CPF;
    }

    public void setCPF(String CPF) {
        this.CPF = CPF;
    }

    @Override
    public double valorDesconto(double valorCompra) {
        double valorDesconto = 0;
        if (valorCompra > 150) {
            valorDesconto = 0.12;
        } else {
            valorDesconto = 0.8;
        }
        return valorDesconto;
    }

    @Override
    public String toString() {
        return "Cliente Pessoa Física: " + getNome() + " (CPF: " + getCPF() + ")";
    }
}