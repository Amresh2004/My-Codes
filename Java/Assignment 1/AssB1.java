import java.util.Date;
import java.text.SimpleDateFormat;
import java.util.Calendar;

public class AssB1 {
    public static void main(String[] args) {
        // Get current date and time
        Date currentDate = new Date();

        // Create SimpleDateFormat objects for different formats
        SimpleDateFormat sdf1 = new SimpleDateFormat("dd/MM/yyyy");
        SimpleDateFormat sdf2 = new SimpleDateFormat("MM-dd-yyyy");
        SimpleDateFormat sdf3 = new SimpleDateFormat("EEEE MMMM dd yyyy");
        SimpleDateFormat sdf4 = new SimpleDateFormat("EEE MMMM dd HH:mm:ss zzz yyyy");
        SimpleDateFormat sdf5 = new SimpleDateFormat("dd/MM/yy HH:mm:ss a Z");
        SimpleDateFormat sdf6 = new SimpleDateFormat("HH:mm:ss");

        // Display date and time in various formats
        System.out.println("Current date is : " + sdf1.format(currentDate));
        System.out.println("Current date is : " + sdf2.format(currentDate));
        System.out.println("Current date is : " + sdf3.format(currentDate));
        System.out.println("Current date and time is : " + sdf4.format(currentDate));
        System.out.println("Current date and time is : " + sdf5.format(currentDate));
        System.out.println("Current time is : " + sdf6.format(currentDate));

        // Get calendar instance
        Calendar cal = Calendar.getInstance();
        cal.setTime(currentDate);

        // Display week of year, week of month, and day of year
        System.out.println("Current week of year is : " + cal.get(Calendar.WEEK_OF_YEAR));
        System.out.println("Current week of month : " + cal.get(Calendar.WEEK_OF_MONTH));
        System.out.println("Current day of the year is : " + cal.get(Calendar.DAY_OF_YEAR));
    }
}
