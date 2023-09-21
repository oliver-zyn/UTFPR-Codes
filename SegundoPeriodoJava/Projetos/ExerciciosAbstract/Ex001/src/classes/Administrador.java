package classes;

public class Administrador extends Empregado{
    private float ajudaDeCusto;

    public Administrador() {
    }

    public Administrador(String nome, String endereço, String telefone, float salarioBase, int codigoSetor, float ajudaDeCusto) {
        super(nome, endereço, telefone, salarioBase, codigoSetor);
        this.ajudaDeCusto = ajudaDeCusto;
    }

    public float getAjudaDeCusto() {
        return this.ajudaDeCusto;
    }

    public void setAjudaDeCusto(float ajudaDeCusto) {
        this.ajudaDeCusto = ajudaDeCusto;
    }

    @Override
    public float calcularSalarioTotal() {
        return getSalarioBase() + getAjudaDeCusto();
    }

    @Override
    public String toString() {
        return "{" +
        "Nome='" + getNome() + "'" +
        ", Endereço='" + getEndereço() + "'" +
        ", Telefone='" + getTelefone() + "'" +
        ", Salario Base='" + getSalarioBase() + "'" +
        ", Codigo Setor='" + getCodigoSetor() + "'" +
        ", Ajuda De Custo='" + getAjudaDeCusto() + "'" +
        "}";
    }
    
}
