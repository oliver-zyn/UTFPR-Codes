package Ex002.br.edu.utfpr.Prova002;

public class PessoaFisica extends Contribuinte {
    private String CPF;
    private int numDependentes;

    public PessoaFisica() {
    }

    public PessoaFisica(String nome, double rendaBruta, String telefone, String Email, String CPF, int numDependentes) {
        super(nome, rendaBruta, telefone, Email);
        this.CPF = CPF;
        this.numDependentes = numDependentes;
    }

    public String getCPF() {
        return this.CPF;
    }

    public void setCPF(String CPF) {
        this.CPF = CPF;
    }

    public int getNumDependentes() {
        return this.numDependentes;
    }

    public void setNumDependentes(int numDependentes) {
        this.numDependentes = numDependentes;
    }

    @Override
    public String toString() {
        return "{" +
        " nome='" + getNome() + "'" +
        ", rendaBruta='" + getRendaBruta() + "'" +
        ", telefone='" + getTelefone() + "'" +
        ", Email='" + getEmail() + "'" +
        " CPF='" + getCPF() + "'" +
        ", numDependentes='" + getNumDependentes() + "'" +
        "}";
    }

    @Override
    public double calculaImposto() {
        double imposto = 0, valorPDependente = 0;

        if (getRendaBruta() <= 2112) {
            valorPDependente = 0;
            imposto = 0;
        } else if (getRendaBruta() > 2112 && getRendaBruta() <= 2826.25) {
            valorPDependente = 158.4;
            imposto = 12 * (getRendaBruta() * 0.075);
        } else if (getRendaBruta() > 2826.25 && getRendaBruta() <= 3751.05) {
            valorPDependente = 370.40;
            imposto = 12 * (getRendaBruta() * 0.15);
        } else if (getRendaBruta() > 3751.05 && getRendaBruta() <= 4664.68) {
            valorPDependente = 651.73;
            imposto = 12 * (getRendaBruta() * 0.225);
        } else if (getRendaBruta() > 4664.68) {
            valorPDependente = 884.96;
            imposto = 12 * (getRendaBruta() * 0.275);
        }

        if (getNumDependentes() == 0) {
            return imposto;
        } else if (getNumDependentes() == 1) {
            return imposto + valorPDependente;
        } else if (getNumDependentes() == 2) {
            return imposto + (valorPDependente * 2);
        } else if (getNumDependentes() == 3) {
            return imposto + (valorPDependente * 3);
        } else {
            return imposto + (valorPDependente * 4);
        }
    }
}
