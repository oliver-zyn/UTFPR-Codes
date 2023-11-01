package Classes;

public class Coordenador extends FuncaoGratificada {

    public Coordenador() {
    }
    
    public Coordenador(String nome, String CPF, double salario, double adicionalTitulacao, double gratificacao) {
        super(nome, CPF, salario, adicionalTitulacao, gratificacao);
    }

    @Override
    public double calcularGastos() {
        return getAdicionalTitulacao() + getGratificacao() + getSalario();
    }

}
