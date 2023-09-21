package br.edu.utfpr.aula3108;

public class Cliente {
    private int codigo;
    private String nome;
    private String celular;
    private String email;
    private double salario;

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCelular() {
        return celular;
    }

    public void setCelular(String celular) {
        this.celular = celular;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public Cliente() {
        this.codigo = 69;
        this.nome = "Leonardo de Caprio";
        this.celular = "(18) 96969-6969";
        this.email = "Ligma@myball.sss";
        this.salario = 6969;
    }

    public Cliente(int codigo, String nome, String celular, String email, double salario) {
        this.codigo = codigo;
        this.nome = nome;
        this.celular = celular;
        this.email = email;
        this.salario = salario;
    }

    @Override
    public String toString() {
        return "{" +
            " codigo='" + getCodigo() + "'" +
            ", nome='" + getNome() + "'" +
            ", celular='" + getCelular() + "'" +
            ", email='" + getEmail() + "'" +
            ", salario='" + getSalario() + "'" +
            "}";
    }


}
