package ClassesPolimorfismo;

public class Luz implements Gastos {
    private double baseCalculo;
    private double valorICMS;
    private double valorTotal;

    public Luz() {
    }

    public Luz(double baseCalculo, double valorICMS) {
        this.baseCalculo = baseCalculo;
        this.valorICMS = valorICMS;
    }

    public double getBaseCalculo() {
        return this.baseCalculo;
    }

    public void setBaseCalculo(double baseCalculo) {
        this.baseCalculo = baseCalculo;
    }

    public double getValorICMS() {
        return this.valorICMS;
    }

    public void setValorICMS(double valorICMS) {
        this.valorICMS = valorICMS;
    }

    @Override
    public void calcularGastos() {
        this.valorTotal = getValorICMS() + getBaseCalculo();
    } 

    public double getGastos() {
        return this.valorTotal;
    }

    @Override
    public String toString() {
        return "Luz: " +
            "\nBase do Calculo: " + getBaseCalculo() +
            "\nValor do ICMS " + getValorICMS() +
            "\nValorTotal " + getGastos();
    }
}
