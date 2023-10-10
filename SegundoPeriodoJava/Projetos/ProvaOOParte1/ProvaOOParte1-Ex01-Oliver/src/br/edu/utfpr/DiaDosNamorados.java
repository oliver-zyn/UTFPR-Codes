package br.edu.utfpr;

public class DiaDosNamorados extends CartaoWeb {
  private String nomeRemetente;

  public DiaDosNamorados() {
  }

  public DiaDosNamorados(Pessoa destinatario, String nomeRemetente) {
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
    System.out.println("Querido(a) " + this.getDestinatario().getNome() + "\nFeliz Dia dos Namorados! " + "\nDe todo meu coracao, \n" + getNomeRemetente());
  }

  @Override
  public String toString() {
    return "\nRemetente: " + getNomeRemetente() +
      "\nDestinatario: " + getDestinatario();
  }
}
