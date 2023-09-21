
public class Ex001 {
    public static void main(String[] args) {
        int rand = (int) (Math.random() * 91) + 10;
        String paridade = (rand % 2 == 0) ? "par" : "ímpar";
        System.out.println("Número: " + rand);
        System.out.println("O número é " + paridade + ".\n");
    }
}
