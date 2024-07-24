import java.util.Scanner;

public class print1ton {
    public static void main(String a[])
	{
		int n,i=1;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number");
		n=sc.nextInt();
		while(i<=n)
		{
			System.out.println(i);
			i++;
		}
	}
}
