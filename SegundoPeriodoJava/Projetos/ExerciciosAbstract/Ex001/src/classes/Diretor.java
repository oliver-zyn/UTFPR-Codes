package classes;

public class Diretor extends Empregado{
    private float gratificação;

    public Diretor() {
    }

    public Diretor(String nome, String endereço, String telefone, float salarioBase, int codigoSetor, float gratificação) {
        super(nome, endereço, telefone, salarioBase, codigoSetor);
        this.gratificação = gratificação;
    }

    public float getGratificação() {
        return this.gratificação;
    }

    public void setGratificação(float gratificação) {
        this.gratificação = gratificação;
    }

    @Override
    public float calcularSalarioTotal() {
        return getGratificação() + getSalarioBase();
    }

    @Override
    public String toString() {
        return "{" +
        "Nome='" + getNome() + "'" +
        ", Endereço='" + getEndereço() + "'" +
        ", Telefone='" + getTelefone() + "'" +
        ", Salario Base='" + getSalarioBase() + "'" +
        ", Codigo Setor='" + getCodigoSetor() + "'" +
        ", Gratificação='" + getGratificação() + "'" +
        "}";
    }
    
}
