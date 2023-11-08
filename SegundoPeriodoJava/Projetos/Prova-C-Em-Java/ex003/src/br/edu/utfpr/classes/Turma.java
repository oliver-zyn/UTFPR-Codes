package br.edu.utfpr.classes;

import java.util.ArrayList;
import javax.swing.JOptionPane;

public class Turma {
  private ArrayList<Aluno> alunos;
  private ArrayList<Nota> notas;

  public Turma() {
  }

  public Turma(ArrayList<Aluno> alunos, ArrayList<Nota> notas) {
    this.alunos = alunos;
    this.notas = notas;
  }

  public void inserirAluno(Aluno aluno) {
    alunos.add(aluno);
    JOptionPane.showMessageDialog(null, "Aluno cadastrado com sucesso!");
  }

  public void inserirNota(Nota nota) {
    if (nota.getNota() >= 0 && nota.getNota() <= 10) {
      notas.add(nota);
      JOptionPane.showMessageDialog(null, "Nota cadastrada com sucesso!");
    } else {
      JOptionPane.showMessageDialog(null, "A nota deve estar entre 0 e 10!", "Erro", JOptionPane.ERROR_MESSAGE);
    }
  }

  public void excluirAluno(int numeroAluno){
    for (int i = 0; i < alunos.size(); i++) {
        Aluno aluno = alunos.get(i);
        if (aluno.getNumero() == numeroAluno) {
            if (alunoPossuiNota(numeroAluno)) {
              JOptionPane.showMessageDialog(null, "O aluno possui notas cadastradas!", "Erro", JOptionPane.ERROR_MESSAGE);
              return;
            }
            alunos.remove(i);
            JOptionPane.showMessageDialog(null, "Aluno removido com sucesso!");
            return;
        }
    }

    JOptionPane.showMessageDialog(null, "Aluno não encontrado ou inexistente!", "Erro", JOptionPane.ERROR_MESSAGE);
  }

  public void excluirNota(int numeroAluno, double valorNota){
    for (int i = 0; i < notas.size(); i++) {
        Nota nota = notas.get(i);
        if (nota.getNumeroAluno() == numeroAluno && nota.getNota() == valorNota) {
            notas.remove(i);
            JOptionPane.showMessageDialog(null, "Nota removida com sucesso!");
            return;
        }
    }

    JOptionPane.showMessageDialog(null, "Nota não encontrada ou inexistente!", "Erro", JOptionPane.ERROR_MESSAGE);
  }

  public void imprimirAlunos() {
    String alunosMsg = "";

    for (Aluno aluno : alunos) {
        alunosMsg += "Aluno " + aluno.getNome() + " (" + aluno.getNumero() + ") \n";

        if (alunoPossuiNota(aluno.getNumero())) {
          String notasMsg = "    Notas: ";

          for (Nota nota : notas) {
            if (nota.getNumeroAluno() == aluno.getNumero()) {
              notasMsg += nota.getNota() + ", ";
            }
          }

          notasMsg = notasMsg.substring(0, notasMsg.length() - 2);

          alunosMsg += notasMsg + ".\n";
        }
    }

    if (alunosMsg == "") {
      alunosMsg = "Nenhum aluno cadastrado!";
    }

    JOptionPane.showMessageDialog(null, alunosMsg);
  }

  public void imprimirAlunosSemNota() {
    String alunosSemNota = "";

    for (Aluno aluno : alunos) {
        if (!alunoPossuiNota(aluno.getNumero())) {
            alunosSemNota += "O aluno " + aluno.getNome() + " (" + aluno.getNumero() + ") não possui notas \n";
        }
    }

    if (alunosSemNota == "") {
      alunosSemNota = "Nenhum aluno sem nota";
    }

    JOptionPane.showMessageDialog(null, alunosSemNota);
  }

  public boolean alunoPossuiNota(int numeroAluno) {
    boolean possuiNota = false;

    for (Nota nota : notas) {
        if (nota.getNumeroAluno() == numeroAluno) {
            possuiNota = true;
            break;
        }
    }

    return possuiNota;
  }

  public double calcularMediaAluno(int numeroAluno) {
    double somaNotas = 0, media = 0;
    int qtdNotas = 0;

    if (alunoPossuiNota(numeroAluno)) {
      for (Nota nota : notas) {
        if (nota.getNumeroAluno() == numeroAluno) {
            qtdNotas++;
            somaNotas += nota.getNota();
        }
      }

      media = somaNotas / qtdNotas;
    } else {
      JOptionPane.showMessageDialog(null, "O aluno não possui notas cadastradas!", "Erro", JOptionPane.ERROR_MESSAGE);
    }

    return media;
  }

  public void ordenarAlunosAlfabetica(){
    alunos.sort((p1, p2)->{
      return p1.getNome().compareTo(p2.getNome());
    });
  }
  
}
