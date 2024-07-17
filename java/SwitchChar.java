import java.util.Scanner;

public class SwitchChar {
    public static void main(String a[])
	{
		char ch;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enetr the Character R,G,B :");
		ch=sc.next().charAt(0);
		switch(ch)
		{
		case 'R':System.out.println("RED");
	           break;
		case 'G':System.out.println("GREEN");
		       break;
		case 'B':System.out.println("BLUE");
	           break;
	    default:
	    	System.out.println("Invalid choice");
		}
	}
}
