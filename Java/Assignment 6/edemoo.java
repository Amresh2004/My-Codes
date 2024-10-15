import java.io.*;
import java.util.*;
class edemoo
{
	public static void main(String args[])
	{
		Scanner sc =new Scanner(System.in);
		System.out.println("Enter the two numbers");
		int x= sc.nextInt();
		int y= sc.nextInt();
		try
		{
			System.out.println("Devision is::" +(x/y));
		}
		catch(Exception e)
		{
			System.out.println("Exception caugth" +e);
		}
		System.out.println("My first exception program");
	}
}

