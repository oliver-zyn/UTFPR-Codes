package ClassesPolimorfismo;

import java.util.ArrayList;

public class Universidade {
  private ArrayList<Pessoa> pessoas;

  public Universidade() {
  }

  public Universidade(ArrayList<Pessoa> pessoas) {
    this.pessoas = pessoas;
  }

  public void inserir(Pessoa pessoa) {
    pessoas.add(pessoa);
  }

  public boolean excluir(String nome) {
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
    Relatorio relatorio = new Relatorio();

    pessoas.forEach(pessoa -> {
      relatorio.somar(pessoa);
    });

    return relatorio.getTotalGastos();
  }

}