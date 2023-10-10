package br.edu.utfpr;

public abstract class CartaoWeb {
  private Pessoa destinatario;

  public CartaoWeb() {
  }

  public CartaoWeb(Pessoa destinatario) {
    this.destinatario = destinatario;
  }

  public Pessoa getDestinatario() {
    return this.destinatario;
  }

  public void setDestinatario(Pessoa destinatario) {
    this.destinatario = destinatario;
  }

  public abstract void mostraMensagem();

  @Override
  public abstract String toString();

}
