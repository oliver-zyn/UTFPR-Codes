import br.edu.utfpr.AAC.Endereço;
import br.edu.utfpr.AAC.Aluno;
import br.edu.utfpr.AAC.Professor;
import br.edu.utfpr.AAC.Disciplina;
import br.edu.utfpr.AAC.Curso;

public class App {
    public static void main(String[] args) throws Exception {
        Endereço endereco1 = new Endereço("Jardim A", 123, "Patao", "Parana");
        Endereço endereco2 = new Endereço("Jardim B", 124, "Patoa", "Parano");

        Aluno aluno1 = new Aluno("Pedro", "2341231241", endereco1, "2314", 15);
        Aluno aluno2 = new Aluno("Oliver", "2414241", endereco2, "32114", 14);

        Professor professor1 = new Professor("Oliveira", "24125112312", endereco1, "23");
        Professor professor2 = new Professor("Oliveira", "24125112312", endereco1, "23");

        Disciplina disciplina1 = new Disciplina(1, professor1, "ABC");
        Disciplina disciplina2 = new Disciplina(2, professor2, "ABD");

        Curso curso1 = new Curso("Cursaodoa");
        curso1.addAluno(aluno1);
        curso1.addAluno(aluno2);
        curso1.addDisciplina(disciplina1);
        curso1.addDisciplina(disciplina2);

        System.out.println(curso1);
    }
}
