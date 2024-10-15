import java.io.*;
import java.util.*;
class college
{
	int cno;
	String cname,cadd;
}
class dept extends college
{
	int dno;
	String dname;
	public void accept()
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the college code");
		super.cno=sc.nextInt();
		System.out.println("Enter the college name");
		super.cname=sc.next();
		System.out.println("Enter the college address");
		super.cadd=sc.next();
		System.out.println("Enter the Department code");
		dno=sc.nextInt();
		System.out.println("Enter the department name");
		dname=sc.next();
	}
	public void display()
	{
		System.out.println("College code ::" +super.cno);
		System.out.println("College name::" + super.cname);
		System.out.println("College address::" + super.cadd);
		System.out.println("Department code::" +dno);
		System.out.println("Department name::" +dname);
	}
	public static void main(String args[])
	{
		dept d =new dept();
		d.accept();
		d.display();
	}
}

