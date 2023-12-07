package Ex001.br.edu.utfpr.ProvaOO1;

public class Aniversario extends CartaoWeb {

    public Aniversario(Pessoa destinatario) {
        super(destinatario);
    }

    @Override
    public void mostraMensagem() {
        Pessoa destinatario = getDestinatario();
        System.out.println("Querido " + destinatario.getNome() + ",");
        System.out.println("Feliz Aniversário!");
        System.out.println("Desejo a você um dia repleto de alegria.");
        System.out.println("Comemore com muita felicidade!");
        System.out.println("Abraços,");
        System.out.println("Pedro");
        System.out.println();
    }
}
