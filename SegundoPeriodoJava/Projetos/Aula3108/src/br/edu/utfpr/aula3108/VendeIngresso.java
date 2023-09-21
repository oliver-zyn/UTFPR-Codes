package br.edu.utfpr.aula3108;

import java.util.Stack;

import javax.swing.JOptionPane;

public class VendeIngresso {
    public static void main(String[] args) {
        double ValorFinal = 0;
        Filme f = new Filme(1, "vid", "Terror", 100, "Vários", 40);
        Stack<Ingresso> st = new Stack<Ingresso>();

        for (int y = 0; y < 3; y++) {
            Cliente c = new Cliente();
            Ingresso i = new Ingresso();
            String cod = JOptionPane.showInputDialog(null, "Codigo do cliente:");
            int codigo = Integer.parseInt(cod); c.setCodigo(codigo);
            String nome = JOptionPane.showInputDialog(null, "Nome do cliente:");
            c.setNome(nome);
            String celular = JOptionPane.showInputDialog(null, "Celular do cliente:");
            c.setCelular(celular);
            String email = JOptionPane.showInputDialog(null, "Email do cliente:");
            c.setEmail(email);
            String sala = JOptionPane.showInputDialog(null, "Salario do cliente:");
            int salario = Integer.parseInt(sala); c.setSalario(salario);

            i.setCliente(c); i.setNumero(c.getCodigo()); i.setValor(f.getValorIngresso());
            ValorFinal += i.getValor();

            String data = JOptionPane.showInputDialog(null, "Data da Sessão:");
            i.setData(data);
            String hora = JOptionPane.showInputDialog(null, "Horário da Sessão:");
            i.setHora(hora);
            String poltrona = JOptionPane.showInputDialog(null, "Poltrona do ingresso:");
            i.setPoltrona(poltrona);
            String sessaoI = JOptionPane.showInputDialog(null, "Sessão do ingresso:");
            int sessao = Integer.parseInt(sessaoI); i.setSessao(sessao);

            st.push(i);
        }

        st.forEach(teste -> 
            System.out.println(teste)
        );
        System.out.println("Valor Ingresso: " + ValorFinal);
    }
    
}
