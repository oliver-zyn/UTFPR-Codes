import java.util.ArrayList;

import javax.swing.JOptionPane;

import ClassesPolimorfismo.*;

public class App {
    public static void main(String[] args) throws Exception {
        ArrayList<Pessoa> pessoas = new ArrayList<>();

        Professor prof = new Professor("Pedro", "018239123", 1200, 1000);
        Coordenador coord = new Coordenador("Oliver1", "123124120", 10000, 1000, 1200);

        Reitor reitor = new Reitor("Oliver", "98236329846", 3000, 200, 100);
        Estagiario estagiario = new Estagiario("Poliglota", "98236329846", 600, 500);

        Universidade univ = new Universidade(pessoas);

        univ.inserir(prof);
        univ.inserir(coord);
        univ.inserir(reitor);
        univ.inserir(estagiario);

        JOptionPane.showMessageDialog(null, prof.toString());
        JOptionPane.showMessageDialog(null, coord.toString());
        JOptionPane.showMessageDialog(null, reitor.toString());
        JOptionPane.showMessageDialog(null, estagiario.toString());

        JOptionPane.showMessageDialog(null, "Total de despesas da universidade: " + univ.getTotalGastoUniversidade());
    }
}
