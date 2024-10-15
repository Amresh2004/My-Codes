import java.util.*;
import java.io.*;
class zero extends Exception
{
}
class prime
{
	static int flag = 0;
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int n,i;
		try
		{
			System.out.println("Enter the number");
			n = sc.nextInt();
			if(n == 0)
				throw new zero();
			for(i=2;i<=n/2;i++)
			{
				if(n % i == 0)
				{
					flag = 1;
					break;
				}
			}
			if(flag == 0)
				System.out.println("Number is prime");
			else
				System.out.println("Number is not prime");
		}
		catch (zero z)
		{
			System.out.print("Number is zero");
		}
	}
}
