import java.text.SimpleDateFormat;
import java.util.Calendar;

public class Ex005 {
    public static void main(String[] args) {
        Calendar data = Calendar.getInstance();
        SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
        System.out.println("Data e horário atual: " + formato.format(data.getTime()));

        int currentMonth = data.get(Calendar.MONTH); // Janeiro é representado por 0
        String[] monthNames = {
            "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
            "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
        };

        System.out.println("Mês atual: " + monthNames[currentMonth]);
    }
}


