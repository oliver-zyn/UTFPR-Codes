package Main;

import javax.swing.JOptionPane;

import classes.Administrador;
import classes.Diretor;
import classes.Fornecedor;

public class App {
    public static void main(String[] args) throws Exception {
        String opcao, nome, endereco, telefone, codigoSetor_S, salarioBase_S, ajudaDeCusto_S, gratificação_S, ValorCredito_S, ValorDivida_S;
        float salarioBase, ajudaDeCusto, gratificação, ValorCredito, ValorDivida;
        int opcaoInt, codigoSetor;
        opcao = JOptionPane.showInputDialog(null, "Qual opção de cadastro irá realizar?\n1- Fornecedor\n2- Administrador\n3- Diretor");
        opcaoInt = Integer.parseInt(opcao);

        switch(opcaoInt) {
            case 1:
                nome = JOptionPane.showInputDialog(null, "Qual o nome do fornecedor? ");
                endereco = JOptionPane.showInputDialog(null, "Qual o endereço do fornecedor? ");
                telefone = JOptionPane.showInputDialog(null, "Qual o telefone do fornecedor? ");

                ValorCredito_S = JOptionPane.showInputDialog(null, "Qual o saldo de crédito do fornecedor? ");
                ValorCredito = Float.parseFloat(ValorCredito_S);
                ValorDivida_S = JOptionPane.showInputDialog(null, "Qual o saldo de dívida do fornecedor? ");
                ValorDivida = Float.parseFloat(ValorDivida_S);

                Fornecedor fornecedor = new Fornecedor(nome, endereco, telefone, ValorCredito, ValorDivida);
                float saldo = fornecedor.calcularSaldo(ValorCredito, ValorDivida);
                System.out.println(fornecedor);
                System.out.println(saldo);
                break;
            case 2:
                nome = JOptionPane.showInputDialog(null, "Qual o nome do administrador? ");
                endereco = JOptionPane.showInputDialog(null, "Qual o endereço do administrador? ");
                telefone = JOptionPane.showInputDialog(null, "Qual o telefone do administrador? ");

                codigoSetor_S = JOptionPane.showInputDialog(null, "Qual o código de setor do administrador? ");
                codigoSetor = Integer.parseInt(codigoSetor_S);
                salarioBase_S = JOptionPane.showInputDialog(null, "Qual o salário base do administrador? ");
                salarioBase = Float.parseFloat(salarioBase_S);

                ajudaDeCusto_S = JOptionPane.showInputDialog(null, "Qual o valor de ajuda de custo do administrador? ");
                ajudaDeCusto = Float.parseFloat(ajudaDeCusto_S);

                Administrador administrador = new Administrador(nome, endereco, telefone, salarioBase, codigoSetor, ajudaDeCusto);
                float saldototal = administrador.calcularSalarioTotal();
                System.out.println(administrador);
                System.out.println("Saldo total= " + saldototal);
                break;
            case 3:
                nome = JOptionPane.showInputDialog(null, "Qual o nome do diretor? ");
                endereco = JOptionPane.showInputDialog(null, "Qual o endereço do diretor? ");
                telefone = JOptionPane.showInputDialog(null, "Qual o telefone do diretor? ");

                codigoSetor_S = JOptionPane.showInputDialog(null, "Qual o código de setor do diretor? ");
                codigoSetor = Integer.parseInt(codigoSetor_S);
                salarioBase_S = JOptionPane.showInputDialog(null, "Qual o salário base do diretor? ");
                salarioBase = Float.parseFloat(salarioBase_S);

                gratificação_S = JOptionPane.showInputDialog(null, "Qual o valor de ajuda de custo do diretor? ");
                gratificação = Float.parseFloat(gratificação_S);

                Diretor diretor = new Diretor(nome, endereco, telefone, salarioBase, codigoSetor, gratificação);
                saldototal = diretor.calcularSalarioTotal();
                System.out.println(diretor);
                System.out.println("Saldo total= " + saldototal);
                break;  
            default:
                break;
        }
    }
}
