package Classes;
import java.util.ArrayList;

public class Empresa {
    private ArrayList<Pessoa> clientes;

    public Empresa() {
    }

    public Empresa(ArrayList<Pessoa> clientes) {
        this.clientes = clientes;
    }

    public void inserir(Pessoa pessoa) {
        clientes.add(pessoa);
    }

    public boolean excluir(String nome){
        for (int i = 0; i < clientes.size(); i++) {
            Pessoa cliente = clientes.get(i);
            if (cliente.getNome().equals(nome)) {
                clientes.remove(i);
                return true;
            }
        }

        return false;
    }

    public void imprimir() {
        clientes.forEach(pessoa -> System.out.println(pessoa));
    }

    public void ordenarAlfabetica(){
      clientes.sort((p1, p2)->{
          return p1.getNome().compareTo(p2.getNome());
      });
    }
}
