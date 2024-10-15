import java.io.*;
import java.util.*;
abstract class staff
{
	protected int id;
	protected String name;
	staff(int id, String name)
	{
		this.id=id;
		this.name=name;
	}
}
class ostaff extends staff
{
	String dname;
	ostaff(int id,String name, String dname)
	{
		super(id,name);
		this.dname=dname;
	}
	void display()
	{
		System.out.println("Staff id is::" +super.id+"\n Staff name is::"+super.name+"\n Staff department is::"+dname);
	}
}
class ademo
{
	public static void main(String args[])
	{
		Scanner sc =new Scanner(System.in);
		int n,i,id;
		String name,dname;
		System.out.println("How many staff you want");
		n = sc.nextInt();
		ostaff o[]=new ostaff[n];
		System.out.println("Enter the staff details");
		for(i=0;i<n;i++)
		{
			System.out.println("Enter the staff id");
			id = sc.nextInt();
			System.out.println("Enter the staff name");
			name = sc.next();
			System.out.println("Enter the staff department");
			dname = sc.next();
			o[i]=new ostaff(id,name,dname);
		}
		System.out.println("**********Office staff details***********");
		for(i=0;i<n;i++)
			o[i].display();
	}
}

