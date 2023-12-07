package PacotesCodigosFonte.Pessoa;

import java.time.LocalDate;

import PacotesCodigosFonte.Excecao.TrataIdade;

public class Pessoa {
  private String nome;
  private int anoNasc;
  private int idade;


    public Pessoa() {
    }

    public Pessoa(String nome, int anoNasc) {
        this.nome = nome;
        this.anoNasc = anoNasc;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getAnoNasc() {
        return this.anoNasc;
    }

    public void setAnoNasc(int anoNasc) {
        this.anoNasc = anoNasc;
    }

    public int getIdade() {
        return this.idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public void calcularIdade() throws TrataIdade {
      int anoAtual = LocalDate.now().getYear();
      int anoNasc = getAnoNasc();

      if (anoNasc < 1900 || anoNasc > anoAtual) {
        throw new TrataIdade();
      } else {
        setIdade(anoAtual - anoNasc);
      }
    }

    @Override
    public String toString() {
        return "{" +
            " nome='" + getNome() + "'" +
            ", anoNasc='" + getAnoNasc() + "'" +
            ", idade='" + getIdade() + "'" +
            "}";
    }
  
}
