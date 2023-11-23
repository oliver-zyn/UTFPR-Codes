package PacotesCodigosFonte.Excecao;

public class TrataIdade extends Exception {
  @Override
  public String getMessage() {
    return "Informe um valor entre 1900 e 2023 para o ano.";
  }
}