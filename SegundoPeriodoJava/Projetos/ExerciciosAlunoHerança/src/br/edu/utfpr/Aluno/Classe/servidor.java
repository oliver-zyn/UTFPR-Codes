package br.edu.utfpr.Aluno.Classe;

public class servidor extends pessoa{
    
    private int SIAPE;

    public servidor() {
    }

    public servidor(String nome, int idade, int SIAPE) {
        super(nome, idade);
        this.SIAPE = SIAPE;
    }

    public int getSIAPE() {
        return this.SIAPE;
    }

    public void setSIAPE(int SIAPE) {
        this.SIAPE = SIAPE;
    }

    @Override
    public String toString() {
        return "\nNome do Servidor: " + getNome() + "\n" +
            "Idade do Servidor: " + getIdade() + "\n" +
            "SIAPE: " + getSIAPE() + "\n";
    }
}
