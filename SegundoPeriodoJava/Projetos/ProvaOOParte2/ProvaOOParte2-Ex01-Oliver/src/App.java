import br.edu.utfpr.Empresa;
import br.edu.utfpr.Grupo;
import br.edu.utfpr.Produto;

public class App {
    public static void main(String[] args) {
        Produto miojo = new Produto("Miojo Premium", 50.0, 80.0, 10);
        Produto xtudo = new Produto("X-Tudo Premium", 30.0, 60.0, 30);
        Produto maionese = new Produto("Maionese Premium", 40.0, 70.0, 15);
        Produto sorvete = new Produto("Sorvete Premium", 20.0, 75.0, 103);
        miojo.mostrarDadosProduto();

        Grupo lanchoneteA = new Grupo("Lanchonete A Premium", "Alimentos");
        lanchoneteA.incluirProduto(miojo);
        lanchoneteA.incluirProduto(xtudo);

        lanchoneteA.mostrarDadosGrupo();

        Grupo lanchoneteB = new Grupo("Lanchonete B Premium", "Alimentos");
        lanchoneteB.incluirProduto(maionese);
        lanchoneteB.incluirProduto(sorvete);
        lanchoneteB.mostrarDadosGrupo();

        Empresa empresaLanchonetes = new Empresa("Empresa de lanchonetes");
        empresaLanchonetes.incluirGrupo(lanchoneteA);
        empresaLanchonetes.incluirGrupo(lanchoneteB);
        empresaLanchonetes.mostrarDadosEmpresa();
    }
}