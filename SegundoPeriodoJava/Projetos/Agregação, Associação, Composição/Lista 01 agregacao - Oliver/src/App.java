import br.edu.utfpr.Escola.Aluno;
import br.edu.utfpr.Escola.Curso;
import br.edu.utfpr.Escola.Disciplina;
import br.edu.utfpr.Escola.Endereco;
import br.edu.utfpr.Escola.Professor;

public class App {
    public static void main(String[] args) throws Exception {
        Endereco endereco1 = new Endereco("Rua Palmas", 123, "Bairro Palminha", "Cidade Guarapuava");
        Endereco endereco2 = new Endereco("Rua Fonseca", 456, "Bairro Fonsequinha", "Cidade Pato Branco");

        Aluno aluno1 = new Aluno("Aluno Marcos", "111-1111", endereco1, 213, 20);
        Aluno aluno2 = new Aluno("Aluno Carlos", "222-2222", endereco2, 432, 18);

        Professor professor1 = new Professor("Professora Danuza", "333-3333", endereco1, 438);
        Professor professor2 = new Professor("Professor Pogba", "444-4444", endereco2, 543);

        Disciplina disciplina1 = new Disciplina(1001, "Disciplina Banco de Dados", professor1);
        Disciplina disciplina2 = new Disciplina(1002, "Disciplina React.js", professor2);

        Curso curso1 = new Curso("Curso Analise e Desenvolvimento de Sistemas");
        curso1.addAluno(aluno1);
        curso1.addAluno(aluno2);
        curso1.addDisciplina(disciplina1);
        curso1.addDisciplina(disciplina2);

        System.out.println(curso1.toString());;
    }
}
