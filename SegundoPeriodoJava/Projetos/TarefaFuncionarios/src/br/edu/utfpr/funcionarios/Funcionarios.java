package br.edu.utfpr.funcionarios;

import java.text.DecimalFormat;

public class Funcionarios {
    private String nome;
    private double salario;

    public Funcionarios() {
    }

    public Funcionarios(String nome, double salario) {
        this.nome = nome;
        this.salario = salario;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getSalario() {
        return this.salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    @Override
    public String toString() {
        DecimalFormat df = new DecimalFormat("#.00");
        return "Nome = " + getNome() + "\n" +
        "Salário = R$ " + df.format(getSalario()) + "\n";
    }
}

