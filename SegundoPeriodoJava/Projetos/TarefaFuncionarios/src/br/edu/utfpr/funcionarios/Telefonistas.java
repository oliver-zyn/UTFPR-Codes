package br.edu.utfpr.funcionarios;

import java.text.DecimalFormat;

public class Telefonistas extends Funcionarios{
    private String num_Ramal;
    private double bonificacao = 0.05;

    public Telefonistas() {
    }

    public Telefonistas(String nome, double salario, String num_Ramal) {
        super(nome, salario);
        this.num_Ramal = num_Ramal;
    }

    public String getNum_Ramal() {
        return this.num_Ramal;
    }

    public void setNum_Ramal(String num_Ramal) {
        this.num_Ramal = num_Ramal;
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
        "Número de Ramal = " + getNum_Ramal() + "\n" +
        "Bonificacao = R$ " + df.format((getBonificacao()) * getSalario()) + "\n";
    }


}
