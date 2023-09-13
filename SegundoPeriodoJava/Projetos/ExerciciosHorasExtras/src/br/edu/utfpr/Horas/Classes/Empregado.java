package br.edu.utfpr.Horas.Classes;

public class Empregado {
    private String nome;
    private String CPF;
    private double salario;
    private double horasSemanais;
    private double horasTrabalhadas;

    public Empregado() {
    }

    public Empregado(String nome, String CPF, double salario, double horasSemanais, double horasTrabalhadas) {
        this.nome = nome;
        this.CPF = CPF;
        this.salario = salario;
        this.horasSemanais = horasSemanais;
        this.horasTrabalhadas = horasTrabalhadas;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCPF() {
        return this.CPF;
    }

    public void setCPF(String CPF) {
        this.CPF = CPF;
    }

    public double getSalario() {
        return this.salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public double getHorasSemanais() {
        return this.horasSemanais;
    }

    public void setHorasSemanais(double horasSemanais) {
        this.horasSemanais = horasSemanais;
    }

    public double getHorasTrabalhadas() {
        return this.horasTrabalhadas;
    }

    public void setHorasTrabalhadas(double horasTrabalhadas) {
        this.horasTrabalhadas = horasTrabalhadas;
    }

    @Override
    public String toString() {
        return "Nome = " + getNome() + "\n" +
            "CPF = " + getCPF() + "\n" +
            "Salario = " + getSalario() + "\n" +
            "Horas Semanais = " + getHorasSemanais() + "\n" +
            "Horas Trabalhadas = " + getHorasTrabalhadas() + "\n";
    }

    public double calcularHorasEx(double horasSemanais, double horasTrabalhadas) {
        double horasEx;

        horasEx = horasTrabalhadas - horasSemanais;
        if (horasEx <= 0) {
            horasEx = 0;
        }

        return horasEx;
    }

    public double calcularValorPorHorasEx(double salario, double horasSemanais) {
        double valorHorasEx;

        valorHorasEx = (salario / horasSemanais) * 1.5;

        return valorHorasEx;
    }

    public double calcularValorHorasEx(double valorHorasEx, double horasEx) {
        double valorHorasExTotal;

        valorHorasExTotal = (valorHorasEx * horasEx);

        return valorHorasExTotal;
    }

}