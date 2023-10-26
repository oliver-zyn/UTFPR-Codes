package Classes;

public class ClientePessoaJuridica extends Pessoa {
    private String cnpj;

    public ClientePessoaJuridica() {
    }

    public ClientePessoaJuridica(String nome, String cnpj) {
        super(nome);
        this.cnpj = cnpj;
    }

    public String getCnpj() {
        return this.cnpj;
    }

    public void setCnpj(String cnpj) {
        this.cnpj = cnpj;
    }

    @Override
    public double valorDesconto(double valorCompra) {
        double valorDesconto = 0;
        if (valorCompra > 200) {
            valorDesconto = 0.12;
        } else {
            valorDesconto = 0.07;
        }

        return valorDesconto;
    }

    @Override
    public String toString() {
        return "Cliente Pessoa Jurídica: " + getNome() + " (CNPJ: " + getCnpj() + ")";
    }
    
}