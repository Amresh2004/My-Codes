import java.util.Scanner;

public class reverse1ToN {
    public static void main(String a[])
	{
		int n;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number");
		n=sc.nextInt();
		while(n>=0)
		{
			System.out.println(n);
			n--;
		}
	}
}
