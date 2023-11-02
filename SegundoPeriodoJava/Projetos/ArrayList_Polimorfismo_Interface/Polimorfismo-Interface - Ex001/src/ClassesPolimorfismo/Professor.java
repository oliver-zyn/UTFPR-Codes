package ClassesPolimorfismo;

public class Professor extends Servidor {

    public Professor() {
    }

    public Professor(String nome, String CPF, double salario, double adicionalTitulacao) {
        super(nome, CPF, salario, adicionalTitulacao);
    }

    @Override
    public double calcularGastos() {
        return getAdicionalTitulacao() + getSalario();
    }
    
    @Override
    public String toString() {
        return "Professor: " + 
        "\nNome: " + getNome() +
        "\nCPF: " + getCPF() + 
        "\nSalário: " + getSalario() +
        "\nAdicional Por Titulação: " + getAdicionalTitulacao() +
        "\nSalário Total: " + calcularGastos(); 
    }

}
