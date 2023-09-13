package br.edu.utfpr.aula3108;

public class Ingresso {
    private int numero;
    private double valor;
    private String data;
    private String hora;
    private String poltrona;
    private int sessao;
    private Cliente cliente;
    
    public Ingresso(int numero, double valor, String data, String hora, String poltrona, int sessao, Cliente cliente) {
        this.numero = numero;
        this.valor = valor;
        this.data = data;
        this.hora = hora;
        this.poltrona = poltrona;
        this.sessao = sessao;
        this.cliente = cliente;
    }

    public Ingresso() {
    }
    
    public int getNumero() {
        return numero;
    }
    public void setNumero(int numero) {
        this.numero = numero;
    }
    public double getValor() {
        return valor;
    }
    public void setValor(double valor) {
        this.valor = valor;
    }
    public String getData() {
        return data;
    }
    public void setData(String data) {
        this.data = data;
    }
    public String getHora() {
        return hora;
    }
    public void setHora(String hora) {
        this.hora = hora;
    }
    public String getPoltrona() {
        return poltrona;
    }
    public void setPoltrona(String poltrona) {
        this.poltrona = poltrona;
    }
    public int getSessao() {
        return sessao;
    }
    public void setSessao(int sessao) {
        this.sessao = sessao;
    }
    public Cliente getCliente() {
        return cliente;
    }
    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    @Override
    public String toString() {
        return "{" +
            " numero='" + getNumero() + "'" +
            ", valor='" + getValor() + "'" +
            ", data='" + getData() + "'" +
            ", hora='" + getHora() + "'" +
            ", poltrona='" + getPoltrona() + "'" +
            ", sessao='" + getSessao() + "'" +
            ", cliente='" + getCliente() + "'" +
            "}";
    }

}
