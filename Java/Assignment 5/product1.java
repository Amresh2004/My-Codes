import java.util.*;
public class product1 implements Cloneable
{
	int pid;
	String pname;
	double cost;
	product1()
	{
		pid =101;
		pname="Pen";
		cost=20;
	}
	product1(int pid, String pname,double cost)
	{
		this.pid =pid;
		this.pname=pname;
		this.cost=cost;
	}
	void display()
	{
		System.out.println("Product id is::" +pid+ "\n Product name is::"+ pname + "\n Product Cost is::" +cost);
	}
	public static void main(String args[]) throws CloneNotSupportedException
		{
			int pid;
			String pname;
			double cost;
			Scanner sc = new Scanner(System.in);
			product1 pp = new product1();
			System.out.println("********* Default Counstructor Information*********");
			pp.display();
			System.out.println("Enter Product id");
			pid = sc.nextInt();
			System.out.println("Enter Product name");
			pname = sc.next();
			System.out.println("Enter Product Cost");
			cost = sc.nextDouble();
			product1 p = new product1(pid,pname,cost);
			System.out.println("********* Parameterised Counstructor Information*********");
			p.display();
			System.out.println("*********Object Clone Information*********");
			product1 p1 =(product1) p.clone();
			p1.display();
		}
}

