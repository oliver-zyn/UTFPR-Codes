import java.text.SimpleDateFormat;
import java.util.Calendar;

public class Ex004 {
    public static void main(String[] args) {
        Calendar data = Calendar.getInstance();
        SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
        System.out.println("Data e horário atual: " + formato.format(data.getTime()));

        Calendar futureDateTime3Years = (Calendar)data.clone();
        futureDateTime3Years.add(Calendar.YEAR, 3);
        System.out.println("Data daqui a 3 anos: " + formato.format(futureDateTime3Years.getTime()));
    }
}
