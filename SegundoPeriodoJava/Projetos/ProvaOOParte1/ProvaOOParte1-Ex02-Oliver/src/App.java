import br.edu.utfpr.Escritorio;
import br.edu.utfpr.PessoaFisica;
import br.edu.utfpr.PessoaJuridica;

public class App {
    public static void main(String[] args) throws Exception {
        double totalImpostos, impostoContribuintePesquisa;
        int contribuintesIsentos;

        Escritorio escritorio = new Escritorio();

        PessoaJuridica sponte = new PessoaJuridica("Sponte", 50000, "111-1111", "sponte@sponte.com", "123456789", "Media");
        PessoaFisica oliver = new PessoaFisica("Oliver", 3000, "222-2222", "oliver@gmail.com", "987654321", 2);
        PessoaFisica pedro = new PessoaFisica("Pedro", 2500, "333-3333", "pedro@gmail.com", "534535346", 1);
        PessoaFisica carlos = new PessoaFisica("Carlos", 1200, "444-4444", "carlos@gmail.com", "324234235", 3);
        
        escritorio.incluirContribuinte(sponte);
        escritorio.incluirContribuinte(oliver);
        escritorio.incluirContribuinte(pedro);
        escritorio.incluirContribuinte(carlos);

        totalImpostos = escritorio.totalImpostos();
        contribuintesIsentos = escritorio.numContribuintesIsentos();

        System.out.printf("Total de impostos a pagar pelos clientes: R$ %.2f\n", totalImpostos);
        System.out.println("Numero de contribuintes isentos: " + contribuintesIsentos);

        impostoContribuintePesquisa = escritorio.pesquisaContribuinte("Oliver");

        if (impostoContribuintePesquisa != -1) {
            System.out.printf("Imposto de Oliver: R$ %.2f", impostoContribuintePesquisa);
        } else {
            System.out.println("Nenhum contribuinte foi encontrado!");
        }
    }
}
