package classes;

public class Fornecedor extends Pessoa{
    private float ValorCredito;
    private float ValorDivida;

    public Fornecedor() {
    }

    public Fornecedor(String nome, String endereço, String telefone, float ValorCredito, float ValorDivida) {
        super(nome, endereço, telefone);
        this.ValorCredito = ValorCredito;
        this.ValorDivida = ValorDivida;
    }

    public float getValorCredito() {
        return this.ValorCredito;
    }

    public void setValorCredito(float ValorCredito) {
        this.ValorCredito = ValorCredito;
    }

    public float getValorDivida() {
        return this.ValorDivida;
    }

    public void setValorDivida(float ValorDivida) {
        this.ValorDivida = ValorDivida;
    }

    public float calcularSaldo(float ValorCredito, float ValorDivida) {
        float saldo = 0;
        if (ValorDivida >= ValorCredito) {
            saldo = 0;
        } else {
            saldo = ValorCredito - ValorDivida;
        }
        return saldo;
    }

    @Override
    public String toString() {
        return "{" +
        " nome='" + getNome() + "'" +
        ", endereço='" + getEndereço() + "'" +
        ", telefone='" + getTelefone() + "'" + 
        " ValorCredito='" + getValorCredito() + "'" +
        ", ValorDivida='" + getValorDivida() + "'" +
        "}";
    }
}
