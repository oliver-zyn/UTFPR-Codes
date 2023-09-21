package br.edu.utfpr.funcionarios;

import java.text.DecimalFormat;

public class Gerentes extends Funcionarios {
    private String login;
    private String senha;
    private double bonificacao = 0.1;

    public Gerentes() {
    }

    public Gerentes(String nome, double salario, String login, String senha) {
        super(nome, salario);
        this.login = login;
        this.senha = senha;
    }

    public String getLogin() {
        return this.login;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public String getSenha() {
        return this.senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public double getBonificacao() {
        return this.bonificacao;
    }

    public void setBonificacao(double bonificacao) {
        this.bonificacao = bonificacao;
    }

    @Override
    public String toString() {
        DecimalFormat df = new DecimalFormat("#.00");
        return 
        "Nome = " + getNome() + "\n" +
        "Salário = R$ " + df.format(getSalario()) + "\n" +
        "Login = " + getLogin() + "\n" +
        "Senha = " + getSenha() + "\n" +
        "Bonificacao = R$ " + df.format((getBonificacao() * getSalario())) + "\n";
    }

}
