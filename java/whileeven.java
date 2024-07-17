import java.util.*;
public class whileeven {
    public static void main(String a[])
	{
		int n,i=1;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number");
		n=sc.nextInt();
		while(i<=n)
		{
			if(i%2==0)
			{
			System.out.println(i);
			}
			i++;
		}
	}
}
