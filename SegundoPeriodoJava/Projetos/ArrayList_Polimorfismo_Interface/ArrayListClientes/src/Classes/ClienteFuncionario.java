package Classes;

public class ClienteFuncionario extends Pessoa {
    private String CTPS;

    public ClienteFuncionario() {
    }

    public ClienteFuncionario(String nome, String CTPS) {
        super(nome);
        this.CTPS = CTPS;
    }

    public String getCTPS() {
        return this.CTPS;
    }

    public void setCTPS(String CTPS) {
        this.CTPS = CTPS;
    }

    @Override
    public double valorDesconto(double valorCompra) {
        double desconto = 0;

        if (valorCompra > 200) {
            desconto = valorCompra * 0.15;
        } else {
            desconto = valorCompra * 0.1;
        }
        
        return desconto;
    }

    @Override
    public String toString() {
        return "Cliente Funcionário: " + getNome() + " (CTPS: " + getCTPS() + ")";
    }
}
