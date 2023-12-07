package Ex001.br.edu.utfpr.ProvaOO1;

public class DiaDosNamorados extends CartaoWeb {
    public DiaDosNamorados(Pessoa destinatario) {
        super(destinatario);
    }

    @Override
    public void mostraMensagem() {
        Pessoa destinatario = getDestinatario();
        System.out.println("Querida " + destinatario.getNome() + ",");
        System.out.println("Feliz Dia dos Namorados!");
        System.out.println("Espero que esse tenha sido o único cartão do Dia dos Namorados que tenha ganhado nessa data! ;-) ");
        System.out.println("De todo meu coração,");
        System.out.println("Pedro");
        System.out.println();
    }
}
