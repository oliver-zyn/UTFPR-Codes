package PacotesCodigosFonte.UsandoPessoa;

import javax.swing.JOptionPane;

import PacotesCodigosFonte.Excecao.TrataIdade;
import PacotesCodigosFonte.Pessoa.Pessoa;

public class UsandoPessoa {
    public static void main(String[] args) throws TrataIdade {
      try {
        Pessoa pessoa = new Pessoa();
        
        String nome = JOptionPane.showInputDialog(null, "Qual o nome da pessoa?");
        int anoNasc = Integer.parseInt(JOptionPane.showInputDialog(null, "Qual o ano de nascimento da pessoa?"));

        pessoa.setNome(nome);
        pessoa.setAnoNasc(anoNasc);
        pessoa.calcularIdade();

        System.err.println("Idade da pessoa: " + pessoa.getIdade());
      
      } catch (NumberFormatException e) {
        System.out.println("Informe um numero!!! >:( ");
      } catch (TrataIdade e) {
        System.out.println(e.getMessage());
      }
    }
}
