import java.io.*;
import java.util.*;
class customer
{
	String name;
	int ph;
}
class depositor extends customer
{
	int acno;
	double balance;
}
class borrower extends depositor
{
	int lno;
	double lamount;
	public void read()
	{
		Scanner sc =new Scanner(System.in);
		System.out.println("Enter the customer name");
		super.name = sc.next();
		System.out.println("Enter the customer phone number");
		super.ph = sc.nextInt();
		System.out.println("Enter the depositer account number");
		super.acno = sc.nextInt();
		System.out.println("Enter the depositer account balance");
		super.balance = sc.nextDouble();
		System.out.println("Enter the borrower loan number");
		lno = sc.nextInt();
		System.out.println("Enter the borrower loan amount");
		lamount = sc.nextDouble();
	}
	public void display()
	{
		System.out.println("Customer name is::" +super.name + "\n hone number ::"+super.ph +"\n Account number is::" +super.acno +"\n Account balance is::"+super.balance + "\n Loan number is::"+lno+"\n Loan amount is::"+lamount);
	}
}
class cdemo
{
	public static void main(String args[])
	{
		int n,i;
		Scanner sc = new Scanner(System.in);
		System.out.println("How many customer you want");
		n= sc.nextInt();
		borrower b[] = new borrower[n];
		System.out.println("Enter "+n+" Customer information");
		for(i=0;i<n;i++)
		{
			b[i]=new borrower();
			b[i].read();
		}
		System.out.println("***********Customer information***********");
		for(i=0;i<n;i++)
			b[i].display();
	}
}
