package br.edu.utfpr;

public class Aniversario extends CartaoWeb {
  private String nomeRemetente;

  public Aniversario() {
  }

  public Aniversario(Pessoa destinatario, String nomeRemetente) {
    super(destinatario);
    this.nomeRemetente = nomeRemetente;
  }

  public String getNomeRemetente() {
    return this.nomeRemetente;
  }

  public void setNomeRemetente(String nomeRemetente) {
    this.nomeRemetente = nomeRemetente;
  }

  @Override
  public void mostraMensagem() {
    System.out.println("Querido(a) " + this.getDestinatario().getNome() + "\nFeliz Aniversario! " + "\nCom todo carinho, \n" + getNomeRemetente());
  }

  @Override
  public String toString() {
    return "\nRemetente: " + getNomeRemetente() +
      "\nDestinatario: " + getDestinatario();
  }
}
