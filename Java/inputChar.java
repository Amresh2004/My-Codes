import java.util.Scanner;

public class inputChar {
    public static void main(String a[])
	{
		char ch;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enetr the character");
		ch=sc.next().charAt(0);
		System.out.println("Charachter is "+ ch);
	}
}
