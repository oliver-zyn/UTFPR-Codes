import br.edu.utfpr.Prova.Empresa;
import br.edu.utfpr.Prova.Grupo;
import br.edu.utfpr.Prova.Produto;

public class App {
    
    public static void main(String[] args) {
        Produto produto1 = new Produto("Produto A", 50.0, 80.0, 151);
        Produto produto2 = new Produto("Produto B", 40.0, 70.0, 120);
        Produto produto3 = new Produto("Produto C", 30.0, 60.0, 100);
        Produto produto4 = new Produto("Produto D", 20.0,50.0, 75);
        Produto produto5 = new Produto("Produto E", 10.0, 40.0, 25);
        Produto produto6 = new Produto("Produto F", 5.0, 30.0, 10);
        Produto produto7 = new Produto("Produto G", 1.0, 20.0, 1);

        System.out.println("Em excesso:");
        produto1.apresentarDadosProduto();
        System.out.println("\n");

        System.out.println("Normal:");
        produto5.apresentarDadosProduto();
        System.out.println("\n");

        System.out.println("Mínimo:");
        produto7.apresentarDadosProduto();
        System.out.println("\n");

        Grupo grupo1 = new Grupo("Grupo A", "Alimento");
        Grupo grupo2 = new Grupo("Grupo B", "Eletronico");
        Grupo grupo3 = new Grupo("Grupo C", "Cosmetico");

        grupo1.adicionarProduto(produto7);
        grupo1.adicionarProduto(produto1);
        grupo1.adicionarProduto(produto1);

        grupo2.adicionarProduto(produto6);
        grupo2.adicionarProduto(produto2);
        grupo2.adicionarProduto(produto2);

        grupo3.adicionarProduto(produto5);
        grupo3.adicionarProduto(produto4);
        grupo3.adicionarProduto(produto3);

        System.out.println("Grupo apresentar dados\n:");
        grupo1.apresentarDadosGrupo();
        System.out.println("\n");

        Empresa empresa1 = new Empresa("Toyota NCI");

        empresa1.adicionarGrupo(grupo1);
        empresa1.adicionarGrupo(grupo2);
        empresa1.adicionarGrupo(grupo3);

        System.out.println("Empresa Apresentar Dados:");
        empresa1.apresentarDados();

        System.out.println("Estoque dos grupos:");
        empresa1.estoqueMinimo();
    }
}
