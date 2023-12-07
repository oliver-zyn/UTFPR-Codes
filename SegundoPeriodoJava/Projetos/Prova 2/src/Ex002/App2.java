package Ex002;

import javax.swing.JOptionPane;
import Ex002.br.edu.utfpr.Prova002.PessoaFisica;
import Ex002.br.edu.utfpr.Prova002.PessoaJuridica;

public class App2 {

    private static PessoaFisica newPf() {
        String nome, rendaS, telefone, email, cpf, numDepS;
        double rendaBruta;
        int numDependentes;

        nome = JOptionPane.showInputDialog( null, "Informe o nome do cliente: ");
        rendaS = JOptionPane.showInputDialog( null, "Informe a renda do cliente: ");
        telefone = JOptionPane.showInputDialog( null, "Informe o telefone do cliente: ");
        email = JOptionPane.showInputDialog( null, "Informe o email do cliente: ");
        cpf = JOptionPane.showInputDialog( null, "Informe o CPF do cliente: ");
        numDepS = JOptionPane.showInputDialog( null, "Informe o número de dependentes do cliente: ");

        rendaBruta = Double.parseDouble(rendaS);
        numDependentes = Integer.parseInt(numDepS);

        PessoaFisica pf = new PessoaFisica(nome, rendaBruta, telefone, email, cpf, numDependentes);
        return pf;
    }

    private static PessoaJuridica newPj() {
        String nome, rendaS, telefone, email, cnpj, tipo;
        double rendaBruta;

        nome = JOptionPane.showInputDialog( null, "Informe o nome do cliente: ");
        rendaS = JOptionPane.showInputDialog( null, "Informe a renda do cliente: ");
        telefone = JOptionPane.showInputDialog( null, "Informe o telefone do cliente: ");
        email = JOptionPane.showInputDialog( null, "Informe o email do cliente: ");
        cnpj = JOptionPane.showInputDialog( null, "Informe o CNPJ do cliente: ");
        tipo = JOptionPane.showInputDialog( null, "Informe o tipo do cliente: ");

        rendaBruta = Double.parseDouble(rendaS);

        PessoaJuridica pj = new PessoaJuridica(nome, rendaBruta, telefone, email, cnpj, tipo);
        return pj;
    }

    private static int menu() {
        String opcao2;
        int opcao;
        opcao2 = JOptionPane.showInputDialog(null, "Informe a opcao de ação:\n1 - Cadastrar novo cliente\n2 - Mostrar imposto total\n3 - Núm. de Cont. Isentos\n4 - Imposto de cliente especifico.\n5 - Sair");
        opcao = Integer.parseInt(opcao2);

        return opcao;
    }
    public static void main(String[] args) {
        int opcao = 0, opcaoP, y = 0, v = 0, countIsentos = 0;
        String opcaoPS, CPF, CNPJ;
        double impostoTotal = 0;

        PessoaFisica[] listaPF = new PessoaFisica[50];
        PessoaJuridica[] listaPJ = new PessoaJuridica[50];        
        
        do {
            opcao = menu();

            switch(opcao) {
                case 1:
                    opcaoPS = JOptionPane.showInputDialog(null, "1 - Pessoa Física\n2 - Pessoa Jurídica");
                    opcaoP = Integer.parseInt(opcaoPS);

                    if (opcaoP == 1) {
                        PessoaFisica novoPf = newPf();
                        listaPF[y] = novoPf;
                        y++;
                    } else if (opcaoP == 2){
                        PessoaJuridica novoPj = newPj();
                        listaPJ[v] = novoPj;
                        v++;
                    }

                    break;
                case 2:
                    impostoTotal = 0;

                    for(int i = 0; i < y; i++) {
                        impostoTotal += listaPF[i].calculaImposto();
                    }
                    for(int i = 0; i < v; i++) {
                        impostoTotal += listaPJ[i].calculaImposto();
                    }
                    System.out.println("Imposto total: " + impostoTotal);

                    break;
                case 3:
                    for(int i = 0; i < y; i++) {
                        if (listaPF[i].calculaImposto() == 0)
                        countIsentos++;
                    }
                    for(int i = 0; i < v; i++) {
                        if (listaPJ[i].calculaImposto() == 0)
                        countIsentos++;
                    }

                    System.out.println("Numero de isentos: " + countIsentos);

                    break;
                case 4:
                    opcaoPS = JOptionPane.showInputDialog(null, "1 - Pessoa Física\n2 - Pessoa Jurídica");
                    opcaoP = Integer.parseInt(opcaoPS);

                    if (opcaoP == 1) {
                        CPF = JOptionPane.showInputDialog(null, "Informe o CPF do Cliente:");
                        for(int i = 0; i < y; i++) {
                            if (listaPF[i].getCPF() == CPF);
                            System.out.println("Imposto especifico: " + listaPF[i].calculaImposto());
                            System.out.println("Dados do cliente: ");
                            System.out.println(listaPF[i].toString());
                        }
                    } else if (opcaoP == 2){
                        CNPJ = JOptionPane.showInputDialog(null, "Informe o CNPJ do Cliente:");
                        for(int i = 0; i < v; i++) {
                            if (listaPF[i].getCPF() == CNPJ);
                            System.out.println("Imposto especifico: " + listaPJ[i].calculaImposto());
                            System.out.println("Dados do cliente: ");
                            System.out.println(listaPJ[i].toString());
                        }
                    }

                    break;
                case 5:
                    System.out.println("Encerrando processo.");
                    break;
                default:
                    System.out.println("Erro, opcao inválida!");
                    break;
            }
        } while (opcao != 5);
    }
}
