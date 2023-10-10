package Ex001.br.edu.utfpr.ProvaOO1;

public abstract class CartaoWeb {
    private Pessoa destinatario;

    public CartaoWeb() {
    }

    public CartaoWeb(Pessoa destinatario) {
        this.destinatario = destinatario;
    }

    public abstract void mostraMensagem();


    public Pessoa getDestinatario() {
        return this.destinatario;
    }

    public void setDestinatario(Pessoa destinatario) {
        this.destinatario = destinatario;
    }
}
