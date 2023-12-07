import java.util.ArrayList;

import javax.swing.JOptionPane;

import br.edu.utfpr.classes.Aluno;
import br.edu.utfpr.classes.Nota;
import br.edu.utfpr.classes.Turma;

public class App {
    public static void main(String[] args) throws Exception {
        ArrayList<Aluno> alunos = new ArrayList<>();
        ArrayList<Nota> notas = new ArrayList<>();
        Turma turma = new Turma(alunos, notas);
        int opcao = 0, idaluno = 0;
        
        do  {
            opcao = Integer.parseInt(JOptionPane.showInputDialog(null, "1 - Cadastrar aluno\n2 - Cadastrar nota\n3 - Calcular média do aluno\n4 - Listar os alunos sem notas\n5 - Excluir Aluno\n6 - Excluir nota\n7 - Apresentar alunos em ordem\n8 - Sair\n"));
            
            switch(opcao) {
                case 1:
                    idaluno++;
                    String nome = JOptionPane.showInputDialog(null, "Nome do aluno: ");
                    Aluno aluno = new Aluno(idaluno, nome);
                    turma.inserirAluno(aluno);
                    break;
                case 2:
                    idaluno++;
                    int idAluno = Integer.parseInt(JOptionPane.showInputDialog(null, "Id do aluno: ")); 
                    double nota = Double.parseDouble(JOptionPane.showInputDialog(null, "Nota do aluno: "));
                    Nota notaN = new Nota(idAluno, nota);
                    turma.inserirNota(notaN);
                    break;
                case 3:
                    int idALuno = Integer.parseInt(JOptionPane.showInputDialog(null, "Id do aluno: ")); 
                    double media = turma.calcularMediaAluno(idALuno);
                    JOptionPane.showMessageDialog(null, "Media do aluno: " + media);
                    break;
                case 4:
                    turma.imprimirAlunosSemNota();
                    break;
                case 5:
                    int numAluno = Integer.parseInt(JOptionPane.showInputDialog(null, "Id do aluno: ")); 
                    turma.excluirAluno(numAluno);
                    break;
                case 6:
                    int numeAluno = Integer.parseInt(JOptionPane.showInputDialog(null, "Id do aluno: ")); 
                    double notaAluno = Double.parseDouble(JOptionPane.showInputDialog(null, "Nota do aluno: "));
                    turma.excluirNota(numeAluno, notaAluno);
                    break;
                case 7:
                    turma.ordenarAlunosAlfabetica();
                    turma.imprimirAlunos();
                    break;
                case 8:
                    JOptionPane.showMessageDialog(null, "Encerrando aplicação...");
                    break;
                default:
                    JOptionPane.showMessageDialog(null, "Opção Inválida! Tente novamente.");
            }

        } while(opcao != 8);
    }
}
