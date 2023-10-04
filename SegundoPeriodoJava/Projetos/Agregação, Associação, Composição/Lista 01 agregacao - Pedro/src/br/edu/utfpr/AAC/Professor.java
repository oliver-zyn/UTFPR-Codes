package br.edu.utfpr.AAC;

public class Professor extends Pessoa{ // Herança
    private String ID;

    public Professor() {
    }

    public Professor(String name, String telefone, Endereço endereco, String ID) {
        super(name, telefone, endereco);
        this.ID = ID;
    }

    public String getID() {
        return this.ID;
    }

    public void setID(String ID) {
        this.ID = ID;
    }

    @Override
    public String toString() {
        return 
        "ID = " + getID() +
        "\nNome = " + getNome() +
        "\nTelefone = " + getTelefone() +
        "\nEndereço = " + getEndereco();
    }

}
