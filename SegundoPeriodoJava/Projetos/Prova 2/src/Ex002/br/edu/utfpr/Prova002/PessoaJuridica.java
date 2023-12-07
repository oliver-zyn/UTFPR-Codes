package Ex002.br.edu.utfpr.Prova002;

public class PessoaJuridica extends Contribuinte {
    private String CNPJ;
    private String tipo;

    public PessoaJuridica() {
    }

    public PessoaJuridica(String nome, double rendaBruta, String telefone, String Email, String CNPJ, String tipo) {
        super(nome, rendaBruta, telefone, Email);
        this.CNPJ = CNPJ;
        this.tipo = tipo;
    }

    public String getCNPJ() {
        return this.CNPJ;
    }

    public void setCNPJ(String CNPJ) {
        this.CNPJ = CNPJ;
    }

    public String getTipo() {
        return this.tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    @Override
    public String toString() {
        return "{" +
        " nome='" + getNome() + "'" +
        ", rendaBruta='" + getRendaBruta() + "'" +
        ", telefone='" + getTelefone() + "'" +
        ", Email='" + getEmail() + "'" +
        " CNPJ='" + getCNPJ() + "'" +
        ", tipo='" + getTipo() + "'" +
        "}";
    }

    @Override
    public double calculaImposto() {
        return (0.10 * getRendaBruta());
    }

}
