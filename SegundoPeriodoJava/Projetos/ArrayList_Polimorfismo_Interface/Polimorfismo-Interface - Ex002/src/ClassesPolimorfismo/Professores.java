package ClassesPolimorfismo;

public class Professores extends UniversidadeFuncionarios {

    public Professores() {
    }

    public Professores(String nome, double salario, double adicionalTitulacao) {
        super(nome, salario, adicionalTitulacao);
    }

    @Override
    public void calcularGastos() {
        this.salarioTotal = getAdicionalTitulacao() + getSalario();
    }

    public double getGastos() {
        return this.salarioTotal;
    }
    
    @Override
    public String toString() {
        return "Professor: " + 
        "\nNome: " + getNome() +
        "\nSalário: " + getSalario() +
        "\nAdicional Por Titulação: " + getAdicionalTitulacao() +
        "\nSalário Total: " + getGastos(); 
    }

}
