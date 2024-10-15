import java.util.Scanner;

public class demo8 {
    public static void main(String[] args)
    {
        char ch;
        Scanner sc = new Scanner (System.in);
        System.out.print("Enter Character");
        ch = sc.next().charAt(0);
        System.out.println("Entered Charcater is " +ch);
    }
}
