package br.edu.utfpr.AAC;

public class Curso {
    private String nome;
    private Disciplina[] disciplinas; // Agregação
    private Aluno[] alunos; // Agregação
    private int numAlunos;
    private int numDisciplinas;

    public Curso() {
    }

    public Curso(String nome) {
        this.nome = nome;
        this.disciplinas = new Disciplina[10];
        this.alunos = new Aluno[30];
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Disciplina[] getDisciplina() {
        return this.disciplinas;
    }

    public Aluno[] getAlunos() {
        return this.alunos;
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

    public String listaAlunos() {
        String listAluno = "";
        if (this.alunos != null) {
            for (Aluno aluno : this.getAlunos()) {
                if (aluno != null) {
                    listAluno += "-> " + aluno.getNome() + " - " + aluno.listEndereco() + "\n";
                }
            }
        } else {
            listAluno = "Não há alunos";
        }
        return listAluno;
    }

    public String listaDisciplinas() {
        String listDisciplina = "";
        if (this.disciplinas != null) {
            for (Disciplina disciplina : this.getDisciplina()) {
                if (disciplina != null) {
                    listDisciplina += "-> " + disciplina.getNome() + " - Professor: " + disciplina.listaProfessor() + "\n";
                }
            }
        } else {
            listDisciplina = "Não há disciplinas";
        }
        return listDisciplina;
    }

    @Override
    public String toString() {
        return "Curso: " + getNome() +
            "\nDisciplinas: \n" + listaDisciplinas() +
            "Alunos: \n" + listaAlunos();
    }
}
