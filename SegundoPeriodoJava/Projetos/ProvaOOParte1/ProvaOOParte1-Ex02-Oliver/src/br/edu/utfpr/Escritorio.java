package br.edu.utfpr;

public class Escritorio {
  private Contribuinte[] contribuintes;
  private int numContribuintes; 

  public Escritorio() {
      this.contribuintes = new Contribuinte[50];
      this.numContribuintes = 0;
  }

  public Contribuinte[] getContribuintes() {
    return this.contribuintes;
  }

  public void incluirContribuinte(Contribuinte contribuinte) {
    if (numContribuintes < contribuintes.length) {
        contribuintes[numContribuintes++] = contribuinte;

        System.out.println("Contribuinte adicionado com sucesso!");
    } else {
        System.out.println("Limite máximo de contribuintes atingido!");
    }
  }

  public double totalImpostos() {
      double total = 0;
      for (Contribuinte contribuinte : this.getContribuintes()) {
        if (contribuinte != null) {
          total += contribuinte.calculaImposto();
        }
      }
      return total;
  }

  public int numContribuintesIsentos() {
      int isentos = 0;
      for (Contribuinte contribuinte : this.getContribuintes()) {
        if (contribuinte != null) {
          if (contribuinte.calculaImposto() == 0) {
                isentos++;
          }
        } 
      }
      return isentos;
  }

  public double pesquisaContribuinte(String nome) {
      for (Contribuinte contribuinte : this.getContribuintes()) {
          if (contribuinte.getNome().equals(nome)) {
              return contribuinte.calculaImposto();
          }
      }
      return -1;
  }
}
