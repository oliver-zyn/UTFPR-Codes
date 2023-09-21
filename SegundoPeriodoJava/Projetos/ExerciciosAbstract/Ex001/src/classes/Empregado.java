package classes;

public abstract class Empregado extends Pessoa{
    private float salarioBase;
    private int codigoSetor;

    public Empregado() {
    }

    public Empregado(String nome, String endereço, String telefone, float salarioBase, int codigoSetor) {
        super(nome, endereço, telefone);
        this.salarioBase = salarioBase;
        this.codigoSetor = codigoSetor;
    }

    public float getSalarioBase() {
        return this.salarioBase;
    }

    public void setSalarioBase(float salarioBase) {
        this.salarioBase = salarioBase;
    }

    public int getCodigoSetor() {
        return this.codigoSetor;
    }

    public void setCodigoSetor(int codigoSetor) {
        this.codigoSetor = codigoSetor;
    }

    public abstract float calcularSalarioTotal();


    @Override
    public String toString() {
        return "{" +
        " nome='" + getNome() + "'" +
        ", endereço='" + getEndereço() + "'" +
        ", telefone='" + getTelefone() + "'" +
        " salarioBase='" + getSalarioBase() + "'" +
        ", codigoSetor='" + getCodigoSetor() + "'" +
        "}";
    }

}
