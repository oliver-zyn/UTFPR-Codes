package Ex002.br.edu.utfpr.Prova002;

public abstract class Contribuinte {
    private String nome;
    private double rendaBruta;
    private String telefone;
    private String Email;

    public Contribuinte() {
    }

    public Contribuinte(String nome, double rendaBruta, String telefone, String Email) {
        this.nome = nome;
        this.rendaBruta = rendaBruta;
        this.telefone = telefone;
        this.Email = Email;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getRendaBruta() {
        return this.rendaBruta;
    }

    public void setRendaBruta(float rendaBruta) {
        this.rendaBruta = rendaBruta;
    }

    public String getTelefone() {
        return this.telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public String getEmail() {
        return this.Email;
    }

    public void setEmail(String Email) {
        this.Email = Email;
    }

    public abstract double calculaImposto();
}
