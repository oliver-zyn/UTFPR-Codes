package br.edu.utfpr;

public class PessoaFisica extends Contribuinte {
  private String cpf;
  private int numDependentes;

  public PessoaFisica() {
  }

  public PessoaFisica(String nome, double rendaBruta, String telefone, String email, String cpf, int numDependentes) {
    super(nome, rendaBruta, telefone, email);
    this.cpf = cpf;
    this.numDependentes = numDependentes;
  }

  public String getCpf() {
    return this.cpf;
  }

  public void setCpf(String cnpj) {
    this.cpf = cnpj;
  }

  public int getNumDependentes() {
    return this.numDependentes;
  }

  public void setNumDependentes(int numDependentes) {
    this.numDependentes = numDependentes;
  }

  public double calculaImposto() {
    if (getRendaBruta() <= 2112.00) {
        return 0;
    } else if (getRendaBruta() <= 2826.65) {
        return (getRendaBruta() * 0.075) - 158.40;
    } else if (getRendaBruta() <= 3751.05) {
        return (getRendaBruta() * 0.15) - 379.40;
    } else if (getRendaBruta() <= 4664.68) {
        return (getRendaBruta() * 0.225) - 651.73;
    } else {
        return (getRendaBruta() * 0.275) - 884.96;
    }
  } 

  @Override
  public String toString() {
    return "\nNome: " + getNome() +
      "\nRenda bruta: " + getRendaBruta() +
      "\nTelefone: " + getTelefone() +
      "\nEmail: " + getEmail() +
      "\nCNPJ: " + getCpf();
  }
}
