package Classes;

public class Estagiario extends Pessoa {
    private double auxilioBolsa;
    private double auxilioTransporte;

    public Estagiario() {
    }

    public Estagiario(String nome, String CPF, double auxilioBolsa, double auxilioTransporte) {
        super(nome, CPF);
        this.auxilioBolsa = auxilioBolsa;
        this.auxilioTransporte = auxilioTransporte;
    }

    public double getAuxilioBolsa() {
        return this.auxilioBolsa;
    }

    public void setAuxilioBolsa(double auxilioBolsa) {
        this.auxilioBolsa = auxilioBolsa;
    }

    public double getAuxilioTransporte() {
        return this.auxilioTransporte;
    }

    public void setAuxilioTransporte(double auxilioTransporte) {
        this.auxilioTransporte = auxilioTransporte;
    }

    @Override
    public double calcularGastos() {
        return getAuxilioBolsa() + getAuxilioTransporte();
    }

    @Override
    public String toString() {
        return "{" +
        " nome='" + getNome() + "'" +
        ", CPF='" + getCPF() + "'" +
        ", auxilioBolsa='" + getAuxilioBolsa() + "'" +
        ", auxilioTransporte='" + getAuxilioTransporte() + "'" +
        "}";
    }
}
