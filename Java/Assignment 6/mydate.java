import java.util.*;
import java.io.*;
class InvalidDateException extends Exception
{
}
class mydate
{
	int dd,mm,yy;
	public void accept()
	{
		Scanner sc = new Scanner(System.in);
		try
		{
			System.out.println("Enter the date");
			dd = sc.nextInt();
			System.out.println("Enter the month");
			mm = sc.nextInt();
			System.out.println("Enter the year");
			yy = sc.nextInt();
			if(dd < 1 || dd > 31 || mm < 1 || mm > 12 || yy < 1000 || yy > 10000)
				throw new InvalidDateException();
			else
				display();
		}
		catch (InvalidDateException d)
		{
			System.out.println("Invalid date exception caught");
		}
	}
	public void display()
	{
		System.out.println("Enterd Date is Valid dd/mm/yyyy :: "+dd+"/" + mm+"/" + yy);
	}
	public static void main(String args[])
	{
		mydate m=new mydate();
		m.accept();
	}
}
