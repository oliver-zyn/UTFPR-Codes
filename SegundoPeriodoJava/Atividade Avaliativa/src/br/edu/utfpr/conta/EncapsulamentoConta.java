package br.edu.utfpr.conta;

public class EncapsulamentoConta {
    private long numero;
    private double saldo;

    public EncapsulamentoConta() {
        this.numero = 10;
        this.saldo = 5000;
    }

    public EncapsulamentoConta(long numero, double saldo) {
        this.numero = numero;
        this.saldo = saldo;
    }

    public double getNumero() {
        return numero;
    }

    public void setNumero(long numero) {
        this.numero = numero;
    }

    public double getSaldo() {
        return numero;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public void deposito(double deposito) {
        setSaldo(saldo += deposito);
    }

    public void saque(double saque) {
        if (saque <= saldo) {
            setSaldo(saldo -= saque);
        } else {
            System.out.println("Saldo insuficiente.");
        }
    }

    public String toString() {
        String saldoS;
        saldoS = "Número da conta: " + numero + ", Saldo: R$ " + saldo;
        return saldoS;
    }
}