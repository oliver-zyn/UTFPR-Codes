import java.text.SimpleDateFormat;
import java.util.Calendar;

public class Ex003 {
    public static void main(String[] args) {
        Calendar data = Calendar.getInstance();
        SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
        System.out.println("Data e horário atual: " + formato.format(data.getTime()));

        Calendar futureDateTime5Days = (Calendar)data.clone();
        futureDateTime5Days.add(Calendar.DAY_OF_YEAR, 5);
        System.out.println("Data daqui a 5 dias: " + formato.format(futureDateTime5Days.getTime()));
    }
}
