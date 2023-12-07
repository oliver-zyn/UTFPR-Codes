package br.edu.utfpr;

public abstract class Contribuinte {
  private String nome;
  private double rendaBruta;
  private String telefone;
  private String email;

  public Contribuinte() {
  }

  public Contribuinte(String nome, double rendaBruta, String telefone, String email) {
    this.nome = nome;
    this.rendaBruta = rendaBruta;
    this.telefone = telefone;
    this.email = email;
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

  public void setRendaBruta(double rendaBruta) {
    this.rendaBruta = rendaBruta;
  }

  public String getTelefone() {
    return this.telefone;
  }

  public void setTelefone(String telefone) {
    this.telefone = telefone;
  }

  public String getEmail() {
    return this.email;
  }

  public void setEmail(String email) {
    this.email = email;
  }

  public abstract double calculaImposto();

  @Override
  public abstract String toString();
  
}
