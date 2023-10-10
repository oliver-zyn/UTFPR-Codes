package br.edu.utfpr;

public class PessoaJuridica extends Contribuinte{
  private String cnpj;
  private String tipoEmpresa;

  public PessoaJuridica() {
  }

  public PessoaJuridica(String nome, double rendaBruta, String telefone, String email, String cnpj, String tipoEmpresa) {
    super(nome, rendaBruta, telefone, email);
    this.cnpj = cnpj;
    this.tipoEmpresa = tipoEmpresa;
  }

  public String getCnpj() {
    return this.cnpj;
  }

  public void setCnpj(String cnpj) {
    this.cnpj = cnpj;
  }

  public String getTipoEmpresa() {
    return this.tipoEmpresa;
  }

  public void setTipoEmpresa(String tipoEmpresa) {
    this.tipoEmpresa = tipoEmpresa;
  }

  public double calculaImposto() {
    return (getRendaBruta() * 0.10);
  } 

  @Override
  public String toString() {
    return "\nNome: " + getNome() +
      "\nRenda bruta: " + getRendaBruta() +
      "\nTelefone: " + getTelefone() +
      "\nEmail: " + getEmail() +
      "\nCNPJ: " + getCnpj();
  }
  
}
