package ClassesPolimorfismo;

public class Estagiario extends Pessoa {
    private double auxilioBolsa;
    private double auxilioTransporte;
    private double auxilioTotal;

    public Estagiario() {
    }

    public Estagiario(String nome, double auxilioBolsa, double auxilioTransporte) {
        super(nome);
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
    public void calcularGastos() {
        this.auxilioTotal = getAuxilioBolsa() + getAuxilioTransporte();
    }

    @Override
    public double getGastos() {
        return this.auxilioTotal;
    }

    @Override
    public String toString() {
        return "Estagiario: " + 
        "\n Nome: " + getNome() +
        "\n AuxilioBolsa: " + getAuxilioBolsa() +
        "\n AuxilioTransporte: " + getAuxilioTransporte() +
        "\n Salario total: " + getGastos();
    }
}
