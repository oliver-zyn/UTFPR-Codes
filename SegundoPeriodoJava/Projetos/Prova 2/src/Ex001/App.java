package Ex001;
import Ex001.br.edu.utfpr.ProvaOO1.Aniversario;
import Ex001.br.edu.utfpr.ProvaOO1.CartaoWeb;
import Ex001.br.edu.utfpr.ProvaOO1.DiaDosNamorados;
import Ex001.br.edu.utfpr.ProvaOO1.Natal;
import Ex001.br.edu.utfpr.ProvaOO1.Pessoa;

public class App {
    public static void main(String[] args) {
        Pessoa destinatario = new Pessoa("Maria", "Rua XYZ", "Cidade A", "Estado B", "maria@example.com", "46 999714554");

        CartaoWeb diaDosNamorados = new DiaDosNamorados(destinatario);
        diaDosNamorados.mostraMensagem();

        CartaoWeb natal = new Natal(destinatario);
        natal.mostraMensagem();

        CartaoWeb aniversario = new Aniversario(destinatario);
        aniversario.mostraMensagem();
    }
}
