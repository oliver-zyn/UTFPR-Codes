package ClassesPolimorfismo;

import java.util.ArrayList;

public class Universidade {
  private ArrayList<Pessoa> pessoas;
  private Luz luz;

  public Universidade() {
  }

  public Universidade(ArrayList<Pessoa> pessoas) {
    this.pessoas = pessoas;
  }

  public void inserirPessoa(Pessoa pessoa) {
    pessoas.add(pessoa);
  }

  public void inserirLuz(Luz luz) {
    this.luz = luz;
  }

  public boolean excluirPessoa(String nome) {
    for (int i = 0; i < pessoas.size(); i++) {
      Pessoa cliente = pessoas.get(i);
      if (cliente.getNome().equals(nome)) {
        pessoas.remove(i);
        return true;
      }
    }

    return false;
  }

  public void imprimir() {
    pessoas.forEach(pessoa -> System.out.println(pessoa));
  }

  public double getTotalGastoUniversidade() {
    GeradorRelatorio relatorio = new GeradorRelatorio();

    pessoas.forEach(pessoa -> {
      relatorio.somarPessoa(pessoa);
    });

    relatorio.somarLuz(this.luz);

    return relatorio.getTotalGastos();
  }

}