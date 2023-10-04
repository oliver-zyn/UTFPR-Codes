package br.edu.utfpr.Escola;

public class Curso {
  private String nome;
  private Aluno[] alunos; //Agregação
  private Disciplina[] disciplinas; //Agregação
  private int numAlunos = 0;
  private int numDisciplinas = 0;

  public Curso() {
  }

  public Curso(String nome) {
    this.nome = nome;
    this.alunos = new Aluno[30];  
    this.disciplinas = new Disciplina[10];
  }

  public String getNome() {
    return this.nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public Aluno[] getAlunos() {
    return this.alunos;
  }

  public Disciplina[] getDisciplinas() {
    return this.disciplinas;
  }

  public void addAluno(Aluno aluno) {
    if (numAlunos < alunos.length) {
        alunos[numAlunos++] = aluno;

        System.out.println("Aluno adicionado com sucesso!");
    } else {
        System.out.println("Limite máximo de alunos atingido!");
    }
  }

  public void addDisciplina(Disciplina disciplina) {
    if (numDisciplinas < disciplinas.length) {
        disciplinas[numDisciplinas++] = disciplina;

        System.out.println("Disciplina adicionada com sucesso!");
    } else {
        System.out.println("Limite máximo de disciplinas atingido!");
    }
  }

  public String listarAlunos() {
    String listaAlunos = "";

    if (this.alunos != null) {
        for (Aluno alun : this.getAlunos()) {
            if (alun != null) {
                listaAlunos += "-> " + alun.getNome() + " - " + alun.listarEndereco() + "\n";
            }
        }
    } else {
        listaAlunos = "Não há alunos! \n";
    }

    return listaAlunos;
  }

  public String listarDisciplinas() {
    String listaDisciplinas = "";

    if (this.disciplinas != null) {
        for (Disciplina disc : this.getDisciplinas()) {
            if (disc != null) {
                listaDisciplinas += "-> " + disc.getNome() + " - " + "Professor: " + disc.getNomeProfessor() + "\n";
            }
        }
    } else {
        listaDisciplinas = "Não há disciplinas! \n";
    }

    return listaDisciplinas;
  }

  @Override
  public String toString() {
    return "\nCurso: " + getNome() +
          "\nDisciplinas: \n" + listarDisciplinas() +
          "Alunos: \n" + listarAlunos();
  }
    
}
