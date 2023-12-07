package Ex001.br.edu.utfpr.ProvaOO1;

public class Natal extends CartaoWeb {

    public Natal(Pessoa destinatario) {
        super(destinatario);
    }

    @Override
    public void mostraMensagem() {
        Pessoa destinatario = getDestinatario();
        System.out.println("Querido " + destinatario.getNome() + ",");
        System.out.println("Feliz Natal!");
        System.out.println("Que o espírito natalino traga muita alegria.");
        System.out.println("Com carinho,");
        System.out.println("Pedro");
        System.out.println();
    }
}
