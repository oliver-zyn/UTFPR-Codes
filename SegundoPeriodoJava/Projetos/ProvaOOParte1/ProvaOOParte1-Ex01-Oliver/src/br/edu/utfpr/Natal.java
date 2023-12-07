package br.edu.utfpr;

public class Natal extends CartaoWeb {
  private String nomeRemetente;

  public Natal() {
  }

  public Natal(Pessoa destinatario, String nomeRemetente) {
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
    System.out.println("Querido(a) " + this.getDestinatario().getNome() + "\nFeliz Natal! " + "\nCom todo carinho, \n" + getNomeRemetente());
  }

  @Override
  public String toString() {
    return "\nRemetente: " + getNomeRemetente() +
      "\nDestinatario: " + getDestinatario();
  }
}
